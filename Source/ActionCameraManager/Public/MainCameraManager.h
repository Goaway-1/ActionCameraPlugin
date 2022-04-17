#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MainCameraManager.generated.h"

UENUM(BlueprintType)
enum class ECameraType : uint8 {
	ECT_2D_Fix			UMETA(DisplayName = "ECT_2D_Fix"),		//RootScene ȸ�� ���� ����
	ECT_2D_NonFix		UMETA(DisplayName = "ECT_2D_NonFix"),	//RootScene ȸ�� ���� ����
	ECT_3D				UMETA(DisplayName = "ECT_3D")			//RootScene ȸ�� ���� ����
};

UCLASS()
class ACTIONCAMERAMANAGER_API AMainCameraManager : public APawn
{
	GENERATED_BODY()

public:
	AMainCameraManager();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	class USceneComponent* DefaultSceneRoot;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	class USpringArmComponent* SpringArmComp;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	class UCameraComponent* CameraComp;

	//ī�޶� ȸ���� �̵��� ������ ���� ������Ʈ
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	class USceneComponent* ReferenceScene;

	UPROPERTY(EditDefaultsOnly, Category = "Environment_Variable")
	TSubclassOf<AActor> PlayerClass;

	UPROPERTY(EditInstanceOnly, Category = "Environment_Variable")
	TArray<AActor*> Players;

	UPROPERTY(EditAnywhere, Category = "Environment_Variable")
	ECameraType CameraType;

	FORCEINLINE ECameraType GetCameraType() { return CameraType; }

private:
	float MinRotDistance = 145.f;	//ȸ���� �ϰԵǴ� �ִ� �Ÿ� (������ ȸ��)
	float RotationDelay = 4.f;
	float Height = 25.f;

	//SpringArm�� �ּ�, �ִ� ����
	float SpringArmBaseDistance = 330.f;
	float SpringArmExtraDistance = 70.f;

	//SpringArm�� Pitch �ּ�, �ִ� ����
	float MinSpringArmRotation = 3.f;
	float MaxSpringArmRotation = 5.f;

	//������ �ּ�, �ִ� ���� ���� �����ϱ� ���� ���� ��
	float MaxOverlapInnerVal = 0.5f;
	float MinOverlapInnerVal = 0.07f;

	float IsForward;	//P1�� P2�� ���ߴµ� �յڿ� �ִ��� �� -> ��(1)/��(-1)
	float IsLeft;		//Reference���� P1�� �¿� ��� �ִ��� �� -> ����(1), ������(-1)

	float GlobalDistanceFactor;		//P1�� P2 ������ �Ÿ��� 0~1�� ������ ��ȯ
	float P1ToRoot_InnerVec;

	bool bIsPlayersOverlap = false;					//Overlap�� ����
	float OverlapRotateForce = -35.f;				//Overlap�� ȸ���� ��
	float TekkenRotateForce = 200.f;				//TekkenŸ���϶� ȸ�� ��

	void FindAndSet();
	void SetReferenceScene();			//�׻� ReferenceScene�� �׻� P1�� ���� X�࿡ �ֵ��� ����
	void RotateDefaultScene();			//�׻� ReferenceScene�� �׻� P1�� �ֺ� Y�࿡ �����ϵ��� ����
	void SetCameraPosition();			//SpringArm�� ���̿� Pitch�� �����Ͽ� ���� ���� ����
	void SetViewAllPlayers();			//�÷��̾ Overlap�� ����
	void SetNonOverlap();				//Overlap�� ī�޶� ȸ���Ͽ� ��ġ�� �ʵ��� ����
	void SetP1RelativeVal();			//P1�� P2�� ���� ������� ��ġ�� ���� (��,�� ��....)
};
