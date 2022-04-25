> # ActionCameraManager Plugin
  - 이 플러그인은 2D, 3D와 같은 액션 격투 게임에 사용되는 카메라 관리자입니다. 이를 사용하면 카메라의 이동(뷰포트)을 자동으로 조작하여 플레이어들이 뷰포트에 항상 위치하도록 유지합니다.  

> ## 목차
1. [설명 (Description)](#설명-(Description))
2. [사용방법 (How to use)](#사용방법-(How-to-use))
3. [동작원리 (Operating Structure)](#동작원리-(Operating-Structure))
   1. [2D_Fix Mode](#2D_Fix-Mode)
   2. [2D Mode](#2D-Mode)
   3. [3D Mode](#2D-Mode)

> ### **<h3>설명 (Description)</h3>**
  - ActionCameraManger 플러그인은 Takken7, Naruto Ulitimate Ninja Storm 4와 같은 __액션 배틀 게임에서 사용하는 로컬 카메라 플러그인입니다.__ 이 플러그인을 사용한다면 카메라의 조작을 MainCameraManager에서 자동으로 조작하기 때문에 개발자는 카메라에 대해서 개발을 진행할 필요가 없습니다. 이 카메라의 모드는 2D, 2D_fix, 3D로 총 3가지를 가지고 있습니다. 

  - <img src="Image/" height="300" title="">
  - 먼저 2D_Fix 모드는 카메라의 회전이 불가능하고, 거리(SpringArm Length)만 조정되기 때문에, 좌우로만 움직여 플레이하는 형식의 프로젝트에 유용합니다. 만약 좌우로만 움직이지 않고 상하방향으로 플레이어가 움직인다면 카메라에 플레이어를 담을 수 없습니다. 그 예시로는 Old Street Fighter2가 있습니다.

  - <img src="Image/" height="300" title="">
  - 다음으로 2D 모드는 카메라의 회전이 가능하고, 거리 또한 조정되기에 두 플레이어가 어디에 있던 뷰포트에 항상 두 플레이어를 모두 담을 수 있습니다. 하지만 두 플레이어의 좌우 위치가 바뀔때 카메라의 회전이 자연스럽지 않기 때문에, 주로 좌우로만 움직여 플레이하고 상하로는 조금씩만 움직여서 플레이하는 형식의 프로젝트에 유용합니다. 그 예시로는 Tekken7이 있습니다. 

  - <img src="Image/" height="300" title="">
  - 마지막으로 이 플러그인의 핵심인 3D 모드입니다. 이 모드는 겉으로 보기에는 2D와 비슷하지만 2D와는 다르게 카메라 회전에 있어 자연스러움을 보여주기 때문에 상하좌우 어디로든 자유롭게 움직여서 플레이하는 형식의 프로젝트에 유용합니다. 그 예시로는 Naruto Ulitimate Ninja Storm 4가 있습니다.

> ### **<h3>사용방법 (How to use)</h3>**
  - [링크](#http)

> ### **<h3>동작원리 (Operating Structure)</h3>**

  - ### **2D_Fix Mode**

  - ### **2D Mode**

  - ### **3D Mode**




- ## <span style = "color:yellow;">카메라 매니저의 설정</span>
  - <img src="Image/MainCameraSetting.gif" height="300" title="MainCameraSetting">
  - 계산에 있어서는 항상 P1(Player1)을 기준으로 계산을 진행
  - 녹색구는 ReferenceScene의 위치, 적색구는 DefaultSceneRoot의 위치를 나타냄

  ___

  ### 1. 카메라가 참조할 ReferenceScene 제작 및 상하 위치 조정
  - SceneComponent타입의 ReferenceScene를 제작하고, 항상 ReferenceScene를 항상 P1과 같은 __X축에__ 있도록 설정
  - 추후 액터의 회전을 통해서 P1의 옆(좌/우)에 항상 상주하도록 설정 (위 사진에서는 녹색구가 ReferenceScene의 위치를 표현)
  - __원리 :__

  + 추가 
  - 아래와 같이 Enum 클래스를 추가하여 사용자들이 편하게 수정할 수 있도록 조정.
  ```c++
  //MainCameraManager.h
  UENUM(BlueprintType)
  enum class ECameraType : uint8 {
    ECT_2D_Fix			UMETA(DisplayName = "ECT_2D_Fix"),		//RootScene 회전 고정 여부
    ECT_2D_NonFix		UMETA(DisplayName = "ECT_2D_NonFix"),	//RootScene 회전 고정 여부
    ECT_3D				UMETA(DisplayName = "ECT_3D")			//RootScene 회전 고정 여부
  };

	UPROPERTY(EditAnywhere, Category = "Environment_Variable")
	ECameraType CameraType;

	FORCEINLINE ECameraType GetCameraType() { return CameraType; }
  ```