#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <windows.h>
#include <cstdlib>

using namespace std;

void main_menu(int& main_menu_navigator);//IDEALNE
void menu_option1(string& player_name, int& credits, int& color, int& credits_played, int& random_number, fstream& save, string& game_name);//ZA DUŻO
void conditions_variable_option(string player_name, int& variable);//IDEALNA
void conditions_credits_option(string player_name, int credits, int& credits_played);//IDEALNA
void draw_option(int& random_number);//IDEALNA
void conditions_result_option1(string player_name, int& credits, int credits_played, int color, int random_number, fstream& save, string& game_name);//ZA DUŻO
void win_option1(string player_name, int& credits, int credits_played, int multiplier);//IDEALNA
void lose_option1(string player_name, int& credits, int credits_played, string correct_color);//IDEALNA
void p_c();//IDEALNA
void save_option1(fstream& save, string& game_name, string player_name, int credits);//IDEALNA
void reading_from_a_file(string Save[], string Nick[], int Credits[], int &selected_save, string& player_name, int& credits);//ZA DUŻO+TABLICE
void menu_option2(string player_name, int& credits, int color, int credits_played, int random_number, fstream& save, string game_name, int &selected_save, string Save[], string Nick[], int Credits[]);//ZA DUŻO + TABLICE
void conditions_result_option2(string player_name, int& credits, int credits_played, int color, int random_number, string Save[], string Nick[], int Credits[], int& selected_save, string game_name, fstream& save);//ZA DUŻO +TABLICE
void save_option2(fstream& save, string game_name, string player_name, int credits, string Save[], string Nick[], int Credits[], int selected_save);
void menu_option3(int& menu_3_navagator);//IDEALNA
void conditions_variable_optionv2(int& variable);//IDEALNA
void chance_option3();//IDEALNA
void prize_option3();//IDEALNA
void end_option3();//IDEALNA
void default_option();//IDEALNA
void end_option4(string end_option);//IDEALNA

