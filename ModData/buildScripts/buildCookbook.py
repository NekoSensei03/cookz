import re
import logging

logging.basicConfig(level=logging.DEBUG, format='%(asctime)s - %(levelname)s - %(message)s')

ingredient_translation_map = {
    "Potato": "#STR_Potato0",
    "GreenBellPepper": "#STR_GreenBellPepper0",
    "SlicedPumpkin": "#STR_SlicedPumpkin0",
    "Tomato": "#STR_Tomato0",
    "Lard": "#STR_Lard0",
    "Zucchini": "#STR_Zucchini0",
    "PowderedMilk": "#STR_CfgVehicles_PowderedMilk0",
    "CowSteakMeat": "#STR_CowSteakMeat0",
    "PigSteakMeat": "#STR_PigSteakMeat0",
    "RabbitLegMeat": "#STR_RabbitLegMeat0",
    "ChickenBreastMeat": "#STR_ChickenBreastMeat0",
    "GoatSteakMeat": "#STR_GoatSteakMeat0",
    "BearSteakMeat": "#STR_BearSteakMeat0",
    "SheepSteakMeat": "#STR_SheepSteakMeat0",
    "BoarSteakMeat": "#STR_BoarSteakMeat0",
    "DeerSteakMeat": "#STR_DeerSteakMeat0",
    "WolfSteakMeat": "#STR_WolfSteakMeat0",
    "HumanSteakMeat": "#STR_HumanSteakMeat0",
    "FoxSteakMeat": "#STR_FoxSteakMeat0",
    "ReindeerSteakMeat": "#STR_ReindeerSteakMeat0",
    "Apple": "#STR_Apple0",
    "Plum": "#STR_Plum0",
    "Pear": "#STR_Pear0",
    "Bone": "#STR_CfgVehicles_Bone0",
    "Rice": "#STR_CfgVehicles_Rice0",
    "Worm": "#STR_Worm0",
    "Guts": "#STR_CfgVehicles_Guts0",
    "SodaCan_Kvass": "#STR_CfgVehicles_SodaCan_Kvass0",
    "PotatoSeed": "#STR_PotatoSeed0",
    "RedCaviar": "#STR_RedCaviar0",
    "CookZ_Cheese": "#STR_CookZ_Cheese_DN",
    "DisinfectantAlcohol": "#STR_CfgVehicles_DisinfectantAlcohol0",
    "BakedBeansCan_Opened": "#STR_BakedBeansCan0 (#STR_CookZ_Open)",
    "SpaghettiCan_Opened": "#STR_SpaghettiCan0 (#STR_CookZ_Open)",
    "PeachesCan_Opened": "#STR_PeachesCan0 (#STR_CookZ_Open)",
    "Marmalade": "#STR_CfgVehicles_Marmalade0",
    "CookZPlants_Dough": "#STR_CookZPlants_Dough_DN",
    "AnyMeat": "#STR_CookZ_Ingredient_AnyMeat",
    "AnyFish": "#STR_CookZ_Ingredient_AnyFish",
    "AnyMushroom": "#STR_CookZ_Ingredient_AnyMushroom",
    "AnyFishFillet": "#STR_CookZ_Ingredient_AnyFishFillet",
    "AnyFruit": "#STR_CookZ_Ingredient_AnyFruit",
    "AnySausage": "#STR_CookZ_Ingredient_AnySausage",
    "AnyBreadcrumb": "#STR_CookZ_Ingredient_AnyBreadcrumb",
    "AnyDisinfect": "#STR_CookZ_Ingredient_AnyDisinfect",
    "AnyBlood": "#STR_CookZ_Ingredient_AnyBlood",
}

translation_map = {
    "TacticalBaconCan": "STR_TacticalBaconCan0"
}

