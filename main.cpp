#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<vector<string>> parseCSVFile(string csvFileAddress);


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
        ~Library();

        void printAll();
        void printFromAttribute(string attribute);

        void addBook(Book bookToAdd);
};

//------------------------------------------------------------------------------

Library::Library(){
    string csvAddress;
    cout << "Please enter the address of the csv file with the list of the books in the library: ";
    cin >> csvAddress ;

    inventory = parseCSVFile(csvAddress);
}

Library::Library(string csvFileAddress){
    inventory = parseCSVFile(csvFileAddress);
}

//------------------------------------------------------------------------------

vector<vector<string>> parseCSVFile(string csvFileAddress){
    fstream csvFile;
    vector<vector<string>> parsedFile;

    csvFile.open(csvFileAddress,fstream::in);

    if (csvFile.fail()){cout << "CSV file opening failed. \n";}
    else{
        int i=0;
        vector<string> tempLine;
        string txt;

        while(getline(csvFile,txt)){
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
            parsedFile.push_back(tempLine);
            tempLine.clear();
        }
    }
    return parsedFile;
}



int main(){
    fstream dataFile;
    string txt;

    Library mySecondLibrary("Data.csv");

    return 0;
}