// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

// When the game starts
void UBullCowCartridge::BeginPlay()
{
	Super::BeginPlay();

	// Welcoming the player
	PrintLine(TEXT("You're playing the BullCowGame!"));
	PrintLine(TEXT("Please guess a 4 letter isogram (words without repeating characters)"));
	PrintLine(TEXT("Please press \"Enter\" to continue"));
	
	// Set the HiddenWord
	HiddenWord = TEXT("star");

	// Set Lives

	// Prompt player for PlayerGuess
};

// When player hits "Enter"
void UBullCowCartridge::OnInput(const FString& Input)
{
	ClearScreen();

	// Checking PlayerGuess
	if (Input == HiddenWord)
	{
		PrintLine(TEXT("You won!"));
	}
	else
	{
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
