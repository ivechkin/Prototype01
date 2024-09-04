// Fill out your copyright notice in the Description page of Project Settings.


#include "RobotBehaviour/Public/BTTask_ChoosePointAroundPlayer1.h"
#include "NavigationSystem.h"
#include "./BehaviorTree/BlackboardComponent.h"
#include "./BehaviorTree/Blackboard/BlackboardKeyType.h"
#include "./BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"

UBTTask_ChoosePointAroundPlayer1::UBTTask_ChoosePointAroundPlayer1()
{
	NodeName = "Chose Point Around Player";
}

EBTNodeResult::Type UBTTask_ChoosePointAroundPlayer1::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (auto* const NavSys = UNavigationSystemV1::GetCurrent(GetWorld()))
	{
		FNavLocation Location;
		FVector BBTargetLocation = OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Vector>(OwnerComp.GetBlackboardComponent()->GetKeyID("TargetLocation"));
		NavSys->GetRandomReachablePointInRadius(BBTargetLocation,PointRadius, Location);
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), Location.Location);
		
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return EBTNodeResult::Succeeded; 
	}

	return EBTNodeResult::Failed;
}
