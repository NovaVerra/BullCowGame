// Fill out your copyright notice in the Description page of Project Settings.
#include "./BullCowCartridge.h"
#include "HiddenWordList.h"

void	UBullCowCartridge::BeginPlay() // When the game starts
{
	Super::BeginPlay();
	Isograms = GetValidWords(HiddenWordList); // Eliminate words
	SetupGame(); // Setting up game
};

void	UBullCowCartridge::OnInput(const FString& PlayerInput) // When player hits "Enter"
{
	if (bGameOver) // Game loop
	{
		ClearScreen();
		SetupGame();
	}
	else
	{
		ProcessGuess(PlayerInput);
	}
};

void	UBullCowCartridge::SetupGame()
{
	// Initializing game state
	HiddenWord = Isograms[FMath::RandRange(0, Isograms.Num() - 1)];
	Lives = HiddenWord.Len();
	bGameOver = false;

	// Welcoming the player and prompt player for PlayerGuess
	PrintLine(TEXT("Welcome to the Bull Cow Game!"));
	PrintLine(FString::Printf(TEXT("Guess the %i letter isogram"), HiddenWord.Len()));
	PrintLine(FString::Printf(TEXT("You have %i Lives\nEnter your guess and press \"Enter\""), HiddenWord.Len()));
	PrintLine(FString::Printf(TEXT("The hidden word is: %s and it is %i characters long\n"), *HiddenWord, HiddenWord.Len())); // Debug Line
}

void	UBullCowCartridge::EndGame()
{
	bGameOver = true;
	PrintLine(TEXT("Please press enter to play again"));
}

void	UBullCowCartridge::ProcessGuess(const FString& Guess)
{
	if (Guess == HiddenWord) // Checking PlayerGuess
	{
		PrintLine(TEXT("You won!"));
		EndGame();
		return;
	}
	if (!IsIsogram(Guess)) // Checking if PlayerGuess is an isogram
	{
		PrintLine(TEXT("No repeating letters"));
		return;
	}
	if (Guess.Len() != HiddenWord.Len()) // Check if PlayerGuess has the right number of characters
	{
		PrintLine(FString::Printf(TEXT("It is a %i letter word, try again"), HiddenWord.Len()));
		PrintLine(FString::Printf(TEXT("You have %i lives remaining"), Lives));
		return;
	}

	--Lives;
	PrintLine(FString::Printf(TEXT("You lost a life... You now have %i lives"), Lives));

	if (Lives <= 0)
	{
		PrintLine(TEXT("You have no lives left!"));
		PrintLine(TEXT("The hidden word was: %s"), *HiddenWord);
		EndGame();
		return;
	}

	FBullCowCount Counts = GetBullsCows(Guess);

	PrintLine(FString::Printf(TEXT("You have %i Bulls and %i Cows"), Counts.BullCount, Counts.CowCount));
	PrintLine(TEXT("Trying guessing again, you have %i lives left"), Lives);
}

bool	UBullCowCartridge::IsIsogram(const FString& Guess) const
{
	for (int32 Index = 0; Index < Guess.Len(); Index++)
	{
		for (int32 Comparison = Index + 1; Comparison < Guess.Len(); Comparison++)
		{
			if (Guess[Index] == Guess[Comparison])
			{
				return false;
			}
		}
	}
	return true;
}

TArray<FString>	UBullCowCartridge::GetValidWords(const TArray<FString>& Words) const
{
	TArray<FString> ValidWords;
	
	for (FString Word : Words)
	{
		if (Word.Len() >= 4 && Word.Len() <= 8 && IsIsogram(Word))
		{
			ValidWords.Emplace(Word);
		}
	}
	return ValidWords;
}

FBullCowCount	UBullCowCartridge::GetBullsCows(const FString Guess) const
{
	FBullCowCount Count;

	// for every index
		// if index of guess == index of word
			// bull++
		// else
			// cow++

	for (int32 GuessIndex = 0; GuessIndex < Guess.Len(); GuessIndex++)
	{
		if (Guess[GuessIndex] == HiddenWord[GuessIndex])
		{
			Count.BullCount++;
			continue;
		}
		for (int32 HiddenIndex = 0; HiddenIndex < HiddenWord.Len(); HiddenIndex++)
		{
			if (Guess[GuessIndex] == HiddenWord[HiddenIndex])
			{
				Count.CowCount++;
			}
		}
	}
	return Count;
}
