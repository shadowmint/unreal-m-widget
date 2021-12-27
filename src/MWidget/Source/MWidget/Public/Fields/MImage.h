// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MWidgetField.h"
#include "UObject/Object.h"
#include "MImage.generated.h"

class UMUserWidget;
class UImage;
/**
 * 
 */
UCLASS()
class MWIDGET_API UMImage : public UMWidgetField
{
	GENERATED_BODY()

	/** The internal data object */
	UImage** Widget;

public:
	static UMImage* From(FName Name, UMUserWidget* Parent, UImage** Widget);
		
protected:
	virtual void OnRedraw() override;
};
