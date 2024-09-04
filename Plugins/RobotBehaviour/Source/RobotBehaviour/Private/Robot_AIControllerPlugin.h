// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Robot_AIControllerPlugin.generated.h"

/**
 * 
 */
UCLASS()
class ROBOTBEHAVIOUR_API ARobot_AIControllerPlugin : public AAIController
{
	GENERATED_BODY()
public:
	explicit ARobot_AIControllerPlugin(FObjectInitializer const& ObjectInitializer);
	UBlackboardComponent* GetBlackboardComponent();
protected:
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

	//temporal varible for getting BlackBoard
	class UBlackboardComponent* BbComp;

private:
	
	
};
