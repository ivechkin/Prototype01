// Fill out your copyright notice in the Description page of Project Settings.


#include "Robot_AIControllerPlugin.h"
#include "RobotPlugin.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTree.h"

ARobot_AIControllerPlugin::ARobot_AIControllerPlugin(FObjectInitializer const& ObjectInitializer)
{

}

UBlackboardComponent* ARobot_AIControllerPlugin::GetBlackboardComponent()
{
	return BbComp;
}

//When pawn's controller is set on this class and the game is started ("possessed")
void ARobot_AIControllerPlugin::OnPossess(APawn* InPawn)
{
	//That is a must. Not sure why
	Super::OnPossess(InPawn);

	//Casting the possessed pawn as our Robot 
	if (ARobotPlugin* const npc = Cast<ARobotPlugin>(InPawn))
	{
		//Getting it's BehaviourT for blackboard where library it's not neccesary because of the include
		if (UBehaviorTree* const tree = npc->GetBehaviorTree())
		{
			
			//It creates new if there isn't already other blackboard in use
			UseBlackboard(tree->GetBlackboardAsset(), BbComp);
			//Setting the controller blackboard variable as the created
			Blackboard = BbComp;
			RunBehaviorTree(tree);

		}
	}
}

void ARobot_AIControllerPlugin::OnUnPossess()
{
	Super::OnUnPossess();
}

