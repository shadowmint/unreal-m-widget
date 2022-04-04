// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MUserWidget.h"
#include "Fields/MTextBlock.h"
#include "MWidgetSampleItem.generated.h"


/**
 * 
 */
UCLASS()
class  UMWidgetSampleItem : public UMUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="MWidgetSample|MWidgetSampleItem", meta=(BindWidget))
	UTextBlock* Info = nullptr;

	UPROPERTY()
	UMTextBlock* InfoRef = nullptr;
	
	virtual void PostInitProperties() override;

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

};
