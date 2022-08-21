#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//------------------------------------------------------------------------------

struct Book{
    string Title;
    string Author;
    int publishDate;
    char genderAuthor;
};

//------------------------------------------------------------------------------
//
// class Point / Definitions
//
//------------------------------------------------------------------------------

class Library{
    private:
        vector<vector<string>> inventory;
    public:
        Library();
        Library(string csvFileAddress);

        void printAll();
        void printFromAttribute(string attribute);

        void addBook(Book bookToAdd);
};

//------------------------------------------------------------------------------

Library::Library(){
    string csvAddress;
    cout << "Please enter the address of the csv file with the list of the books in the library: ";
    cin >> csvAddress ;
}

//------------------------------------------------------------------------------

int main(){
    fstream dataFile;
    string txt;
    vector<vector<string>> BigData;
    
    dataFile.open("Data.csv",fstream::in);

    if (dataFile.fail()){cout << "Input file opening failed. \n";}
    else{
        int i = 0;
        vector<string> tempLine;
        
        while (getline(dataFile,txt)){
            string tempString;

            while (txt.length() > 0){
                if (txt[0] != ','){
                    tempString.push_back(txt[0]);
                    txt.erase(0,1);
                }
                else{
                    txt.erase(0,1);
                    tempLine.push_back(tempString);
                    tempString.clear();
                }
            }
            BigData.push_back(tempLine);
            tempLine.clear();
        }
    }
    return 0;
}