#include "UserInterface.h"

void CursorPlacementMethodForPrinting(HANDLE handleOutput, int leftForCursor, int topForCursor) {

	COORD coord;
	coord.X = leftForCursor;
	coord.Y = topForCursor;
	SetConsoleCursorPosition(handleOutput, coord);
}

UserInterface::UserInterface()
{
}

void UserInterface::RestartApplication()
{
	RestartApplicationSetUp();

	isPressed = false;
	while (!isPressed)
	{
		int userInput = _getch();
		if (userInput == 0xe0) { // for extended keys like a - z/F1 - F12. Not SHIFT/CAPS/CRTL
			userInput = _getch();
		}

		switch (userInput)
		{
		case KEY_UP:
			if (isYesTextHighlighted)
			{
				isYesTextHighlighted = false;
				PrintYesAnswer();
				PrintHighlightedNo();
			}
			else {
				isNoTextHighlighted = false;
				PrintNoAnswer();
				PrintYesAnswer();
			}
			break;

		case KEY_DOWN:
			if (!isNoTextHighlighted)
			{
				isNoTextHighlighted = true;
				PrintHighlightedNo();
			}
			else {
				isYesTextHighlighted = true;
				PrintNoAnswer();
				PrintHighlightedYes();
			}
			break;

		case KEY_ENTER:
			if (isYesTextHighlighted)
			{
				isPressed = true;
				isNoTextHighlighted = false;
				ShowCursor();
			}
			else if (isNoTextHighlighted) {
				system("CLS");
				PrintASCIITitle();
				CursorPlacementMethodForPrinting(handleOutput, 37, 14);
				cout << "Thanks for stopping by :)" << endl;
				SetConsoleTextAttribute(handleOutput, BLACK_COLOR);
				system("Pause");
				exit(0);
			}
			break;
		}
	}
}

void UserInterface::MainMenu()
{
	MainMenuSetUp();

	isPressed = false;
	while (!isPressed)
	{
		int userInput = _getch();
		if (userInput == 0xe0) { // for extended keys like a - z/F1 - F12. Not SHIFT/CAPS/CRTL
			userInput = _getch();
		}

		switch (userInput)
		{
		case KEY_UP:
			if (isASCIIExitHighlighted)
			{
				isASCIIExitHighlighted = false;
				PrintASCIIExit();
				PrintHighlightedASCIIPlay();
			}
			else {
				isASCIIPlayHighlighted = false;
				PrintASCIIPlay();
				PrintASCIIExit();
			}
			break;

		case KEY_DOWN:
			if (!isASCIIPlayHighlighted)
			{
				isASCIIPlayHighlighted = true;
				PrintHighlightedASCIIPlay();
			}
			else {
				isASCIIExitHighlighted = true;
				PrintASCIIPlay();
				PrintHighlightedASCIIExit();
			}
			break;

		case KEY_ENTER: {
			if (isASCIIExitHighlighted)
			{
				ClearExitFromConsole();
				PrintNoAnswer();
				PrintYesAnswer();

				bool isPressed = false;

				while (!isPressed)
				{
					int userInput = _getch();
					if (userInput == 0xe0) { // for extended keys like a - z/F1 - F12. Not SHIFT/CAPS/CRTL
						userInput = _getch();
					}

					switch (userInput)
					{
					case KEY_UP:
						if (isYesTextHighlighted)
						{
							isYesTextHighlighted = false;
							PrintYesAnswer();
							PrintHighlightedNo();
						}
						else {
							isNoTextHighlighted = false;
							PrintNoAnswer();
							PrintYesAnswer();
						}
						break;

					case KEY_DOWN:
						if (!isNoTextHighlighted)
						{
							isNoTextHighlighted = true;
							PrintHighlightedNo();
						}
						else {
							isYesTextHighlighted = true;
							PrintNoAnswer();
							PrintHighlightedYes();
						}
						break;

					case KEY_ENTER:
						if (isYesTextHighlighted)
						{
							ExitApplication();
						}
						else if (isNoTextHighlighted) {
							isPressed = true;
							isNoTextHighlighted = false;
							isASCIIPlayHighlighted = false;
							isASCIIExitHighlighted = false;
							PrintASCIIPlay();
							PrintASCIIExit();
						}
						break;
					}
				}
			}
			else if (isASCIIPlayHighlighted) {
				isPressed = true;
				GameInstructions();
			}
			break;
		}
		}
	}
}

