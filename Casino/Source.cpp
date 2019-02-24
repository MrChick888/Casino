#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <windows.h>

using namespace std;

void main_menu(int& main_menu_navigator);
void menu_option1(string& player_name, int& credits, int& color, int& credits_played, int& random_number);
void conditions_color_option1(string player_name, int& variable);
void conditions_credits_option1(string player_name, int credits, int& credits_played);
void draw_option1(int& random_number);
void conditions_result_option1(string player_name, int& credits, int credits_played, int color, int random_number);
void win_option1(string player_name, int& credits, int credits_played, int multiplier);
void lose_option1(string player_name, int& credits, int credits_played, string correct_color);
void p_c();

int main()
{
	int main_menu_navigator, credits, color, credits_played = 0, random_number;
	string player_name;
	while (1)
	{
		main_menu(main_menu_navigator);
		switch (main_menu_navigator)
		{
		case 1:
			menu_option1(player_name, credits, color, credits_played, random_number);
			break;
		case 2:
			//kod
		case 3:
			//kod
		default: break;
		}

	}
	system("PAUSE");
}
void main_menu(int& main_menu_navigator)
{
	cout << "ROULETTE GAME" << endl;
	cout << "=============" << endl;
	cout << "<<MAIN MENU>>" << endl;
	cout << "=============" << endl;
	cout << "1.Start a new game." << endl;
	cout << "2.Coutinue the game." << endl;
	cout << "3.Rule section." << endl;
	cout << "4.END." << endl;
	cout << "Enter: ";
	if (!(cin >> main_menu_navigator))
	{
		cout << "You can't enter anything other than a number here! " << endl;
		cout << "Restart program and try again." << endl;
		system("PAUSE");
		exit(0);
	}
	system("cls");
	return;
}
void menu_option1(string& player_name, int& credits, int& color, int& credits_played, int& random_number)
{
	credits = 50;
	cout << "WELCOME IN C++ CASINO." << endl;
	cout << "Enter your name: ";
	cin >> player_name;
	cout << "Good luck and have fun " << player_name << "." << endl;
	cout << "Your credits: " << credits << endl;
	cout << "Let's start the game!" << endl;
	cout << player_name << " choose color : " << endl;
	cout << "1.RED" << endl;
	cout << "2.GREEN" << endl;
	cout << "3.BLACK" << endl;
	conditions_color_option1(player_name, color);
	while (color < 1 || color>3)
	{
		system("cls");
		cout << "This option dosn't exits!" << endl;
		cout << player_name << " choose color : " << endl;
		cout << "1.RED" << endl;
		cout << "2.GREEN" << endl;
		cout << "3.BLUE" << endl;
		conditions_color_option1(player_name, color);
	}
	cout << "How many credits do you want to play? ";
	conditions_color_option1(player_name, credits_played);
	conditions_credits_option1(player_name, credits, credits_played);
	draw_option1(random_number);
	conditions_result_option1(player_name, credits, credits_played, color, random_number);

	return;
}
void conditions_color_option1(string player_name, int& variable)
{
	if (!(cin >> variable))
	{
		cout << player_name << " you can't enter anything other than a number here! " << endl;
		cout << "Restart program and try again." << endl;
		system("PAUSE");
		exit(0);
	}
}
void conditions_credits_option1(string player_name, int credits, int& credits_played)
{
	while (credits < credits_played || credits_played <= 0)//mo¿na lepiej na dwa przypadki
	{
		system("cls");
		cout << player_name << " you have only " << credits << " credits! You can't play for " << credits_played << "!" << endl;
		cout << "How many credits do you want to play? " << endl;
		conditions_color_option1(player_name, credits_played);
	}
}
void draw_option1(int& random_number)
{
	system("cls");
	cout << "The drawing machine begins the countdown." << endl;
	for (int i = 5; i > -2; i--)
	{
		Sleep(1000);//1000
		system("cls");
		cout << i;
	}
	system("cls");
	srand(time(NULL));
	random_number = rand() % 9 + 1;//99+1
}
void conditions_result_option1(string player_name, int& credits, int credits_played, int color, int random_number)
{
	if (random_number >= 1 && random_number <= 48)
	{
		if (color == 1)win_option1(player_name, credits, credits_played, 2);
		else lose_option1(player_name, credits, credits_played, "Red");
	}
	if (random_number >= 49 && random_number <= 51)
	{
		if (color == 2)win_option1(player_name, credits, credits_played, 14);
		else lose_option1(player_name, credits, credits_played, "Green");
	}
	if (random_number >= 52 && random_number <= 99)
	{
		if (color == 3)win_option1(player_name, credits, credits_played, 2);
		else lose_option1(player_name, credits, credits_played, "Black");
	}
}
void win_option1(string player_name, int& credits, int credits_played, int multiplier)
{
	cout << "YOU WON!, Well played " << player_name << "." << endl;
	cout << "You won " << credits_played * multiplier << "." << endl;
	credits += (credits_played * multiplier) - credits_played;
	cout << "Your credits: " << credits << endl;
	p_c();
	return;
}
void lose_option1(string player_name, int& credits, int credits_played, string correct_color)
{
	cout << "YOU LOST! Correct color is " << correct_color << " . You must try one more time " << player_name << "." << endl;
	credits -= credits_played;
	cout << "Your credits: " << credits << endl;
	if (credits == 0)
	{
		cout << "You lose this game :(" << endl;
		system("PAUSE");
		exit(0);
	}
	p_c();
	return;
}
void p_c()
{
	system("PAUSE");
	system("cls");
}
//zapisy!

