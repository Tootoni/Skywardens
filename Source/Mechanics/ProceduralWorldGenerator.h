// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <vector>
#include <map>
#include "ProceduralWorldGenerator.generated.h"

UCLASS()
class MECHANICS_API AProceduralWorldGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProceduralWorldGenerator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ProceduralContent, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Floor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ProceduralContent, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> ChairClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ProceduralContent, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<AActor> BuildingClass;

	int32 gridSize;
	int32 worldSize;
	int32 rowCount;
	std::vector<std::vector<int>> G;
	std::map<TSubclassOf<AActor>, int32> ZO;
	std::map<TSubclassOf<AActor>, int32> XO;

	void SpawnItem(UClass* ItemToSpawn, FVector SL);
	FVector GetGridWorldLocation(int x, int y, int xo, int zo);
};
