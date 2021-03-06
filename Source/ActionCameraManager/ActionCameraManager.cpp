// Copyright Epic Games, Inc. All Rights Reserved.

#include "ActionCameraManager.h"

#define LOCTEXT_NAMESPACE "FActionCameraManagerModule"

void FActionCameraManagerModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FActionCameraManagerModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FActionCameraManagerModule, ActionCameraManager)


/* 모듈 개발용 */

//#include "ActionCameraManager.h"
//
////핫리로딩을 지원하도록 설정
//IMPLEMENT_PRIMARY_GAME_MODULE(FDefaultGameModuleImpl, ActionCameraManager, "ActionCameraManager");