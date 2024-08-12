class CookZ_Recipe
{
    string name;
    ref array<ref CookZ_Ingredient> ingredients;
    bool allowPot;
    bool allowCauldron;
    bool allowPan;
    bool needsWater;
    bool needsEmptyCan;
    bool needsEmptyBox;

    void CookZ_Recipe(string name, bool allowPot, bool allowCauldron, bool allowPan, bool needsWater, bool needsEmptyCan, bool needsEmptyBox)
    {
        this.ingredients = new array<ref CookZ_Ingredient>();
        this.name = name;
        this.allowPot = allowPot;
        this.allowCauldron = allowCauldron;
        this.allowPan = allowPan;
        this.needsWater = needsWater;
        this.needsEmptyCan = needsEmptyCan;
        this.needsEmptyBox = needsEmptyBox;
    }

    void AddIngredient(CookZ_Ingredient ingredient)
    {
        ingredients.Insert(ingredient);
    }

    int GetNumIngredients()
    {
        int result = 0;
        foreach (CookZ_Ingredient ingredient : ingredients)
        {
            result += ingredient.quantity;
        }
        return result;
    }
}