void UserInterface::GameInstructions()
{
	GameInstructionsSetUp();

	int instructionsCounter = 1;

	isPressed = false;
	while (!isPressed)
	{
		++instructionsCounter;

		int userInput = _getch();
		if (userInput == 0xe0) { // for extended keys like a - z/F1 - F12. Not SHIFT/CAPS/CRTL
			userInput = _getch();
		}

		switch (userInput)
		{
		case KEY_SPACE:
		case KEY_ENTER:
			switch (instructionsCounter)
			{
			case 2:
				PrintGameInstructions2of6();
				break;
			case 3:
				PrintGameInstructions3of6();
				break;
			case 4:
				PrintGameInstructions4of6();
				break;
			case 5:
				PrintGameInstructions5of6();
				break;
			case 6:
				PrintGameInstructions6of6();
				break;
			default:
				isPressed = true;
				system("CLS");
				break;
			}
		}
	}
	ShowCursor();
}

UserInterface::~UserInterface()
{
}

void UserInterface::MainMenuSetUp()
{
	system("CLS");
	HideCursor();
	PrintASCIITitle();
	PrintRandomMightBeUnsolvable();
	PrintASCIIPlay();
	PrintASCIIExit();
	PrintMainMenuInstructionsControls();
}

void UserInterface::RestartApplicationSetUp()
{
	system("CLS");
	HideCursor();
	PrintASCIITitle();
	PrintRestartGameUI();
	PrintNoAnswer();
	PrintYesAnswer();
}

void UserInterface::GameInstructionsSetUp()
{
	system("CLS");
	PrintASCIIHowToPlayTitle();
	PrintGameInstructions1of6();
	PrintGameInstructionsControls();
}

void UserInterface::PrintRestartGameUI()
{
	CursorPlacementMethodForPrinting(handleOutput, 41, 8);
	cout << "Congratulations!";
	CursorPlacementMethodForPrinting(handleOutput, 31, 9);
	cout << "Would you like to restart the game?";
}

void UserInterface::PrintASCIIPlay()
{
	CursorPlacementMethodForPrinting(handleOutput, 38, 9);
	cout << " ____  _             ";
	CursorPlacementMethodForPrinting(handleOutput, 38, 10);
	cout << "|  _ \\| | __ _ _   _ ";
	CursorPlacementMethodForPrinting(handleOutput, 38, 11);
	cout << "| |_) | |/ _` | | | |";
	CursorPlacementMethodForPrinting(handleOutput, 38, 12);
	cout << "|  __/| | (_| | |_| |";
	CursorPlacementMethodForPrinting(handleOutput, 38, 13);
	cout << "|_|   |_|\\__,_|\\__, |";
	CursorPlacementMethodForPrinting(handleOutput, 38, 14);
	cout << "               |___/ ";
}

void UserInterface::PrintHighlightedASCIIPlay()
{
	SetConsoleTextAttribute(handleOutput, TURQUOISE_COLOR);
	CursorPlacementMethodForPrinting(handleOutput, 38, 9);
	cout << " ____  _             ";
	CursorPlacementMethodForPrinting(handleOutput, 38, 10);
	cout << "|  _ \\| | __ _ _   _ ";
	CursorPlacementMethodForPrinting(handleOutput, 38, 11);
	cout << "| |_) | |/ _` | | | |";
	CursorPlacementMethodForPrinting(handleOutput, 38, 12);
	cout << "|  __/| | (_| | |_| |";
	CursorPlacementMethodForPrinting(handleOutput, 38, 13);
	cout << "|_|   |_|\\__,_|\\__, |";
	CursorPlacementMethodForPrinting(handleOutput, 38, 14);
	cout << "               |___/ ";
	SetConsoleTextAttribute(handleOutput, WHITE_COLOR);
}

void UserInterface::PrintASCIIExit()
{
	CursorPlacementMethodForPrinting(handleOutput, 40, 17);
	cout << " _____      _ _   ";
	CursorPlacementMethodForPrinting(handleOutput, 40, 18);
	cout << "| ____|_  _(_) |_ ";
	CursorPlacementMethodForPrinting(handleOutput, 40, 19);
	cout << "|  _| \\ \\/ / | __|";
	CursorPlacementMethodForPrinting(handleOutput, 40, 20);
	cout << "| |___ >  <| | |_ ";
	CursorPlacementMethodForPrinting(handleOutput, 40, 21);
	cout << "|_____/_/\\_\\_|\\__|";
}

