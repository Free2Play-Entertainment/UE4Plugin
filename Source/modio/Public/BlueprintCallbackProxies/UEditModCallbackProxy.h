// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Customizables/FModioModEditor.h"
#include "ModioUE4Plugin.h"
#include "Enums/EModioMaturityOption.h"
#include "Schemas/FModioResponse.h"
#include "Schemas/FModioMod.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "UEditModCallbackProxy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FEditModResult,
    FModioResponse,
    Response,
    FModioMod,
    Mod);

UCLASS()
class MODIO_API UEditModCallbackProxy : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  FModioModEditor ModEditor;
  int32 ModId;

  UPROPERTY(BlueprintAssignable)
  FEditModResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FEditModResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true"))
  static UEditModCallbackProxy *EditMod(int32 ModId, FModioModEditor ModEditor);

  virtual void Activate() override;

  virtual void OnEditModDelegate(FModioResponse Response, FModioMod Mod);
};