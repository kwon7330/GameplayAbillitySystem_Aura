// Copyrigth Druid Mechanics


#include "Character/AuraCharacterBase.h"


AAuraCharacterBase::AAuraCharacterBase()
{
 	
	PrimaryActorTick.bCanEverTick = false;

	// 무기를 생성해서  Mesh의  WeaponHandSocket을 만들어 붙일것이다.
	// 그리고 무기의 충돌처리를 NoCollision으로 한다.
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	Weapon-> SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon-> SetCollisionEnabled(ECollisionEnabled::NoCollision);

}


void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}




