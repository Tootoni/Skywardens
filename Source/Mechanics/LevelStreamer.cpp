// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelStreamer.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/UObjectGlobals.h"
// Sets default values
ALevelStreamer::ALevelStreamer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALevelStreamer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALevelStreamer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float ALevelStreamer::getProgress(FName XX)
{
	float x = GetAsyncLoadPercentage(XX);
	//UE_LOG(LogTemp, Warning, TEXT("%f"), x);
	return x;
}
