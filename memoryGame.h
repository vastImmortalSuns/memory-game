#pragma once
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <windows.h>

using namespace std;

class memoryGame		// Thanks for checking this out. If you have any ideas/questions
{						// feel free to email me at jenkinsb1@spu.edu
public:
	void run();
	void initializeMenu();
	void checkInput(string inp);
	void startGame();

	void runLvlOne();
	void runLvlTwo();
	void runLvlThree();
	void runLvlFour();
	void runLvlFive();

	void distinguish(int lvlNum);
	void createPicture(int selector, int marker);

	void formatBody();
	void formatGuess(int lvlNum);
	void exit();

private:
	int curLvl = 0;
	int numVars = 5;
	int picOne, picTwo, picThree, picFour, picFive;
};

void memoryGame::run()
{
	string input;
	initializeMenu();

	cout << "\n\n\t\t\t\t\t\t\t Do you want to play? If so, enter \"Yes\". If not, enter \"No\".\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t       ";
	cin >> input;
	checkInput(input);
}

void memoryGame::initializeMenu()
{
	cout << "\t\t\t\t\t\t\t\t\t\t      --" << endl;
	cout << "\t\t\t\t\t    _     B     _     E     _     N     _     ||     _     S     _     P     _     U     _" << endl;
	cout << "\t\t\t\t\t   / \\___/ \\___/ \\___/ \\___/ \\___/ \\___/ \\___/  \\___/ \\___/ \\___/ \\___/ \\___/ \\___/ \\___/ \\ " << endl;
	cout << "\t\t\t\t\t  |   __________     _______      _______			    		 ________  |" << endl;
	cout << "\t\t\t\t\t  |  |____  ____|   /    	 |       \\   ||\\\\      //||   ||\\\\      //||   ||          |" << endl;
	cout << "\t\t\t\t\t  |	  ||       /    _____    | ____ _/   || \\\\    // ||   || \\\\    // ||   ||________  |" << endl;
	cout << "\t\t\t\t\t  | 	  ||	   \\         |   ||    \\\\    ||  \\\\  //  ||   ||  \\\\  //  ||   ||          |" << endl;
	cout << "\t\t\t\t\t  | 	  ||	    \\_______/    ||     \\\\   ||   \\\\//   ||   ||   \\\\//   ||   ||________  |" << endl;
	cout << "\t\t\t\t\t  |											   |" << endl;
	cout << "\t\t\t\t\t  |    ________    __________		         ________   		       ________    |" << endl;
	cout << "\t\t\t\t\t  |  ||           |____  ____|   |         |   ||            ||\\\\      ||     /        \\   |" << endl;
	cout << "\t\t\t\t\t  |  ||________        ||        |         |   ||________    ||  \\\\    ||    /          \\  |" << endl;
	cout << "\t\t\t\t\t  |  ||		       ||        |         |   ||            ||    \\\\  ||    \\	        /  |" << endl;
	cout << "\t\t\t\t\t  |  ||                ||         \\_______/    ||            ||      \\\\||     \\________/   |" << endl;
	cout << "\t\t\t\t\t  |                                                                                        |" << endl;
	cout << "\t\t\t\t\t  |			   ________          _______          ____		           |" << endl;
	cout << "\t\t\t\t\t  |			  / 	   \\       ||       \\        /    \\                        |" << endl;
	cout << "\t\t\t\t\t  |		         /                 ||_______/        \\____		           |" << endl;
	cout << "\t\t\t\t\t  |		         \\	           ||       \\	          \\			   |" << endl;
	cout << "\t\t\t\t\t  |			  \\________/       ||_______/        \\____/			   |" << endl;
	cout << "\t\t\t\t\t  |				  			       				   |" << endl;
	cout << "\t\t\t\t\t  |					  		       				   |" << endl;
	cout << "\t\t\t\t\t  |		         (This Game Requires Massive Mental Energy)			   |" << endl;
	cout << "\t\t\t\t\t  |			        (From The User For Not Only)				   |" << endl;
	cout << "\t\t\t\t\t  |			       (Completion  But Satisfaction)				   |" << endl;
	cout << "\t\t\t\t\t  |   ___   ___   ___   ___   ___   ___   ___    ___   ___   ___   ___   ___   ___   ___   |" << endl;
	cout << "\t\t\t\t\t   \\_/   \\_/   \\_/   \\_/   \\_/   \\_/   \\_/   \\  /   \\_/   \\_/   \\_/   \\_/   \\_/   \\_/   \\_/" << endl;
	cout << "\t\t\t\t\t          A           D           V           ||           P           R           O" << endl;
}

void memoryGame::checkInput(string inp)
{
	string input; 

	if (inp == "yes" || inp == "Yes")
	{
		startGame();
	}
	else if (inp == "no" || inp == "No")
	{
		cout << "Goodbye!" << endl;
	}
	else
	{
		cout << "I didn't catch that, please enter either \"Yes\" or \"No\"." << endl;
		cin >> input;
		checkInput(input);
	}
}

