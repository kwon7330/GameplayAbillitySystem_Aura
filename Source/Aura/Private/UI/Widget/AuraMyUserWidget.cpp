// Copyrigth Druid Mechanics


#include "UI/Widget/AuraMyUserWidget.h"

void UAuraMyUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
