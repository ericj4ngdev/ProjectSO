﻿#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "NiagaraSystem.h"
#include "SOGunPartsEnumLibrary.h"
#include "SOWeaponEnumLibrary.h"
#include "Library/ALSCharacterEnumLibrary.h"
#include "SOWeaponStructLibrary.generated.h"


enum class EALSOverlayState : uint8;

USTRUCT(BlueprintType)
struct FSOWeaponStat : public FTableRowBase
{
	GENERATED_BODY()

public:
	FSOWeaponStat(): WeaponType(ESOWeaponType::Pistol), FireMode(0), AmmoType(
		ESOAmmoType::None), FireInterval(0), ReloadInterval(0), QuickReloadInterval(0),
					 Speed(0),
					 MaxRange(0),
					 AimedRecoilYaw(0), AimedRecoilPitch(0),bLargeClip(false), ClipSize(0),
					 NormalClipSize(0),
					 LargeClipSize(0), Damage(0), AimingTime(0), MuzzleFlashScale(1)
	{
	}

	FSOWeaponStat& operator=(const FSOWeaponStat& InOhterStat)
	{
		if(this!= &InOhterStat)
		{
			ID = InOhterStat.ID;
			WeaponName = InOhterStat.WeaponName;
			WeaponType = InOhterStat.WeaponType;
			FireMode = InOhterStat.FireMode;
			AmmoType = InOhterStat.AmmoType;
			FireInterval = InOhterStat.FireInterval;
			ReloadInterval = InOhterStat.ReloadInterval;
			QuickReloadInterval = InOhterStat.QuickReloadInterval;
			Speed = InOhterStat.Speed;
			MaxRange = InOhterStat.MaxRange;
			RecoilYaw = InOhterStat.RecoilYaw;
			RecoilPitch = InOhterStat.RecoilPitch;
			AimedRecoilYaw = InOhterStat.AimedRecoilYaw;
			AimedRecoilPitch = InOhterStat.AimedRecoilPitch;
			bCanLensAim = InOhterStat.bCanLensAim;
			bCanZoomInOut = InOhterStat.bCanZoomInOut;
			MinFOV = InOhterStat.MinFOV;
			MaxFOV = InOhterStat.MaxFOV;
			bLargeClip = InOhterStat.bLargeClip;
			ClipSize = InOhterStat.ClipSize;
			NormalClipSize = InOhterStat.NormalClipSize;
			LargeClipSize = InOhterStat.LargeClipSize;
			Damage = InOhterStat.Damage;
			AimingTime = InOhterStat.AimingTime;
			MuzzleFlashScale = InOhterStat.MuzzleFlashScale;
		}
		return *this;
	}
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	uint8 ID;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	FName WeaponName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	ESOWeaponType WeaponType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	int FireMode;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	ESOAmmoType AmmoType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float FireInterval;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float ReloadInterval;
    	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float QuickReloadInterval;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float MaxRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float RecoilYaw;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float RecoilPitch;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float AimedRecoilYaw;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float AimedRecoilPitch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	uint8 bCanLensAim : 1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	uint8 bCanZoomInOut : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float MinFOV;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float MaxFOV;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	uint8 bLargeClip : 1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	int ClipSize;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	int NormalClipSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	int LargeClipSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float AimingTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float MuzzleFlashScale;	
};

