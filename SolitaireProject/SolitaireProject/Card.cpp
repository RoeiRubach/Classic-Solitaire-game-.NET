#include "Card.h"

static void CursorPlacementMethodForPrinting(HANDLE handleOutput, int leftForCursor, int topForCursor) {
	COORD coord;
	coord.X = leftForCursor;
	coord.Y = topForCursor;
	SetConsoleCursorPosition(handleOutput, coord);
}

Card::Card(int numberToSwitch, int whichListPassed, int bankOrPulled) {

	// Sets the card value to all 52 cards, to determine which card is higher
	/// This action happens when trying to transfer a card from one column to another
	if (numberToSwitch % 13 == 0) {
		cardValue = 13;
	}
	else {
		cardValue = numberToSwitch % 13;
	}

	WhichListToPassItTo(whichListPassed, bankOrPulled);
	ApplyCardDataMembers(numberToSwitch);
}

void Card::WhichListToPassItTo(int whichListPassed, int bankOrPulled) {

	// Sets the card's column

	switch (whichListPassed)
	{
	case _BankCardsSpot:
		whichListIsIt = _BankCardsSpot;
		switch (bankOrPulled)
		{
		case _BankCardsList:
			this->bankOrPulled = _BankCardsList;
			break;

		case _ADrawnCardsList:
			this->bankOrPulled = _ADrawnCardsList;
			break;
		}
		break;

	case _FirstSpot:
		whichListIsIt = _FirstSpot;
		break;

	case _SecondSpot:
		whichListIsIt = _SecondSpot;
		break;

	case _ThirdSpot:
		whichListIsIt = _ThirdSpot;
		break;

	case _FourthSpot:
		whichListIsIt = _FourthSpot;
		break;

	case _FifthSpot:
		whichListIsIt = _FifthSpot;
		break;

	case _SixthSpot:
		whichListIsIt = _SixthSpot;
		break;

	case _SeventhSpot:
		whichListIsIt = _SeventhSpot;
		break;

	case _SpadesShapedSpot:
		whichListIsIt = _SpadesShapedSpot;
		break;

	case _HeartsShapedSpot:
		whichListIsIt = _HeartsShapedSpot;
		break;

	case _DiamondsShapedSpot:
		whichListIsIt = _DiamondsShapedSpot;
		break;

	case _ClubsShapedSpot:
		whichListIsIt = _ClubsShapedSpot;
		break;
	}
}

