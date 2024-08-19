// provide infrastructure for ui to register to quantity changes
// need to be done in ItemBase as EntityAI cannot be modded
modded class ItemBase
{
    //Called when an this item quantity is changed
	protected ref ScriptInvoker m_OnItemQuantityChanged;

    ScriptInvoker GetOnItemQuantityChanged()
	{
		if(!m_OnItemQuantityChanged)
        {
			m_OnItemQuantityChanged = new ScriptInvoker;
        }
		return m_OnItemQuantityChanged;
	}

    override void OnQuantityChanged(float delta)
    {
        super.OnQuantityChanged(delta);

        if(m_OnItemQuantityChanged)
        {
			m_OnItemQuantityChanged.Invoke( delta, this );
        }
    }
}
