#include <iostream>
#include <vector>


using namespace std;


class FileEditor {
    private:
        string filename;
        int numLines = 0; 
        vector<string> lines = {};
        int getNumLines() const;
        void save(int index, string newLine);

    public:
        FileEditor(const string& file) : filename(file) {}
        void updateLines();
        void display() const;
        bool chooseLine();
        void edit();


};