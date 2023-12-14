// Copyrigth Druid Mechanics

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraMyHUD.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
class UAuraMyUserWidget;
class UOverlayWidgetController;
struct FWidgetControllerParams;
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

	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);

	//InitOverlay는 위젯 컨트롤러를 구성하고, 위젯을 구성하고, 위젯을 설정한다. 따라서 BeginPlay를 제거한다.
	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC,UAttributeSet* AS);



private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraMyUserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
};
