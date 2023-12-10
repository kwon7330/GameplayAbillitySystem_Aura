// Copyrigth Druid Mechanics


#include "Character/AuraCharacterBase.h"


AAuraCharacterBase::AAuraCharacterBase()
{
 	
	PrimaryActorTick.bCanEverTick = false;

	// 무기를 생성해서  Mesh의  WeaponHandSocket을 만들어 붙일것이다.
	// 그리고 무기의 충돌처리를 NoCollision으로 한다.
	
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	// 무기를 붙일 소켓을 정한다.
	Weapon-> SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	// 무기는 NoCollision 으로 처리한다.
	Weapon-> SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

UAbilitySystemComponent* AAuraCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}




