// Fill out your copyright notice in the Description page of Project Settings.


#include "RobotBehaviour/Public/MyBTTask_ChasingPlayer.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "../Private/Robot_AIControllerPlugin.h"


UMyBTTask_ChasingPlayer::UMyBTTask_ChasingPlayer()
{
	NodeName = "Chase Player";
}

EBTNodeResult::Type UMyBTTask_ChasingPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (auto* const Controller = Cast<ARobot_AIControllerPlugin>(OwnerComp.GetAIOwner()))
	{
		auto const PlayerLoc = OwnerComp.GetBlackboardComponent()->GetValueAsVector(GetSelectedBlackboardKey());

		//move the robot
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(Controller, PlayerLoc);

		//Finishing the task
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
