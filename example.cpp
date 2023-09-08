#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <filesystem>
#include <windows.h>

using namespace std;
namespace fs = std::filesystem;

void clearScreen() {
    system("cls");
}

int main() {
    clearScreen();
    string currentDir = "C:\\Users\\" + string(getenv("USERNAME"));
    fs::current_path(currentDir);
    
    cout << " _______  __   __  _______  __   __  __   __  __   __  __   __  __   __  __   __  __   __  __   __" << endl;
    cout << "|       ||  | |  ||       ||  | |  ||  | |  ||  | |  ||  | |  ||  | |  ||  | |  ||  | |  ||  | |  |" << endl;
    cout << "|  _____||  |_|  ||    _  ||  |_|  ||  | |  ||  |_|  ||  |_|  ||  |_|  ||  |_|  ||  |_|  ||  | |  |" << endl;
    cout << "| |_____ |       ||   |_| ||       ||  |_|  ||       ||       ||       ||       ||       ||  |_|  |" << endl;
    cout << "|_____  ||       ||    ___||       ||       ||       ||       ||       ||       ||       ||       |" << endl;
    cout << " _____| ||   _   ||   |    |   _   | |     | |   _   ||   _   | |     | | |     | |     | |     |" << endl;
    cout << "|_______||__| |__||___|    |__| |__|  |___|  |__| |__||__| |__|  |___|   |___|   |___|   |___|  " << endl;
    cout << "(c) Copyright AUTHOR. All rights reserved." << endl << endl;

    while (true) {
        try {
            string command;
            if (currentDir == "C:\\Users\\" + string(getenv("USERNAME"))) {
                cout << getenv("USERNAME") << "@CLI ~ $ ";
            } else {
                cout << getenv("USERNAME") << "@CLI " << currentDir << " $ ";
            }
            getline(cin, command);

            if (command.empty() || command[0] == ' ') {
                continue;
            } else if (command == "cls" || command == "clear") {
                clearScreen();
            } else if (command == "license") {
                cout << "\n[CLI]: Opening LICENSE\n";
                ShellExecute(NULL, "open", "https://example.com/license", NULL, NULL, SW_SHOWNORMAL);
            } else if (command == "authors") {
                cout << "\n[CLI]: (c) Copyright AUTHOR. All rights reserved.\n";
            } else if (command.substr(0, 2) == "cd") {
                string newDir = command.substr(3);
                try {
                    fs::current_path(newDir);
                    currentDir = fs::current_path();
                    cout << "\n[CLI]: Changed directory to " << currentDir << "\n";
                } catch (const fs::filesystem_error& ex) {
                    cout << "\n[CLI]: Directory not found: " << newDir << "\n";
                }
            } else if (command == "dir" || command == "ls") {
                for (const auto& entry : fs::directory_iterator(currentDir)) {
                    cout << entry.path().filename() << endl;
                }
            } else if (command == "exit" || command == "quit") {
                cout << "\n[CLI]: Exiting\n";
                return 0;
            } else if (command.substr(0, 3) == "cmd") {
                system("cmd");
            } else if (command.substr(0, 10) == "powershell") {
                system("powershell");
            } else {
                cout << "\n[CLI]: '" << command.substr(0, command.find(' ')) << "' is not recognized as an internal or external command, operable program or batch file.\n";
            }
        } catch (const exception& ex) {
            cout << "\n[CLI]: An error has occurred: " << ex.what() << "\n";
        }
    }
    return 0;
}
