#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<fstream>
#include<ctime>

using namespace std;

void sign_up();
void login();
void menu();
void add_entry();
string select_file();
void view_entry();
void delete_entry();
void sticky_note();
void header();

struct users
{
	string user_name;
	string password;
};

time_t timetoday;
string active_user;

int main()
{
	system("CLS");
	header();
	char choice_access, choice;

	cout << endl << endl;
	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;
	cout << setw(65) << "|" << "\t\tMENU   \t " << setw(13) << " | " << endl;
	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;
	cout << setw(65) << "|" << setw(37) << " | " << endl;
	cout << setw(65) << "|" << "\tLogin\t\t1" << setw(13) << " | " << endl;
	cout << setw(65) << "|" << "\tSign Up\t\t2" << setw(13) << " | " << endl;
	cout << setw(65) << "|" << "\tLogout\t\t3" << setw(13) << " | " << endl;
	cout << setw(65) << "|" << "\tEXIT\t\t4" << setw(13) << " | " << endl;
	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;
again:
	cout << endl << setw(84) << "Enter your choice: ";
	cin >> choice_access;

	switch (choice_access)
	{
	case '1':
	{
				login();
				break;
	}
	case '2':
	{
				sign_up();
				break;
	}
	case '3':
	{
				cout << "Are you sure you want to logout?(Y/N)";
				cin >> choice;
				if (choice == 'Y' || choice == 'y')
				{
					active_user = " ";
					system("CLS");
					cout << "\n\n\n\n\n" << setw(90) << "Logged out\n\n";
					cout << setw(103) << "Press any key to go the main screen.";
					cin.get(); cin.get();
					main();
				}
				else
					menu();
				break;
	}

	case '4':
	{
				cout << "Are you sure you want to Exit?(Y/N)";
				cin >> choice;
				if (choice == 'Y' || choice == 'y')
				{
					system("CLS");
					cout << "\n\n\n\n\n";
					cout << setw(100) << "Thank you for using this software." << endl;
					cout << setw(93) << "Hope to see you again" << endl;
					cout << setw(96) << "Have a nice day\n\n\n\n\n";
					cout << setw(90) << "Regards from\n";
					cout << setw(87) << "Unaiza\n";
					cout << setw(87) << "Wajiha\n";
					cout << setw(87) << "Zainab\n";
					exit(0);
				}
				else
				{
					system("CLS");
					main();
				}
				break;
	}
	default:
	{
			   cout << "Invalid choice.\n Try again.\n";
			   goto again;
	}
	}

	cout << endl;
	return 0;
}

void header() //This function displays the header of this software. This function will be called in the start of almost every function
{
	cout << endl;
	cout << "=" << setw(167) << setfill('=') << "=" << setfill(' ');
	cout << setw(90) << "Chronicles of Life\n";
	cout << "=" << setw(167) << setfill('=') << "=" << setfill(' ');
}


void login()
{
	system("CLS");
	header();
	string user, pass, user_f, pass_f;
	char choice;
	//Login header
	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;
	cout << setw(65) << "|" << "\t\tLOGIN \t " << setw(13) << " | " << endl;
	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;
	//Inputting username and password from user
	cout << setw(85) << "Username:";
	cin >> user;
	cout << setw(85) << "Password:";
	cin >> pass;

	//Checking if account exists in "users.txt" file
	fstream file;
	file.open("users.txt", ios::in);
	if (!file)
	{
		cout << "No Account exists. Create account first.";
		cin.ignore(); cin.ignore();
		sign_up();
	}

	else
	{
		while (!file.eof())
		{
			getline(file, user_f);
			getline(file, pass_f);
			//checking if username and password are correct
			if ((user == user_f) && (pass == pass_f))
			{
				active_user = user_f;
				file.close();
				cout << endl << endl << setw(93) << "Access granted." << endl;
				cout << setw(102) << "Press any key to go the main menu.";
				cin.get(); cin.get();
				menu();
			}
			else;
		}
	}
	file.close();
	//If account does not exists then sending to the sign_up() function
	cout << endl << endl << setw(93) << "Invalid credentials." << endl;
	cout << "Do you want to create a account?(Y/N)";
	cin >> choice;
	if (choice == 'Y' || choice == 'y')
		sign_up();
	else
		main();
}

