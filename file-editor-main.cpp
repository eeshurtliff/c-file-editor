#include <iostream>
#include "fileeditor.h"


using namespace std;

int main(){
    cout << "hello world" << endl;
    string filename = "test.txt";
    FileEditor file(filename);
    file.updateLines();
    file.display();
    cout << endl;
    file.edit();

    bool stillWorking = true;
    while(stillWorking){
        menu();


    }



    return 0;

}

int menu(){

    cout << "1. View the text in the file" << endl;
    cout << "2. Change a line in the file.  " << endl;

}