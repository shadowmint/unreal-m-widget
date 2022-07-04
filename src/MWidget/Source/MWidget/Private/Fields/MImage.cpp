// Fill out your copyright notice in the Description page of Project Settings.


#include "Fields/MImage.h"
#include "Components/Widget.h"
#include "MUserWidget.h"
#include "Components/Image.h"

UMImage* UMImage::From(UMUserWidget* Parent, UImage** Widget)
{
	const auto Instance = NewObject<UMImage>();
	Instance->Widget = Widget;
	Parent->RegisterWidget(Instance->Initialize(reinterpret_cast<UWidget**>(Widget)));

	// Default to white so the image doesn't vanish
	Instance->BrushTint = FColor(255, 255, 255, 255);
	
	return Instance;
}

void UMImage::SetBrushTint(const FColor& Color)
{
	if (BrushTint == Color) return; 
	BrushTint = Color;
	RedrawRequired();
}

void UMImage::SetBrushTexture(UTexture2D* InBrushTexture)
{
	if (BrushTexture == InBrushTexture) return; 
	BrushTexture = InBrushTexture;
	RedrawRequired();
}

void UMImage::CopyTo(UMWidgetField* OtherField)
{
	auto const Other = Cast<UMImage>(OtherField);
	if (!Other) return;
	Other->SetBrushTexture(BrushTexture);
	Other->SetBrushTint(BrushTint);
	UE_LOG(LogTemp, Display, TEXT("Copy texture!"));
	Other->Redraw();
}

void UMImage::OnRedraw()
{
	UMWidgetField::OnRedraw();
	if (*Widget)
	{
		(*Widget)->SetBrushFromTexture(BrushTexture);
		(*Widget)->SetBrushTintColor(FSlateColor(BrushTint));
		Dirty = false;
	}
}
