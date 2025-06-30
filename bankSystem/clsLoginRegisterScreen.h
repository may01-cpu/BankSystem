#pragma once
#include"clsScreen.h"
#include <iomanip>
class clsLoginRegisterScreen : protected clsScreen {
	
private:
	
	static void _PrintLoggedUserRecordLine(clsUser:: stLoggedUsers LoggedUsers)
	{

		cout << setw(8) << left << "" << "| " << setw(25) << left << LoggedUsers.Date;
		cout << "| " << setw(20) << left << LoggedUsers.Username;
		cout << "| " << setw(20) << left << LoggedUsers.password;
		cout << "| " << setw(12) << left << LoggedUsers.Permission;

	}

public:

	static void ShowLoginRegisterScreen() {
		if (!CheckAccessRights(clsUser::enPermissions::pListLogin))
		{
			return;// this will exit the function and it will not continue
		}
		vector <clsUser::stLoggedUsers> vLoggedUsers = clsUser::LoadLoginDataFromFile();

		
		string SubTitle = "\t    (" + to_string(vLoggedUsers.size()) + ") Logged User(s).";

		_DrawScreenHeader("\tLogin Register Screen",SubTitle);


		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(25) << "Date";
		cout << "| " << left << setw(20) << "Username";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(12) << "Permission";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	
		if (vLoggedUsers.size() == 0) {
			cout << "\t\t\t\t There is no Logged Users" << endl;
		}
		else {
			
		for (clsUser::stLoggedUsers& Lu : vLoggedUsers) {
			_PrintLoggedUserRecordLine(Lu);
			cout << endl;
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		}
	}
};