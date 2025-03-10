// Fill out your copyright notice in the Description page of Project Settings.


// Judge.cpp
#include "Judge.h"
#include "Containers/Array.h"

TArray<int32> UJudge::GenerateRandomNumbers()
{
    TArray<int32> Numbers;
    TArray<int32> AvailableNumbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    for (int32 i = 0; i < 3; i++)
    {
        int32 RandomIndex = FMath::RandRange(0, AvailableNumbers.Num() - 1);
        Numbers.Add(AvailableNumbers[RandomIndex]);
        AvailableNumbers.RemoveAt(RandomIndex);
    }

    return Numbers;
}

void UJudge::JudgeNumbers(const TArray<int32>& TargetNumbers, const TArray<int32>& UserNumbers,
    int32& StrikeCount, int32& BallCount, int32& OutCount)
{
    StrikeCount = 0;
    BallCount = 0;
    OutCount = 0;

    if (TargetNumbers.Num() != 3 || UserNumbers.Num() != 3)
    {
        return;
    }

    // 각 숫자에 대해 판정
    for (int32 i = 0; i < 3; i++)
    {
        int32 UserNum = UserNumbers[i];

        // Strike 체크
        if (UserNum == TargetNumbers[i])
        {
            StrikeCount++;
        }
        // Ball 체크
        else if (TargetNumbers.Contains(UserNum))
        {
            BallCount++;
        }
    }

    // Out 체크
	if (StrikeCount == 0 && BallCount == 0)
	{
		OutCount = 1;
	}
}

bool UJudge::IsValidUserInput(const TArray<int32>& UserNumbers)
{
    // 모든 숫자가 1~9 범위 내에 있는지 확인
    for (int32 Num : UserNumbers)
    {
        if (Num < 1 || Num > 9)
        {
            return false;
        }
    }

    // 중복 체크
    TSet<int32> NumberSet;
    NumberSet.Reserve(3);
    for (int32 Num : UserNumbers)
    {
        if (NumberSet.Contains(Num))
        {
            return false; // 이미 존재하면 중복
        }
        NumberSet.Add(Num);
    }

    return true;
}

TArray<int32> UJudge::StringToNumberArray(const FString& InputString)
{
    TArray<int32> NumberArray;

    // 입력이 3자리가 아니면 빈 배열 반환
    if (InputString.Len() != 3)
    {
        return NumberArray;
    }

    // 각 문자를 숫자로 변환
    for (int32 i = 0; i < 3; i++)
    {
        FString Char = InputString.Mid(i, 1);
        int32 Num;
        if (Char.IsNumeric() && LexTryParseString(Num, *Char))
        {
            NumberArray.Add(Num);
        }
        else
        {
            // 숫자가 아닌 경우 빈 배열 반환
            NumberArray.Empty();
            return NumberArray;
        }
    }

    return NumberArray;
}