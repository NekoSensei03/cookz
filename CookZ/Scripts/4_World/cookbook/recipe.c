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

    void CookZ_Recipe(string pName, bool pAllowPot, bool pAllowCauldron, bool pAllowPan, bool pNeedsWater, bool pNeedsEmptyCan, bool pNeedsEmptyBox)
    {
        ingredients = new array<ref CookZ_Ingredient>();
        name = pName;
        allowPot = pAllowPot;
        allowCauldron = pAllowCauldron;
        allowPan = pAllowPan;
        needsWater = pNeedsWater;
        needsEmptyCan = pNeedsEmptyCan;
        needsEmptyBox = pNeedsEmptyBox;
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
