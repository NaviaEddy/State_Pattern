// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Estado.h"
#include "GameFramework/Actor.h"
#include "EstadoSinMonedas.generated.h"

UCLASS()
class STATEPATTERN_API AEstadoSinMonedas : public AActor, public IEstado
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEstadoSinMonedas();

private:
	//La maquina tragamonedas de este estado
	UPROPERTY()
		class AMaquinaTragamonedasDeCasino* SM_MaquinaTragamonedas;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	//Establecer la maquina a este estado
	FORCEINLINE virtual void EstablecerMaquina(class AMaquinaTragamonedasDeCasino* _Maquina) override;

	//Ejecutar la rutina MonedaInsertada
	virtual void InsertarMoneda() override;

	//Ejecutar la rutina RechazarMoneda
	virtual void RechazarMoneda() override;

	//Ejecutar la rutina TirarDeLaPalanca
	virtual void TirarDeLaPalanca() override;

	//Ejecutar la rutina Pago
	virtual void Pago() override;

	//Ejecutar la rutina ReabastecerDolares
	virtual void ReabastecerDolares() override {};

	//Obtener el estado actual
	FORCEINLINE virtual FString ObtenerEstado() override;

};
