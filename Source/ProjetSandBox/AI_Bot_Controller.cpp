// Fill out your copyright notice in the Description page of Project Settings.

#include "AI_Bot_Controller.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

AAI_Bot_Controller::AAI_Bot_Controller() {
	PrimaryActorTick.bCanEverTick = true;

	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component")));

	SightConfig->SightRadius = AISightRadius;
	SightConfig->LoseSightRadius = AILoseSightRadius;
	SightConfig->PeripheralVisionAngleDegrees = AIFieldOfView;
	SightConfig->SetMaxAge(AISightAge);

	//Fot that the perception component works property
	SightConfig->DetectionByAffiliation.bDetectEnemies = true; // Detecting ennemis
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true; // Detecting friendlies
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true; // Detecting neutrals

	//Set the sight config variable into the perception component or the perception components knows how it need to work in the game
	GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation()); // We are settings the dominant sense as sight
	GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, &AAI_Bot_Controller::OnPawnDetected); // Attach the function that will run when a new object or a new pawn is detected by the perception system
	GetPerceptionComponent()->ConfigureSense(*SightConfig);

}

void AAI_Bot_Controller::BeginPlay()
{
	Super::BeginPlay();

	if (GetPerceptionComponent() != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("All Systems Set"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Some Problem Occured"));
	}
}

void AAI_Bot_Controller::OnPossess(APawn * Pawn)
{
	Super::OnPossess(Pawn);
}

void AAI_Bot_Controller::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

FRotator AAI_Bot_Controller::GetControlRotation() const
{
	if (GetPawn() == nullptr)
	{
		return FRotator(0.0f, 0.0f, 0.0f);
	}

	return FRotator(0.0f, GetPawn()->GetActorRotation().Yaw, 0.0f);
}

void AAI_Bot_Controller::OnPawnDetected(const TArray<AActor*>& DetectedPawns)
{
}
