// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Components/Widget.h"
#include "MWidgetField.generated.h"

class UMUserWidget;

/** Base type for all field widget wrappers */
UCLASS()
class MWIDGET_API UMWidgetField : public UObject
{
	GENERATED_BODY()

protected:
	UWidget** Component;

	bool IsMaterialized;

	/** Implement this event to sync when the instance becomes materialized */
	virtual void OnMaterialized();

	/**
	 * Implement this event to sync when the instance is removed.
	 * OnDematerialized is only invoked if OnMaterialized has previously been invoked.
	 */
	virtual void OnDematerialized();

	/** Implement this to sync the state to the widget instance */
	virtual void OnRedraw();

	virtual UMWidgetField* Initialize(UWidget** RawComponent);

	/** Call this if a virtual value is changed */
	void RedrawRequired();

public:
	/** Are there pending changes for this widget? */
	bool Dirty;
	
	/** This object's parent */
	TWeakObjectPtr<UMUserWidget> Parent;

	void Redraw();

	/** Implement this to copy to another field of the same type */
	virtual void CopyTo(UMWidgetField *OtherField);
};