void Card::ApplyCardDataMembers(int numberToSwitch) {

	// Sets each card with its data.

	switch (numberToSwitch)
	{
	case 1:
		cardID = numberToSwitch;
		cardLabel = 'A';
		typeShapeOfCard = _SpadesShapedCard;
		color = _BLACK;
		break;

	case 2:
		cardID = numberToSwitch;
		cardLabel = '2';
		typeShapeOfCard = _SpadesShapedCard;
		color = _BLACK;
		break;

	case 3:
		cardID = numberToSwitch;
		cardLabel = '3';
		typeShapeOfCard = _SpadesShapedCard;
		color = _BLACK;
		break;

	case 4:
		cardID = numberToSwitch;
		cardLabel = '4';
		typeShapeOfCard = _SpadesShapedCard;
		color = _BLACK;
		break;

	case 5:
		cardID = numberToSwitch;
		cardLabel = '5';
		typeShapeOfCard = _SpadesShapedCard;
		color = _BLACK;
		break;

	case 6:
		cardID = numberToSwitch;
		cardLabel = '6';
		typeShapeOfCard = _SpadesShapedCard;
		color = _BLACK;
		break;

	case 7:
		cardID = numberToSwitch;
		cardLabel = '7';
		typeShapeOfCard = _SpadesShapedCard;
		color = _BLACK;
		break;

	case 8:
		cardID = numberToSwitch;
		cardLabel = '8';
		typeShapeOfCard = _SpadesShapedCard;
		color = _BLACK;
		break;

	case 9:
		cardID = numberToSwitch;
		cardLabel = '9';
		typeShapeOfCard = _SpadesShapedCard;
		color = _BLACK;
		break;

	case 10:
		cardID = numberToSwitch;
		cardLabel = "10";
		typeShapeOfCard = _SpadesShapedCard;
		color = _BLACK;
		break;

	case 11:
		cardID = numberToSwitch;
		cardLabel = 'J';
		typeShapeOfCard = _SpadesShapedCard;
		color = _BLACK;
		break;

	case 12:
		cardID = numberToSwitch;
		cardLabel = 'Q';
		typeShapeOfCard = _SpadesShapedCard;
		color = _BLACK;
		break;

	case 13:
		cardID = numberToSwitch;
		cardLabel = 'K';
		typeShapeOfCard = _SpadesShapedCard;
		color = _BLACK;
		break;

	case 14:
		cardID = numberToSwitch;
		cardLabel = 'A';
		typeShapeOfCard = _ClubsShapedCard;
		color = _BLACK;
		break;

	case 15:
		cardID = numberToSwitch;
		cardLabel = '2';
		typeShapeOfCard = _ClubsShapedCard;
		color = _BLACK;
		break;

	case 16:
		cardID = numberToSwitch;
		cardLabel = '3';
		typeShapeOfCard = _ClubsShapedCard;
		color = _BLACK;
		break;

	case 17:
		cardID = numberToSwitch;
		cardLabel = '4';
		typeShapeOfCard = _ClubsShapedCard;
		color = _BLACK;
		break;

	case 18:
		cardID = numberToSwitch;
		cardLabel = '5';
		typeShapeOfCard = _ClubsShapedCard;
		color = _BLACK;
		break;

	case 19:
		cardID = numberToSwitch;
		cardLabel = '6';
		typeShapeOfCard = _ClubsShapedCard;
		color = _BLACK;
		break;

	case 20:
		cardID = numberToSwitch;
		cardLabel = '7';
		typeShapeOfCard = _ClubsShapedCard;
		color = _BLACK;
		break;

	case 21:
		cardID = numberToSwitch;
		cardLabel = '8';
		typeShapeOfCard = _ClubsShapedCard;
		color = _BLACK;
		break;

	case 22:
		cardID = numberToSwitch;
		cardLabel = '9';
		typeShapeOfCard = _ClubsShapedCard;
		color = _BLACK;
		break;

	case 23:
		cardID = numberToSwitch;
		cardLabel = "10";
		typeShapeOfCard = _ClubsShapedCard;
		color = _BLACK;
		break;

	case 24:
		cardID = numberToSwitch;
		cardLabel = 'J';
		typeShapeOfCard = _ClubsShapedCard;
		color = _BLACK;
		break;

	case 25:
		cardID = numberToSwitch;
		cardLabel = 'Q';
		typeShapeOfCard = _ClubsShapedCard;
		color = _BLACK;
		break;

	case 26:
		cardID = numberToSwitch;
		cardLabel = 'K';
		typeShapeOfCard = _ClubsShapedCard;
		color = _BLACK;
		break;

	case 27:
		cardID = numberToSwitch;
		cardLabel = 'A';
		typeShapeOfCard = _HeartsShapedCard;
		color = _RED;
		break;

	case 28:
		cardID = numberToSwitch;
		cardLabel = '2';
		typeShapeOfCard = _HeartsShapedCard;
		color = _RED;
		break;

	case 29:
		cardID = numberToSwitch;
		cardLabel = '3';
		typeShapeOfCard = _HeartsShapedCard;
		color = _RED;
		break;

	case 30:
		cardID = numberToSwitch;
		cardLabel = '4';
		typeShapeOfCard = _HeartsShapedCard;
		color = _RED;
		break;

	case 31:
		cardID = numberToSwitch;
		cardLabel = '5';
		typeShapeOfCard = _HeartsShapedCard;
		color = _RED;
		break;

	case 32:
		cardID = numberToSwitch;
		cardLabel = '6';
		typeShapeOfCard = _HeartsShapedCard;
		color = _RED;
		break;

	case 33:
		cardID = numberToSwitch;
		cardLabel = '7';
		typeShapeOfCard = _HeartsShapedCard;
		color = _RED;
		break;

	case 34:
		cardID = numberToSwitch;
		cardLabel = '8';
		typeShapeOfCard = _HeartsShapedCard;
		color = _RED;
		break;

	case 35:
		cardID = numberToSwitch;
		cardLabel = '9';
		typeShapeOfCard = _HeartsShapedCard;
		color = _RED;
		break;

	case 36:
		cardID = numberToSwitch;
		cardLabel = "10";
		typeShapeOfCard = _HeartsShapedCard;
		color = _RED;
		break;

	case 37:
		cardID = numberToSwitch;
		cardLabel = 'J';
		typeShapeOfCard = _HeartsShapedCard;
		color = _RED;
		break;

	case 38:
		cardID = numberToSwitch;
		cardLabel = 'Q';
		typeShapeOfCard = _HeartsShapedCard;
		color = _RED;
		break;

	case 39:
		cardID = numberToSwitch;
		cardLabel = 'K';
		typeShapeOfCard = _HeartsShapedCard;
		color = _RED;
		break;

	case 40:
		cardID = numberToSwitch;
		cardLabel = 'A';
		typeShapeOfCard = _DiamondsShapedCard;
		color = _RED;
		break;

	case 41:
		cardID = numberToSwitch;
		cardLabel = '2';
		typeShapeOfCard = _DiamondsShapedCard;
		color = _RED;
		break;

	case 42:
		cardID = numberToSwitch;
		cardLabel = '3';
		typeShapeOfCard = _DiamondsShapedCard;
		color = _RED;
		break;

	case 43:
		cardID = numberToSwitch;
		cardLabel = '4';
		typeShapeOfCard = _DiamondsShapedCard;
		color = _RED;
		break;

	case 44:
		cardID = numberToSwitch;
		cardLabel = '5';
		typeShapeOfCard = _DiamondsShapedCard;
		color = _RED;
		break;

	case 45:
		cardID = numberToSwitch;
		cardLabel = '6';
		typeShapeOfCard = _DiamondsShapedCard;
		color = _RED;
		break;

	case 46:
		cardID = numberToSwitch;
		cardLabel = '7';
		typeShapeOfCard = _DiamondsShapedCard;
		color = _RED;
		break;

	case 47:
		cardID = numberToSwitch;
		cardLabel = '8';
		typeShapeOfCard = _DiamondsShapedCard;
		color = _RED;
		break;

	case 48:
		cardID = numberToSwitch;
		cardLabel = '9';
		typeShapeOfCard = _DiamondsShapedCard;
		color = _RED;
		break;

	case 49:
		cardID = numberToSwitch;
		cardLabel = "10";
		typeShapeOfCard = _DiamondsShapedCard;
		color = _RED;
		break;

	case 50:
		cardID = numberToSwitch;
		cardLabel = 'J';
		typeShapeOfCard = _DiamondsShapedCard;
		color = _RED;
		break;

	case 51:
		cardID = numberToSwitch;
		cardLabel = 'Q';
		typeShapeOfCard = _DiamondsShapedCard;
		color = _RED;
		break;

	case 52:
		cardID = numberToSwitch;
		cardLabel = 'K';
		typeShapeOfCard = _DiamondsShapedCard;
		color = _RED;
		break;
	}
}

