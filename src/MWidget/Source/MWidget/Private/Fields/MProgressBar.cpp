// Fill out your copyright notice in the Description page of Project Settings.


#include "Fields/MProgressBar.h"

UMProgressBar* UMProgressBar::From(UMUserWidget* Parent, UProgressBar** Widget)
{
	const auto Instance = NewObject<UMProgressBar>();
	Instance->Widget = Widget;
	Parent->RegisterWidget(Instance->Initialize(reinterpret_cast<UWidget**>(Widget)));
	return Instance;
}

void UMProgressBar::OnRedraw()
{
	UMWidgetField::OnRedraw();
	if (*Widget)
	{
		(*Widget)->SetPercent(Value);
		Dirty = false;
	}
}

void UMProgressBar::SetValue(float NextValue)
{
	if (Value == NextValue) return;
	Value = NextValue;
	RedrawRequired();
}

void UMProgressBar::CopyTo(UMWidgetField* OtherField)
{
	auto const Other = Cast<UMProgressBar>(OtherField);
	if (!Other) return;
	Other->SetValue(Value);
}
