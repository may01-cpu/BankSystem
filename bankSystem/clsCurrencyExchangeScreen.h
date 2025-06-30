#pragma once
#include "clsScreen.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCurrencyCalculatorScreen.h"

class clsCurrencyExchangeScreen :protected clsScreen {

private:

    enum eCurrencyExchOptions {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyCalculator = 4, eMainMenu = 5
    };

    static int _ReadOption() {
        cout << "\n\tChoose what do you wanna do? [1 To 5]? ";
        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 5, "\n\tEnter Number between 1 to 5? ");
        return Choice;
    }

    static void  _GoBackToCurrencyMenu() {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
        system("pause>0");
        ShowCurrencyExchangeScreen();
    }

    static void _ShowCurrenciesListScreen() {
        clsCurrenciesListScreen::ShowCurrenciesListScreen();
    }

    static void _ShowFindCurrencyScreen() {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateRateScreen() {
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }

    static void _ShowCurrencyCalculatorScreen() {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }
   
    static void _PerformCurrencyExchangeMenu(eCurrencyExchOptions option) {
        switch (option) {
        case eCurrencyExchOptions::eListCurrencies:
            system("cls");
            _ShowCurrenciesListScreen();
            _GoBackToCurrencyMenu();
            break;
        case eCurrencyExchOptions::eFindCurrency:
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyMenu();
            break;
        case eCurrencyExchOptions::eUpdateRate:
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToCurrencyMenu();
            break;
        case eCurrencyExchOptions::eCurrencyCalculator:
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrencyMenu();
            break;
        case eCurrencyExchOptions::eMainMenu:
          //nothing
            break;

        }
    }

public:

	static void ShowCurrencyExchangeScreen() {

         system("cls");
		_DrawScreenHeader("Currency Exchange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrencyExchangeMenu((eCurrencyExchOptions)_ReadOption());
	}

};
