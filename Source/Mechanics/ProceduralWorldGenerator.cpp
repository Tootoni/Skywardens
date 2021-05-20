// Fill out your copyright notice in the Description page of Project Settings.


#include "ProceduralWorldGenerator.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

using namespace std;
// Sets default values
AProceduralWorldGenerator::AProceduralWorldGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Floor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorComponent"));
	SetRootComponent(Floor);
	gridSize = 100.f;
	worldSize = 10000.f;
	rowCount = worldSize / gridSize;
	G = vector<std::vector<int>> (rowCount, std::vector<int> (rowCount));
}

// Called when the game starts or when spawned
void AProceduralWorldGenerator::BeginPlay()
{
	Super::BeginPlay();
	ZO[BuildingClass] = 4500;
	XO[BuildingClass] = 500;
	ZO[ChairClass] = 50;
	XO[ChairClass] = 50;
	for(int i=0;i<rowCount;i++) for(int j=0;j<rowCount;j++) SpawnItem(BuildingClass, GetGridWorldLocation(i,j, XO[BuildingClass], ZO[BuildingClass]));
}

// Called every frame
void AProceduralWorldGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
FVector AProceduralWorldGenerator::GetGridWorldLocation(int x, int y, int xoffset, int zoffset) {
	if(x >= rowCount || y >= rowCount) return FVector(0.f);
	FVector Ret = GetActorLocation();
	Ret.X -= worldSize/2 - xoffset;
	Ret.Y -= worldSize/2 - xoffset;
	Ret.X += ((x) * gridSize);
	Ret.Y += ((y) * gridSize);
	Ret.Z += (zoffset - (rand() % 1000));
	return Ret;
}
void AProceduralWorldGenerator::SpawnItem(UClass* ItemToSpawn, FVector SpawnLocation)
{
	TArray<AActor*> Ignored;
	Ignored.Add(GetParentActor());
	Ignored.Add(this);
	TArray<AActor*> Out;
	TArray<TEnumAsByte<EObjectTypeQuery> > oo;
	oo.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Visibility));
	oo.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldDynamic));
	oo.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldStatic));
	oo.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_PhysicsBody));
	oo.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_GameTraceChannel2));
	oo.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Camera));
	bool ok = UKismetSystemLibrary::BoxOverlapActors(GetWorld(), SpawnLocation, FVector(XO[ItemToSpawn]*2, XO[ItemToSpawn]*2, ZO[ItemToSpawn]*2), oo, nullptr, Ignored, Out);
	//UE_LOG(LogTemp, Warning, TEXT("%d"),Out.Num());
	if(Out.Num() > 0) return;
	GetWorld()->SpawnActor<AActor>(ItemToSpawn, SpawnLocation, FRotator(0.f));
}

