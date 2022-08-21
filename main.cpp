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