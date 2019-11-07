// Fill out your copyright notice in the Description page of Project Settings.
#include "./BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
	Super::BeginPlay();

	SetupGame(); // Setting up game

	PrintLine(FString::Printf(TEXT("The hidden word is: %s and it is %i characters long\n"), *HiddenWord, HiddenWord.Len())); // Debug Line
};

void UBullCowCartridge::OnInput(const FString& Input) // When player hits "Enter"
{
	if (bGameOver) // Game loop
	{
		ClearScreen();
		SetupGame();
	}
	else
	{
		if (Input == HiddenWord) // Checking PlayerGuess
		{
			PrintLine(TEXT("You won!"));
			EndGame();
		}
		else
		{
			PrintLine(FString::Printf(TEXT("You now have %i lives"), --Lives));
			if (Lives > 0)
			{
				if (Input.Len() != HiddenWord.Len())
				{
					PrintLine(FString::Printf(TEXT("It is a %i letter word, try again"), HiddenWord.Len()));
				}
			}
			else
			{
				PrintLine(TEXT("You have no lives left!"));
				EndGame();
			}
		}
	}
};

void UBullCowCartridge::SetupGame()
{
	// Initializing game state
	HiddenWord = TEXT("star");
	Lives = HiddenWord.Len();
	bGameOver = false;

	// Welcoming the player and prompt player for PlayerGuess
	PrintLine(TEXT("Welcome to the Bull Cow Game!"));
	PrintLine(FString::Printf(TEXT("Guess the %i letter isogram"), HiddenWord.Len()));
	PrintLine(FString::Printf(TEXT("You have %i Lives\nEnter your guess and press \"Enter\""), HiddenWord.Len()));
}

void UBullCowCartridge::EndGame()
{
	bGameOver = true;
	PrintLine(TEXT("Please press enter to play again"));
}