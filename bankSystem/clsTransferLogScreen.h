#pragma once
#include "clsScreen.h"
class clsTransferLogScreen :protected clsScreen {
private:
	static void _PrintTransferLogLine(clsBankClient::stTransferLog TL) {
		cout << setw(8) << left << "" << "| " << setw(21) << left <<TL.Date;
		cout << "| " << setw(10) << left << TL.SourceAccNum;
		cout << "| " << setw(10) << left << TL.DestinationAccNum;
		cout << "| " << setw(10) << left << TL.Amount;
		cout << "| " << setw(15) << left << TL.NewSourceBalance;
		cout << "| " << setw(15) << left << TL.NewDestinationBalance;
		cout << "| " << setw(8) << left << TL.Username;
	}

	static void _PrintTransferHeader() {
		cout << setw(8) << left << "" << "\n\t_____________________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(21) << "Date";
		cout << "| " << left << setw(10) << "S.ACC";
		cout << "| " << left << setw(10) << "D.ACC";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(15) << "S.New-Balance";
		cout << "| " << left << setw(15) << "D.New-Balance";
		cout << "| " << left << setw(8) << "User";
		cout << setw(8) << left << "" << "\n\t_____________________________________________________________";
		cout << "_________________________________________\n" << endl;
	}

public:
	static void ShowTransferLogScreen() {
		
		vector<clsBankClient::stTransferLog> vTransferLogs;
		vTransferLogs = clsBankClient::LoadTransferLogDataFromFile();

		string Subtitle = vTransferLogs.size() + " record(s).";
		_DrawScreenHeader("Transfer Log List Screen",Subtitle);
	
		_PrintTransferHeader();

		if (vTransferLogs.size() == 0) {
			cout << "\t\t\t\tTHERE IS NO TRANSFER LOGS PERRR MEAWWW :3" <<endl;
		}
		else {
			for (clsBankClient::stTransferLog& TL : vTransferLogs) {
				_PrintTransferLogLine(TL);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_____________________________________________________________";
		cout << "_________________________________________\n" << endl;
	}

};