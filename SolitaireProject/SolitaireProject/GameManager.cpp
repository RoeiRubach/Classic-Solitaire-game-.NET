#include "GameManager.h"

bool GameManager::isRestartDeck = false;

GameManager::GameManager()
{
	this->InsertCardsToLists();
	for (size_t i = 0; i < 4; i++) {
		arFoundationPilesCounter[i] = 1;
	}
}

void GameManager::InsertCardsToLists() {

	array<int, 52> allCards;

	for (size_t i = 0; i < 52; i++) {
		allCards[i] = i + 1;
	}

	// Shuffles all 52 cards
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	shuffle(allCards.begin(), allCards.end(), default_random_engine(seed));

	// Deal each card to its wanted list
	for (size_t i = 0; i < 52; i++) {
		if (i < 24) {
			// adding 24 cards to the bankCardsList
			arBankAndDrawn[_BankCardsList].push_back(Card(allCards[i], _BankCardsSpot, _BankCardsList));
		}
		else if (i < 25) {
			// adding to the left most pile
			arColumnFieldLists[_FirstSpot].push_back(Card(allCards[i], _FirstSpot, 0));
		}
		else if (i < 27) {
			arColumnFieldLists[_SecondSpot].push_back(Card(allCards[i], _SecondSpot, 0));
		}
		else if (i < 30) {
			arColumnFieldLists[_ThirdSpot].push_back(Card(allCards[i], _ThirdSpot, 0));
		}
		else if (i < 34) {
			arColumnFieldLists[_FourthSpot].push_back(Card(allCards[i], _FourthSpot, 0));
		}
		else if (i < 39) {
			arColumnFieldLists[_FifthSpot].push_back(Card(allCards[i], _FifthSpot, 0));
		}
		else if (i < 45) {
			arColumnFieldLists[_SixthSpot].push_back(Card(allCards[i], _SixthSpot, 0));
		}
		else {
			// adding to the right most pile
			arColumnFieldLists[_SeventhSpot].push_back(Card(allCards[i], _SeventhSpot, 0));
		}
	}
}

void GameManager::RevealTheLastCardsInLists() {

	for (size_t i = 0; i < 7; i++) {
		if (!arColumnFieldLists[i].empty()) {
			arColumnFieldLists[i].back().RevealCard();
		}
	}
	for (size_t i = 0; i < 4; i++) {
		if (!arFoundationPilesLists[i].empty()) {
			arFoundationPilesLists[i].back().RevealCard();
		}
	}
}

void CursorPlacementMethodForPlayer(HANDLE handle, int x, int y) {

	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(handle, coord);
}

void GameManager::PrintBoardData() {

	// Prints a bank's card
	if ((!arBankAndDrawn[_BankCardsList].empty() && !isBankReachTheLastItem)) {
		arBankAndDrawn[_BankCardsList].back().PrintCard(_UpperHalf);
	}

	// Prints the foundation piles
	for (size_t i = 0; i < 4; i++) {
		if (!arFoundationPilesLists[i].empty()) {
			arFoundationPilesLists[i].back().PrintCard(_UpperHalf);
			cout << " ";
		}
	}

	// Prints the board's columns
	for (size_t lineCount = 0; lineCount < 7; lineCount++) {
		for (size_t columnCount = 0; columnCount < mostCardsInAList; columnCount++) {
			tempIterator = next(arColumnFieldLists[lineCount].begin(), columnCount); // Gets the element in the specific index

			if (tempIterator != arColumnFieldLists[lineCount].end()) { // Checks if the element isn't empty
				tempIterator->PrintCard(columnCount);
			}
			else {
				break;
			}
		}
	}
	CursorPlacementMethodForPlayer(userInterface.handleOutput, leftForCursor, topForCursor);
}

bool GameManager::IsGameOver() {

	int foundationPilesGoalCounter = 0;

	// Checks if the foundation piles are full
	for (size_t i = 0; i < 4; i++) {
		if (arFoundationPilesCounter[i] == _GoalToWin) {
			++foundationPilesGoalCounter;
		}
	}
	if (foundationPilesGoalCounter == 4) {
		return isGameOver = true;
	}

	if (GameManager::isRestartDeck)
	{
		return true;
	}
	return false;
}

void GameManager::ResetTheSelectedCard() {

	isPlayerSelectedACard = false;
	RevealTheLastCardsInLists();
	saveTheSelectedIterator->SetCursorPosition(currentColumn); // Prints \t (bunch of spaces) on the drawn card
	saveTheSelectedIterator->PrintCard(_UpperHalf);
	CursorPlacementMethodForPlayer(userInterface.handleOutput, leftForCursor, topForCursor);
}

