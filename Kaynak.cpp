#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class StringClass {
private:
	string myString;
public:

	void setString(string myString) {
		this->myString = myString;
	}
	string convertToUpper() {

		for (int i = 0; i < myString.length(); i++)
		{
			if (islower(myString[i])) {

				myString[i] = toupper(myString[i]);
			}
		}
		return myString;
	}
	string convertTolower() {

		for (int i = 0; i < myString.length(); i++)
		{
			if (isupper(myString[i])) {

				myString[i] = tolower(myString[i]);
			}
		}
		return myString;
	}
	string convertToVicaVersa() {

		for (int i = 0; i < myString.length(); i++)
		{
			if (islower(myString[i]))
			{
				myString[i] = toupper(myString[i]);
			}
			else
			{
				myString[i] = tolower(myString[i]);
			}

		}

		int j = 0;
		char* ptr = NULL;
		ptr = new char[myString.length() + 1];
		string copyMyString = myString;
		for (int i = myString.length() - 1; i >= 0; i--)
		{
			ptr[j] = copyMyString[i];
			myString[j] = ptr[j];
			j++;
		}

		ptr[myString.length()] = NULL;
		delete[] ptr;
		return myString;
	}
	string firstLetter() {
		int counter = 0;
		for (int i = 0; i < myString.length(); i++)
		{
			if (isspace(myString[i]))
			{
				break;
			}
			counter++;
		}
		for (int i = 0; i < counter; i++)
		{
			if (islower(myString[i]))
			{
				myString[i] = toupper(myString[i]);
			}
			else
			{
				myString[i] = tolower(myString[i]);
			}

		}
		return myString;
	}
};

void menu() {

	cout << "ENTER YOUR OPERATION" << endl;
	cout << "1.Convert to lover" << endl;
	cout << "2.Convert to upper" << endl;
	cout << "3.Convert to Vica Versa" << endl;
	cout << "4.First letter" << endl;
}

int main() {

	string myString;
	int operation;
	bool changeString = 1;
	bool exit = 1;
	StringClass stringConvert;
	do
	{

		if (changeString)
		{
			cout << "Enter your string :" << endl;
			getline(cin, myString);
			stringConvert.setString(myString);
			changeString = 0;
		}

		menu();
		cin >> operation;
		switch (operation)
		{
		case 1: myString = stringConvert.convertTolower();
			cout << "Your converted to lowercase string : " << myString << endl;
			break;
		case 2: myString = stringConvert.convertToUpper();
			cout << "Your converted to uppercase string : " << myString << endl;
			break;
		case 3: myString = stringConvert.convertToVicaVersa();
			cout << "Your converted to vica versa string : " << myString << endl;
			break;
		case 4: myString = stringConvert.firstLetter();
			cout << "Your first letter fixed string : " << myString << endl;
			break;
		default:
			cout << "Invalid option!" << endl;
			break;
		}

		cout << "To exit press (0) , to continue press (1) : ";
		cin >> exit;

		if (exit == 0)
		{
			break;
		}
		else
		{
			cout << "Do you want to change the word ? (yes (1) , no (0)) : ";
			cin >> changeString;
		}

	} while (exit);

	return 0;
}