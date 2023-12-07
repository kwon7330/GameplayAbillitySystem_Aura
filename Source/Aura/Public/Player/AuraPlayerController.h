// Copyrigth Druid Mechanics

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class IEnemyInterface;
/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AAuraPlayerController();
	
	virtual void PlayerTick(float DeltaTime) override;
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere, Category="Input")
	// Aura Build.Cs에 EnhancedInput 모듈을 추가하였다.
	// IMC 만들기
	TObjectPtr<UInputMappingContext> AuraContext;

	// InputAction 만들기
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	// 작동(움직이기)을 위한 함수를 선언
	void Move(const FInputActionValue& InputActionValue);

	void CursorTrace();
	
	IEnemyInterface* LastActor;
	IEnemyInterface* ThisActor;

	
};
