// Copyrigth Druid Mechanics

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraMyHUD.generated.h"

class UAuraMyUserWidget;
/**
 * 
 */
UCLASS()
class AURA_API AAuraMyHUD : public AHUD
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UAuraMyUserWidget> OverlayWidget;

// Viewport에 보여주기위해서 BeginPlay를 사용
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraMyUserWidget> OverlayWidgetClass; 
};
