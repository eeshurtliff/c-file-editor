#include <iostream>
#include "fileeditor.h"


using namespace std;

int main(){
    cout << "hello world" << endl;
    string filename = "file1";
    FileEditor file("file1");
    file.display();


    return 0;

}