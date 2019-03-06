#pragma once

#include "Enums.h"
#include <string>
#include <list>
#include <iostream>
#include <windows.h> // --- HANDLE
#include <fcntl.h> // --- _O_U16TEXT
#include <io.h> // --- _setmode

#define LIGHT_BLUE 11
#define LIGHT_RED 12
#define WHITE_COLOR 15

using namespace std;

class Card
{
public:

	Card(int numberToSwitch, int whichListPassed, int bankOrPulled);

	bool IsColorsEqual(list <Card>::iterator firstIterator, list <Card>::iterator secondIterator);
	bool IsFirstCardGreaterThanSecond(list <Card>::iterator firstIterator, list <Card>::iterator secondIterator);
	bool IsPlayerSelectingTheSameCard(list <Card>::iterator firstIterator, list <Card>::iterator secondIterator);
	bool IsCardAKing();

	int GetTheShapeOfTheCard() { return typeShapeOfCard; };
	int GetCardIndex() { return cardValue; };

	void PrintCard(int columnCount);
	void RevealCard();
	void HideCard();
	void CardHasBeenSelectedToggle();
	bool IsCardShown();
	void WhichListToPassItTo(int whichListPassed, int bankOrPulled);
	void SetCursorPosition(int columnCount);

	~Card();
	HANDLE handleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

private:
	void WhichTypeOfCard();
	void ApplyCardDataMembers(int numberToSwitch);
	void SetColorToPrintOn();

	int cardID;
	int cardValue; // 1(A) - 10, 11(J), 12(Q), 13(K)
	string cardLabel; // A , Q, 10
	bool isShown = false;
	bool isSelected = false;

	TypeShapeOfCard typeShapeOfCard;
	WhichListIsIt whichListIsIt;
	BankOrPulled bankOrPulled;
	Color color;
};

