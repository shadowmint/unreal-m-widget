// Fill out your copyright notice in the Description page of Project Settings.

#include "MWidgetField.h"

#include "MUserWidget.h"

void UMWidgetField::OnMaterialized()
{
}

void UMWidgetField::OnDematerialized()
{
}

void UMWidgetField::OnRedraw()
{
}

void UMWidgetField::CopyTo(UMWidgetField* OtherField)
{
	UE_LOG(LogTemp, Warning, TEXT("UMWidgetField::CopyTo not implemented for this widget field"));
}

UMWidgetField* UMWidgetField::Initialize(UWidget** RawComponent)
{
	IsMaterialized = false;
	Component = RawComponent;
	Dirty = true;
	return this;
}

void UMWidgetField::RedrawRequired()
{
	if (Parent.IsValid())
	{
		Parent->SetDirty(true);
	}
	Dirty = true;
}

void UMWidgetField::Redraw()
{
	const auto CurrentlyMaterialized = Component && *Component;
	if (CurrentlyMaterialized != IsMaterialized)
	{
		if (CurrentlyMaterialized)
		{
			IsMaterialized = true;
			OnMaterialized();
		}
		else
		{
			IsMaterialized = false;
			OnDematerialized();
		}
	}
	if (IsMaterialized)
	{
		OnRedraw();
	}
}
