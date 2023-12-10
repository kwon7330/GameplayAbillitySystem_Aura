// Copyrigth Druid Mechanics


#include "Character/AuraEnemy.h"

#include "AbilitySystemComponent.h"
#include "ClassViewerModule.h"

#include "Aura/Aura.h"

AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility,ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent -> SetIsReplicated(true);
	AbilitySystemComponent -> SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UAttributeSet>("AttributeSet");
	
}

// Highlight를 켜주는 함수. PostProcessing_Mat를 사용하여 아웃라인을 생성시킨다.
void AAuraEnemy::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	// 메크로를 사용하여 250의 숫자를 CUSTOM_DEPTH_RED로 치환하였다. 
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AAuraEnemy::UnHighlightActor()
{
	
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}

void AAuraEnemy::BeginPlay()
{
	Super::BeginPlay();
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
