// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MWidgetField.h"
#include "Blueprint/UserWidget.h"
#include "MUserWidget.generated.h"

/**
 * UMUserWidget is a data synchronization helper for part of a UI.
 * Basically, what you do is you extend UMUserWidget and then in the constructor
 * call RegisterWidget on every property on the widget which has the `BindWidget`
 * meta specifier.
 */
UCLASS()
class MWIDGET_API UMUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	/** Does this widget need to be re-rendered? */
	UPROPERTY(BlueprintReadOnly)
	bool Dirty = true;

	/** The set of managed fields on this widget */
	TArray<TWeakObjectPtr<UMWidgetField>> Fields;

	void RegisterWidget(UMWidgetField *Field);

	/** Mark that something changed on this widget */
	UFUNCTION(BlueprintCallable)
	void SetDirty(bool SomethingChanged);

	/** Apply state to this widget */
	void Redraw();

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
};
