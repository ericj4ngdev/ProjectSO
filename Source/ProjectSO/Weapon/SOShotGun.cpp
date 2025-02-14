// Fill out your copyright notice in the Description page of Project Settings.


#include "SOShotGun.h"

#include "Kismet/KismetMathLibrary.h"
#include "ProjectSO/ProjectSO.h"
#include "ProjectSO/Character/SOCharacterBase.h"

ASOShotGun::ASOShotGun()
{
	Spread = 100;
	ShrapnelCount = 8;
}

void ASOShotGun::BeginPlay()
{
	Super::BeginPlay();
}

void ASOShotGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASOShotGun::FireAuto()
{
	Super::FireAuto();
}

void ASOShotGun::FireBurst(uint32 InMaxRepeatCount)
{
	Super::FireBurst(InMaxRepeatCount);
}

void ASOShotGun::FireSingle()
{
	Super::FireSingle();
}

void ASOShotGun::FireProjectile()
{
	// SO_LOG(LogSOTemp, Log, TEXT("ShotGun"))
	
	AController* OwnerController = OwningCharacter->GetController();
	if (OwnerController == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("OwnerController"));
		return;
	}

	// 화면 중앙 LineTrace
	FVector TraceStartLocation;
	FRotator TraceStartRotation;
	OwnerController->GetPlayerViewPoint(TraceStartLocation, TraceStartRotation);
	FTransform MuzzleSocketTransform = GetSocketTransformByName(WeaponData.MuzzleSocketName, WeaponMesh);

	TArray<FVector> TraceEndArray;
	TraceEndArray.Empty();
	for(int i =0; i< ShrapnelCount; ++i)
	{
		FVector TraceEnd = TraceStartLocation + TraceStartRotation.Vector() *  CurrentWeaponStat.MaxRange * 100 +  SpreadTraceEnd();
		TraceEndArray.Add(TraceEnd);
		DrawDebugLine(GetWorld(), MuzzleSocketTransform.GetLocation(), TraceEnd, FColor::Red,false, 5, 0, 2);
	}
	FTransform AmmoEjectSocketTransform = GetSocketTransformByName(AmmoEjectSocketName, WeaponMesh);
	FRotator MuzzleRotation = MuzzleSocketTransform.GetRotation().Rotator();
	FRotator EjectRotation = AmmoEjectSocketTransform.GetRotation().Rotator();

	// 효과 재생
	PlayMuzzleEffect(MuzzleSocketTransform.GetLocation(), MuzzleRotation);
	PlayEjectAmmoEffect(AmmoEjectSocketTransform.GetLocation(), EjectRotation);
	PlaySound();
	if(!bInfiniteAmmo) { CurrentAmmoInClip--; }
	ServerRPCOnFireShotGun(MuzzleSocketTransform, TraceEndArray);
}

void ASOShotGun::CreateProjectile(const FTransform& MuzzleTransform, const FVector& HitLocation)
{
	Super::CreateProjectile(MuzzleTransform, HitLocation);
}

FVector ASOShotGun::SpreadTraceEnd()
{
	FVector OutTraceEnd;
	OutTraceEnd.X = UKismetMathLibrary::RandomFloatInRange(Spread * -1, Spread);
	OutTraceEnd.Y = UKismetMathLibrary::RandomFloatInRange(Spread * -1, Spread);
	OutTraceEnd.Z = UKismetMathLibrary::RandomFloatInRange(Spread * -1, Spread);

	return OutTraceEnd;
}

void ASOShotGun::PlayMuzzleEffect(const FVector& MuzzleLocation, FRotator& MuzzleRotation)
{
	Super::PlayMuzzleEffect(MuzzleLocation, MuzzleRotation);
}

void ASOShotGun::PlaySound()
{
	Super::PlaySound();
}

void ASOShotGun::Recoil()
{
	Super::Recoil();
}

void ASOShotGun::PressLMB()
{
	Super::PressLMB();
}

void ASOShotGun::OnFire(ESOFireMode InFireMode)
{
	Super::OnFire(InFireMode);
}

void ASOShotGun::Reload()
{
	Super::Reload();
}

void ASOShotGun::Aim(bool bPressed)
{
	Super::Aim(bPressed);
}

void ASOShotGun::ServerRPCOnFireShotGun_Implementation(const FTransform& MuzzleTransform, const TArray<FVector>& InTraceEndArray)
{
	SO_LOG(LogSOTemp, Warning, TEXT("Begin"))
	
	for(int i =0; i < InTraceEndArray.Num(); ++i)
	{
		CreateProjectile(MuzzleTransform, InTraceEndArray[i]);
	}
	
	FireStartTime = GetWorld()->GetTimeSeconds();
	
	SO_LOG(LogSOTemp, Warning, TEXT("End"))
}
