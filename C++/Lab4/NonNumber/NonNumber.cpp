#include <iostream>

#include "NonNumberException.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	while (true)
	{
		try
		{
			cout << "Please enter a number (end-of-file to terminate): ";
			std::string s;
			cin >> s;
			if (cin.eof()) break;
			int len = s.length();
			if ((s[0] == '-' || (s[0] >= '0' && s[0] <= '9')) == false)
				throw NonNumberException();
			for (int i = 1; i < len; i++)
				if ((s[i] >= '0' && s[i] <= '9') == false)
					throw NonNumberException();
			int p = 0;
			long long number = 0;
			if (s[0] == '-') p = 1;
			for (int i = p; i < len; i++)
				number = number * 10 + ((long long)s[i] - '0');
			if (s[0] == '-') number = -number;
			cout << "The number entered was: " << number << endl;
		}
		catch (NonNumberException& e)
		{
			cout << e.what() << endl;
		}
		catch (std::exception& e)
		{
			cout << e.what() << endl;
		}
		cout << endl;
	}
	return 0;
}