void GameManager::HighlightADrawnCard() {

	isPlayerSelectedADrawnCard = true;
	isPlayerSelectedACard = true;
	saveTheSelectedIterator = tempIterator;
	saveTheLastLine = currentLine;
	saveTheLastColumn = currentColumn;
	tempIterator->CardHasBeenSelectedToggle();
}

void GameManager::HighlightAFieldCard() {

	isPlayerSelectedACard = true;
	saveTheLastLine = currentLine;
	saveTheLastColumn = currentColumn;

	list <Card>::iterator saveTheFirstIterator = tempIterator;

	while (tempIterator != arColumnFieldLists[currentLine].end()) {
		tempIterator->CardHasBeenSelectedToggle();
		tempIterator->PrintCard(currentColumn);
		CursorPlacementMethodForPlayer(userInterface.handleOutput, leftForCursor, topForCursor);
		++tempIterator;
		++currentColumn;
	}
	tempIterator = saveTheFirstIterator;
	saveTheSelectedIterator = tempIterator;
}

void GameManager::SwitchWhichCollectingList(int whichShapeIsTheCard) {

	switch (whichShapeIsTheCard) {
	case _SpadesShapedCard:
		/* Checks whether the card you want to insert is next in line to enter the its foundation pile
		 For example, the foundation pile is currently empty, and only an ace will fit in*/
		if (arFoundationPilesCounter[_SpadesShapedList] == saveTheSelectedIterator->GetCardIndex()) {

			// Checks whether the user is trying to insert a drawn card or a field card
			if ((topForCursor == _FirstLine) && (leftForCursor == _SecondLine)) {
				TransferBetweenDrawnCardsListToFoundationPilesLists(_SpadesShapedList, _SpadesShapedSpot);
			}
			else {
				TransferBetweenColumnFieldListsFoundationPilesLists(_SpadesShapedList, _SpadesShapedSpot);
			}
		}
		else {
			ResetTheSelectedCard();
		}
		break;

	case _HeartsShapedCard:
		// Checks whether the card you want to insert is next in line to enter the its foundation pile
		if (arFoundationPilesCounter[_HeartsShapedList] == saveTheSelectedIterator->GetCardIndex()) {

			// Checks whether the user is trying to insert a drawn card or a field card
			if ((topForCursor == _FirstLine) && (leftForCursor == _SecondLine)) {
				TransferBetweenDrawnCardsListToFoundationPilesLists(_HeartsShapedList, _HeartsShapedSpot);
			}
			else {
				TransferBetweenColumnFieldListsFoundationPilesLists(_HeartsShapedList, _HeartsShapedSpot);
			}
		}
		else {
			ResetTheSelectedCard();
		}
		break;

	case _DiamondsShapedCard:
		// Checks whether the card you want to insert is next in line to enter the its foundation pile
		if (arFoundationPilesCounter[_DiamondsShapedList] == saveTheSelectedIterator->GetCardIndex()) {

			// Checks whether the user is trying to insert a drawn card or a field card
			if ((topForCursor == _FirstLine) && (leftForCursor == _SecondLine)) {
				TransferBetweenDrawnCardsListToFoundationPilesLists(_DiamondsShapedList, _DiamondsShapedSpot);
			}
			else {
				TransferBetweenColumnFieldListsFoundationPilesLists(_DiamondsShapedList, _DiamondsShapedSpot);
			}
		}
		else {
			ResetTheSelectedCard();
		}
		break;

	case _ClubsShapedCard:
		// Checks whether the card you want to insert is next in line to enter the its foundation pile
		if (arFoundationPilesCounter[_ClubsShapedList] == saveTheSelectedIterator->GetCardIndex()) {

			// Checks whether the user is trying to insert a drawn card or a field card
			if ((topForCursor == _FirstLine) && (leftForCursor == _SecondLine)) {
				TransferBetweenDrawnCardsListToFoundationPilesLists(_ClubsShapedList, _ClubsShapedSpot);
			}
			else {
				TransferBetweenColumnFieldListsFoundationPilesLists(_ClubsShapedList, _ClubsShapedSpot);
			}
		}
		else {
			ResetTheSelectedCard();
		}
		break;
	}
}

void GameManager::ClearTheWantedColumn() {

	for (size_t i = 0; i < mostCardsInAList; i++) {
		tempIterator->SetCursorPosition(i);
		SetConsoleTextAttribute(userInterface.handleOutput, COLOR_BACKGROUND);
		cout << "    ";
	}
}

