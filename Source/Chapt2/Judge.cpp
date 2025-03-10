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

    // �� ���ڿ� ���� ����
    for (int32 i = 0; i < 3; i++)
    {
        int32 UserNum = UserNumbers[i];

        // Strike üũ
        if (UserNum == TargetNumbers[i])
        {
            StrikeCount++;
        }
        // Ball üũ
        else if (TargetNumbers.Contains(UserNum))
        {
            BallCount++;
        }
    }

    // Out üũ
	if (StrikeCount == 0 && BallCount == 0)
	{
		OutCount = 1;
	}
}

bool UJudge::IsValidUserInput(const TArray<int32>& UserNumbers)
{
    // ��� ���ڰ� 1~9 ���� ���� �ִ��� Ȯ��
    for (int32 Num : UserNumbers)
    {
        if (Num < 1 || Num > 9)
        {
            return false;
        }
    }

    // �ߺ� üũ
    TSet<int32> NumberSet;
    NumberSet.Reserve(3);
    for (int32 Num : UserNumbers)
    {
        if (NumberSet.Contains(Num))
        {
            return false; // �̹� �����ϸ� �ߺ�
        }
        NumberSet.Add(Num);
    }

    return true;
}

TArray<int32> UJudge::StringToNumberArray(const FString& InputString)
{
    TArray<int32> NumberArray;

    // �Է��� 3�ڸ��� �ƴϸ� �� �迭 ��ȯ
    if (InputString.Len() != 3)
    {
        return NumberArray;
    }

    // �� ���ڸ� ���ڷ� ��ȯ
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
            // ���ڰ� �ƴ� ��� �� �迭 ��ȯ
            NumberArray.Empty();
            return NumberArray;
        }
    }

    return NumberArray;
}