void Card::SetCursorPosition(int columnCount) {

	// Receives the specific column and places the cursor in the designated place

	switch (whichListIsIt)
	{
	case _BankCardsSpot:
		switch (bankOrPulled)
		{
		case _BankCardsList:
			CursorPlacementMethodForPrinting(handleOutput, _BankCardsList, _UpperHalf);
			break;

		case _ADrawnCardsList:
			CursorPlacementMethodForPrinting(handleOutput, _SecondLine, _UpperHalf);
			SetConsoleTextAttribute(handleOutput, COLOR_BACKGROUND);
			//cout << "\t";
			cout << "      ";
			CursorPlacementMethodForPrinting(handleOutput, _SecondLine, columnCount);
			break;
		}
		break;

	case _SpadesShapedSpot:
		CursorPlacementMethodForPrinting(handleOutput, _SpadesShapedCard, columnCount);
		break;

	case _HeartsShapedSpot:
		CursorPlacementMethodForPrinting(handleOutput, _HeartsShapedCard, columnCount);
		break;

	case _DiamondsShapedSpot:
		CursorPlacementMethodForPrinting(handleOutput, _DiamondsShapedCard, columnCount);
		break;

	case _ClubsShapedSpot:
		CursorPlacementMethodForPrinting(handleOutput, _ClubsShapedCard, columnCount);
		break;

	case _FirstSpot:
		++columnCount;
		CursorPlacementMethodForPrinting(handleOutput, _FirstLine, columnCount);
		break;

	case _SecondSpot:
		++columnCount;
		CursorPlacementMethodForPrinting(handleOutput, _SecondLine, columnCount);
		break;

	case _ThirdSpot:
		++columnCount;
		CursorPlacementMethodForPrinting(handleOutput, _ThirdLine, columnCount);
		break;

	case _FourthSpot:
		++columnCount;
		CursorPlacementMethodForPrinting(handleOutput, _FourthLine, columnCount);
		break;

	case _FifthSpot:
		++columnCount;
		CursorPlacementMethodForPrinting(handleOutput, _FifthLine, columnCount);
		break;

	case _SixthSpot:
		++columnCount;
		CursorPlacementMethodForPrinting(handleOutput, _SixthLine, columnCount);
		break;

	case _SeventhSpot:
		++columnCount;
		CursorPlacementMethodForPrinting(handleOutput, _SeventhLine, columnCount);
		break;
	}
}

