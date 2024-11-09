#include <iostream>
#include "fileeditor.h"
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

int FileEditor::getLines() const {
        ifstream inputFile("test.txt");

        string line;
        int numLines = 0;

        while (getline(inputFile, line)) {
                numLines += 1;
                
        }

        inputFile.close();

        return numLines;

}


void FileEditor::display() const {
        ifstream inputFile("test.txt");

        string line;
        int numLines = 0;

        while (getline(inputFile, line)) {
                cout << numLines << ". " << line << endl;
                numLines += 1;
        }

        inputFile.close();

        cout << getLines() << endl;

}

void FileEditor::save(){
        cout << "hello world";

}


void FileEditor::edit(){
        string text = "Hello World!";

        while (true) {
                system("cls"); // Clear the screen (Windows specific)
                std::cout << text << std::endl;

                char input = _getch(); // Get a single character input without requiring Enter
                if (input == 'q') {
                break;
                } else if (input >= 32 && input <= 126) { // Check for printable characters
                text += input;
                }
        }


}


