#pragma once
#include "clsCurrency.h"
class clsCurrenciesListScreen :protected clsScreen{

private:
	static void _PrintCurrencyLine(clsCurrency Currency) {
		cout << setw(8) << left << "" << "| " << setw(27) << left << Currency.Country();
		cout << "| " << setw(6) << left << Currency.CurrencyCode();
		cout << "| " << setw(40) << left << Currency.CurrencyName();
		cout << "| " << setw(15) << left << Currency.Rate();
	
	}
public:
	static void ShowCurrenciesListScreen() {
		vector <clsCurrency> vCurrencies;
		vCurrencies = clsCurrency::GetCurrenciesList();
		string Sub = vCurrencies.size() + "Currencies.";
		_DrawScreenHeader("Currencies List Screen",Sub);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(27) << "Country";
		cout << "| " << left << setw(6) << "c.Code";
		cout << "| " << left << setw(40) << "c.Name";
		cout << "| " << left << setw(15) << "Rate";
	
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;


		if (vCurrencies.size() == 0) {
			cout << "\n\t\t\t\t THERE IS NO CURRENCY DUHHH";
		}
		else {
			for (clsCurrency& Currency : vCurrencies) {
				_PrintCurrencyLine(Currency);
				cout << endl;
			}
		}
	}

};