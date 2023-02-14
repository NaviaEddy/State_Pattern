// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Estado.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEstado : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class STATEPATTERN_API IEstado
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	//Las funciones virtuales puras del Estado
	virtual void EstablecerMaquina(class AMaquinaTragamonedasDeCasino* _Maquina) = 0;
	virtual void InsertarMoneda() = 0;
	virtual void RechazarMoneda() = 0;
	virtual void TirarDeLaPalanca() = 0;
	virtual void Pago() = 0;
	virtual void ReabastecerDolares() = 0;
	virtual FString ObtenerEstado() = 0;
};
