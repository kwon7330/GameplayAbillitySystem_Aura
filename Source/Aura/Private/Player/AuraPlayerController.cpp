// Copyrigth Druid Mechanics


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"

AAuraPlayerController::AAuraPlayerController()
{
		bReplicates = true;
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	CursorTrace();
	
}
void AAuraPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility,false,CursorHit);
	if(!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = Cast<IEnemyInterface>(CursorHit.GetActor());

	/**
	 * Line Trace From cursor. 몇가지의 시나리오가 있다.
	 * 1. LastActor = NULL && ThisActor = NULL.
	 *		- 아무것도 하지 않는다.
	 * 2. LastActor = NULL && ThisActor is Valid 
	 *		- 그 액터를 찝는다.
	 *	3. LastActor is Valid && ThisActor is NULL
	 *		- 액터를 찝는것을 푼다.
	 *	4. BothActors are Valid, But LastActor != ThisActor
	 *		- LastActor 찝는것을 풀고, ThisActor를 찝는다.
	 *	5. BothActors are Valid, 두액터가 모두 같은 액터일때
	 *		- 아무것도 하지 않는다.
	 */

	if(LastActor == nullptr)
	{
		if(ThisActor != nullptr)
		{
			// Case 2
			ThisActor->HighlightActor();
		}
		else
		{
			// 둘다 NULL값이므로 Case1에 속한다. (아무것도 하지 않는다.)
		}
	}
	else // Last Actor is Valid
	{
		if(ThisActor == nullptr)
		{
			//Case 3
			LastActor->UnHighlightActor();
		}
		else // BothActor is Valid
		{
			if(LastActor != ThisActor)
			{
				// Case 4
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			}
			else
			{
				//Case 5
				//아무것도 하지않는다.
			}
		}
	}	
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// MappingContext가 잘들어왔는지 확인한다.
	check(AuraContext);
	// IMC 받기위해 변수 Sbusystem을 만든다.
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	check(Subsystem);
	// IMC를 받는다.
	Subsystem->AddMappingContext(AuraContext,0);

	// 마우스를 게임 화면에 보이게 하기 위한 작업
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f,Rotation.Yaw,0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if(APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);

	}
}


