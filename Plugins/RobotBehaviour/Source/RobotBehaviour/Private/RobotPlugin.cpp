// Fill out your copyright notice in the Description page of Project Settings.


#include "RobotPlugin.h"
#include "GameFramework/Character.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"



// Sets default values
ARobotPlugin::ARobotPlugin()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

//Returns behavior tree
UBehaviorTree* ARobotPlugin::GetBehaviorTree() const {
	return Tree;
}

// Called to bind functionality to input
void ARobotPlugin::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

