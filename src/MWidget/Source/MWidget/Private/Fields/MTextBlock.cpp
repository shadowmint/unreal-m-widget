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
	if (Value.EqualTo(Text)) return;
	Value = Text;
	RedrawRequired();
}

void UMTextBlock::SetText(FString Text)
{
	if (Value.EqualTo(FText::FromString(Text))) return;
	Value = FText::FromString(Text);
	RedrawRequired();
}

void UMTextBlock::SetColor(const FLinearColor& InColor)
{
	if (Color == InColor) return;
	Color = InColor;
	RedrawRequired();
}

void UMTextBlock::CopyTo(UMWidgetField* OtherField)
{
	auto const Other = Cast<UMTextBlock>(OtherField);
	if (!Other) return;
	Other->SetText(Value);
	if (Color)
	{
		Other->SetColor(*Color);	
	}
}

void UMTextBlock::OnRedraw()
{
	UMWidgetField::OnRedraw();
	if (*Widget)
	{
		(*Widget)->SetText(Value);
		if (Color)
		{
			(*Widget)->SetColorAndOpacity(FSlateColor(*Color));	
		}
		Dirty = false;
	}
}
