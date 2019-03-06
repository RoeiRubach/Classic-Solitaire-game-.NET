#pragma once
#include <iostream>
#include <iomanip>
#include <windows.h> // --- HANDLE
#include <conio.h> // --- _getch


#define BLACK_COLOR 0
#define TURQUOISE_COLOR 3 // --- Highlight
#define LIGHT_BLUE 9 // --- Title
#define KEY_ENTER 13
#define LIGHT_YELLOW 14 // --- Instructions
#define WHITE_COLOR 15
#define KEY_SPACE 32
#define KEY_UP 72
#define KEY_DOWN 80

using namespace std;

class UserInterface
{
public:
	UserInterface();

	void RestartApplication();
	void MainMenu();
	void GameInstructions();
	void PrintDeckControls();
	void ExitApplication();

	~UserInterface();
	HANDLE handleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

private:
	CONSOLE_CURSOR_INFO consoleCursorController;

	void MainMenuSetUp();
	void RestartApplicationSetUp();
	void GameInstructionsSetUp();
	void PrintRestartGameUI();
	void PrintASCIIPlay();
	void PrintHighlightedASCIIPlay();
	void PrintASCIIExit();
	void PrintHighlightedASCIIExit();
	void PrintASCIITitle();
	void PrintASCIIHowToPlayTitle();
	void PrintGameInstructions1of6();
	void PrintGameInstructions2of6();
	void PrintGameInstructions3of6();
	void PrintGameInstructions4of6();
	void PrintGameInstructions5of6();
	void PrintGameInstructions6of6();
	void PrintRandomMightBeUnsolvable();
	void PrintGameInstructionsControls();
	void PrintMainMenuInstructionsControls();
	void HideCursor();
	void ShowCursor();
	void ClearExitFromConsole();
	void PrintYesAnswer();
	void PrintHighlightedYes();
	void PrintNoAnswer();
	void PrintHighlightedNo();

	bool isASCIIPlayHighlighted = false, isASCIIExitHighlighted = false;
	bool isYesTextHighlighted = false, isNoTextHighlighted = false;
	bool isPressed = false;
};