void GameManager::DrawACardFromBank() {

	if (!isBankReachTheLastItem) {
		++drawnCardsIndexCounter;
		arBankAndDrawn[_ADrawnCardsList].push_back(arBankAndDrawn[_BankCardsList].front());
		arBankAndDrawn[_ADrawnCardsList].back().RevealCard();
		arBankAndDrawn[_ADrawnCardsList].back().WhichListToPassItTo(_BankCardsSpot, _ADrawnCardsList);
		arBankAndDrawn[_ADrawnCardsList].back().PrintCard(_UpperHalf);
		cout << " ";
		CursorPlacementMethodForPlayer(userInterface.handleOutput, leftForCursor, topForCursor);
		arBankAndDrawn[_BankCardsList].pop_front();
	}
	else {
		// User has reached the bank's last element

		/* If the 'drawn cards list' is currently lower than 'bank cards list', it means that the user removed its last element(s).
		 Therefore, we need to balance the lists, by removing the last elements for the 'bank cards list'*/
		while (arBankAndDrawn[_BankCardsList].size() != arBankAndDrawn[_ADrawnCardsList].size()) {
			arBankAndDrawn[_BankCardsList].pop_back();
		}

		// Resets the bank and drawn cards UI
		if (!arBankAndDrawn[_BankCardsList].empty()) {
			arBankAndDrawn[_ADrawnCardsList].clear();
			drawnCardsIndexCounter = -1;
			cout << "        ";
			isBankReachTheLastItem = false;
			arBankAndDrawn[_BankCardsList].back().PrintCard(_UpperHalf);
		}
		CursorPlacementMethodForPlayer(userInterface.handleOutput, leftForCursor, topForCursor);
	}
}

void GameManager::ResetTheBankCards() {

	if (arBankAndDrawn[_BankCardsList].empty()) {
		SetConsoleTextAttribute(userInterface.handleOutput, WHITE_COLOR);
		cout << "X";
		CursorPlacementMethodForPlayer(userInterface.handleOutput, leftForCursor, topForCursor);
		isBankReachTheLastItem = true;

		if (arBankAndDrawn[_ADrawnCardsList].size() != 1) {
			for (Card card : arBankAndDrawn[_ADrawnCardsList]) {
				arBankAndDrawn[_BankCardsList].push_back(card);
				arBankAndDrawn[_BankCardsList].back().WhichListToPassItTo(_BankCardsSpot, _BankCardsList);
				arBankAndDrawn[_BankCardsList].back().HideCard();
			}
		}
	}
}

void GameManager::ColumnLastElementChecking()
{
	// Checks if the user is tapping on the last current column's element

	list <Card>::iterator getLastElement = arColumnFieldLists[currentLine].end();
	--getLastElement;
	if (saveTheSelectedIterator == getLastElement) {
		int whichShapeIsTheCard = saveTheSelectedIterator->GetTheShapeOfTheCard();

		SwitchWhichCollectingList(whichShapeIsTheCard);
	}
	isPlayerSelectedADrawnCard = false;
	isPlayerSelectedACard = false;
	PrintBoardData();
}

void GameManager::TransferBetweenDrawnCardsListToColumnFieldLists() {

	// If the transfered card is the first element, erase it from the console
	if (saveTheSelectedIterator == arBankAndDrawn[_ADrawnCardsList].begin()) {
		saveTheSelectedIterator->SetCursorPosition(currentColumn); // Prints \t (bunch of spaces) on the drawn card
	}
	saveTheSelectedIterator->WhichListToPassItTo(currentLine, _UpperHalf);
	arColumnFieldLists[currentLine].push_back(*saveTheSelectedIterator);

	arBankAndDrawn[_ADrawnCardsList].erase(next(arBankAndDrawn[_ADrawnCardsList].begin(), drawnCardsIndexCounter));
	RevealTheLastCardsInLists();

	if (!arBankAndDrawn[_ADrawnCardsList].empty()) {
		arBankAndDrawn[_ADrawnCardsList].back().PrintCard(_UpperHalf);
	}
	--drawnCardsIndexCounter;
	--mostCardsInBank;
}