void sign_up()
{
	system("CLS");
	header();
	users user_account;
	fstream file;
	file.open("users.txt", ios::out | ios::app);

	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;
	cout << setw(65) << "|" << "\t\tSign Up\t " << setw(13) << " | " << endl;
	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;

	cout << setw(85) << "Username:";
	cin.ignore();
	getline(cin, user_account.user_name);
	cout << setw(85) << "Password:";
	getline(cin, user_account.password);

	file << user_account.user_name << endl;
	file << user_account.password << endl;
	file.close();
	cout << endl << endl << setw(93) << "Account created." << endl;
	cout << setw(100) << "Press any key to go to Login.";
	cin.ignore();
	login();
}

void menu()
{
	char choice, logout_choice;
	string sticky_data;
	string quote[20], data;
	int counter = 0;

	//random number generation
	time(&timetoday);
	srand((unsigned)time(0));
	int randomNumber;
	randomNumber = (rand() % 19) + 1;

	system("CLS");
	header();

	//Random quote generator
	fstream file;
	file.open("Quotes.txt", ios::in);
	while (getline(file, data))
	{
		quote[counter] = data;
		counter++;
	}
	file.close();
	cout << endl << endl << "\t\t" << quote[randomNumber] << "\t\t\t" << asctime(localtime(&timetoday));


	cout << endl << setw(83) << "Welcome " << active_user << endl << endl;

	//Displaying Sticky Note
	file.open(active_user + " Note", ios::in | ios::out);
	if (!file);
	else
	{
		cout << setw(167) << setfill('-') << "-" << setfill(' ') << endl;
		while (!file.eof())
		{
			getline(file, sticky_data);
			cout << "NOTE:\t" << sticky_data << endl;
		}
		cout << setw(167) << setfill('-') << "-" << setfill(' ') << endl;
		file.close();
	}

	//Menu
	cout << endl;
	cout << setw(56) << "|" << setw(52) << setfill('-') << "|" << setfill(' ') << endl;
	cout << setw(56) << "|" << "\t\t\tMENU\t " << setw(20) << " | " << endl;
	cout << setw(56) << "|" << setw(52) << setfill('-') << "|" << setfill(' ') << endl;
	cout << setw(56) << "|" << setw(53) << " | " << endl;
	cout << setw(56) << "|" << "\tAdd an entry\t\t1" << setw(20) << " | " << endl;
	cout << setw(56) << "|" << "\tView all entries\t2" << setw(20) << " | " << endl;
	cout << setw(56) << "|" << "\tDelete a entry\t\t3" << setw(20) << " | " << endl;
	cout << setw(56) << "|" << "\tAdd a sticky note\t4" << setw(20) << " | " << endl;
	cout << setw(56) << "|" << "\tLogout\t\t\t5" << setw(20) << " | " << endl;
	cout << setw(56) << "|" << "\tEXIT\t\t\t6" << setw(20) << " | " << endl;
	cout << setw(56) << "|" << setw(51) << setfill('-') << "-" << "|" << setfill(' ') << endl;

	cout << endl << setw(88) << "Enter your choice=";
	cin >> choice;

	switch (choice)
	{
	case '1':
	{
				add_entry();
				break;
	}

	case '2':
	{
				view_entry();
				break;
	}
	case '3':
	{
				delete_entry();
				break;
	}
	case '4':
	{
				sticky_note();
				break;
	}
	case '5':
	{//log out
				cout << "Are you sure you want to logout?(Y/N)";
				cin >> logout_choice;
				if (logout_choice == 'Y' || logout_choice == 'y')
				{
					active_user = " ";
					system("CLS");
					cout << "\n\n\n\n\n" << setw(90) << "Logged out\n\n";
					cout << setw(103) << "Press any key to go the main screen.";
					cin.ignore(); cin.ignore();
					main();
				}
				else
					menu();
				break;
	}
	case '6':
	{
				//exit
				cout << "Are you sure you want to Exit?(Y/N)";
				cin >> logout_choice;
				if (logout_choice == 'Y' || logout_choice == 'y')
				{
					system("CLS");
					cout << "\n\n\n\n\n";
					cout << setw(100) << "Thank you for using this software." << endl;
					cout << setw(93) << "Hope to see you again" << endl;
					cout << setw(96) << "Have a nice day\n\n\n\n\n";
					cout << setw(90) << "Regards from\n";
					cout << setw(87) << "Unaiza\n";
					cout << setw(87) << "WajIha\n";
					cout << setw(87) << "Zainab\n";
					exit(0);
				}
				else
					menu();
				break;
	}

	default:
	{
			   cout << "Invalid choice.Try Again" << endl;
			   menu();
	}
	}

}