void memoryGame::startGame()
{
	srand(time(NULL));
	runLvlOne();
}

void memoryGame::runLvlOne()
{
	int guess;
	int level = 1;

	distinguish(level);		// Displays the picture to the user and 
	formatBody();			// formats the text to align in the middle
							// of the screen.
	cout << "\n\t\t\t\t\t\t\t\t\t  What was the picture you saw? \n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t";
	cin >> guess;

	if (guess == picOne)	
	{
		level++;
		formatGuess(level);	// If the user guessed correctly, format 
		runLvlTwo();			// the next section fo text properly and
	}							// run the next level.
	else
		exit();
		cout << endl;
}

void memoryGame::runLvlTwo()
{
	int guess;
	int level = 2;

	distinguish(level);
	formatBody();

	cin >> guess;

	if (guess == picOne)	
	{
		cout << "\n\t\t\t\t\t\t\t\t   Correct! What was the second picture you saw? \n" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t";
		cin >> guess;

		if (guess == picTwo)
		{
			level++;
			formatGuess(level);
			runLvlThree();
		}
		else
			exit();
	}
	else
		exit();
}

void memoryGame::runLvlThree()
{
	int guess;
	int level = 3;

	distinguish(level);
	formatBody();

	cin >> guess;

	if (guess == picOne)
	{
		cout << "\n\t\t\t\t\t\t\t\t   Correct! What was the second picture you saw?\n" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t";
		cin >> guess;

		if (guess == picTwo)
		{
			cout << "\n\t\t\t\t\t\t\t\t   Correct! What was the second picture you saw?\n" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t";
			cin >> guess;

			if (guess == picThree)
			{
				level++;
				formatGuess(level);
				runLvlFour();
			}
			else
				exit();
		}
		else
			exit();
	}
	else
		exit();
}

void memoryGame::runLvlFour()
{
	int guess;
	int level = 4;

	distinguish(level);
	formatBody();

	cin >> guess;

	if (guess == picOne)
	{
		cout << "\n\t\t\t\t\t\t\t\t   Correct! What was the second picture you saw?\n" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t";
		cin >> guess;

		if (guess == picTwo)
		{
			cout << "\n\t\t\t\t\t\t\t\t   Correct! What was the second picture you saw?\n" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t";
			cin >> guess;

			if (guess == picThree)
			{
				cout << "\n\t\t\t\t\t\t\t\t   Correct! What was the second picture you saw?\n" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t";
				cin >> guess;

				if (guess == picFour)
				{
					level++;
					formatGuess(level);
					runLvlFive();
				}
				else
					exit();
			}
			else
				exit();
		}
		else
			exit();
	}
	else
		exit();
}

void memoryGame::runLvlFive()
{
	int guess;
	int level = 5;

	distinguish(level);
	formatBody();

	cin >> guess;

	if (guess == picOne)
	{
		cout << "\n\t\t\t\t\t\t\t\t   Correct! What was the second picture you saw?\n" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t";
		cin >> guess;

		if (guess == picTwo)
		{
			cout << "\n\t\t\t\t\t\t\t\t   Correct! What was the second picture you saw?\n" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t";
			cin >> guess;

			if (guess == picThree)
			{
				cout << "\n\t\t\t\t\t\t\t\t   Correct! What was the second picture you saw?\n" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t";
				cin >> guess;

				if (guess == picFour)
				{
					cout << "\n\t\t\t\t\t\t\t\t   Correct! What was the second picture you saw?\n" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t";
					cin >> guess;

					if (guess != picFive)
					{
						cout << "\n\t\t\t\t\t\t\t\t\t\t     You win!" << endl;
					}
				}
				else
					exit();
			}
			else
				exit();
		}
		else
			exit();
	}
	else
		exit();
}

void memoryGame::distinguish(int lvlNum)
{
	int picID = 1;

	picOne = rand() % numVars + 1;
	picTwo = rand() % numVars + 1;
	picThree = rand() % numVars + 1;
	picFour = rand() % numVars + 1;
	picFive = rand() % numVars + 1;

	if (lvlNum == 1)
	{
		createPicture(picOne, picID);
	}
	else if (lvlNum == 2)
	{
		createPicture(picOne, picID);
		picID++;
		createPicture(picTwo, picID);
	}
	else if (lvlNum == 3)
	{
		createPicture(picOne, picID);
		picID++;
		createPicture(picTwo, picID);
		picID++;
		createPicture(picThree, picID);
	}
	else if (lvlNum == 4)
	{
		createPicture(picOne, picID);
		picID++;
		createPicture(picTwo, picID);
		picID++;
		createPicture(picThree, picID);
		picID++;
		createPicture(picFour, picID);
	}
	else if (lvlNum == 5)
	{
		createPicture(picOne, picID);
		picID++;
		createPicture(picTwo, picID);
		picID++;
		createPicture(picThree, picID);
		picID++;
		createPicture(picFour, picID);
		picID++;
		createPicture(picFour, picID);
	}
}

