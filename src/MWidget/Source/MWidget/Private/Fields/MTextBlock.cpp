// Fill out your copyright notice in the Description page of Project Settings.


#include "Fields/MTextBlock.h"
#include "Components/Widget.h"
#include "MUserWidget.h"
#include "Components/TextBlock.h"

UMTextBlock* UMTextBlock::From(FName Name, UMUserWidget* Parent, UTextBlock** Widget)
{
	const auto Instance = NewObject<UMTextBlock>(Parent, Name);
	Instance->Widget = Widget;
	Parent->RegisterWidget(Instance->Initialize(reinterpret_cast<UWidget**>(Widget)));
	return Instance;
}

void UMTextBlock::SetText(FText Text)
{
	Value = Text;
}

void UMTextBlock::SetText(FString Text)
{
	Value = FText::FromString(Text);
}

void UMTextBlock::OnRedraw()
{
	UMWidgetField::OnRedraw();
	if (*Widget)
	{
		(*Widget)->SetText(Value);
		Dirty = false;
	}
}
