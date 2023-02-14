// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Estado.h"
#include "GameFramework/Actor.h"
#include "MaquinaTragamonedasDeCasino.generated.h"

UCLASS()
class STATEPATTERN_API AMaquinaTragamonedasDeCasino : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMaquinaTragamonedasDeCasino();

private:
	//El EstadoSinDolares de esta maquina tragamonedas
	IEstado* EstadoSinDolares;

	//El EstadoSinMonedas de esta maquina tragamonedas
	IEstado* EstadoSinMonedas;
	
	//El EstadoDeMonedaInsertada de esta maquina tragamonedas
	IEstado* EstadoDeMonedaInsertada;

	//El EstadoDeDolaresGanados de esta maquina tragamonedas
	IEstado* EstadoDeDolaresGanados;

	//El Estado de esta maquina tragamonedas
	IEstado* Estado;

	//La cantidad de dolares de esta maquina tragamonedas
	int CantidadDeDolares = 0;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	//Inicializar la maquina tragamonedas;
	void InicializarMaquina(int _NumeroDeDolares);

	//Establecer el estado de la maquina con el estado pasado
	FORCEINLINE void EstablecerEstado(IEstado* _Estado);

	//Insertar moneda
	void M_InsertarMoneda();

	//Rechazar moneda
	void M_RechazarMoneda();

	//Tirar de la palanca
	void M_TirarDeLaPalanca();

	//Emitir los dolares de la maquina tragamonedas
	void M_EmitirDolares();

	//Restablecer los dolares de la maquina con la cantidad pasada
	void M_RestablecerDolares(int _Cantidad);

	//Obtener Estado de la maquina tragamonedas
	FORCEINLINE IEstado* M_ObtenerEstado();

	//Obtener el EstadoSinDolares de la maquina tragamonedas
	FORCEINLINE IEstado* M_ObtenerEstadoSinDolares();

	//Obtener el EstadoSinMonedas de la maquina tragamonedas
	FORCEINLINE IEstado* M_ObtenerEstadoSinMonedas();

	//Obtener el EstadoDeDolaresGanados de la maquina tragamonedas
	FORCEINLINE IEstado* M_ObtenerEstadoDeDolaresGanados();

	//Obtener el EstadoDeMonedaInsertada de la maquina tragamonedas
	FORCEINLINE IEstado* M_ObtenerEstadoDeMonedaInsertada();

	//Obtener el EstadoActual de la maquina tragamonedas
	FORCEINLINE FString M_ObtenerEstadoActual();

	//Obtener la CantidadDeDolares de la maquina tragamonedas
	FORCEINLINE int M_ObtenerCantidad();


};
