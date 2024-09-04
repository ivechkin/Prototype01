 // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_FindPlayerLocation1.generated.h"

/**
 * 
 */
UCLASS()
class ROBOTBEHAVIOUR_API UBTTask_FindPlayerLocation1 : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	//Constructor for setting it's name in the editor
	explicit UBTTask_FindPlayerLocation1();
	//Must function for executing the task
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
