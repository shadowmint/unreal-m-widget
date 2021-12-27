// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MWidgetField.h"
#include "Components/TextBlock.h"
#include "MTextBlock.generated.h"

/**
 * 
 */
UCLASS()
class MWIDGET_API UMTextBlock : public UMWidgetField
{
	GENERATED_BODY()

	/** The internal data object */
	UTextBlock** Widget;

	FText Value;
	
public:
	static UMTextBlock* From(FName Name, UMUserWidget* Parent, UTextBlock** Widget);

	void SetText(FText Text);

	void SetText(FString Text);
	
protected:
	virtual void OnRedraw() override;
};
