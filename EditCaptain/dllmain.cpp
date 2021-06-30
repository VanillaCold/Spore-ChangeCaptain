// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "EditCaptain.h"
#include <Spore/App/ScenarioMode.h>

void Initialize()
{
	// This method is executed when the game starts, before the user interface is shown
	// Here you can do things such as:
	//  - Add new cheats
	//  - Add new simulator classes
	//  - Add new game modes
	//  - Add new space tools

	//App::ScenarioMode::OnExit


	//  - Change materials
	CheatManager.AddCheat("editCaptain", new EditCaptain());
}

void Dispose()
{
	// This method is called when the game is closing
}

/*virtual_detour(ChangeCaptainMidGameDetour, App::ScenarioMode,App::IGameMode, void())
{
	void detoured()
	{
		if (GameModeManager.GetActiveModeID() != kEditorMode)
		{
			original_function(this);
		}
	}
};*/

void AttachDetours()
{
	//ChangeCaptainMidGameDetour::attach(GetAddress(App::ScenarioMode,OnExit));
	// Call the attach() method on any detours you want to add
	// For example: cViewer_SetRenderType_detour::attach(GetAddress(cViewer, SetRenderType));
}


// Generally, you don't need to touch any code here
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		ModAPI::AddPostInitFunction(Initialize);
		ModAPI::AddDisposeFunction(Dispose);

		PrepareDetours(hModule);
		AttachDetours();
		CommitDetours();
		break;

	case DLL_PROCESS_DETACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}

