#include <iostream>
#include <string>
using namespace std;

int main()
{
    string command;

    while (true)
    {
        cout << "$ ";

        getline(cin, command);

        if (command == "exit")
        {
            break;
        }

        cout << "Command: " << command << endl;
    }

    return 0;
}