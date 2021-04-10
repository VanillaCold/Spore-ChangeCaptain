#include "stdafx.h"
#include "EditCaptain.h"
#include <SourceCode/Simulator/cGameData.cpp>

EditCaptain::EditCaptain()
{
}


EditCaptain::~EditCaptain()
{
}


void EditCaptain::ParseLine(const ArgScript::Line& line)
{
	// This method is called when your cheat is invoked.
	// Put your cheat code here.
	//GameNounManager.GetAvatar()->SetModelKey()
	Sporepedia::ShopperRequest request(this);
	request.shopperID = 0xB6277D21;
	Sporepedia::ShopperRequest::Show(request);
}

void EditCaptain::OnShopperAccept(const ResourceKey& selection)
{
	cCreatureAnimalPtr creature;
	auto oldav = GameNounManager.GetAvatar();
	creature = Simulator::cCreatureAnimal::Create(GameNounManager.GetAvatar()->GetPosition(), SpeciesManager.GetSpeciesProfile(selection), 1, nullptr, 1, 0);
	GameNounManager.SetAvatar(creature.get());
	GameNounManager.DestroyInstance(oldav);
	//GameNounManager.DestroyInstance(object_cast<Simulator::cGameData>(oldav));
	
}

const char* EditCaptain::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "This cheat does something.";
	}
	else {
		return "EditCaptain: Elaborate description of what this cheat does.";
	}
}
