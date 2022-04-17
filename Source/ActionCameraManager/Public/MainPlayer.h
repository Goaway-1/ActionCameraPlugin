#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Character.h"
#include "MainPlayer.generated.h"

UCLASS()
class ACTIONCAMERAMANAGER_API AMainPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	AMainPlayer();

protected:
	virtual void BeginPlay() override;

	void MoveForward(float Value);
	void MoveRight(float Value);

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	TSubclassOf<AActor> SpectatingViewpointClass;		//Find MainCameraManager Class...

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	class AMainCameraManager* CameraManager;
public:
	virtual void Tick(float DeltaTime) override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