# Define a Recipe model
class Recipe:
    def __init__(self, name, allow_pot, allow_cauldron, allow_pan, needs_water, needs_empty_can,
                 needs_empty_box, num_dishes, ingredients):
        self.name = name
        self.allow_pot = allow_pot
        self.allow_cauldron = allow_cauldron
        self.allow_pan = allow_pan
        self.needs_water = needs_water
        self.needs_empty_can = needs_empty_can
        self.needs_empty_box = needs_empty_box
        self.num_dishes = num_dishes
        self.ingredients = ingredients

    def __repr__(self):
        return f"Recipe({self.name}, {self.ingredients})"

    def generate(self):
        # Generate ingredient list
        mapped_ingredients = []
        for ingredient in self.ingredients:
            name, qty = ingredient.split(",")
            
            # Check if the ingredient has a mapping
            if name not in ingredient_translation_map:
                raise ValueError(f"Error: No mapping found for ingredient '{name}'")
            
            # Get the mapped string
            quantity = f"{qty}x" if int(qty) > 0 else "#STR_CookZ_AtLeastOne"
            mapped_ingredient = f"{quantity} {ingredient_translation_map[name]}"
            mapped_ingredients.append(mapped_ingredient)
        ingredient_string = ", ".join(mapped_ingredients)

        # Generate equipment instructions
        tools = []
        if self.allow_pot:
            tools.append("#STR_CfgVehicles_Pot0")
        if self.allow_cauldron:
            tools.append("#STR_Cauldron0")
        if self.allow_pan:
            tools.append("#STR_CfgVehicles_FryingPan0")
        use_equipment = f"#STR_CookZ_UseA {" #STR_CookZ_Or ".join(tools)}{" #STR_CookZ_WithWater" if self.needs_water else ""}."

        return f"<p><b>#{translation_map.get(self.name, f"STR_{self.name}_DN")}:</b> {ingredient_string}. {use_equipment}{" #STR_CookZ_UseEmptyCan" if self.needs_empty_can else " #STR_CookZ_UseEmptyBox" if self.needs_empty_box else ""}</p>"

# Function to parse the content into models
def parse_recipe_file(file_content):
    logging.debug("Starting to parse recipe file content...")
    recipes = []
    
    # Remove comments (lines starting with //)
    file_content = re.sub(r'//[^\n]*', '', file_content)
    logging.debug("Removed comments from the content.")

    # Improved regex pattern to match the structure
    pattern = r'        class ([\w]+)\s*{([^}]+)}\s*;'

    matches = re.findall(pattern, file_content, re.DOTALL)
    logging.debug(f"Found {len(matches)} recipe classes.")
    

    for match in matches:
        recipe_name = match[0]
        recipe_content = match[1]
        #logging.debug(f"Parsing {recipe_name}")
        
        # Extracting specific fields using regex
        allow_pot = bool(re.search(r'allowPot\s*=\s*(true);', recipe_content))
        allow_cauldron = bool(re.search(r'allowCauldron\s*=\s*(true);', recipe_content))
        allow_pan = bool(re.search(r'allowPan\s*=\s*(true);', recipe_content))
        needs_water = bool(re.search(r'needsWater\s*=\s*(true);', recipe_content))
        needs_empty_can = bool(re.search(r'needsEmptyCan\s*=\s*(true);', recipe_content))
        needs_empty_box = bool(re.search(r'needsEmptyBox\s*=\s*(true);', recipe_content))
        num_dishes_match = re.search(r'numDishes\s*=\s*(\d+);', recipe_content)
        num_dishes = int(num_dishes_match.group(1)) if num_dishes_match else 1
        
        # Extracting ingredients
        ingredients = []
        ingredients_matches = re.findall(r'\"([^\"]+)\"', recipe_content)
        for ingredient in ingredients_matches:
            ingredients.append(ingredient)
        
        # Log the extracted recipe details
        #logging.debug(f"Parsed recipe {recipe_name} with {len(ingredients)} ingredients.")
        
        # Create Recipe object
        recipe = Recipe(recipe_name, allow_pot, allow_cauldron, allow_pan, needs_water, needs_empty_can,
                        needs_empty_box, num_dishes, ingredients)
        recipes.append(recipe)
    
    logging.debug(f"Parsing complete. Total recipes: {len(recipes)}.")
    return recipes

def read_and_parse_input(file_path):
    logging.info(f"Reading file: {file_path}")
    with open(file_path, 'r') as file:
        content = file.read()
    return parse_recipe_file(content)

def generate_recipes_html(title, recipes, extra = ""):
    """Generate the HTML content for a specific category of recipes."""
    cookbook_entries = [f"    {recipe.generate()}" for recipe in recipes]
    body_content = f"    <h2>{title}</h2>\n{extra}{'\n'.join(cookbook_entries)}"
    return generate_html_by_body_content(body_content)


