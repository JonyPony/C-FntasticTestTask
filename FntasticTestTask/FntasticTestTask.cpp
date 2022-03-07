// FntasticTestTask.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <cstring>


using namespace std;


int main()
{
    string str;

    cout << "Enter string: ";
    getline(cin, str);

    std::transform(str.begin(), str.end(), str.begin(), tolower);

    //std::unordered_set<char> temp;

    std::map<char, int> map;
    std::vector<char> cstr(str.c_str(), str.c_str() + str.size() + 1);

    string answer;
    int i = 0;

    for (char chr : str)
    {
        if (map.find(chr) == map.end())
        {
           map.try_emplace(chr,i);

           cstr[i] = '(';
        }
        else
        {
            cstr[i] = ')';
            cstr[map[chr]] = ')';
        }

        i++;
    }

    std::transform(cstr.begin(), cstr.end(), std::back_inserter(answer),
        [](char c)
        {
            return c;
        });

    //for (char a : str) 
    //{
    //    if (temp.find(a) == temp.end()) 
    //    {
    //        temp.insert(a);
    //        answer.append("(");
    //    }
    //    else 
    //    {
    //        answer.append(")");
    //    }
    //}

    /* Говно
    for (char a : str)
    {
       bool temp = false;
       int J = 0;

       for (char b : str)
       {
           if (a == b) J++;
          
           if (J > 1) 
           {
               temp = true;

               break;
           }
       }
       if(temp)
       {
           answer.append(")");
       }
       else 
       {
           answer.append("(");
       }
    }
    */

    cout << answer << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
