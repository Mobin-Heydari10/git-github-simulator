#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

int main() {
    string command;

    while (true) {
        cout << "$ ";
        getline(cin, command);

        try {
            if (command == "exit") {
                cout << "Program ended." << endl;
                break;
            }
            else if (command == "hello") {
                cout << "Hello!" << endl;
            }
            else if (command == "test") {
                cout << "Test successful!" << endl;
            }
            else if (command == "") {
                throw runtime_error("Empty command!");
            }
            else {
                throw runtime_error("Invalid command!");
            }
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}