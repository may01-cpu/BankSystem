#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "Global.h"
using namespace std;

class clsLoginScreen :protected clsScreen
{
private:

	static void _Login() {

		string UserName, Password;
		bool FaildLogin = false;
		short trials = 3;
		do {
			if (FaildLogin) {
				cout << "\n  Invalid username/Password!\n";
				cout << "  You have " << trials << " to login\n\n";
			}
			cout << " Enter your Username:";
			cin >> UserName;

			cout << "\n Enter your Password:";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);
			FaildLogin = CurrentUser.IsEmpty();
			trials--;
		} while (FaildLogin && trials > 0);
		if (FaildLogin) {
			cout << "You are locked after 3 trials" << endl;
			exit(0);
		}
		else {
			CurrentUser.RegisterLogIn();
			clsMainScreen::ShowMainMenue();
		}
	}

	

public:

	static void ShowLoginMenu() {

		system("cls");
		_DrawScreenHeader("\t Login Menu");
	
		_Login();
	}

};

