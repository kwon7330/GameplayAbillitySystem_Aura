// Copyrigth Druid Mechanics


#include "UI/HUD/AuraMyHUD.h"

#include "UI/Widget/AuraMyUserWidget.h"

void AAuraMyHUD::BeginPlay()
{
	Super::BeginPlay();
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget-> AddToViewport();
}
