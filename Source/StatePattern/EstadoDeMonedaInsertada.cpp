// Fill out your copyright notice in the Description page of Project Settings.


#include "EstadoDeMonedaInsertada.h"
#include "MaquinaTragamonedasDeCasino.h"

// Sets default values
AEstadoDeMonedaInsertada::AEstadoDeMonedaInsertada()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstadoDeMonedaInsertada::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstadoDeMonedaInsertada::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstadoDeMonedaInsertada::EstablecerMaquina(AMaquinaTragamonedasDeCasino* _Maquina)
{
	//Establecer la maquina tragamonedas en este estado
	MI_MaquinaTragamonedas = Cast<AMaquinaTragamonedasDeCasino>(_Maquina);
}

void AEstadoDeMonedaInsertada::InsertarMoneda()
{
	//Registramos la moneda insertada en una cadena
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("No puedes insertar otra moneda de casino")));
}

void AEstadoDeMonedaInsertada::RechazarMoneda()
{
	//Registramos el rechazo de moneda en una cadena y establecemos el estado en "EstadoSinMonedas"
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Moneda de casino rechazada")));
	MI_MaquinaTragamonedas->EstablecerEstado(MI_MaquinaTragamonedas->M_ObtenerEstadoSinMonedas());
}

void AEstadoDeMonedaInsertada::TirarDeLaPalanca()
{
	//Registramos el tiro de la palanca en una cadena y establecemos el estado en "EstadoDeDolaresGanados"
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Tiraste de la palanca...")));
	MI_MaquinaTragamonedas->EstablecerEstado(MI_MaquinaTragamonedas->M_ObtenerEstadoDeDolaresGanados());
}

void AEstadoDeMonedaInsertada::Pago()
{
	//Registramos el pago en una cadena
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Sin dolares dispensados")));
}

FString AEstadoDeMonedaInsertada::ObtenerEstado()
{
	//Devolvemos la cadena de estado
	return "a la espera de tirar de la palanca";
}