int main()
{
	int main_menu_navigator, menu_3_navagator, credits, color, credits_played = 0, random_number, selected_save;
	string player_name, game_name, end_option;;
	fstream save;
	string Save[100], Nick[100];//dynamika
	int Credits[100];//dynamika
	bool whileend = false;

	while (1)
	{
		main_menu(main_menu_navigator);
		switch (main_menu_navigator)
		{
		case 1:
			menu_option1(player_name, credits, color, credits_played, random_number, save, game_name);
			break;
		case 2:
			menu_option2(player_name, credits, color, credits_played, random_number, save, game_name, selected_save, Save, Nick, Credits);
			break;
		case 3:
			while (whileend == false)
			{
				menu_option3(menu_3_navagator);
				switch (menu_3_navagator)
				{
				case 1:
					chance_option3(); whileend = true; break;
				case 2:
					prize_option3(); whileend = true; break;
				case 3:
					end_option3(); whileend = true; break;
				default:
					default_option();
				}
			}whileend = false; break;
		case 4:
			end_option4(end_option);
		default: default_option();
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
	conditions_variable_optionv2(main_menu_navigator);
	system("cls");
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
	conditions_variable_option(player_name, color);
	while (color < 1 || color>3)
	{
		system("cls");
		cout << "This option dosn't exits!" << endl;
		cout << player_name << " choose color : " << endl;
		cout << "1.RED" << endl;
		cout << "2.GREEN" << endl;
		cout << "3.BLUE" << endl;
		conditions_variable_option(player_name, color);
	}
	cout << "How many credits do you want to play? ";
	conditions_variable_option(player_name, credits_played);
	conditions_credits_option(player_name, credits, credits_played);
	draw_option(random_number);
	conditions_result_option1(player_name, credits, credits_played, color, random_number, save, game_name);
	return;
}
void conditions_variable_option(string player_name, int& variable)
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
		conditions_variable_option(player_name, credits_played);
	}
	return;
}
void draw_option(int& random_number)
{
	system("cls");
	cout << "The drawing machine begins the countdown." << endl;
	for (int i = 5; i > -2; i--)
	{
		Sleep(500);
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
	save.open("save.txt", ios::out | ios::app);
	if (save.good() == true)
	{
		cout << "Save you game. Enter game name: ";
		cin >> game_name;
		save << game_name << endl << player_name << endl << credits << endl;
		cout << "The game saved Successfully." << endl;
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
	while (getline(save >> ws, Save[i]) && getline(save, Nick[i]) && save >> Credits[i] && i < 100)//zamiast 4 dynamika
	{
		cout << "[" << i + 1 << "]" << Save[i] << endl;
		++i;
	}
	cout << "Select which save do you want to play: ";//wywali jak siê da co wiecej ni¿ jest savów
	cin >> selected_save;

	player_name = Nick[selected_save - 1];
	credits = Credits[selected_save - 1];
	return;
}
void menu_option2(string player_name, int& credits, int color, int credits_played, int random_number, fstream& save, string game_name, int &selected_save, string Save[], string Nick[], int Credits[])
{
	reading_from_a_file(Save, Nick, Credits, selected_save, player_name, credits);
	system("cls");
	cout << "Good luck and have fun " << player_name << "." << endl;
	cout << "Your credits: " << credits << endl;
	cout << "Let's start the game!" << endl;
	cout << player_name << " choose color : " << endl;
	cout << "1.RED" << endl;
	cout << "2.GREEN" << endl;
	cout << "3.BLACK" << endl;
	conditions_variable_option(player_name, color);
	while (color < 1 || color>3)
	{
		system("cls");
		cout << "This option dosn't exits!" << endl;
		cout << player_name << " choose color : " << endl;
		cout << "1.RED" << endl;
		cout << "2.GREEN" << endl;
		cout << "3.BLUE" << endl;
		conditions_variable_option(player_name, color);
	}
	cout << "How many credits do you want to play? ";
	conditions_variable_option(player_name, credits_played);
	conditions_credits_option(player_name, credits, credits_played);
	draw_option(random_number);
	conditions_result_option2(player_name, credits, credits_played, color, random_number, Save, Nick, Credits, selected_save, game_name, save);
	return;
}
void conditions_result_option2(string player_name, int& credits, int credits_played, int color, int random_number, string Save[], string Nick[], int Credits[], int& selected_save, string game_name, fstream& save)
{
	if (random_number >= 1 && random_number <= 48)
	{
		if (color == 1)win_option1(player_name, credits, credits_played, 2);
		else lose_option1(player_name, credits, credits_played, "Red");
		save_option2(save, game_name, player_name, credits, Save, Nick, Credits, selected_save);
	}
	if (random_number >= 49 && random_number <= 51)
	{
		if (color == 2)win_option1(player_name, credits, credits_played, 14);
		else lose_option1(player_name, credits, credits_played, "Green");
		save_option2(save, game_name, player_name, credits, Save, Nick, Credits, selected_save);
	}
	if (random_number >= 52 && random_number <= 99)
	{
		if (color == 3)win_option1(player_name, credits, credits_played, 2);
		else lose_option1(player_name, credits, credits_played, "Black");
		save_option2(save, game_name, player_name, credits, Save, Nick, Credits, selected_save);
	}
	return;
}
void save_option2(fstream& save, string game_name, string player_name, int credits, string Save[], string Nick[], int Credits[], int selected_save)
{
	save.open("save.txt", ios::out | ios::trunc);
	Credits[selected_save - 1] = credits;
	if (save.good() == true)
	{
		cout << "You are saving game on save - " << Save[selected_save - 1] << "." << endl;
		for (int i = 0; i < 4; i++)//zamiast 4 dynamika
		{
			save << Save[i] << endl << Nick[i] << endl << Credits[i] << endl;
		}
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
void menu_option3(int& menu_3_navagator)
{
	cout << "WELCOME IN RULE SECTION." << endl;
	cout << "1.Chance to win." << endl;
	cout << "2.How much I can win." << endl;
	cout << "3.Go back to menu." << endl;
	cout << "Enter: ";
	conditions_variable_optionv2(menu_3_navagator);
	system("cls");
	return;
}
void conditions_variable_optionv2(int& variable)
{
	if (!(cin >> variable))
	{
		cout << "You can't enter anything other than a number here! " << endl;
		cout << "Restart program and try again." << endl;
		system("PAUSE");
		exit(0);
	}
	return;
}
void chance_option3()
{
	cout << "==========" << endl;
	cout << "==CHANCE==" << endl;
	cout << "==========" << endl;
	cout << "If you bet on RED, you have 48,45% chance to win. Tickets - (1-48) " << endl;
	cout << "If you bet on GREEN, you have 3,10% chance to win. Tickets - (49-51)" << endl;
	cout << "If you bet on BLACK, you have 48,45% chance to win. Tickets - (52-100)" << endl;
	p_c();
	return;
}
void prize_option3()
{
	cout << "======================" << endl;
	cout << "==HOW MUCH I CAN WIN==" << endl;
	cout << "======================" << endl;
	cout << "If you bet on RED, you can win 2 times more." << endl;
	cout << "If you bet on GREEN, you can win 14 times more." << endl;
	cout << "If you bet on BLACK, you can win 2 times more." << endl;
	p_c();
	return;
}
void end_option3()
{
	cout << "So, let's go back to the main menu." << endl;
	p_c();
	return;
}
void default_option()
{
	cout << "THIS OPTION DOESN'T EXIST!" << endl;
	cout << "Try one more time." << endl;
	p_c();
	return;
}
void end_option4(string end_option)
{
	while (1)
	{
		cout << "DO YOU REALLY WANT TO LEAVE THE CASINO?" << endl;
		cout << "Choose Y/N: ";
		cin >> end_option;
		if (end_option == "Y" || end_option == "y")
		{
			cout << "SEE YOU SOON." << endl;
			system("PAUSE");
			exit(0);
		}
		if (end_option == "N" || end_option == "n")
		{
			cout << "So, let's go back to the main menu." << endl;
			p_c(); break;
		}
		else
		{
			cout << "THIS OPTION DOESN'T EXIST!" << endl;
			cout << "Try one more time." << endl;
			p_c();
		}
	}
	return;
}