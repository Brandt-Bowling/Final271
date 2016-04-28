#include "PhoneNumber.h"

void main()
{
	string phoneNum = "";
	bool good = false;
	PhoneNumber number;

	do
	{
		try
		{
			cout << "Enter phone number: ";
			getline(cin, phoneNum);

			if (phoneNum.length() != 14)
				throw Length();
			else if (phoneNum[0] != '(')
				throw areaCode("area code is missing parenthesis");
			else if (phoneNum[1] == '0' || phoneNum[1] == '1')
				throw areaCode("area code begin with 0 or 1", phoneNum[1]);
			else if (phoneNum[2] != '0' && phoneNum[2] != '1')
				throw areaCode("area code middle digit is not 0 or 1");
			else if (phoneNum[4] != ')')
				throw areaCode("area code missing parenthesis");
			else if (phoneNum[5] != ' ')
				throw Syntax("no space between area code and exchange");
			else if (phoneNum[6] == '0' || phoneNum[6] == '1')
				throw Exchange("exchange starts with 0 or 1");
			else if (phoneNum[9] != '-')
				throw Syntax("missing dash between exchange and line");
			else
			{
				good = true;
				cout << phoneNum << "\t nothing wrong with this number" << endl;
			}
		}
		catch (Length le)
		{
			cout << "Error-\t" << le.what() << endl;
			cin.clear();
		}
		catch (areaCode e)
		{
			cout << "Error-\t" << e.what() << endl;
			cin.clear();
		}
		catch (Syntax s)
		{
			cout << "Error-\t" << s.what() << endl;
			cin.clear();
		}
		catch (Exchange e)
		{
			cout << "Error-\t" << e.what() << endl;
			cin.clear();
		}

	} while (!good);

	number.copy(phoneNum);


	system("pause");
}