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
    // 1~9���� �ߺ� ���� ���� 3�ڸ� ���� �迭 ����
    UFUNCTION(BlueprintCallable, Category = "Judge")
    static TArray<int32> GenerateRandomNumbers();

    // ����� �Է°� ��ǥ ���� ���Ͽ� ��� ��ȯ
    UFUNCTION(BlueprintCallable, Category = "Judge")
    static void JudgeNumbers(const TArray<int32>& TargetNumbers, const TArray<int32>& UserNumbers,
        int32& StrikeCount, int32& BallCount, int32& OutCount);

    // ����� �Է°� �迭�� ��ȯ
    UFUNCTION(BlueprintCallable, Category = "Judge")
    static TArray<int32> StringToNumberArray(const FString& InputString);

    // ����� �Է� ����
    UFUNCTION(BlueprintCallable, Category = "Judge")
    static bool IsValidUserInput(const TArray<int32>& UserNumbers);
};
