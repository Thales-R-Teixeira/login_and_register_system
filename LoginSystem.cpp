#include <iostream>
#include <string>
#include <fstream>

using namespace std;

inline bool userAuthentication()
{
	string userName, password, user, passw;
	cout << "Enter Username:\t"; cin >> userName;
	cout << "Enter Password:\t"; cin >> password;
	ifstream read("users" + userName + ".txt");
	getline(read, user);
	getline(read, passw);
	if ((userName == user) && (password == passw)) {
		return true;
	}
	else {
		return false;
	}
}

int main() 
{
	// MAIN MENU
	int choice;
	do {
		system("cls");
		cout << "\n=========[MAIN MENU]=========\n";
		cout << "1:Login\n2:Create Account\n3:Exit\nYour Choice:"; cin >> choice;
		if (choice == 1)
		{
			system("cls");
			cout << "\n==========[Enter Username and Password]==========\n";
			bool status = userAuthentication();
			
			if (!status)
			{
				cout << "Username or Password Invalid!";
		
			}
			else 
			{
				cout << "Sucessfully logged in!";
			}
			system("pause>nul");
		}
		if (choice == 2)
		{
			system("cls");
			string userName, password;
			cout << "\n=========[Account Creation]=========\n";
			cout << "Enter create your username: "; cin >> userName;
			cout << "Enter create your password: "; cin >> password;
			
			ofstream userFile;
			userFile.open("users" + userName + ".txt");
			userFile <<  userName << endl  << password;
			userFile.close();
			cout << "Account Succesfully Created!";

			system("pause>nul");
		}
	} 
	while (choice != 3);

	return 0;
}