void UserInterface::PrintHighlightedASCIIExit()
{
	SetConsoleTextAttribute(handleOutput, TURQUOISE_COLOR);
	CursorPlacementMethodForPrinting(handleOutput, 40, 17);
	cout << " _____      _ _   ";
	CursorPlacementMethodForPrinting(handleOutput, 40, 18);
	cout << "| ____|_  _(_) |_ ";
	CursorPlacementMethodForPrinting(handleOutput, 40, 19);
	cout << "|  _| \\ \\/ / | __|";
	CursorPlacementMethodForPrinting(handleOutput, 40, 20);
	cout << "| |___ >  <| | |_ ";
	CursorPlacementMethodForPrinting(handleOutput, 40, 21);
	cout << "|_____/_/\\_\\_|\\__|";
	SetConsoleTextAttribute(handleOutput, WHITE_COLOR);
}

void UserInterface::ClearExitFromConsole()
{
	for (size_t i = 17; i < 22; i++)
	{
		CursorPlacementMethodForPrinting(handleOutput, 40, i);
		cout << "                   ";
	}
}

void UserInterface::PrintYesAnswer()
{
	CursorPlacementMethodForPrinting(handleOutput, 47, 19);
	cout << "Yes";
}

void UserInterface::PrintHighlightedYes()
{
	SetConsoleTextAttribute(handleOutput, TURQUOISE_COLOR);
	CursorPlacementMethodForPrinting(handleOutput, 47, 19);
	cout << "Yes";
	SetConsoleTextAttribute(handleOutput, WHITE_COLOR);
}

void UserInterface::PrintNoAnswer()
{
	CursorPlacementMethodForPrinting(handleOutput, 47, 17);
	cout << "No";
}

void UserInterface::PrintHighlightedNo()
{
	SetConsoleTextAttribute(handleOutput, TURQUOISE_COLOR);
	CursorPlacementMethodForPrinting(handleOutput, 47, 17);
	cout << "No";
	SetConsoleTextAttribute(handleOutput, WHITE_COLOR);
}

void UserInterface::PrintASCIITitle()
{
	SetConsoleTextAttribute(handleOutput, LIGHT_BLUE);
	CursorPlacementMethodForPrinting(handleOutput, 20, 0);
	cout << " _____  _____ _     _____ _____ ___  ___________ _____ ";
	CursorPlacementMethodForPrinting(handleOutput, 20, 1);
	cout << "/  ___||  _  | |   |_   _|_   _/ _ \\|_   _| ___ \\  ___|";
	CursorPlacementMethodForPrinting(handleOutput, 20, 2);
	cout << "\\ `--. | | | | |     | |   | |/ /_\\ \\ | | | |_/ / |__  ";
	CursorPlacementMethodForPrinting(handleOutput, 20, 3);
	cout << " `--. \\| | | | |     | |   | ||  _  | | | |    /|  __| ";
	CursorPlacementMethodForPrinting(handleOutput, 20, 4);
	cout << "/\\__/ /\\ \\_/ / |_____| |_  | || | | |_| |_| |\\ \\| |___ ";
	CursorPlacementMethodForPrinting(handleOutput, 20, 5);
	cout << "\\____/  \\___/\\_____/\\___/  \\_/\\_| |_/\\___/\\_| \\_\\____/ ";
	CursorPlacementMethodForPrinting(handleOutput, 20, 6);
	cout << "------------------------------------------------------";
	SetConsoleTextAttribute(handleOutput, WHITE_COLOR);
}

void UserInterface::PrintASCIIHowToPlayTitle()
{
	SetConsoleTextAttribute(handleOutput, LIGHT_BLUE);
	CursorPlacementMethodForPrinting(handleOutput, 20, 0);
	cout << " _   _                 _                _             ";
	CursorPlacementMethodForPrinting(handleOutput, 20, 1);
	cout << "| | | |               | |              | |            ";
	CursorPlacementMethodForPrinting(handleOutput, 20, 2);
	cout << "| |_| | _____      __ | |_ ___    _ __ | | __ _ _   _ ";
	CursorPlacementMethodForPrinting(handleOutput, 20, 3);
	cout << "|  _  |/ _ \\ \\ /\\ / / | __/ _ \\  | '_ \\| |/ _` | | | |";
	CursorPlacementMethodForPrinting(handleOutput, 20, 4);
	cout << "| | | | (_) \\ V  V /  | || (_) | | |_) | | (_| | |_| |";
	CursorPlacementMethodForPrinting(handleOutput, 20, 5);
	cout << "\\_| |_/\\___/ \\_/\\_/    \\__\\___/  | .__/|_|\\__,_|\\__, |";
	CursorPlacementMethodForPrinting(handleOutput, 20, 6);
	cout << "                                 | |             __/ |";
	CursorPlacementMethodForPrinting(handleOutput, 20, 7);
	cout << "                                 |_|            |___/ ";
	CursorPlacementMethodForPrinting(handleOutput, 20, 8);
	cout << "------------------------------------------------------";
	SetConsoleTextAttribute(handleOutput, WHITE_COLOR);
}

