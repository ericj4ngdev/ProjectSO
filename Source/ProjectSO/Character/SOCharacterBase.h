// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/ALSCharacter.h"
#include "ProjectSO/Interface/SOCharacterWidgetInterface.h"
#include "ProjectSO/Weapon/SOGunBase.h"
#include "ProjectSO/Interface/SOEquippableInterface.h"
#include "ProjectSO/Interface/SOInteractableInterface.h"
#include "SOCharacterBase.generated.h"

class ASOHUD;
class USOInventoryComponent;
class USOStatComponent;
/**
 * 
 */

USTRUCT()
struct FInteractionData
{
	GENERATED_USTRUCT_BODY()

	FInteractionData() :
		CurrentInteractable(nullptr),
		LastInteractionCheckTime(0.0f)
	{
	};

	UPROPERTY()
	TObjectPtr<AActor> CurrentInteractable;

	UPROPERTY()
	float LastInteractionCheckTime;
};


UCLASS()
class PROJECTSO_API ASOCharacterBase : public AALSCharacter, public ISOCharacterWidgetInterface
{
	GENERATED_BODY()

public:
	ASOCharacterBase(const FObjectInitializer& ObjectInitializer);

	virtual void PostInitializeComponents() override;
protected:
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;
	
public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	// 나중에 장착 가능한 것들만 모아서 하기
	void EquipItem(ASOItemActor* InEquipment);

	/** Input */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "SO|Input")
	void AttackAction(bool bValue);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "SO|Input")
	void ChangeFireModeAction(bool bValue);

	UFUNCTION(BlueprintCallable, Category = "SO|Input")
	void AimAction_(bool bValue);

	UFUNCTION(BlueprintCallable, Category = "SO|Input")
	void ReloadAction(bool bValue);

	UFUNCTION(BlueprintCallable, Category = "SO|Input")
	void BeginInteract(bool bValue);

	UFUNCTION(BlueprintCallable, Category = "SO|Input")
	void ZoomInOutAction(float value);
	
	void UpdateCharacterMinigunMovement();

public:
	UFUNCTION(NetMulticast, Unreliable)
	void MulticastRPCEquipItem(ASOItemActor* Weapon);

public:
	FORCEINLINE USOStatComponent* GetHealth() const { return StatComponent; }
	FORCEINLINE USOInventoryComponent* GetInventory() const { return InventoryComponent; }
	
	// Health
protected:
	//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS|Component")
	//	TObjectPtr<USkeletalMeshComponent> SkeletalMesh = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SO|MeshComponent")
	TObjectPtr<USkeletalMeshComponent> CharacterMesh;
	
protected:
	UFUNCTION()
	void ReceiveDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, class AController* InstigatorController, AActor* DamageCauser);
	
	virtual void SetDead();
	
	UFUNCTION()
	virtual void SetUpHUD(ASOHUD* InHUD) override;
	UFUNCTION(BlueprintCallable)
	virtual void SetUpUserWidget(USOUserWidget* InWidget) override;
public:
	//Apply Recoil 
	void ApplyRecoil(const float InYawRecoil, const float InPitchRecil);
	FName GetHitParentBone(const FName& InBoneString);
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category = "SO|Equip")
	TObjectPtr<ASOGunBase> CurrentWeapon;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category = "SO|Health")
	TObjectPtr<USOStatComponent> StatComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category = "SO|Inventory")
	TObjectPtr<USOInventoryComponent> InventoryComponent;

	
	// Interact
	FORCEINLINE bool IsInteracting() const { return GetWorldTimerManager().IsTimerActive(TimerHandle_Interaction); };
	
	UPROPERTY(VisibleAnywhere, Category = "SO| Interactable")
	TScriptInterface<ISOInteractableInterface> TargetInteractable;
public:
	UFUNCTION()
	void InteractionCheck(AActor* MyActor);

	UFUNCTION()
	void NoInteractableFound();
	
protected:
	UFUNCTION()
	void InteractWithObject();
	
	UFUNCTION()
	void EndInteract();
	
	UFUNCTION()
	void FoundInteractable(AActor* NewInteractable);

	UFUNCTION(Server, Unreliable)
	void ServerRPCInteract();
	
	FTimerHandle TimerHandle_Interaction;
	FInteractionData InteractionData;
};
