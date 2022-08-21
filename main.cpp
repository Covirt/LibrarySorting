#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//------------------------------------------------------------------------------

struct Book{
    string Title;
    string Author;
    string Nationality;
    string publishDate;
    string GenderAuthor;

    //int publishDate;
    //char genderAuthor;
};

//------------------------------------------------------------------------------

vector<Book> parseCSVFile(string csvFileAddress);


//------------------------------------------------------------------------------
//
// class Point / Definitions
//
//------------------------------------------------------------------------------

class Library{
    private:
        vector<Book> inventory;
    public:
        Library();
        Library(string csvFileAddress);
        //~Library();

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


void Library::printAll(){
    int i=0;
    for (const Book& tempBook : inventory){
        cout << "-------------" << endl;
        cout << "Title: " << tempBook.Title << endl;

        cout << "Author: ";
        if (tempBook.GenderAuthor == "M"){cout << "Mr. ";}
        else if (tempBook.GenderAuthor == "F"){cout << "Mrs. ";}
        cout << tempBook.Author << endl;

        cout << "Authour Nationality: " << tempBook.Nationality << endl;
        cout << "Century of Publishing: " << tempBook.publishDate << endl;
    }
    cout <<  "-------------";
}

//------------------------------------------------------------------------------

vector<Book> parseCSVFile(string csvFileAddress){
    fstream csvFile;
    vector<Book> parsedFile;

    csvFile.open(csvFileAddress,fstream::in);

    if (csvFile.fail()){cout << "CSV file opening failed. \n";}
    else{
        Book tempBook;
        string txt;

        while(getline(csvFile,txt)){
            int i=0;
            string tempString;
            
            while (txt.length() > 0){
                bool commaRule = false;

                if (txt[0] != '|'){
                    tempString.push_back(txt[0]);
                    txt.erase(0,1);
                }
                else{
                    txt.erase(0,1);

                    switch(i){
                        case 0:
                            tempBook.Title = tempString;
                        
                        case 1:
                            tempBook.Author = tempString;

                        case 2:
                            tempBook.Nationality = tempString;
                        
                        case 3:
                            tempBook.GenderAuthor = tempString;

                        case 4:
                            tempBook.publishDate = tempString;
                    }

                    tempString.clear(); i++;
                    
                }
            }
            parsedFile.push_back(tempBook); i=0;
        }
    }
    return parsedFile;
}



int main(){
    fstream dataFile;
    string txt;

    Library mySecondLibrary("Data.csv");

    mySecondLibrary.printAll();

    return 0;
}