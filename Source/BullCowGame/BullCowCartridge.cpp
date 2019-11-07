// Fill out your copyright notice in the Description page of Project Settings.
#include "./BullCowCartridge.h"

// When the game starts
void UBullCowCartridge::BeginPlay()
{
	Super::BeginPlay();

	// Setting up game
	SetupGame();

	// // Debug Line
	// PrintLine(FString::Printf(TEXT("The hidden word is: %s and it is %i characters long\n"), *HiddenWord, HiddenWord.Len()));

	// Welcoming the player
	PrintLine(TEXT("Welcome to the Bull Cow Game!"));
	PrintLine(FString::Printf(TEXT("Guess the %i letter isogram"), HiddenWord.Len()));
	PrintLine(TEXT("Enter your guess and press \"Enter\""));

	// Prompt player for PlayerGuess
};

// When player hits "Enter"
void UBullCowCartridge::OnInput(const FString& Input)
{
	ClearScreen();

	// Checking PlayerGuess
	if (Input == HiddenWord)
		PrintLine(TEXT("You won!"));
	else
	{
		if (Input.Len() != HiddenWord.Len())
			PrintLine(FString::Printf(TEXT("The hidden word has %i letters..."), HiddenWord.Len()));
		PrintLine(TEXT("You lost..."));
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
};

void UBullCowCartridge::SetupGame()
{
	// Set the HiddenWord
	HiddenWord = TEXT("star");

	// Set Lives
	Lives = 4;
}
