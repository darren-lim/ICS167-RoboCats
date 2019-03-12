#include <RoboCatServerPCH.h>


MouseServer::MouseServer()
{
}

void MouseServer::HandleDying()
{
	NetworkManagerServer::sInstance->DecrementAmmoCrateCount();
	NetworkManagerServer::sInstance->UnregisterGameObject( this );
}


bool MouseServer::HandleCollisionWithCat( RoboCat* inCat )
{
	//kill yourself!
	if (inCat->GetAmmoCount() == 0)
	{
		SetDoesWantToDie(true);
		static_cast<RoboCatServer*>(inCat)->IncreaseAmmo(inCat->GetPlayerId());
	}

	//ScoreBoardManager::sInstance->IncScore( inCat->GetPlayerId(), 1 );

	return false;
}


