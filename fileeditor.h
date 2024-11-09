#include <iostream>

using namespace std;


class FileEditor {
    private:
        string filename;
        int getLines() const;

    public:
        FileEditor(const string& file) : filename(file) {}
        void display() const;
        void save();
        void edit();


};