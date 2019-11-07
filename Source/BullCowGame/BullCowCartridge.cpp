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
	if (bGameOver)
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
			if (Input.Len() != HiddenWord.Len())
			{
				PrintLine(FString::Printf(TEXT("The hidden word has %i letters...\nYou have lost!"), HiddenWord.Len()));
				EndGame();
			}
		}

		// Check if PlayerGuess is Isogram
			// Prompt to guess again
		// Check if PlayerGuess has the right number of characters
			// Prompt to guess again
		// Check if Life > 0

		// Remove Life

		// Does user want to play again?
			// If yes, repeat (set next word)
			// If no, print game failed and show HiddenWord	
	}
};

void UBullCowCartridge::SetupGame()
{
	// Initializing game state
	HiddenWord = TEXT("star");
	Lives = 4;
	bGameOver = false;

	// Welcoming the player and prompt player for PlayerGuess
	PrintLine(TEXT("Welcome to the Bull Cow Game!"));
	PrintLine(FString::Printf(TEXT("Guess the %i letter isogram"), HiddenWord.Len()));
	PrintLine(TEXT("Enter your guess and press \"Enter\""));
}

void UBullCowCartridge::EndGame()
{
	bGameOver = true;
	PrintLine(TEXT("Please press enter to play again"));
}