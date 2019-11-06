// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

// When the game starts
void UBullCowCartridge::BeginPlay()
{
	Super::BeginPlay();
	PrintLine(TEXT("You're playing the BullCowGame!"));
	PrintLine(TEXT("Please guess a 4 letter isogram (words without repeating characters)"));
	PrintLine(TEXT("Please press \"Enter\" to continue"));
};

//When the player hits enter
void UBullCowCartridge::OnInput(const FString& Input)
{
	ClearScreen();
	FString HiddenWord = TEXT("star");	// move outside function
	if (Input == HiddenWord)
		PrintLine(TEXT("You won!"));
	else
		PrintLine(TEXT("You lost..."));

};
