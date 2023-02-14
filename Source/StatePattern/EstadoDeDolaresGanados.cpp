// Fill out your copyright notice in the Description page of Project Settings.


#include "EstadoDeDolaresGanados.h"
#include "MaquinaTragamonedasDeCasino.h"

// Sets default values
AEstadoDeDolaresGanados::AEstadoDeDolaresGanados()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstadoDeDolaresGanados::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstadoDeDolaresGanados::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstadoDeDolaresGanados::EstablecerMaquina(AMaquinaTragamonedasDeCasino* _Maquina)
{
	//Establecer la maquina tragamonedas en este estado
	DG_MaquinaTragamonedas = _Maquina;
}

void AEstadoDeDolaresGanados::InsertarMoneda()
{
	//Registramos la moneda insertada en una cadena
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Por favor espere, la maquina esta dispensando dolares")));
}

void AEstadoDeDolaresGanados::RechazarMoneda()
{
	//Registramos el rechazo de la moneda en una cadena
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Tranquilo, ya has tirado de la palanca")));
}

void AEstadoDeDolaresGanados::TirarDeLaPalanca()
{
	//Registramos el tiro de la palanca en una cadena
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("No tire de la palanca dos veces!")));
}

void AEstadoDeDolaresGanados::Pago()
{
	//Hora de pagar! Emitir los dolares de la maquina tragamonedas
	DG_MaquinaTragamonedas->M_EmitirDolares();

	if (DG_MaquinaTragamonedas->M_ObtenerCantidad() > 0) {
		//Si la maquina tragamonedas aun tiene dolares, establece su estado en "EstadoSinMonedas"
		DG_MaquinaTragamonedas->EstablecerEstado(DG_MaquinaTragamonedas->M_ObtenerEstadoSinMonedas());
	}
	else {
		//Si a la Maquina tragamonedas no le quedan dolares, registrelo y establezca su estado a "EstadoSinDolares"
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("La maquina ya no tiene dinero")));
		DG_MaquinaTragamonedas->EstablecerEstado(DG_MaquinaTragamonedas->M_ObtenerEstadoSinDolares());
	}
}

FString AEstadoDeDolaresGanados::ObtenerEstado()
{
	//Devolvemos la cadena de estado
	return "dispensacion de efectivo";
}

