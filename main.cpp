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
    vector<vector<string>> BigData;
    vector<string> tempLine;

    dataFile.open("Data.csv",fstream::in);

    if (dataFile.fail()){cout << "Input file opening failed. \n";}
    else{
        int i = 0;
        while (getline(dataFile,txt,',')){
            tempLine.push_back(txt);
            cout << i << "|" <<txt << endl;
            if (txt.find("\n") != string::npos){
                i++;
                BigData.push_back(tempLine);
                tempLine.clear();
            }
        }
    }
    return 0;
}