void add_entry()
{
	system("CLS");
	header();

	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;
	cout << setw(65) << "|" << "\t      Add Entry  " << setw(13) << " | " << endl;
	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;

	char day_date[30];
	char data[2000];
	cout << "Today:" << asctime(localtime(&timetoday)) << endl;
	cout << "Entry date:";
	cin.ignore();
	cin.getline(day_date, 30);

	fstream file;

	file.open(day_date, ios::out);
	cout << "Add entry:" << endl;
	cin.getline(data, 2000);
	file << data;
	cout << endl << endl << "Day written..." << endl;
	file.close();

	//Adding name of record in a user specific file for record keeping
	file.open(active_user, ios::out | ios::app);
	file << day_date << endl;
	file.close();

	cout << "Press any key to go back to menu";
	cin.ignore();
	system("CLS");
	menu();
}


void view_entry()
{
	system("CLS");
	header();
	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;
	cout << setw(65) << "|" << "\t     View Entry  " << setw(13) << " | " << endl;
	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;

	//Calling select_file() function to choose a file.
	string view_file = select_file();
	string data;

	fstream file;
	file.open(view_file);

	if (file.fail())
	{
		cout << endl << endl << "ERROR.Failed to open file.\nEither the file does not exist or the name you enetered is wrong.\nTry again";
		cin.ignore();
		menu();
	}
	//displaying contents of selected file
	else
	{
		cout << endl << setw(167) << setfill('-') << "-" << setfill(' ') << endl;
		cout << "Day entry of \"" << view_file << "\":" << endl;
		cout << setw(167) << setfill('-') << "-" << setfill(' ') << endl;
		do
		{
			getline(file, data);
			cout << data << endl;
		} while (!file.eof());
	}
	file.close();

	cout << endl << endl << "Press any key to go back to menu.";
	cin.ignore();
	menu();
}

//This function is created because the same procedure is repeated in two functions view_entry() and delete_entry().
//This function is used to select any file from record
string select_file()
{
	string data;
	string view_file;
	int counter = 1;

	ifstream file(active_user);

	//Check if file exists or has any content.If it doesnt exist or is empty it displays no entries message and send user to menu.

	if (!file || file.peek() == ifstream::traits_type::eof())
	{
		cout << "No Entries..." << endl;
		cout << "Press any key to go to main menu";
		cin.ignore(); cin.ignore();
		menu();
	}
	else
	{
		cout << endl << "All entries :" << endl << endl;
		while (getline(file, data))
		{
			cout << counter << ". " << data << endl;
			counter++;
		}
	}
	file.close();
	cout << endl << endl << "Enter name of file=";
	cin.ignore();
	getline(cin, view_file);
	return view_file;
}


void delete_entry()
{
	system("CLS");
	header();
	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;
	cout << setw(65) << "|" << "\t   Delete Entry  " << setw(13) << " | " << endl;
	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;
	string del_file = select_file(), line;
	int status;
	char choice;
	cout << "Are you sure you want to delete the record of " << del_file << " ?(Y/N)";
	cin >> choice;

	if (choice == 'Y' || choice == 'y')
	{
		string line;
		/* To update the file which keeps record of all entries entered by the user.
		This part writes the data of the file which has record of all entries in a temporary file.
		It does not write the name of file which is to be deleted in the temporary file.
		Then it deletes the record keeping file and the file which the user asked to delete and renames the temp file to the record keeping file.*/
		ifstream infile;
		ofstream outfile;

		infile.open(active_user);
		outfile.open("temp.txt");

		while (getline(infile, line))
		{
			if (line != del_file)
				outfile << line << endl;
		}
		outfile.close();
		infile.close();

		status = remove(del_file.c_str());
		remove(active_user.c_str());
		rename("temp.txt", active_user.c_str());
	}
	else
	{
		cout << "Press any key to go back to main menu";
		cin.ignore();
		menu();
	}
	//If the file was deleted then the remove function returns 0.
	if (status != 0)
	{
		cout << "Error deleting file";
		cin.ignore();
		menu();
	}

	else
	{
		cout << "File successfully deleted.\nPress any key to go back to main menu.";
		cin.ignore(); cin.ignore();
		menu();
	}
}


void sticky_note()
{
	string sticky, data;
	system("CLS");
	header();

	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;
	cout << setw(65) << "|" << "\t   Sticky Note   " << setw(13) << " | " << endl;
	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;
	fstream file;

	file.open(active_user + " Note", ios::out | ios::trunc);
	cout << endl << "Note:";
	cin.ignore();
	getline(cin, sticky);
	file << sticky;
	file.close();

	cout << endl << "Note created on main menu.\nPress any key to go to the main menu.";
	cin.ignore();
	menu();
}