void UserInterface::PrintGameInstructions1of6()
{
	CursorPlacementMethodForPrinting(handleOutput, 2, 11);
	cout << "The goal is to create a stack of cards from low to high, in each of the four foundation piles.";
	CursorPlacementMethodForPrinting(handleOutput, 30, 12);
	cout << "Each pile can contain only one suit.";
}

void UserInterface::PrintGameInstructions2of6()
{
	CursorPlacementMethodForPrinting(handleOutput, 31, 14);
	cout << "Aces are low and kings are high.";
	CursorPlacementMethodForPrinting(handleOutput, 15, 15);
	cout << "The four foundation piles must begin with aces and end with kings.";
}

void UserInterface::PrintGameInstructions3of6()
{
	CursorPlacementMethodForPrinting(handleOutput, 12, 17);
	cout << "Below the foundation piles, you can move cards from one column to another.";
	CursorPlacementMethodForPrinting(handleOutput, 2, 18);
	cout << "Cards in columns must be placed in descending order and must alternate between red and black.";
	CursorPlacementMethodForPrinting(handleOutput, 24, 19);
	cout << "For example, you can put a black 9 on a red 10.";
}

void UserInterface::PrintGameInstructions4of6()
{
	CursorPlacementMethodForPrinting(handleOutput, 15, 21);
	cout << "You can also move sequential runs of the cards between columns.";
	CursorPlacementMethodForPrinting(handleOutput, 15, 22);
	cout << "Just tap the deepest card in the run and tap on another column.";
}

void UserInterface::PrintGameInstructions5of6()
{
	CursorPlacementMethodForPrinting(handleOutput, 17, 24);
	cout << "If you ever have an empty column, you can place a king there";
	CursorPlacementMethodForPrinting(handleOutput, 21, 25);
	cout << "or any sequential stack with a king at its head.";
}

void UserInterface::PrintGameInstructions6of6()
{
	CursorPlacementMethodForPrinting(handleOutput, 6, 27);
	cout << "If you get stuck, tap the 'bank deck' in the upper-left corner to draw more cards.";
	CursorPlacementMethodForPrinting(handleOutput, 8, 28);
	cout << "If you exahust the deck, you can deal it again by tapping the empty deck space.";
}

void UserInterface::PrintRandomMightBeUnsolvable()
{
	CursorPlacementMethodForPrinting(handleOutput, 0, 30);
	cout << "*My Solitaire's shuffle is random, the deck might be unsolvable.";
}

void UserInterface::PrintGameInstructionsControls()
{
	CursorPlacementMethodForPrinting(handleOutput, 0, 33);
	cout << "Use the - Enter - or the - Space - keys to continue.";
}

void UserInterface::PrintMainMenuInstructionsControls()
{
	CursorPlacementMethodForPrinting(handleOutput, 0, 27);
	cout << "Use the - UpArrow - and the - DownArrow - keys to navigate.";
	CursorPlacementMethodForPrinting(handleOutput, 0, 28);
	cout << "Use the - Enter - key to choose.";
}

void UserInterface::PrintDeckControls()
{
	CursorPlacementMethodForPrinting(handleOutput, 0, 27);
	cout << "Use the - Arrows - keys to navigate.";
	CursorPlacementMethodForPrinting(handleOutput, 0, 28);
	cout << "Use the - Enter - or the - Space - keys to select.";
	CursorPlacementMethodForPrinting(handleOutput, 0, 29);
	cout << "*Double tap a selected card to insert to its pile";
	CursorPlacementMethodForPrinting(handleOutput, 0, 30);
	cout << "Use the - R - key to reset the deck.";
	CursorPlacementMethodForPrinting(handleOutput, 0, 31);
	cout << "Use the - ESC - key to exit the application.";
}

void UserInterface::ExitApplication()
{
	system("CLS");
	HideCursor();
	PrintASCIITitle();
	CursorPlacementMethodForPrinting(handleOutput, 37, 14);
	cout << "Thanks for stopping by :)" << endl;
	SetConsoleTextAttribute(handleOutput, BLACK_COLOR);
	system("Pause");
	exit(0);
}

void UserInterface::HideCursor()
{
	consoleCursorController.bVisible = 0;
	consoleCursorController.dwSize = 100;
	SetConsoleCursorInfo(handleOutput, &consoleCursorController);
}

void UserInterface::ShowCursor()
{
	consoleCursorController.bVisible = 1;
	consoleCursorController.dwSize = 1;
	SetConsoleCursorInfo(handleOutput, &consoleCursorController);
}