void GameManager::TransferBetweenDrawnCardsListToFoundationPilesLists(TypeOfFoundationPileList typeOfFoundationPileList, WhichListIsIt whichListIsIt) {

	++arFoundationPilesCounter[typeOfFoundationPileList];

	// If the transfered card is the first element, erase it from the console
	if (saveTheSelectedIterator == arBankAndDrawn[_ADrawnCardsList].begin()) {
		saveTheSelectedIterator->SetCursorPosition(currentColumn); // Prints \t (bunch of spaces) on the drawn card
	}
	saveTheSelectedIterator->WhichListToPassItTo(whichListIsIt, _UpperHalf);
	arFoundationPilesLists[typeOfFoundationPileList].push_back(*saveTheSelectedIterator);

	arBankAndDrawn[_ADrawnCardsList].erase(next(arBankAndDrawn[_ADrawnCardsList].begin(), drawnCardsIndexCounter));
	RevealTheLastCardsInLists();

	if (!arBankAndDrawn[_ADrawnCardsList].empty()) {
		arBankAndDrawn[_ADrawnCardsList].back().PrintCard(_UpperHalf);
	}
	--drawnCardsIndexCounter;
	--mostCardsInBank;
}

void GameManager::TransferBetweenColumnFieldLists() {

	ClearTheWantedColumn();

	// Transfers all the elements that has been selected
	while (tempIterator != arColumnFieldLists[saveTheLastLine].end()) {
		++tempIterator;
		saveTheSelectedIterator->WhichListToPassItTo(currentLine, 0);
		arColumnFieldLists[currentLine].push_back(*saveTheSelectedIterator);
		++saveTheSelectedIterator;
		arColumnFieldLists[saveTheLastLine].erase(next(arColumnFieldLists[saveTheLastLine].begin(), saveTheLastColumn));
	}
	RevealTheLastCardsInLists();
}

void GameManager::TransferBetweenColumnFieldListsFoundationPilesLists(TypeOfFoundationPileList typeOfFoundationPileList, WhichListIsIt whichListIsIt) {

	++arFoundationPilesCounter[typeOfFoundationPileList];

	ClearTheWantedColumn();
	saveTheSelectedIterator->WhichListToPassItTo(whichListIsIt, 0);
	arFoundationPilesLists[typeOfFoundationPileList].push_back(*saveTheSelectedIterator);
	arColumnFieldLists[currentLine].pop_back();
	RevealTheLastCardsInLists();
}

