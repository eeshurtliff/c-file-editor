#include <iostream>
#include "fileeditor.h"


using namespace std;



void menu(){

    cout << "1. View the text in the file" << endl;
    cout << "2. Change a line in the file.  " << endl;
    cout << "3. View instructions. " << endl;
    cout << "4. Exit. " << endl;

}

void showInstructions(){
    cout << "Welcome to the file editor. The menu contains options to view the file, change the file, view these instructions, or exit\
the file editor. When viewing the file, the lines are numbered. This makes it easier to edit the file, which allows you\
to edit one line at a time. Choose a line to edit, save the changes, and the line in the file will be updated. Select the number of \
your choice. " << endl << endl;
}


int getChoice(int options){
    cout << "Select an option to work with the file: ";
    int choice;

    bool badChoice = true;


    while (badChoice) {
                
        int newValue;
        if ( !(cin >> choice) ){
                cin.clear();
                cin.ignore();
                cout << "Incorrect entry. Try again: ";
                
        } else if (choice > 0 && choice <= options) {
                // cout << choice << " done!" << endl;
                badChoice = false;  
        } else {
                cout << "Incorrect entry. Try again. ";
                 
        }
    }
    return choice;
}


int main(){
    // cout << "hello world" << endl;
    string filename = "test.txt";
    FileEditor file(filename);
    file.updateLines();
    // file.display();
    // cout << endl;
    // file.edit();
    showInstructions();
    bool stillWorking = true;
    while(stillWorking){
        file.updateLines();
        menu();
        int choice = getChoice(4);
        if (choice == 1){
            file.display();

        }else if (choice == 2){
            file.edit();
        }else if (choice == 3){
            showInstructions();
        }else {
            stillWorking = false;
        }

    }
    cout << "Thanks for using the file editor!" << endl;

    return 0;

}
