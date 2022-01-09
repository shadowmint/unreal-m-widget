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
UCLASS(BlueprintType)
class MWIDGET_API UMImage : public UMWidgetField
{
	GENERATED_BODY()

	/** The internal data object */
	UImage** Widget;
	
	FColor BrushTint;

	UPROPERTY()
	UTexture2D *BrushTexture;

public:
	static UMImage* From(UMUserWidget* Parent, UImage** Widget);

	void SetBrushTint(const FColor& InBrushTint);

	void SetBrushTexture(UTexture2D *InBrushTexture);

	virtual void CopyTo(UMWidgetField* OtherField) override;
	
protected:
	virtual void OnRedraw() override;
};
