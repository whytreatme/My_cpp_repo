#include <iostream>
#include<string>

const int ArSize = 10;

void strcount(std::string str);

int main()
{
    using namespace std;
    string input;
    

    cout << "Enter a line:\n";
    getline(cin,input);
    while (cin)
    {
        if (input != "")
        {
            strcount(input);
            cout << "Enter next line (empty line to quit):\n";
            getline(cin, input);
        }
        else
            break;
    }
    cout << "Bye\n";

    return 0;
}

void strcount(std::string str)
{
    using namespace std;
    static int total = 0;
    int count = 0;
    int i = 0;

    cout << "\"" << str << "\" contains ";
  //  while (str[i++])
    //    count++;
    count = str.size();
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}