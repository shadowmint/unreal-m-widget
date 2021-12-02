// Fill out your copyright notice in the Description page of Project Settings.


#include "Fields/MProgressBar.h"

UMProgressBar* UMProgressBar::From(FName Name, UMUserWidget* Parent, UProgressBar** Widget)
{
	const auto Instance = NewObject<UMProgressBar>(Parent, Name);
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

inline void UMProgressBar::SetValue(float NextValue)
{
	Value = NextValue;
	RedrawRequired();
}