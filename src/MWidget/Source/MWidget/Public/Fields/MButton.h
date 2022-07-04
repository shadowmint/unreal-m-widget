// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MUserWidget.h"
#include "MWidgetField.h"
#include "Components/Button.h"
#include "MButton.generated.h"

UCLASS()
class MWIDGET_API UMButton : public UMWidgetField
{
	GENERATED_BODY()
	
	/** The internal data object */
	UButton** Widget;

public:
	static UMButton* From(UMUserWidget* Parent, UButton** Widget);

	FOnButtonClickedEvent OnClicked;
	FOnButtonPressedEvent OnPressed;
	FOnButtonReleasedEvent OnReleased;
	FOnButtonHoverEvent OnHovered;
	FOnButtonHoverEvent OnUnhovered;
	
	UFUNCTION()
	void OnClickHandler();

	UFUNCTION()
	void OnPressedHandler();

	UFUNCTION()
	void OnReleasedHandler();
	
	UFUNCTION()
	void OnHoveredHandler();

	UFUNCTION()
	void OnUnhoveredHandler();
	
protected:
	virtual void OnRedraw() override;

	virtual void OnMaterialized() override;
};
