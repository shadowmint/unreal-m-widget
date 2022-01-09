// Fill out your copyright notice in the Description page of Project Settings.


#include "MWidgetSampleItem.h"

#include "Fields/MTextBlock.h"

void UMWidgetSampleItem::PostInitProperties()
{
	Super::PostInitProperties();

	// Setup widgets
	InfoRef = UMTextBlock::From(this, &Info);
}

void UMWidgetSampleItem::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	InfoRef->SetText(FString::Printf(TEXT("-- %f"), InDeltaTime));
}
