// FntasticTestTask.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>


using namespace std;


int main()
{
    string InputString;

    cout << "Enter string: ";
    getline(cin, InputString);

    std::map<char, int> AlreadyExistingSymbols;

    char* InputStringInCharArray = new char[InputString.length() + 1];

    int i = 0;

    for (char chr : InputString)
    {
        if (isupper(chr)) chr = tolower(chr);

        if (AlreadyExistingSymbols.find(chr) == AlreadyExistingSymbols.end())
        {
            AlreadyExistingSymbols.try_emplace(chr,i);

            InputStringInCharArray[i] = '(';
        }
        else
        {
            InputStringInCharArray[i] = ')';
            InputStringInCharArray[AlreadyExistingSymbols[chr]] = ')';
        }

        i++;
    }

    InputStringInCharArray[InputString.length()] = '\0';

    cout << InputStringInCharArray << endl;

    system("pause");
}
