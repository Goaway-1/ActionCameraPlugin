# ActionCameraManager Plugin
- d~~~

- 목차
0. 지원 범위 (27ver, single)
1. 사용방법 (2D-1, 2D-2, 3D) : 영상까지
2. 원리 : 

> **<h3>Today Dev Story</h3>**
- ## <span style = "color:yellow;">원리</span>
  - 

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