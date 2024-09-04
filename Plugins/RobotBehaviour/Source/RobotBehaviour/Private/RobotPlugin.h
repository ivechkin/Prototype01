// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RobotPlugin.generated.h"

class UBehaviorTree;

UCLASS()
class ROBOTBEHAVIOUR_API ARobotPlugin : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARobotPlugin();
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	//Returns his Behavior tree. Used in the controller
	UBehaviorTree* GetBehaviorTree() const;
	
protected:
	

	//Adding Behavior tree variable in the blueprint under Category AI (It also wants library)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"));
	class UBehaviorTree* Tree;

	
};
