#include <iostream>
#include "fileeditor.h"


using namespace std;


void menu(){

    cout << "1. View the text in the file" << endl;
    cout << "2. Change a line in the file.  " << endl;
    cout << "3. Exit. " << endl;

}


int getChoice(){
    cout << "Select an option to work with the file: ";
    int choice;

    bool badChoice = true;


    while (badChoice) {
                
        int newValue;
        if ( !(cin >> choice) ){
                cin.clear();
                cin.ignore();
                cout << "Incorrect entry. Try again: ";
                
        } else if (choice > 0 && choice <= 3) {
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

    bool stillWorking = true;
    while(stillWorking){
        file.updateLines();
        menu();
        int choice = getChoice();
        if (choice == 1){
            file.display();

        }else if (choice == 2){
            file.edit();
        }else{
            stillWorking = false;
        }

    }
    cout << "Thanks for using the file editor!" << endl;

    return 0;

}
