// Copyrigth Druid Mechanics

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AuraMyUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraMyUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

	// BlueprintImplementableEvent는블루프린트의 CustomEvent와 유사하다.
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
	
};
