// Fill out your copyright notice in the Description page of Project Settings.


#include "MaquinaTragamonedasDeCasino.h"
#include "EstadoDeDolaresGanados.h"
#include "EstadoDeMonedaInsertada.h"
#include "EstadoSinDolares.h"
#include "EstadoSinMonedas.h"

// Sets default values
AMaquinaTragamonedasDeCasino::AMaquinaTragamonedasDeCasino()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMaquinaTragamonedasDeCasino::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMaquinaTragamonedasDeCasino::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMaquinaTragamonedasDeCasino::InicializarMaquina(int _NumeroDeDolares)
{
	//Engendra el EstadoSinDolares y establece la maquina Tragamonedas en el.
	EstadoSinDolares = GetWorld()->SpawnActor<AEstadoSinDolares>(AEstadoSinDolares::StaticClass());
	EstadoSinDolares->EstablecerMaquina(this);

	//Engendra el EstadoSinMonedas y establece la maquina Tragamonedas en el.
	EstadoSinMonedas = GetWorld()->SpawnActor<AEstadoSinMonedas>(AEstadoSinMonedas::StaticClass());
	EstadoSinMonedas->EstablecerMaquina(this);

	//Engendra el EstadoDeMonedaInsertada y establece la maquina Tragamonedas en el.
	EstadoDeMonedaInsertada = GetWorld()->SpawnActor<AEstadoDeMonedaInsertada>(AEstadoDeMonedaInsertada::StaticClass());
	EstadoDeMonedaInsertada->EstablecerMaquina(this);

	//Engendra el EstadoDeDolaresGanados y establece la maquina Tragamonedas en el.
	EstadoDeDolaresGanados = GetWorld()->SpawnActor<AEstadoDeDolaresGanados>(AEstadoDeDolaresGanados::StaticClass());
	EstadoDeDolaresGanados->EstablecerMaquina(this);

	//Establecemos la cantidad de dolares
	CantidadDeDolares = _NumeroDeDolares;

	//Si es mayor que 0, establece el estado actual en EstadoSinMonedas.
	if (_NumeroDeDolares > 0) {
		Estado = EstadoSinMonedas;
	}
	else {
		//Si es menor que 0, establece el estado actual en EstadoSinDolares.
		Estado = EstadoSinDolares;
	}

}

void AMaquinaTragamonedasDeCasino::EstablecerEstado(IEstado* _Estado)
{
	//Establece el estadp actual con el estado pasado
	Estado = _Estado;
}

void AMaquinaTragamonedasDeCasino::M_InsertarMoneda()
{
	//Ejecutar la rutina InsertarMoneda en funcion del estado actual
	Estado->InsertarMoneda();
}

void AMaquinaTragamonedasDeCasino::M_RechazarMoneda()
{
	//Ejecutar la rutina RechazarMoneda en funcion del estado actual
	Estado->RechazarMoneda();
}

void AMaquinaTragamonedasDeCasino::M_TirarDeLaPalanca()
{
	//Ejecutar la rutina TirarDeLaPalanca y Pago en funcion del estado actual
	Estado->TirarDeLaPalanca();
	Estado->Pago();
}

void AMaquinaTragamonedasDeCasino::M_EmitirDolares()
{
	//¡Has ganado!
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("¡Haz que llueva!")));

	//Si la maquina tragamonedas todavia tiene algunos dolares, disminuyelos en un 50
	if (CantidadDeDolares != 0) {
		CantidadDeDolares -= 50;
	}
}

void AMaquinaTragamonedasDeCasino::M_RestablecerDolares(int _Cantidad)
{
	//Sume el recuento pasado al importe en dolares y registrelo
	CantidadDeDolares += _Cantidad;
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("La maquina tragamonedas se acaba de llenar y su nueva cuenta de dolares es: %i"), CantidadDeDolares));

	//A continuacion, ejecute la rutina Reabastecer dolares en funcion del estado actual
	Estado->ReabastecerDolares();
}

IEstado* AMaquinaTragamonedasDeCasino::M_ObtenerEstado()
{
	//Devuelve el estado actual
	return Estado;
}

IEstado* AMaquinaTragamonedasDeCasino::M_ObtenerEstadoSinDolares()
{
	//Devuelve el EstadoSinDolares
	return EstadoSinDolares;
}

IEstado* AMaquinaTragamonedasDeCasino::M_ObtenerEstadoSinMonedas()
{
	//Devuelve el EstadoSinMonedas
	return EstadoSinMonedas;
}

IEstado* AMaquinaTragamonedasDeCasino::M_ObtenerEstadoDeDolaresGanados()
{
	//Devuelve el EstadoDeDolaresGanados
	return EstadoDeDolaresGanados;
}

IEstado* AMaquinaTragamonedasDeCasino::M_ObtenerEstadoDeMonedaInsertada()
{
	//Devuelve el EstadoDeMonedaInsertada
	return EstadoDeMonedaInsertada;
}

FString AMaquinaTragamonedasDeCasino::M_ObtenerEstadoActual()
{
	//Devuelve el EstadoActual
	return "El estado actual de la maquina tragamonedas es: " + Estado->ObtenerEstado();
}

int AMaquinaTragamonedasDeCasino::M_ObtenerCantidad()
{
	//Devuelve la cantidad de dolares
	return CantidadDeDolares;
}

