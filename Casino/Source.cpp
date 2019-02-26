#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <windows.h>
#include <sstream>
using namespace std;

void main_menu(int& main_menu_navigator);
void menu_option1(string& player_name, int& credits, int& color, int& credits_played, int& random_number, fstream& save, string& game_name);
void conditions_color_option(string player_name, int& variable);
void conditions_credits_option(string player_name, int credits, int& credits_played);
void draw_option(int& random_number);
void conditions_result_option1(string player_name, int& credits, int credits_played, int color, int random_number, fstream& save, string& game_name);
void win_option1(string player_name, int& credits, int credits_played, int multiplier);
void lose_option1(string player_name, int& credits, int credits_played, string correct_color);
void p_c();
void save_option1(fstream& save, string& game_name, string player_name, int credits);
void reading_from_a_file(string Save[], string Nick[], int Credits[], int &selected_save, string& player_name, int& credits);
void menu_option2(string player_name, int& credits, int credits_played, int color, int random_number);
void conditions_result_option2(string player_name, int& credits, int credits_played, int color, int random_number);
void save_option2(fstream& save, string game_name, string player_name, int credits);

int main()
{
	int main_menu_navigator, credits, color, credits_played = 0, random_number, selected_save;
	string player_name, game_name;
	fstream save;
	string Save[10], Nick[10];
	int Credits[10];
	while (1)
	{
		main_menu(main_menu_navigator);
		switch (main_menu_navigator)
		{
		case 1:
			menu_option1(player_name, credits, color, credits_played, random_number, save, game_name);
			break;
		case 2:
			reading_from_a_file(Save, Nick, Credits, selected_save, player_name, credits);
			menu_option2(player_name, credits, credits_played, color, random_number);
			break;
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
void menu_option1(string& player_name, int& credits, int& color, int& credits_played, int& random_number, fstream& save, string& game_name)
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
	conditions_color_option(player_name, color);
	while (color < 1 || color>3)
	{
		system("cls");
		cout << "This option dosn't exits!" << endl;
		cout << player_name << " choose color : " << endl;
		cout << "1.RED" << endl;
		cout << "2.GREEN" << endl;
		cout << "3.BLUE" << endl;
		conditions_color_option(player_name, color);
	}
	cout << "How many credits do you want to play? ";
	conditions_color_option(player_name, credits_played);
	conditions_credits_option(player_name, credits, credits_played);
	draw_option(random_number);
	conditions_result_option1(player_name, credits, credits_played, color, random_number, save, game_name);
	return;
}
void conditions_color_option(string player_name, int& variable)
{
	if (!(cin >> variable))
	{
		cout << player_name << " you can't enter anything other than a number here! " << endl;
		cout << "Restart program and try again." << endl;
		system("PAUSE");
		exit(0);
	}
	return;
}
void conditions_credits_option(string player_name, int credits, int& credits_played)
{
	while (credits < credits_played || credits_played <= 0)//mo¿na lepiej na dwa przypadki
	{
		system("cls");
		cout << player_name << " you have only " << credits << " credits! You can't play for " << credits_played << "!" << endl;
		cout << "How many credits do you want to play? " << endl;
		conditions_color_option(player_name, credits_played);
	}
	return;
}
void draw_option(int& random_number)
{
	system("cls");
	cout << "The drawing machine begins the countdown." << endl;
	for (int i = 5; i > -2; i--)
	{
		Sleep(500);//1000 to 1 sekunda
		system("cls");
		cout << i;
	}
	system("cls");
	srand(time(NULL));
	random_number = rand() % 99 + 1;
	return;
}
void conditions_result_option1(string player_name, int& credits, int credits_played, int color, int random_number, fstream& save, string& game_name)
{
	if (random_number >= 1 && random_number <= 48)
	{
		if (color == 1)win_option1(player_name, credits, credits_played, 2);
		else lose_option1(player_name, credits, credits_played, "Red");
		save_option1(save, game_name, player_name, credits);
	}
	if (random_number >= 49 && random_number <= 51)
	{
		if (color == 2)win_option1(player_name, credits, credits_played, 14);
		else lose_option1(player_name, credits, credits_played, "Green");
		save_option1(save, game_name, player_name, credits);
	}
	if (random_number >= 52 && random_number <= 99)
	{
		if (color == 3)win_option1(player_name, credits, credits_played, 2);
		else lose_option1(player_name, credits, credits_played, "Black");
		save_option1(save, game_name, player_name, credits);
	}
	return;
}
void win_option1(string player_name, int& credits, int credits_played, int multiplier)
{
	cout << "YOU WON!, Well played " << player_name << "." << endl;
	cout << "You won " << credits_played * multiplier << "." << endl;
	credits += (credits_played * multiplier) - credits_played;
	cout << "Your credits: " << credits << endl;
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
	return;
}
void p_c()
{
	system("PAUSE");
	system("cls");
	return;
}
void save_option1(fstream& save, string& game_name, string player_name, int credits)
{
	save.open("save.txt", ios::in | ios::out | ios::app);
	if (save.good() == true)
	{
		cout << "Save you game. Enter game name: ";
		cin >> game_name;
		save << game_name << endl << player_name << endl << credits << endl;
	}
	else
	{
		cout << "Program can't find save file :(";
		system("PAUSE");
		exit(0);
	}
	save.close();
	p_c();
	return;
}
void reading_from_a_file(string Save[], string Nick[], int Credits[], int& selected_save, string& player_name, int& credits)
{
	cout << "WELCOME IN C++ CASINO AGAIN!" << endl;
	cout << "Your save's: " << endl;
	std::ifstream save("save.txt");
	int i = 0;
	while (getline(save >> ws, Save[i]) && getline(save, Nick[i]) && save >> Credits[i] && i < 3)
	{
		cout << "[" << i + 1 << "]" << Save[i] << endl;
		++i;
	}
	cout << "Select which save do you want to play: ";
	cin >> selected_save;

	player_name = Nick[selected_save - 1];
	credits = Credits[selected_save - 1];
	return;
}
void menu_option2(string player_name, int& credits, int credits_played, int color, int random_number)
{
	system("cls");
	cout << "Good luck and have fun " << player_name << "." << endl;
	cout << "Your credits: " << credits << endl;
	cout << "Let's start the game!" << endl;
	cout << player_name << " choose color : " << endl;
	cout << "1.RED" << endl;
	cout << "2.GREEN" << endl;
	cout << "3.BLACK" << endl;
	conditions_color_option(player_name, color);
	while (color < 1 || color>3)
	{
		system("cls");
		cout << "This option dosn't exits!" << endl;
		cout << player_name << " choose color : " << endl;
		cout << "1.RED" << endl;
		cout << "2.GREEN" << endl;
		cout << "3.BLUE" << endl;
		conditions_color_option(player_name, color);
	}
	cout << "How many credits do you want to play? ";
	conditions_color_option(player_name, credits_played);
	conditions_credits_option(player_name, credits, credits_played);
	draw_option(random_number);
	conditions_result_option2(player_name, credits, credits_played, color, random_number);
	return;
}
void conditions_result_option2(string player_name, int& credits, int credits_played, int color, int random_number)
{
	if (random_number >= 1 && random_number <= 48)
	{
		if (color == 1)win_option1(player_name, credits, credits_played, 2);
		else lose_option1(player_name, credits, credits_played, "Red");
		//save_option2(save, game_name, player_name, credits);
	}
	if (random_number >= 49 && random_number <= 51)
	{
		if (color == 2)win_option1(player_name, credits, credits_played, 14);
		else lose_option1(player_name, credits, credits_played, "Green");
		//save_option2(save, game_name, player_name, credits);
	}
	if (random_number >= 52 && random_number <= 99)
	{
		if (color == 3)win_option1(player_name, credits, credits_played, 2);
		else lose_option1(player_name, credits, credits_played, "Black");
		//save_option2(save, game_name, player_name, credits);
	}
	return;
}
void save_option2(fstream& save, string game_name, string player_name, int credits)
{
	save.open("save.txt", ios::in | ios::out | ios::app);
	if (save.good() == true)
	{
		cout << player_name << " you are saving game on save -  " << game_name << "." << endl;
		//usun¹c i napisaæ now¹ lnie
	}
	else
	{
		cout << "Program can't find save file :(";
		system("PAUSE");
		exit(0);
	}
	save.close();
	p_c();
	return;
}