#pragma once

#include "Card.h"
#include "UserInterface.h"
#include <array>
#include <conio.h> // --- _getch
#include <chrono>  // --- chrono
#include <random> // --- default_random_engine

#define KEY_ENTER 13
#define KEY_ESC 27
#define KEY_SPACE 32
#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_DOWN 80
#define KEY_R 114

using namespace std;

class GameManager
{
public:
	static bool isRestartDeck;

	GameManager();
	void InsertCardsToLists();
	void RevealTheLastCardsInLists();
	void Start();
	bool IsGameOver();
	~GameManager();

private:

	void PrintBoardData();
	void ResetTheSelectedCard();
	void HighlightADrawnCard();
	void HighlightAFieldCard();
	void TransferBetweenDrawnCardsListToColumnFieldLists();
	void TransferBetweenDrawnCardsListToFoundationPilesLists(TypeOfFoundationPileList typeOfFoundationPileList, WhichListIsIt whichListIsIt);
	void TransferBetweenColumnFieldLists();
	void TransferBetweenColumnFieldListsFoundationPilesLists(TypeOfFoundationPileList typeOfFoundationPileList, WhichListIsIt whichListIsIt);
	void SwitchWhichCollectingList(int whichShapeIsTheCard);
	void ClearTheWantedColumn();
	void DrawACardFromBank();
	void ResetTheBankCards();
	void ColumnLastElementChecking();
	void ActivatePlayerControls();

	const int mostCardsInAList = 20;
	int mostCardsInBank = 24;
	int drawnCardsIndexCounter = -1;
	int currentColumn = 0;
	int currentLine = 0;
	int saveTheLastLine = 0;
	int saveTheLastColumn = 0;
	int topForCursor = 0;
	int leftForCursor = 0;

	bool isGameOver = false;
	bool isBankReachTheLastItem = false;
	bool isPlayerSelectedADrawnCard = false;
	bool isPlayerSelectedACard = false;

	UserInterface userInterface;
	list <Card>::iterator tempIterator;
	list <Card>::iterator saveTheSelectedIterator;
	
	list <Card> arBankAndDrawn[2];
	list <Card> arColumnFieldLists[7];
	list <Card> arFoundationPilesLists[4];
	int arFoundationPilesCounter[4];
};