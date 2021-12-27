// Fill out your copyright notice in the Description page of Project Settings.


#include "Fields/MImage.h"
#include "Components/Widget.h"
#include "MUserWidget.h"

UMImage* UMImage::From(FName Name, UMUserWidget* Parent, UImage** Widget)
{
	const auto Instance = NewObject<UMImage>(Parent, Name);
	Instance->Widget = Widget;
	Parent->RegisterWidget(Instance->Initialize(reinterpret_cast<UWidget**>(Widget)));
	return Instance;
}

void UMImage::OnRedraw()
{
	UMWidgetField::OnRedraw();
	if (*Widget)
	{
		Dirty = false;
	}
}