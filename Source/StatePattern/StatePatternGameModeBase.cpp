// Copyright Epic Games, Inc. All Rights Reserved.


#include "StatePatternGameModeBase.h"
#include "MaquinaTragamonedasDeCasino.h"

AStatePatternGameModeBase::AStatePatternGameModeBase()
{
	// Set this actor to call Tick() every frame.You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AStatePatternGameModeBase::BeginPlay()
{
	Super::BeginPlay();

    //Crea la maquina tragamonedas y fija su importe en 100 dolares.
    AMaquinaTragamonedasDeCasino* MaquinaDeCasino = GetWorld()->SpawnActor<AMaquinaTragamonedasDeCasino>(AMaquinaTragamonedasDeCasino::StaticClass());
    MaquinaDeCasino->InicializarMaquina(100);

    //Registrar el estado actual de la maquina tragamonedas
    GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%s"), *MaquinaDeCasino->M_ObtenerEstadoActual()));

    //Inserta la moneda y baja la palanca
    MaquinaDeCasino->M_InsertarMoneda();
    MaquinaDeCasino->M_TirarDeLaPalanca();

    //Registrar el estado actual de la maquina tragamonedas
    GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%s"), *MaquinaDeCasino->M_ObtenerEstadoActual()));

    //Inserta la moneda, tira de la palanca y vuelve a insertar la moneda
    MaquinaDeCasino->M_InsertarMoneda();
    MaquinaDeCasino->M_TirarDeLaPalanca();
    MaquinaDeCasino->M_InsertarMoneda();

    //Registrar el estado actual de la maquina tragamonedas
    GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%s"), *MaquinaDeCasino->M_ObtenerEstadoActual()));

    //Tira de la palanca
    MaquinaDeCasino->M_TirarDeLaPalanca();

    //Adiciona 100 dolares
    MaquinaDeCasino->M_RestablecerDolares(100);

    //Inserta una moneda y tira de la palanca
    MaquinaDeCasino->M_InsertarMoneda();
    MaquinaDeCasino->M_TirarDeLaPalanca();

    //Registrar el estado actual de la maquina tragamonedas
    GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%s"), *MaquinaDeCasino->M_ObtenerEstadoActual()));

}

void AStatePatternGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
