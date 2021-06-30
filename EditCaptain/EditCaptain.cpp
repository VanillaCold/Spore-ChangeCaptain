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
		 //old code:
		cCreatureAnimalPtr creature;
		auto oldav = GameNounManager.GetAvatar();
		creature = Simulator::cCreatureAnimal::Create(GameNounManager.GetAvatar()->GetPosition(), SpeciesManager.GetSpeciesProfile(selection), 1, nullptr, 0, 0);
		//GameNounManager.SetAvatar(creature.get());
		//GameNounManager.DestroyInstance(oldav);
		//GameNounManager.DestroyInstance(object_cast<Simulator::cGameData>(oldav));

		//auto av = GameNounManager.GetAvatar();
		//av->mSpeciesKey = selection;
		//av->mNextSpecies = selection;
		//av->field_B20 = SpeciesManager.GetSpeciesProfile(selection);
		// = new Anim::AnimatedCreature();
		//creature = av->mpAnimatedCreature->mpAnimWorld->LoadCreature(selection);
		//auto& oldcreature = av->mpAnimatedCreature;
		 //creature->mnRefCount = oldcreature->mnRefCount;
		 //creature->field_154 = oldcreature->field_154;
		 //creature->field_158 = oldcreature->field_158;
		//creature->field_15C = oldcreature->field_15C;
		 //creature->field_160 = oldcreature->field_160;
		 //creature->field_164 = oldcreature->field_164;
		//creature->field_170 = oldcreature->field_170;
		//creature->field_184 = oldcreature->field_184;
		 //creature->field_188 = oldcreature->field_188;
		//creature->func
		//creature->field_18C = oldcreature->field_18C;
		//creature->field_194 = oldcreature->field_194;
		//creature->p_cid-> = oldcreature->p_cid;
		//	av->mpAnimatedCreature;
		
		//av->mpAnimatedCreature->p_cid = creature->p_cid;
		//av->mpAnimatedCreature->mpModel = creature->mpModel;
		//av->mpAnimatedCreature->
		//av->mpAnimatedCreature->p_cid->field_2C0 = creature->p_cid->field_2C0;
		//av->mpAnimatedCreature->p_cid->pCreature = creature->p_cid->pCreature;
		//av->mpAnimatedCreature->p_cid->blocks = creature->p_cid->blocks;
		//av->mpAnimatedCreature = creature;'

		oldav->SetModelKey(selection);
		auto scale = oldav->GetScale();
		//oldav->mpAnimatedCreature->mpModel = creature->mpAnimatedCreature->mpModel;
		//oldav->GetModelWorld()->DestroyModel(oldav->GetModel(),0);
		oldav->SetModel(creature->GetModel(),oldav->GetModelWorld());
		oldav->mpAnimatedCreature.swap(creature->mpAnimatedCreature);
		oldav->SetHasModelChanged(true);
		oldav->SetScale(scale);
		//GameNounManager.DestroyInstance(creature.get());
		creature->SetPosition(Vector3(0, 0, 0));

		//delete creature.get();
		//av->SetModel(av->GetModelWorld()->LoadModel(selection.instanceID, selection.groupID),av->GetModelWorld());
		//av->SetHasModelChanged(true);
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