void Card::SetColorToPrintOn() {

	// Each card owns a color enum

	switch (color)
	{
	case _RED:
		SetConsoleTextAttribute(handleOutput, LIGHT_RED);
		if (isSelected) {
			SetConsoleTextAttribute(handleOutput, BACKGROUND_RED);
			isSelected = false;
		}
		break;

	case _BLACK:
		SetConsoleTextAttribute(handleOutput, FOREGROUND_INTENSITY); // Gray (black was already taken by the background)
		if (isSelected) {
			SetConsoleTextAttribute(handleOutput, BACKGROUND_INTENSITY);
			isSelected = false;
		}
		break;
	}
}

void Card::PrintCard(int columnCount) {

	SetCursorPosition(columnCount);

	if (isShown) {
		SetColorToPrintOn();
		cout << cardLabel;
		_setmode(_fileno(stdout), _O_U16TEXT);

		WhichTypeOfCard();
	}
	else {
		SetConsoleTextAttribute(handleOutput, LIGHT_BLUE);
		cout << "?  ";
	}
}

bool Card::IsColorsEqual(list<Card>::iterator firstIterator, list<Card>::iterator secondIterator) {

	// Gets 2 cards to check whether the colors matched

	--secondIterator;
	if (firstIterator->color == secondIterator->color) {
		return false;
	}
	return true;
}

bool Card::IsFirstCardGreaterThanSecond(list<Card>::iterator firstIterator, list<Card>::iterator secondIterator) {

	// Gets 2 cards to check whether the first card can be placed under the second card

	--secondIterator;
	int tempCardIndex = firstIterator->cardValue + 1;
	if (secondIterator->cardValue == tempCardIndex) {
		return true;
	}
	return false;
}

bool Card::IsPlayerSelectingTheSameCard(list<Card>::iterator firstIterator, list<Card>::iterator secondIterator) {

	if (firstIterator->cardID == secondIterator->cardID) {
		return true;
	}
	return false;
}

bool Card::IsCardAKing() {

	if (cardValue == 13) {// King card
		return true;
	}
	return false;
}

void Card::RevealCard() {

	if (!isShown) {
		isShown = true;
	}
}

void Card::HideCard() {

	isShown = false;
}

void Card::WhichTypeOfCard() {

	// Each card owns a shape type. This method prints it

	switch (typeShapeOfCard) {

	case _SpadesShapedCard:
		wprintf(L"\x2660"); // Spade label
		_setmode(_fileno(stdout), _O_TEXT);
		break;

	case _ClubsShapedCard:
		wprintf(L"\x2663"); // Club label
		_setmode(_fileno(stdout), _O_TEXT);
		break;

	case _HeartsShapedCard:
		wprintf(L"\x2665"); // Heart label
		_setmode(_fileno(stdout), _O_TEXT);
		break;

	case _DiamondsShapedCard:
		wprintf(L"\x2666"); // Diamond label
		_setmode(_fileno(stdout), _O_TEXT);
		break;
	}
}

void Card::CardHasBeenSelectedToggle() {

	if (!isSelected) {
		isSelected = true;
	}
	else {
		isSelected = false;
	}
}

bool Card::IsCardShown() {

	return isShown;
}

Card::~Card()
{
}