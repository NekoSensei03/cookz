// provide infrastructure for ui to register to quantity changes
// need to be done in ItemBase as EntityAI cannot be modded
modded class ItemBase
{
    // holds registered callbacks for quantity changes 
	protected ref ScriptInvoker m_OnItemQuantityChanged;

    ScriptInvoker GetOnItemQuantityChanged()
	{
		if(!m_OnItemQuantityChanged)
        {
			m_OnItemQuantityChanged = new ScriptInvoker;
        }
		return m_OnItemQuantityChanged;
	}

    override void OnVariablesSynchronized()
    {
        float delta = m_VarQuantity - m_VarQuantityPrev;
        super.OnVariablesSynchronized();

        if(delta != 0 && m_OnItemQuantityChanged)
        {
			m_OnItemQuantityChanged.Invoke(delta, this);
        }
    }
}