void GameManager::ActivatePlayerControls() {
	while (!IsGameOver())
	{
		int userInput = _getch();
		if (userInput == 0xe0) { // for extended keys like a - z/F1 - F12. Not SHIFT/CAPS/CRTL
			userInput = _getch();
		}

		switch (userInput) {
		case KEY_UP:
			if (topForCursor <= 0) {
				break;
			}
			else {
				CursorPlacementMethodForPlayer(userInterface.handleOutput, leftForCursor, --topForCursor);
			}
			break;

		case KEY_DOWN:
			if (topForCursor >= mostCardsInAList) {
				break;
			}
			else {
				CursorPlacementMethodForPlayer(userInterface.handleOutput, leftForCursor, ++topForCursor);
			}
			break;

		case KEY_LEFT:
			if (leftForCursor <= 0) {
				break;
			}
			else {
				CursorPlacementMethodForPlayer(userInterface.handleOutput, leftForCursor -= 4, topForCursor);
			}
			break;

		case KEY_RIGHT:
			if (leftForCursor >= _SeventhLine) {
				break;
			}
			else {
				CursorPlacementMethodForPlayer(userInterface.handleOutput, leftForCursor += 4, topForCursor);
			}
			break;

			{ case KEY_SPACE:
			case KEY_ENTER:

				/* Checks whether the user is tapping on the 'bank cards list'
				 and if it's not empty or already selected.*/
				if ((topForCursor == _BankCardsList) && (leftForCursor == _BankCardsList)
					&& (!arBankAndDrawn[_BankCardsList].empty()) && !isPlayerSelectedACard) {
					DrawACardFromBank();
					ResetTheBankCards();
				}

				// Checks whether the user is tapping on the 'drawn cards list'
				else if ((topForCursor == _FirstLine) && (leftForCursor == _SecondLine) && (!arBankAndDrawn[_ADrawnCardsList].empty())) {
					tempIterator = next(arBankAndDrawn[_ADrawnCardsList].begin(), drawnCardsIndexCounter); // Gets the element in the specific index from the DrawnCardsList

					if ((tempIterator->IsCardShown()) && (!isPlayerSelectedACard)) {
						HighlightADrawnCard();
						tempIterator->PrintCard(_UpperHalf);
						CursorPlacementMethodForPlayer(userInterface.handleOutput, leftForCursor, topForCursor);
					}
					else {
						int whichShapeIsTheCard = saveTheSelectedIterator->GetTheShapeOfTheCard();

						SwitchWhichCollectingList(whichShapeIsTheCard);
						isPlayerSelectedACard = false;
						isPlayerSelectedADrawnCard = false;
					}
					PrintBoardData();
				}

				else {
					/*My game is divided into two. Upper and lower half.
					The upper contains the bank, drawn cards and the foundation piles lists.
					The lower contains the columns field lists.
					The next 2 statements are to let the compiler understand to work on the lower half.*/
					currentColumn = topForCursor - 1;
					currentLine = leftForCursor / 4;
					int currentColumnElementsCounter = 0;

					for (list <Card>::iterator iterat = arColumnFieldLists[currentLine].begin(); iterat != arColumnFieldLists[currentLine].end(); ++iterat) {
						++currentColumnElementsCounter;
					}

					// Checks if the user is tapping on a field card
					if ((currentColumnElementsCounter > currentColumn && currentColumn > -1) || (currentColumnElementsCounter == 0)) {

						if ((!isPlayerSelectedACard) && (!arColumnFieldLists[currentLine].empty())) {
							tempIterator = next(arColumnFieldLists[currentLine].begin(), currentColumn); // Gets the element in the specific index

							if (tempIterator->IsCardShown()) {
								HighlightAFieldCard();
							}
						}
						else {
							if (!arColumnFieldLists[currentLine].empty()) {
								if (saveTheSelectedIterator->IsPlayerSelectingTheSameCard(next(arColumnFieldLists[currentLine].begin(), currentColumn), saveTheSelectedIterator)) {

									ColumnLastElementChecking();
									break;
								}
							}
							if (arColumnFieldLists[currentLine].size() <= mostCardsInAList) {
								if (isPlayerSelectedADrawnCard) {
									// The user has selected a card from the 'drawn cards list'

									isPlayerSelectedADrawnCard = false;

									if (!arColumnFieldLists[currentLine].empty()) {

										// Checks whether the cards own the same color and if the fisrt card is greater than the second
										if (saveTheSelectedIterator->IsColorsEqual(saveTheSelectedIterator, arColumnFieldLists[currentLine].end())
											&& (saveTheSelectedIterator->IsFirstCardGreaterThanSecond(saveTheSelectedIterator, arColumnFieldLists[currentLine].end()))) {
											TransferBetweenDrawnCardsListToColumnFieldLists();
										}
										else {
											ResetTheSelectedCard();
										}
									}
									else if (!saveTheSelectedIterator->IsCardAKing()) {
										ResetTheSelectedCard();
										break;
									}
									else {
										// The selected card is a king and can be transfer to an empty column
										TransferBetweenDrawnCardsListToColumnFieldLists();
									}
								}
								else if (!arColumnFieldLists[currentLine].empty()) {
									// The user has selected a card from the 'column field list'
									
									if (tempIterator->IsCardShown()) {

										// Checks whether the cards own the same color and if the fisrt card is greater than the second
										if (saveTheSelectedIterator->IsColorsEqual(saveTheSelectedIterator, arColumnFieldLists[currentLine].end())
											&& (saveTheSelectedIterator->IsFirstCardGreaterThanSecond(saveTheSelectedIterator, arColumnFieldLists[currentLine].end()))) {
											TransferBetweenColumnFieldLists();
										}
									}
								}
								else {
									if (isPlayerSelectedACard) {
										if (saveTheSelectedIterator->IsCardAKing()) {
											TransferBetweenColumnFieldLists();
										}
									}
								}
							}
							else if (isPlayerSelectedADrawnCard) {
								ResetTheSelectedCard();
							}

							isPlayerSelectedADrawnCard = false;
							isPlayerSelectedACard = false;
							PrintBoardData();
						}
					}
				}
				break;
			}
		case KEY_R:
			GameManager::isRestartDeck = true;
			break;

		case KEY_ESC:
			userInterface.ExitApplication();
		}
	}
	if (!GameManager::isRestartDeck)
	{
		userInterface.RestartApplication();
	}
}

void GameManager::Start() {
	if (!GameManager::isRestartDeck)
	{
		userInterface.MainMenu();
		userInterface.PrintDeckControls();
	}
	else {
		system("CLS");
		isGameOver = false;
		GameManager::isRestartDeck = false;
	}

	RevealTheLastCardsInLists();
	PrintBoardData();

	ActivatePlayerControls();
}

GameManager::~GameManager() {
}