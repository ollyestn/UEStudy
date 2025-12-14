// Fill out your copyright notice in the Description page of Project Settings.


#include "SpeechToTextActor.h"

// Sets default values
ASpeechToTextActor::ASpeechToTextActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpeechToTextActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpeechToTextActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

