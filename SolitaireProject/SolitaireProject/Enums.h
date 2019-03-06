#pragma once
enum PrintsOnThe
{
	_UpperHalf
};

enum Color {
	_RED,
	_BLACK
}; 

enum BankOrPulled {
	_BankCardsList,
	_ADrawnCardsList
};

enum LineInteger {
	_FirstLine = 0,
	_SecondLine = 4,
	_ThirdLine = 4 * 2,
	_FourthLine = 4 * 3,
	_FifthLine = 4 * 4,
	_SixthLine = 4 * 5,
	_SeventhLine = 4 * 6
};

enum TypeOfFoundationPileList {
	_SpadesShapedList,
	_HeartsShapedList,
	_DiamondsShapedList,
	_ClubsShapedList
};

enum TypeShapeOfCard {
	_SpadesShapedCard = 12,
	_HeartsShapedCard = 16,
	_DiamondsShapedCard = 20,
	_ClubsShapedCard = 24
};

enum WhichListIsIt {
	_FirstSpot,
	_SecondSpot,
	_ThirdSpot,
	_FourthSpot,
	_FifthSpot,
	_SixthSpot,
	_SeventhSpot,
	_BankCardsSpot,
	_SpadesShapedSpot,
	_HeartsShapedSpot,
	_DiamondsShapedSpot,
	_ClubsShapedSpot
};

enum ReachGoalToWin {
	_GoalToWin = 14
};