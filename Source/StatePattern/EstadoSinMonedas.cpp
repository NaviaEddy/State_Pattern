// Fill out your copyright notice in the Description page of Project Settings.


#include "EstadoSinMonedas.h"
#include "MaquinaTragamonedasDeCasino.h"

// Sets default values
AEstadoSinMonedas::AEstadoSinMonedas()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstadoSinMonedas::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstadoSinMonedas::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstadoSinMonedas::EstablecerMaquina(AMaquinaTragamonedasDeCasino* _Maquina)
{
	//Establecer la maquina tragamonedas en este estado
	SM_MaquinaTragamonedas = Cast<AMaquinaTragamonedasDeCasino>(_Maquina);
}

void AEstadoSinMonedas::InsertarMoneda()
{
	//Registramos la moneda insertada en una cadena y establecemos el estado en "EstadoDeMonedaInsertada"
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Insertaste una moneda de casino")));
	SM_MaquinaTragamonedas->EstablecerEstado(SM_MaquinaTragamonedas->M_ObtenerEstadoDeMonedaInsertada());
}

void AEstadoSinMonedas::RechazarMoneda()
{
	//Registamos el rechazo de moneda en una cadena
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("No has introducido una moneda de casino")));
}

void AEstadoSinMonedas::TirarDeLaPalanca()
{
	//Registramos el tiro de la palanca en una cadena
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Giraste, pero no hay moneda de casino")));
}

void AEstadoSinMonedas::Pago()
{
	//Registramos el pago en una cadena
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Primero hay que introducir una moneda de casino")));
}

FString AEstadoSinMonedas::ObtenerEstado()
{
	//Devolvemos la cadena de estado
	return "esperando una moneda del casino";
}

