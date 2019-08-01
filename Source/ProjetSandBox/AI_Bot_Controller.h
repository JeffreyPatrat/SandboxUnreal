// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AI_Bot_Controller.generated.h"

/**
 * 
 */
UCLASS()
class PROJETSANDBOX_API AAI_Bot_Controller : public AAIController
{
	GENERATED_BODY()

public : 
	AAI_Bot_Controller(); 

	virtual void BeginPlay() override; 

	virtual void OnPossess(APawn* Pawn) override; 

	virtual void Tick(float DeltaSeconds) override; 

	virtual FRotator GetControlRotation() const override; 
	
	UFUNCTION()

		void OnPawnDetected(const TArray<AActor*> &DetectedPawns);

	UPROPERTY(visibleAnywhere, BlueprintReadWrite, Category = AI)
		float AISightRadius = 500.0f; // how far the AI can see


	UPROPERTY(visibleAnywhere, BlueprintReadWrite, Category = AI)
		float AISightAge = 5.0f; // how long an object skip memory of the AI has detected


	UPROPERTY(visibleAnywhere, BlueprintReadWrite, Category = AI)
		float AILoseSightRadius = AISightRadius + 50.0f; // extends the AI sight radius

	UPROPERTY(visibleAnywhere, BlueprintReadWrite, Category = AI)
		float AIFieldOfView = 90.0f; // what angle the AI agent can view things or the field of view of the AI agent

	UPROPERTY(visibleAnywhere, BlueprintReadWrite, Category = AI)
		class UAISenseConfig_Sight* SightConfig;
};
