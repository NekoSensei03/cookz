// all here is meant for marking items in a cooking equipment green if a recipe is met
// i.e., trigger the check if an item or attachment is added or removed or if the water or item quantity changes
// (ingredient foodstage change might also be nice - but is neglected for now)

modded class Icon
{
    void SetValidRecipeColor(bool mark)
    {
        int color;
        if (mark)
        {
            color = ColorManager.GREEN_COLOR;
        }
        else
        {
            color = ColorManager.BASE_COLOR;
        }
        m_SelectedPanel.Show(mark);
        ColorManager.GetInstance().SetColor(m_SelectedPanel, color);
    }
}

modded class CargoContainer
{
    void ~CargoContainer()
    {
        ItemBase itemBase = GetCookingEquipment();
        if (itemBase)
        {
            ClearGetOnItemQuantityChangedCallback(itemBase);
            for (int i = 0; i < m_Cargo.GetItemCount(); i++)
            {
                ClearGetOnItemQuantityChangedCallback(m_Cargo.GetItem(i));
            }
        }
    }

    override void SetEntity(EntityAI item, int cargo_index = 0, bool immedUpdate = true)
    {
        super.SetEntity(item, cargo_index, immedUpdate);
        ItemBase itemBase = GetCookingEquipment();
        if (itemBase)
        {
            AddGetOnItemQuantityChangedCallback(itemBase);
            for (int i = 0; i < m_Cargo.GetItemCount(); i++)
            {
                AddGetOnItemQuantityChangedCallback(m_Cargo.GetItem(i));
            }
        }
    }

    override void AddedToCargo(EntityAI item)
    {
        super.AddedToCargo(item);
        if(GetCookingEquipment())
        {
            UpdateItemBackGround();
            AddGetOnItemQuantityChangedCallback(item);
        }
    }

    override void RemovedFromCargo(EntityAI item)
    {
        super.RemovedFromCargo(item);
        if(GetCookingEquipment())
        {
            UpdateItemBackGround();
            ClearGetOnItemQuantityChangedCallback(item);
        }
    }

    private void AddGetOnItemQuantityChangedCallback(EntityAI item)
    {
        ItemBase itemBase = ItemBase.Cast(item);
        if (itemBase)
        {
            itemBase.GetOnItemQuantityChanged().Clear();
            itemBase.GetOnItemQuantityChanged().Insert(ItemQuantityChanged);
        }
    }

    private void ClearGetOnItemQuantityChangedCallback(EntityAI item)
    {
        ItemBase itemBase = ItemBase.Cast(item);
        if (itemBase)
        {
            itemBase.GetOnItemQuantityChanged().Clear();
        }
    }

    override void Refresh()
    {
        super.Refresh();
        UpdateItemBackGround();
    }

    void ItemQuantityChanged(float delta, ItemBase target)
    {
        UpdateItemBackGround();
    }

    void UpdateItemBackGround()
    {
        ItemBase cookingEquipment = GetCookingEquipment();
        if(!cookingEquipment)
        {
            return;
        }

        bool holdsRecipe = CookZ_GetCookbook().GetDishForIngredients(cookingEquipment) != null;

        for (int i = 0; i < m_Cargo.GetItemCount(); i++)
        {
            Icon icon = GetIcon(i);
            if (icon)
            {
                icon.SetValidRecipeColor(holdsRecipe);
            }
        }
    }

    private ItemBase GetCookingEquipment()
    {
        if (!m_Entity)
        {
            return null;
        }

        ItemBase item = ItemBase.Cast(m_Entity);
        if (!item)
        {
            return null;
        }

        if (item.Type() == Pot || item.Type() == Cauldron || item.Type() == FryingPan)
        {
            return item;
        }

        return null;
    }
}

modded class Attachments
{
    override void AttachmentAdded(EntityAI item, string slot, EntityAI parent)
    {
        super.AttachmentAdded(item, slot, parent);
        if (IsCookingEquipment(parent))
        {
            m_Parent.Refresh();
        }
    }

    override void AttachmentRemoved(EntityAI item, string slot, EntityAI parent)
    {
        super.AttachmentRemoved(item, slot, parent);
        if (IsCookingEquipment(parent))
        {
            m_Parent.Refresh();
        }
    }

    private bool IsCookingEquipment(EntityAI item)
    {
        return item.Type() == Pot || item.Type() == Cauldron || item.Type() == FryingPan;
    }
}
