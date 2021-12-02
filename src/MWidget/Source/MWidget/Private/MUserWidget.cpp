// Fill out your copyright notice in the Description page of Project Settings.


#include "MUserWidget.h"

void UMUserWidget::RegisterWidget(UMWidgetField* Field)
{
	if (!Field)
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid attempt to bind a null field in UMUserWidget::RegisterWidget"));
		return;
	}
	if (!Fields.Contains(Field))
	{
		Field->Parent = TWeakObjectPtr<UMUserWidget>(this);
		Fields.Add(TWeakObjectPtr<UMWidgetField>(Field));
		Dirty = true;
	}
}

void UMUserWidget::SetDirty(const bool SomethingChanged)
{
	Dirty = SomethingChanged;
}

void UMUserWidget::Redraw()
{
	auto StillDirty = false;
	for (const auto &Field : Fields)
	{
		if (!Field.IsValid()) continue;
		if (Field->Dirty)
		{
			Field->Redraw();
			StillDirty = StillDirty | Field->Dirty;
		}
	}
	Dirty = StillDirty;
}

void UMUserWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	if (!Dirty) return;
	auto Offset = 0;
	Redraw();
}
