// Fill out your copyright notice in the Description page of Project Settings.


#include "EstadoSinDolares.h"
#include "MaquinaTragamonedasDeCasino.h"

// Sets default values
AEstadoSinDolares::AEstadoSinDolares()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstadoSinDolares::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstadoSinDolares::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstadoSinDolares::EstablecerMaquina(AMaquinaTragamonedasDeCasino* _Maquina)
{
	//Establecer la maquina tragamonedas en este estado
	SD_MaquinaTragamonedas = Cast<AMaquinaTragamonedasDeCasino>(_Maquina);
}

void AEstadoSinDolares::InsertarMoneda()
{
	//Registramos la moneda insertada en una cadena
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("No puede insertar una moneda de casino, la maquina no tiene dolares")));

}

void AEstadoSinDolares::RechazarMoneda()
{
	//Registramos el rechazo de moneda en una cadena
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("No ha introducido una moneda de casino")));
}

void AEstadoSinDolares::TirarDeLaPalanca()
{
	//Registramos el tiro de la palanca en una cadena
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Has girado, pero NO hay dinero en la maquina")));
}

void AEstadoSinDolares::Pago()
{
	//Registramos el pago en una cadena
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("No se pago ningun dinero")));
}

void AEstadoSinDolares::ReabastecerDolares()
{
	//Establecemos el estado en "EstadoSinMonedas"
	SD_MaquinaTragamonedas->EstablecerEstado(SD_MaquinaTragamonedas->M_ObtenerEstadoSinMonedas());
}

FString AEstadoSinDolares::ObtenerEstado()
{
	//Devolvemos la cadena de estado
	return "la maquina no tiene efectivo";
}