def generate_html_by_body_content(body_content):
    """Generate the HTML content for a body content."""
    return (
        "<!DOCTYPE html>\n"
        "<html>\n"
        "  <head>\n"
        "    <meta http-equiv=\"content-type\" content=\"text/html; charset=UTF-8\"/>\n"
        "  </head>\n"
        "  <body>\n"
        f"{body_content}\n"
        "  </body>\n"
        "</html>\n"
    )


def write_html_file(output_path, content):
    """Write the HTML content to a file."""
    with open(output_path, "w", encoding="utf-8") as file:
        file.write(content)


def process_recipes(recipes, filter_func, output_path, title, extra = ""):
    """Filter recipes, generate HTML, and write to a file."""
    filtered_recipes = [recipe for recipe in recipes if filter_func(recipe)]
    file_content = generate_recipes_html(title, filtered_recipes, extra)
    write_html_file(output_path, file_content)
    logging.debug(f"Processed {len(filtered_recipes)} recipes for {title}.")


def main():
    cookz_input_path = 'P:\\CookZ\\Scripts\\4_World\\cookbook\\config.cpp'
    plants_input_path = 'P:\\CookZPlants\\Scripts\\4_World\\cookbook\\config.cpp'
    try:
        recipes = read_and_parse_input(cookz_input_path)
        plant_recipes = read_and_parse_input(plants_input_path)
        recipes.extend(plant_recipes)

        # Define filters and outputs for each category
        categories = [
            {
                "filter": lambda recipe: not recipe.name.startswith("CookZPlants_") and recipe.needs_empty_box,
                "output": "P:\\CookZ\\data\\cookbook\\02_boxed.html",
                "title": "#STR_CookZ_BoxedDishes",
            },
            {
                "filter": lambda recipe: not recipe.name.startswith("CookZPlants_") and recipe.needs_empty_can,
                "output": "P:\\CookZ\\data\\cookbook\\03_canned.html",
                "title": "#STR_CookZ_CannedDishes",
            },
            {
                "filter": lambda recipe: not recipe.name.startswith("CookZPlants_") and re.match(r"^CookZ_.+_Sausage$", recipe.name) and recipe.name not in ["CookZ_Human_Sausage", "CookZ_Blood_Sausage"],
                "output": "P:\\CookZ\\data\\cookbook\\04_sausage.html",
                "title": "#STR_CookZ_Sausages",
            },
            {
                "filter": lambda recipe: not recipe.name.startswith("CookZPlants_") and not (
                    re.match(r"^CookZ_.+_Sausage$", recipe.name) or recipe.needs_empty_can or recipe.needs_empty_box
                ),
                "output": "P:\\CookZ\\data\\cookbook\\05_misc.html",
                "title": "#STR_CookZ_Miscellaneous",
            },
            {
                "filter": lambda recipe: recipe.name.startswith("CookZPlants_"),
                "output": "P:\\CookZPlants\\data\\cookbook\\01_plant_dishes.html",
                "extra": "    <p>#STR_CookZPlants_CookingInstructions</p>\n    <h2>#STR_CookZPlants_Dishes</h2>\n",
                "title": "#STR_CookZPlants_CookingPlants",
            },
        ]

        # Process each category
        for category in categories:
            process_recipes(recipes, category["filter"], category["output"], category["title"], category.get("extra", ""))

        # build intro page
        intro_body_content = (
            f"    <h2>#STR_CookZ_Intro</h2>\n"
            f"    <p>#STR_CookZ_Instructions</p>\n"
            f"    <h2>#STR_CookZ_PackagingMaterials</h2>\n"
            f"    <p>#STR_CookZ_EmptyCanInstructions</p>\n"
            f"    <p>#STR_CookZ_EmptyBoxInstructions</p>"
        )
        intro_content = generate_html_by_body_content(intro_body_content)
        write_html_file("P:\\CookZ\\data\\cookbook\\01_introdcution.html", intro_content)
        logging.debug(f"Created intro page.")


    except Exception as e:
        logging.error(f"An error occurred: {e}")


if __name__ == "__main__":
    main()