void memoryGame::createPicture(int selector, int picID)
{
	if (selector == 1)
	{
		cout << "\t\t\t\t\t\t\t\t\t   _______" << endl;
		cout << "\t\t\t\t\t\t\t\t\t  |\\_     |        ___________" << endl;
		cout << "\t\t\t\t\t\t\t\t\t  || \\ _  |       /           \\" <<  endl;
		cout << "\t\t\t\t\t\t\t\t\t  | \\_(_) |	  | Picture " << picID << " |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t  | (_)   |       \\___________/" << endl;
		cout << "\t\t\t\t\t\t\t\t\t  |_______|" << endl;
	}

	else if (selector == 2)
	{
		cout << "\t\t\t\t\t\t\t\t\t   _______" << endl;
		cout << "\t\t\t\t\t\t\t\t\t  | _____ |        ___________" << endl;
		cout << "\t\t\t\t\t\t\t\t\t  ||     ||       /           \\" << endl;
		cout << "\t\t\t\t\t\t\t\t\t  ||*BAR*||	  | Picture " << picID << " |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t  ||_____||       \\___________/" << endl;
		cout << "\t\t\t\t\t\t\t\t\t  |_______|" << endl;
	}

	else if (selector == 3)
	{
		cout << "\t\t\t\t\t\t\t\t\t   _______" << endl;
		cout << "\t\t\t\t\t\t\t\t\t  |  ___  |        ___________" << endl;
		cout << "\t\t\t\t\t\t\t\t\t  | |_  | |       /           \\" << endl;
		cout << "\t\t\t\t\t\t\t\t\t  |  / /  |	  | Picture " << picID << " |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t  | /_/   |       \\___________/" << endl;
		cout << "\t\t\t\t\t\t\t\t\t  |_______|" << endl;
	}

	else if (selector == 4)
	{
		cout << "\t\t\t\t\t\t\t\t\t   _______" << endl;
		cout << "\t\t\t\t\t\t\t\t\t  |   _   |        ___________" << endl;
		cout << "\t\t\t\t\t\t\t\t\t  | _( )_ |       /           \\" << endl;
		cout << "\t\t\t\t\t\t\t\t\t  |/\\   /\\|       | Picture " << picID << " |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t  |  \\_/  |       \\___________/" << endl;
		cout << "\t\t\t\t\t\t\t\t\t  |__| |__|" << endl;
	}

	else if (selector == 5)
	{
		cout << "\t\t\t\t\t\t\t\t\t   _______" << endl;
		cout << "\t\t\t\t\t\t\t\t\t  |     __|        ___________" << endl;
		cout << "\t\t\t\t\t\t\t\t\t  |    / /|       /           \\" << endl;
		cout << "\t\t\t\t\t\t\t\t\t  | /\\/ / |       | Picture " << picID << " |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t  | \\  /  |       \\___________/" << endl;
		cout << "\t\t\t\t\t\t\t\t\t  |__\\/___| " << endl;
	}
}

void memoryGame::formatBody()
{
	cout << "\n\t\t\t\t\t\t\t\t\tThe picture will disappear in 3.. " << endl;
	Sleep(1250);
	cout << "\t\t\t\t\t\t\t\t\t\t\t2.. " << endl;
	Sleep(1250);
	cout << "\t\t\t\t\t\t\t\t\t\t\t1.. \n" << endl;
	Sleep(1250);

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" <<
			"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" <<
			"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;

	cout << "\t\t\t\t\t\t\t     If the picture you just saw was a Cherry, type \"Cherry\"." << endl;
	cout << "\t\t\t\t\t\t\t\t\tIf it was a BAR block, type \"BAR\"." << endl;
	cout << "\t\t\t\t\t\t\t\t\tIf it was a large 7, type \"Seven\"." << endl;
	cout << "\t\t\t\t\t\t\t\t\tIf it was a small man, type \"Man\"." << endl;
	cout << "\t\t\t\t\t\t\t\t     If it was a checkmark, type \"Checkmark\".\n\n\n" << endl;

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t";
}

void memoryGame::formatGuess(int lvlNum)
{
	cout << "\n\t\t\t\t\t\t\t\t\tCorrect! Level " << lvlNum << " will begin in 3.. " << endl;
	Sleep(1250);
	cout << "\t\t\t\t\t\t\t\t\t\t\t2.. " << endl;
	Sleep(1250);
	cout << "\t\t\t\t\t\t\t\t\t\t\t1.. \n" << endl;
	Sleep(1250);
}

void memoryGame::exit()
{
	cout << "\t\t\t\t\t\t\t      That was incorrect! If you want to quit, type \"quit\"." << endl;
	cout << "\t\t\t\t\t\t\t      If you want to return to the main menu, type \"Menu\"." << endl;
}