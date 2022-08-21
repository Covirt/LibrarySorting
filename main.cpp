#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//------------------------------------------------------------------------------

struct Book{
    string Title;
    string Author;
    string Nationality;
    string PublishDate; //idealy this would be an int
    string GenderAuthor; //idealy this would be a char
};

//------------------------------------------------------------------------------

vector<Book> parseCSVFile(const string csvFileAddress);
void printBook(const Book myBook);


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
        void printFromAttribute(string searchAttribute, string searchRequest);

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
    for (const Book& tempBook : inventory){
        printBook(tempBook);
    }
}

void Library::printFromAttribute(string searchAttribute, string searchRequest){

    // this step can be optimised better to have less copy pastes
    // but that is beyong my expertise

    bool printedBook = false;

    if (searchAttribute == "Title"){
        for (const Book& tempBook : inventory){
            if (tempBook.Title == searchRequest){printBook(tempBook);printedBook = true;}
        }
    }

    else if (searchAttribute == "Author"){
        for (const Book& tempBook : inventory){
            if (tempBook.Author == searchRequest){printBook(tempBook);printedBook = true;}
        }
    }

    else if (searchAttribute == "Nationality"){
        for (const Book& tempBook : inventory){
            if (tempBook.Nationality == searchRequest){printBook(tempBook);printedBook = true;}
        }
    }

    else if (searchAttribute == "PublishDate"){
        for (const Book& tempBook : inventory){
            if (tempBook.PublishDate == searchRequest){printBook(tempBook);printedBook = true;}
        }
    }

    else if (searchAttribute == "GenderAuthor"){
        for (const Book& tempBook : inventory){
            if (tempBook.GenderAuthor == searchRequest){printBook(tempBook);printedBook = true;}
        }
    }

    else {cout << "searchAttribute does not match any of the book's attributes" << endl;}
    if (!printedBook){cout << "No books match that definition" << endl;}
}


//------------------------------------------------------------------------------



vector<Book> parseCSVFile(const string csvFileAddress){
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

                if (txt[0] != '|'){ // until you have read a whole attribute, read the line
                    tempString.push_back(txt[0]);
                    txt.erase(0,1);
                }
                else{ // when you have read a whole line
                    txt.erase(0,1); // remove the comma

                    switch(i){
                        // associate the string in the correct book attribute
                        case 0:
                            tempBook.Title = tempString;
                        
                        case 1:
                            tempBook.Author = tempString;

                        case 2:
                            tempBook.Nationality = tempString;
                        
                        case 3:
                            tempBook.GenderAuthor = tempString;

                        case 4:
                            tempBook.PublishDate = tempString;
                    }

                    tempString.clear(); i++;
                    
                }
            }
            parsedFile.push_back(tempBook); i=0; // when a whole line has been read, add the book to the inventory
        }
    }
    return parsedFile;
}

void printBook(const Book myBook){
    cout << "-------------" << endl;
    cout << "Title: " << myBook.Title << endl;

    cout << "Author: ";
    if (myBook.GenderAuthor == "M"){cout << "Mr. ";}
    else if (myBook.GenderAuthor == "F"){cout << "Mrs. ";}
    cout << myBook.Author << endl;

    cout << "Authour Nationality: " << myBook.Nationality << endl;
    cout << "Century of Publishing: " << myBook.PublishDate << endl;
}

int main(){
    fstream dataFile;
    string txt;

    Library myLibrary("Data.csv");

    //myLibrary.printAll();
    //myLibrary.printFromAttribute("GenderAuthor","F");

    return 0;
}