USTRUCT(BlueprintType)
struct FSOWeaponData : public FTableRowBase
{
	GENERATED_BODY()

public:
	FSOWeaponData& operator=(const FSOWeaponData& InOhterStat)
	{
		if(this!= &InOhterStat)
		{
			ID = InOhterStat.ID;
			AmmoClass=InOhterStat.AmmoClass;
			WeaponType = InOhterStat.WeaponType;
			OverlayState = InOhterStat.OverlayState;
			DistanceDamageFalloff = InOhterStat.DistanceDamageFalloff;
			WeaponMeshDataAsset = InOhterStat.WeaponMeshDataAsset;
			FireMontage =  InOhterStat.FireMontage;
			EquipMontage = InOhterStat.EquipMontage;
			ReloadMontage = InOhterStat.ReloadMontage;
			ReloadWeaponMontage = InOhterStat.ReloadWeaponMontage;
			MuzzleFlashEffect = InOhterStat.MuzzleFlashEffect;
			EjectShellParticles = InOhterStat.EjectShellParticles;
			FireSound = InOhterStat.FireSound;
			EquipSocketName= InOhterStat.EquipSocketName;
			MuzzleSocketName= InOhterStat.MuzzleSocketName;
			FireEffectSocketName= InOhterStat.FireEffectSocketName;
			PartsSocketMap = InOhterStat.PartsSocketMap;
		}
		return *this;
	}
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ID)
	uint8 ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Ammo)
	TSubclassOf<class ASOProjectileBase> AmmoClass; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WeaponType)
	ESOWeaponType WeaponType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimationState)
	EALSOverlayState OverlayState;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Distance)
	FRuntimeFloatCurve DistanceDamageFalloff;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
	TObjectPtr<class USOWeaponMeshDataAsset> WeaponMeshDataAsset;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation)
	TObjectPtr<UAnimMontage> FireMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation)
	TObjectPtr<UAnimMontage> EquipMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation)
	TObjectPtr<UAnimMontage> ReloadMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation)
	TObjectPtr<UAnimMontage> ReloadWeaponMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
	TObjectPtr<UParticleSystem> MuzzleFlashEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Effect)
	TObjectPtr<class UNiagaraSystem> EjectShellParticles;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Sound)
	TObjectPtr<class USoundBase> FireSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Socket)
	FName EquipSocketName; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Socket)
	FName MuzzleSocketName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Socket)
	FName FireEffectSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Socket|Parts")
	TMap<ESOGunPartsType, FName> PartsSocketMap;	
};

USTRUCT(BlueprintType)
struct FSOWeaponDamageData : public FTableRowBase
{
	GENERATED_BODY()
	
public:
	FSOWeaponDamageData(): Head(0), Neck(0), Clavicles(0), Upperchest(0), Lowerchest(0),
				 Stomach(0),
				 Pelvis(0),
				 Upperlimb(0), Lowerlimb(0),
				 Handfoot(0)
	{
	}
	
	FSOWeaponDamageData& operator=(const FSOWeaponDamageData& InOhterDamageData)
	{
		if(this!= &InOhterDamageData)
		{
			ID = InOhterDamageData.ID;
			Head = InOhterDamageData.Head;
			Neck = InOhterDamageData.Neck;
			Clavicles = InOhterDamageData.Clavicles;
			Upperchest =  InOhterDamageData.Upperchest;
			Lowerchest = InOhterDamageData.Lowerchest;
			Stomach = InOhterDamageData.Stomach;
			Pelvis = InOhterDamageData.Pelvis;
			Upperlimb = InOhterDamageData.Upperlimb;
			Lowerlimb = InOhterDamageData.Lowerlimb;
			Handfoot = InOhterDamageData.Handfoot;
		}
		return *this;
	}
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WeaponDamage)
	uint8 ID;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WeaponDamage)
	float Head;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WeaponDamage)
	float Neck;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WeaponDamage)
	float Clavicles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WeaponDamage)
	float Upperchest;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WeaponDamage)
	float Lowerchest;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WeaponDamage)
	float Stomach;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WeaponDamage)
	float Pelvis;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WeaponDamage)
	float Upperlimb;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WeaponDamage)
	float Lowerlimb;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WeaponDamage)
	float Handfoot;
};

USTRUCT(BlueprintType)
struct FSOWeaponDamageByBone  : public FTableRowBase
{
	GENERATED_BODY()
	
public:
	
	FSOWeaponDamageByBone & operator=(const FSOWeaponDamageByBone& InOhterDamageData)
	{
		if(this!= &InOhterDamageData)
		{
			DamageByHitLocationMap = InOhterDamageData.DamageByHitLocationMap;
		}
		return *this;
	}
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WeaponDamage)
	TMap<FString, float> DamageByHitLocationMap;
	
};

