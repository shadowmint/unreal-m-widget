// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MUserWidget.h"
#include "MWidgetField.h"
#include "Components/ProgressBar.h"
#include "MProgressBar.generated.h"

UCLASS()
class MWIDGET_API UMProgressBar : public UMWidgetField
{
	GENERATED_BODY()

	/** The internal data object */
	UProgressBar** Widget;

	float Value;

public:
	static UMProgressBar* From(FName Name, UMUserWidget* Parent, UProgressBar** Widget);

	void SetValue(float NextValue);

	virtual void CopyTo(UMWidgetField* OtherField) override;
	
protected:
	virtual void OnRedraw() override;
};
