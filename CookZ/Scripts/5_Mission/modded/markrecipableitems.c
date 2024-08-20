// all here is meant for marking items in a cooking equipment green if a recipe is met
// i.e., trigger the check if an item or attachment is added or removed or if the water quantity changes

modded class Icon
{
    void SetValidRecipeColor(int color)
    {
        if (color)
        {
            m_ColorWidget.SetColor(ARGB(150, 20, 150, 20));
            m_ColorWidget.SetAlpha(0.1);
        }
        else
        {
            m_ColorWidget.SetColor(ColorManager.BASE_COLOR);
            m_ColorWidget.SetAlpha(0.05);
        }
    }
}

modded class CargoContainer
{
    void ~CargoContainer()
	{
		if ( m_Entity )
		{
            ItemBase itemBase = ItemBase.Cast(m_Entity);
            if (itemBase)
            {
			    itemBase.GetOnItemQuantityChanged().Remove( ItemQuantityChanged );
            }
		}
	}

    override void SetEntity( EntityAI item, int cargo_index = 0, bool immedUpdate = true )
    {
        super.SetEntity(item, cargo_index, immedUpdate);
        ItemBase itemBase = ItemBase.Cast(m_Entity);
        if (itemBase)
        {
            itemBase.GetOnItemQuantityChanged().Insert( ItemQuantityChanged );
        }
    }

    void ItemQuantityChanged(float delta)
    {
        UpdateItemBackGround();
    }

    override void AddedToCargo(EntityAI item)
    {
        super.AddedToCargo(item);
        UpdateItemBackGround();
    }

    override void RemovedFromCargo( EntityAI item )
    {
        super.RemovedFromCargo(item);
        UpdateItemBackGround();
    }

    override void Refresh()
    {
        super.Refresh();
        UpdateItemBackGround();
    }

    void UpdateItemBackGround()
    {
        if (!m_Cargo)
        {
            return;
        }

        ItemBase cooking_equipment = ItemBase.Cast(m_Cargo.GetCargoOwner());
        if (!cooking_equipment)
        {
            return;
        }

        if(cooking_equipment.Type() != Pot && cooking_equipment.Type() != Cauldron && cooking_equipment.Type() != FryingPan)
        {
            return;
        }

        bool holdsRecipe = CookZ_GetCookbook().GetDishForIngredients(cooking_equipment) != null;

        for (int i = 0; i < m_Cargo.GetItemCount(); i++)
        {
            Icon icon = GetIcon(i);
            if (icon)
            {
                icon.SetValidRecipeColor(holdsRecipe);
            }
        }
    }
}

modded class Attachments
{
    override void AttachmentAdded(EntityAI item, string slot, EntityAI parent)
    {
        super.AttachmentAdded(item, slot, parent);
        m_Parent.Refresh();
    }

    override void AttachmentRemoved(EntityAI item, string slot, EntityAI parent)
    {
        super.AttachmentRemoved(item, slot, parent);
        m_Parent.Refresh();
    }
}
