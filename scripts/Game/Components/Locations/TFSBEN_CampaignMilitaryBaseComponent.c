#include "scripts/Game/config.c"
//------------------------------------------------------------------------------------------------
modded class SCR_CampaignMilitaryBaseComponentClass : SCR_MilitaryBaseComponentClass
{
}

//------------------------------------------------------------------------------------------------
modded class SCR_CampaignMilitaryBaseComponent : SCR_MilitaryBaseComponent
{
	//------------------------------------------------------------------------------------------------
	override void SetAsHQ(bool isHQ)
	{
		if (IsProxy())
			return;

		m_bIsHQ = isHQ;
		SCR_CampaignFaction faction = GetCampaignFaction();

		if (m_bIsHQ)
		{
			SCR_CampaignMilitaryBaseComponent previousHQ = faction.GetMainBase();
			// SCR_CampaignMilitaryBaseComponent enemyHQ = SCR_CampaignFactionManager.Cast(GetGame().GetFactionManager()).GetEnemyFaction(faction).GetMainBase();

			if (previousHQ && previousHQ != this && previousHQ)
			{
				if (previousHQ.GetDisableWhenUnusedAsHQ())
					previousHQ.Disable();
			}
		}

		Replication.BumpMe();
		OnHQSet();
	}
}