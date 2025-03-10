// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Judge.generated.h"

/**
 * 
 */
UCLASS()
class CHAPT2_API UJudge : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
    // 1~9까지 중복 없는 랜덤 3자리 숫자 배열 생성
    UFUNCTION(BlueprintCallable, Category = "Judge")
    static TArray<int32> GenerateRandomNumbers();

    // 사용자 입력과 목표 숫자 비교하여 결과 반환
    UFUNCTION(BlueprintCallable, Category = "Judge")
    static void JudgeNumbers(const TArray<int32>& TargetNumbers, const TArray<int32>& UserNumbers,
        int32& StrikeCount, int32& BallCount, int32& OutCount);

    // 사용자 입력값 배열로 변환
    UFUNCTION(BlueprintCallable, Category = "Judge")
    static TArray<int32> StringToNumberArray(const FString& InputString);

    // 사용자 입력 검증
    UFUNCTION(BlueprintCallable, Category = "Judge")
    static bool IsValidUserInput(const TArray<int32>& UserNumbers);
};
