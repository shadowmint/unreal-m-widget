// Fill out your copyright notice in the Description page of Project Settings.


#include "Fields/MButton.h"

UMButton* UMButton::From(FName Name, UMUserWidget* Parent, UButton** Widget)
{
	const auto Instance = NewObject<UMButton>();
	Instance->Widget = Widget;
	Parent->RegisterWidget(Instance->Initialize(reinterpret_cast<UWidget**>(Widget)));
	return Instance;
}

void UMButton::OnRedraw()
{
	UMWidgetField::OnRedraw();
	if (*Widget)
	{
		Dirty = false;
	}
}

void UMButton::OnMaterialized()
{
	UMWidgetField::OnMaterialized();
	(*Widget)->OnClicked.AddDynamic(this, &UMButton::OnClickHandler);
	(*Widget)->OnPressed.AddDynamic(this, &UMButton::OnPressedHandler);
	(*Widget)->OnReleased.AddDynamic(this, &UMButton::OnReleasedHandler);
	(*Widget)->OnHovered.AddDynamic(this, &UMButton::OnHoveredHandler);
	(*Widget)->OnUnhovered.AddDynamic(this, &UMButton::OnUnhoveredHandler);
}

void UMButton::OnClickHandler()
{
	if (!IsMaterialized) return;
	OnClicked.Broadcast();
}


void UMButton::OnPressedHandler()
{
	if (!IsMaterialized) return;
	OnPressed.Broadcast();
}

void UMButton::OnReleasedHandler()
{
	if (!IsMaterialized) return;
	OnReleased.Broadcast();
}

void UMButton::OnHoveredHandler()
{
	if (!IsMaterialized) return;
	OnHovered.Broadcast();
}

void UMButton::OnUnhoveredHandler()
{
	if (!IsMaterialized) return;
	OnUnhovered.Broadcast();
}
