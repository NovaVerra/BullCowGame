// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

// When the game starts
void UBullCowCartridge::BeginPlay()
{
	Super::BeginPlay();
	PrintLine(TEXT("You're playing the BullCowGame!"));
	PrintLine(TEXT("Please type something into the terminal and press \"Enter\""));
};

//When the player hits enter
void UBullCowCartridge::OnInput(const FString& Input)
{
	ClearScreen();
	FString HiddenWord = TEXT("star");
	PrintLine(Input);
};
