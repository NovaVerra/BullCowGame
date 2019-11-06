// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
	Super::BeginPlay();
	PrintLine("You're playing the BullCowGame!");
	PrintLine("Please type something into the terminal and press \"Enter\"");
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
	ClearScreen();
}