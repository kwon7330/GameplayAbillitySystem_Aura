// Copyrigth Druid Mechanics


#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

// 메크로를 사용하여 접근 하여 값을 초기화한다.
UAuraAttributeSet::UAuraAttributeSet()
{
	InitHealth(100.f);
	InitMaxHealth(100.f);
	InitMana(50.f);
	InitMaxMana(50.f);
}

// 복제하려는 모든 항목에 필요한 복제할 상태를 등록하는 곳
// COND_NONE -> 아무런 조건 없이 복제하겠다는 뜻이다.
// REPNOTIFY_Always -> 항상 값이 서버에 설정 되어 있으면 이를 클라이언트에 복제한다는 뜻이다.
// REPNOTIFY_OnChanged -> 서버에서 상태 값을 설정 했는데 해당 값이 변경 되지 않은 경우 복제가 발생되지 않는다.
void UAuraAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Health,COND_None,REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, MaxHealth,COND_None,REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Mana,COND_None,REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, MaxMana, COND_None,REPNOTIFY_Always);
}

void UAuraAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	// GAS에 Health가 복제 된것을 알려주었다.
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet,Health, OldHealth);
}

void UAuraAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	// GAS에 MaxHealth가  복제 된것을 알려주었다.
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet,Health, OldMaxHealth);
}

void UAuraAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	// GAS 에 Mana가 복제된것을 알려주었다.
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet,Mana, OldMana);
}

void UAuraAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	// GAS에 MaxMana가 복제된것을 알려주었다.
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet,MaxMana,OldMaxMana);
}
