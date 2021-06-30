#include "stdafx.h"
#include "EditCaptain.h"
#include <SourceCode/Simulator/cGameData.cpp>
#include <Spore/App/ScenarioMode.h>

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
	if (Simulator::IsScenarioMode())
	{

		if (!line.HasFlag("editor"))
		{
			Sporepedia::ShopperRequest request(this);
			request.shopperID = 0xB6277D21;
			Sporepedia::ShopperRequest::Show(request);
			//return;
		}
		/*else
		{
			if (hasEnteredEditorThroughCheat == 1 && Editor.mpEditorModel != nullptr)
			{
				hasEnteredEditorThroughCheat = 0;
				cCreatureAnimalPtr creature;
				auto oldav = GameNounManager.GetAvatar();
				creature = Simulator::cCreatureAnimal::Create(GameNounManager.GetAvatar()->GetPosition(), SpeciesManager.GetSpeciesProfile(Editor.mpEditorModel->field_0C), 1, nullptr, 1, 0);
				GameNounManager.SetAvatar(creature.get());
				GameNounManager.DestroyInstance(oldav);
				//return;
			}
			else
			{
				hasEnteredEditorThroughCheat = 1;
				EditorRequestPtr request = new Editors::EditorRequest();
				request->editorID = 0x465C50BA; //id("CreatureEditorExtraLarge");
				request->creationKey = GameNounManager.GetAvatar()->mSpeciesKey;
				Simulator::cGameModeManager::Get()->SubmitEditorRequest(request.get());
			}//return;
		}*/
	}
}

void EditCaptain::OnShopperAccept(const ResourceKey& selection)
{
	if (selection != ResourceKey(0, 0, 0))
	{
		cCreatureAnimalPtr creature; //create new pointer
		auto oldav = GameNounManager.GetAvatar();
		creature = Simulator::cCreatureAnimal::Create(GameNounManager.GetAvatar()->GetPosition(), SpeciesManager.GetSpeciesProfile(selection), 1, nullptr, 0, 0); //create new creature for said pointer

		oldav->SetModelKey(selection); //change the resourcekey for the model
		auto scale = oldav->GetScale(); //get the current avatar scale
		oldav->SetModel(creature->GetModel(),oldav->GetModelWorld()); //change avatar model
		oldav->mpAnimatedCreature.swap(creature->mpAnimatedCreature); //swap avatar mpAnimatedCreature with that of placeholder creature
		oldav->SetHasModelChanged(true); //tell the avatar that its model has changed
		oldav->SetScale(scale); //restore the avatar scale
		creature->SetPosition(Vector3(0, 0, 0)); //removing placeholder creature crashes, so put it into the void instead.
	}
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

bool EditCaptain::hasEnteredEditorThroughCheat = 0;