class CookZ_ClosedDish: Edible_Base
{
    // used to store a quantity that will be taken over by the opened box
    int m_cookZ_quantity = -1;

    void CookZ_SetQuantity(int cookZ_quantity)
    {
        m_cookZ_quantity = cookZ_quantity;
    }

    int CookZ_GetQuantity()
    {
        return m_cookZ_quantity;
    }

    // note: this is for the open action (e.g. box) and not for, e.g., opening a can with a can opener.
    // this is handled in OpenCan.Do.
    override void Open()
    {
        // see Edible_Base.ReplaceEdibleWithNew
        PlayerBase player = PlayerBase.Cast(GetHierarchyRootPlayer());
		if (player)
		{
            string typeName = string.Format("%1_Opened", this.Type().ToString());
			ReplaceEdibleWithNewLambda lambda = new ReplaceEdibleWithNewLambda(this, typeName, player);
            int transferQuantity = m_cookZ_quantity;
            if (transferQuantity <= 0)
            {
                transferQuantity = -1; // -1 for do not transfer
            }
            lambda.SetTransferParams (true, true, true, false, m_cookZ_quantity);
			player.ServerReplaceItemInHandsWithNew(lambda);
		}
		else
        {
			Error("ReplaceEdibleWithNew - cannot use edible without player");
        }
    }

    override bool IsOpen()
    {
        return false;
    }
}