USTRUCT(BlueprintType)
struct FSOWeaponClassAreaDamageData : public FTableRowBase
{
	GENERATED_BODY()
	
public:
	FSOWeaponClassAreaDamageData& operator=(const FSOWeaponClassAreaDamageData& InOhterDamageData)
	{
		if(this!= &InOhterDamageData)
		{
			WeaponType = InOhterDamageData.WeaponType;
			WeaponBoneDamageDataAsset = InOhterDamageData.WeaponBoneDamageDataAsset;
		}
		return *this;
	}
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WeaponType)
	ESOWeaponType WeaponType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WeaponDamageDataAsset)
	TObjectPtr<class USOWeaponDamageDataAsset> WeaponBoneDamageDataAsset;
};

USTRUCT(BlueprintType)
struct FSOHitAreaDamageData : public FTableRowBase
{
	GENERATED_BODY()
	
public:
	
	FSOHitAreaDamageData& operator=(const FSOHitAreaDamageData& InOhterDamageData)
	{
		if(this!= &InOhterDamageData)
		{
			ReflectRate = InOhterDamageData.ReflectRate;
		}
		return *this;
	}
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HitAreaDamage)
	float ReflectRate;
};

USTRUCT(BlueprintType)
struct FProjectileData
{
	GENERATED_BODY()
	
public:
	
	FProjectileData& operator=(const FProjectileData& InProjectileData)
	{
		if(this!= &InProjectileData)
		{
			Location = InProjectileData.Location;
			Rotation = InProjectileData.Rotation;
			FiringPawn = InProjectileData.FiringPawn;
			Damage = InProjectileData.Damage;
			WeaponType = InProjectileData.WeaponType;
			DistanceDamageFalloff = InProjectileData.DistanceDamageFalloff;
		}
		return *this;
	}
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ProjectileData)
	FVector Location;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ProjectileData)
	FRotator Rotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ProjectileData)
	APawn* FiringPawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ProjectileData)
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ProjectileData)
	ESOWeaponType WeaponType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ProjectileData)
	FRuntimeFloatCurve DistanceDamageFalloff;
};

USTRUCT(BlueprintType)
struct FSOEquippedPartsInfo
{
	GENERATED_BODY()

public:
	FSOEquippedPartsInfo()
	{
		int32 NumGunParts = static_cast<int32>(ESOGunPartsType::MAX);
		PartsIDArray.SetNum(NumGunParts);
	}
	// 각 파츠 enum 또는 ID?
	UPROPERTY(EditDefaultsOnly)
	TArray<FName> PartsIDArray;
	// 1 0 1 5 0

	/*UPROPERTY(EditDefaultsOnly)
	uint8 MuzzleID;

	UPROPERTY(EditDefaultsOnly)
	uint8 ScopeID;

	UPROPERTY(EditDefaultsOnly)
	uint8 GripID;

	UPROPERTY(EditDefaultsOnly)
	uint8 MagazineID;

	UPROPERTY(EditDefaultsOnly)
	uint8 StockID;*/	
};

USTRUCT(BlueprintType)
struct FSOWeaponStatAug
{
	GENERATED_BODY()
	
public:
	FSOWeaponStatAug& operator=(const FSOWeaponStatAug& InWeaponStatModifier)
	{
		if(this!= &InWeaponStatModifier)
		{
			AccumulatedPitchRecoilReduction = InWeaponStatModifier.AccumulatedPitchRecoilReduction;
			AccumulatedYawRecoilReduction = InWeaponStatModifier.AccumulatedYawRecoilReduction;
			AccumulatedAimingRate = InWeaponStatModifier.AccumulatedAimingRate;
			AccumulatedReloadRate = InWeaponStatModifier.AccumulatedReloadRate;
			AccumulatedHideMuzzleFlash = InWeaponStatModifier.AccumulatedHideMuzzleFlash;
			AccumulatedLensMinFOV = InWeaponStatModifier.AccumulatedLensMinFOV;
			AccumulatedLensMaxFOV = InWeaponStatModifier.AccumulatedLensMaxFOV;
			AccumulatedCanLensAim = InWeaponStatModifier.AccumulatedCanLensAim;
		}
		return *this;
	}

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float AccumulatedPitchRecoilReduction;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)	
	float AccumulatedYawRecoilReduction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float AccumulatedAimingRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float AccumulatedReloadRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float AccumulatedHideMuzzleFlash;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float AccumulatedLensMinFOV;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float AccumulatedLensMaxFOV;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	uint8 AccumulatedCanLensAim;
};
