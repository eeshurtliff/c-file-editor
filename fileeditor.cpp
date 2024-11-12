#include <iostream>
#include "fileeditor.h"
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include <typeinfo>

using namespace std;



int FileEditor::getNumLines() const {
        ifstream inputFile(FileEditor::filename);

        string line;
        int numLines = 0;

        while (getline(inputFile, line)) {
                numLines += 1;
                
        }

        inputFile.close();

        return numLines;

}


void FileEditor::updateLines() {
        ifstream inputFile(FileEditor::filename);

        string line;
        FileEditor::numLines = 1;
        

        while (getline(inputFile, line)) {
                FileEditor::lines.push_back(line);
                FileEditor:: numLines += 1;
                
        }

        inputFile.close();

}


void FileEditor::display() const {

        int numLines = 1;

        for (string line : FileEditor::lines){
                cout << numLines << ". " << line << endl;
                numLines += 1;
        }

}


bool FileEditor::chooseLine(){
        int linesSize = FileEditor::lines.size();
        int &length = FileEditor::numLines;
        cout << linesSize << " " << length << endl;
        cout << "Which line of the file would you like to edit? ";
        int chosenLine;
        // cin >> chosenLine;
        bool outOfRange = true;
        while (outOfRange) {
                
                int newValue;
                if ( !(cin >> chosenLine) ){
                        cin.clear();
                        cin.ignore();
                        cout << "Incorrect entry. Try again: ";
                        // cin >> newValue;
                        // chosenLine = newValue;
                } else if (chosenLine > 0 && chosenLine <= linesSize + 1) {
                        cout << chosenLine << " done!" << endl;
                        outOfRange = false;  
                } else {
                        cout << "Incorrect entry. Try again. ";
                        // cin >> newValue;
                        // chosenLine = newValue;  
                }
        }
        

        return chosenLine - 1;
}

void FileEditor::save(int index, string newLine){
        int &vectorLines = FileEditor::numLines;

        ofstream myFile(FileEditor::filename);

        string changedLine;
        int numLines = 0;
        
        for (int i=0; i < vectorLines; i++){
                if (i != index){
                        myFile << FileEditor::lines.at(i) << endl;
                }else{
                        myFile << newLine << endl;
                }
        }

        myFile.close();

        

}


void FileEditor::edit(){
        int index = FileEditor::chooseLine();
        

        cout << "NOTE: this will remove all of the orignal line of the file and replace it with new text. Type 'q' to abort. " << endl;
        
        cout << "Type the new line of the file: ";
        string newLine;
        cin >> newLine;
        if (newLine != "q"){
                string saveResponse;
                cout << "Would you like to save this change?(y/n) " << endl;
                cin >> saveResponse;
                if (saveResponse == "y" || saveResponse == "Y" ){
                        FileEditor::save(index, newLine);
                }
                else{
                        cout << "Your change will not be saved. " << endl;
                }


        }
        else{
                cout << "You have decided not to change this line of the file. " << endl;;
        }


}


