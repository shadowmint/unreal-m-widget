// Fill out your copyright notice in the Description page of Project Settings.


#include "Fields/MTextBlock.h"
#include "Components/Widget.h"
#include "MUserWidget.h"
#include "Components/TextBlock.h"

UMTextBlock* UMTextBlock::From(UMUserWidget* Parent, UTextBlock** Widget)
{
	const auto Instance = NewObject<UMTextBlock>();
	Instance->Widget = Widget;
	Parent->RegisterWidget(Instance->Initialize(reinterpret_cast<UWidget**>(Widget)));
	return Instance;
}

void UMTextBlock::SetText(FText Text)
{
	Value = Text;
	RedrawRequired();
}

void UMTextBlock::SetText(FString Text)
{
	Value = FText::FromString(Text);
	RedrawRequired();
}

void UMTextBlock::SetColor(const FLinearColor& InColor)
{
	Color = InColor;
	RedrawRequired();
}

void UMTextBlock::CopyTo(UMWidgetField* OtherField)
{
	auto const Other = Cast<UMTextBlock>(OtherField);
	if (!Other) return;
	Other->SetText(Value);
	Other->SetColor(Color);
}

void UMTextBlock::OnRedraw()
{
	UMWidgetField::OnRedraw();
	if (*Widget)
	{
		(*Widget)->SetText(Value);
		(*Widget)->SetColorAndOpacity(FSlateColor(Color));
		Dirty = false;
	}
}
