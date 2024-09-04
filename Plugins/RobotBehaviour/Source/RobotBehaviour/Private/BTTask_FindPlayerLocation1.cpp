// Fill out your copyright notice in the Description page of Project Settings.


#include "RobotBehaviour/Public/BTTask_FindPlayerLocation1.h"
#include "Kismet/GameplayStatics.h"
#include "./BehaviorTree/BlackboardComponent.h"
#include "./GameFramework/Character.h"

UBTTask_FindPlayerLocation1::UBTTask_FindPlayerLocation1()
{
	NodeName = "Find Player Location";
}

EBTNodeResult::Type UBTTask_FindPlayerLocation1::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UWorld* World = GetWorld();
	
	/*
	TArray <AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(World, AActor::StaticClass(), FoundActors);
	if (FoundActors.Num() <= 0)
	{
		return EBTNodeResult::Failed;
	}
	*/
	//AActor* Player;

	////It may not work when the world has more than one Actor
	//if (FoundActors[0] != OwnerComp.GetOwner())
	//{
	//	Player = FoundActors[0];
	//}
	//else {
	//	Player = FoundActors[1];
	//}
	if (auto* const Player = UGameplayStatics::GetPlayerCharacter(World, 0))
	{
		auto const PlayerLoc = Player->GetActorLocation();
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), PlayerLoc);

		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return EBTNodeResult::Succeeded;
	}
	
	

	return EBTNodeResult::Failed;

}
