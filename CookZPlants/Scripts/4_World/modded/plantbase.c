modded class PlantBase
{
    // harvest an item that is splitable - i.e. only create one item and set the quantity to m_CropsCount
    override void Harvest( PlayerBase player )
    {
        if (this.Type() != CookZPlants_PlantWheat)
        {
            super.Harvest(player);
            return;
        }

        if ( !IsSpoiled() )
        {
            vector pos = player.GetPosition();
            ItemBase item = ItemBase.Cast( GetGame().CreateObjectEx( m_CropsType, pos, ECE_PLACE_ON_SURFACE ) );
            item.SetQuantity(m_CropsCount);
        }
        
        m_HasCrops = false;
        SetSynchDirty();
        UpdatePlant();
    }
}