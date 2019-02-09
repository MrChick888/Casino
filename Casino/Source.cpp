#include <iostream>
#include <string>
#include <ctime>

using namespace std;

void menu();
void p_c();
void menu2();
void chance();
void how_much();
int main()
{
	int navigator=0,navigator_2=0,credits=50,random, credits_now=0;
	string game_name,player_name;
	char end_option, color, wl_option;
	bool while1end = false, while2end = false;
	while (1)
	{
		menu();
		cin >> navigator;
		system("cls");
		switch (navigator)
		{
		case 1:
			while (while1end==false)
			{
				cout << "WELCOME IN C++ CASINO." << endl;
				cout << "Enter your name: ";
				cin >> player_name;
				cout << "Good luck and have fun " << player_name << "." << endl;
				cout << "Your credits: " << credits << endl;
				cout << "Let's start the game!" << endl;
				cout << player_name << " choose color (Red/Green/Black): ";
				cin >> color;
				cout << "How many credits do you want to play? ";
				cin >> credits_now;
				while (credits < credits_now || credits_now < 0)
				{
					system("cls");
					cout << player_name << " you have only " << credits << " credits! You can't play for " << credits_now << "!" << endl;
					cout << "How many credits do you want to play? " << endl;
					cin >> credits_now;
				}
				cout << "The drawing machine begins the countdown." << endl;
				for (int i = 10; i > -2; i--)
				{
					_sleep(10);
					system("cls");
					cout << i;
				}
				srand(time(NULL));
				random = rand() % 100 + 1;
				if (random >= 1 && random <= 48 && (color == 'R' || color == 'r'))
				{
					system("cls");
					cout << "YOU WON!, Well played " << player_name << "." << endl;
					cout << "You won " << credits_now * 2 << "." << endl;
					cout << "Your credits: " << credits + credits_now * 2 << endl;
					cout << player_name << " you want to play again (a) or save game and return to main menu(r)? ";
					cin >> wl_option;
					if (wl_option == 'A' || wl_option == 'a')
					{
						// NWM JAK ZROBIÆ OPCJE PONOWNA GRA/MENU G£ÓWNE
					}
					if (wl_option == 'R' || wl_option == 'r')
					{
						// NWM JAK ZROBIÆ OPCJE PONOWNA GRA/MENU G£ÓWNE
					}
					else
					{
						cout << "THIS OPTION DOESN'T EXIST!" << endl;
						cout << "Try one more time." << endl;
						p_c();
					}
				}
				if (random >= 1 && random <= 48 && (color != 'R' || color != 'r'))
				{
					system("cls");
					cout << "YOU LOST! Correct color is Red" << endl;
					cout << "Your credits: " << credits - credits_now;
					if (credits_now < 0)
					{
						cout << "You lose this game :(" << endl;
						system("PAUSE");
						exit(0);
					}
					break;
				}
				if (random >= 49 && random <= 51 && (color == 'G' || color == 'g'))
				{
					system("cls");
					cout << "YOU WON!, Well played " << player_name << "." << endl;
					cout << "You won " << credits_now * 14 << "." << endl;
					cout << "Your credits: " << credits + credits_now * 14 << endl;
					break;
				}
				if (random >= 49 && random <= 51 && (color != 'G' || color != 'g'))
				{
					system("cls");
					cout << "YOU LOST! Correct color is Green" << endl;
					cout << "Your credits: " << credits - credits_now;
					if (credits_now < 0)
					{
						cout << "You lose this game :(" << endl;
						system("PAUSE");
						exit(0);
					}
					break;
				}
				if (random >= 52 && random <= 100 && (color == 'B' || color == 'b'))
				{
					system("cls");
					cout << "YOU WON!, Well played " << player_name << "." << endl;
					cout << "You won " << credits_now * 2 << "." << endl;
					cout << "Your credits: " << credits + credits_now * 2 << endl;
					break;
				}
				if (random >= 52 && random <= 100 && (color != 'B' || color != 'b'))
				{
					system("cls");
					cout << "YOU LOST! Correct color is Black" << endl;
					cout << "Your credits: " << credits - credits_now;
					if (credits_now < 0)
					{
						cout << "You lose this game :(" << endl;
						system("PAUSE");
						exit(0);
					}
					break;
				}
				else
				{
					system("cls");
					cout << "Something has failed.";
					break;
				}
			}
		case 2:
			while (while2end==false)
			{
				menu2();
				cin >> navigator_2;
				system("cls");
				switch (navigator_2)
				{
				case 1:
					chance(); p_c(); while2end = true; break;
				case 2:
					how_much(); p_c(); while2end = true; break;
				case 3:
					cout << "So, let's go back to the main menu." << endl;
					p_c(); while2end = true; break;
				default:
					cout << "THIS OPTION DOESN'T EXIST!" << endl;
					cout << "Try one more time." << endl;
					p_c();
				}
			}while2end = false; break;
		case 3:
			while (1)
			{
				cout << "DO YOU REALLY WANT TO LEAVE THE CASINO?" << endl;
				cout << "Choose Y/N: ";
				cin >> end_option;
				if (end_option == 'Y' || end_option == 'y')
				{
					cout << "SEE YOU SOON." << endl;
					system("PAUSE");
					exit(0);
				}
				if (end_option == 'N' || end_option == 'n')
				{
					cout << "So, let's go back to the main menu." << endl;
					p_c();break;
				}
				else
				{
					cout << "THIS OPTION DOESN'T EXIST!" << endl;
					cout << "Try one more time." << endl;
					p_c();
				}
			}break;
		default:
			cout << "THIS OPTION DOESN'T EXIST!" << endl;
			cout << "Try one more time." << endl;
			p_c(); break;
		}
	}
	system("PAUSE");
}
void menu()
{
	cout << "ROULETTE GAME" << endl;
	cout << "=============" << endl;
	cout << "<<MAIN MENU>>" << endl;
	cout << "=============" << endl;
	cout << "1.Start a new game." << endl;
	cout << "2.Rule section." << endl;
	cout << "3.END." << endl;
	cout << "Enter: ";
}
void p_c()
{
	system("PAUSE");
	system("cls");
}
void menu2()
{
	cout << "WELCOME IN RULE SECTION." << endl;
	cout << "1.Chance to win." << endl;
	cout << "2.How much I can win." << endl;
	cout << "3.Go back to menu." << endl;
	cout << "Enter: ";
}
void chance()
{
cout << "==========" << endl;
cout << "==CHANCE==" << endl;
cout << "==========" << endl;
cout << "If you bet on RED, you have 48,5% chance to win. Tickets - (1-48) " << endl;
cout << "If you bet on GREEN, you have 3% chance to win. Tickets - (49-51)" << endl;
cout << "If you bet on BLACK, you have 48,5% chance to win. Tickets - (52-100)" << endl;
}
void how_much()
{
	cout << "======================" << endl;
	cout << "==HOW MUCH I CAN WIN==" << endl;
	cout << "======================" << endl;
	cout << "If you bet on RED, you can win 2 times more." << endl;
	cout << "If you bet on GREEN, you can win 14 times more." << endl;
	cout << "If you bet on BLACK, you can win 2 times more." << endl;
}