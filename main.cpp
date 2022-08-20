#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Book{
    string Title;
    string Author;
    int publishDate;
    char genderAuthor;
};


int main(){
    fstream dataFile;
    string txt;

    dataFile.open("Data.csv",fstream::in);

    if (dataFile.fail()){cout << "Input file opening failed. \n";}
    else{
        while (getline(dataFile,txt,',')){
            cout << txt << endl;
        }
    }




    cout << "Hello World" << endl;
    cout << "This is a new feature!" << endl;
    return 0;
}