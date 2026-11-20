#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <stdexcept>
#include <cctype>
#include <algorithm>
using namespace std;

char lower(char c){return char(tolower(c));}
string allLower(string inp){
    string result = "";
    for(int i = 0; i < inp.size(); i++){
        result += lower(inp[i]);
    } return result;
}

string msgInputStr(string msg){
    string inp;
    cout << "enter the " << msg << ": ";
    getline(cin >> ws, inp);
    return inp;
}

vector<string> splitString(string txt){
    vector<string> result = {};
    string textToAdd = "";
    for(int i = 0; i < txt.length(); i++){
        if(i == txt.length() - 1 && textToAdd.length() > 0){
            if(txt[i] != ' ') textToAdd += txt[i];
            result.push_back(textToAdd);
            break;
        }

        if(txt[i] == ' ' || txt[i] == ','){
            if(textToAdd.length() != 0){
                result.push_back(textToAdd);
                textToAdd = "";
            } else continue;
        } else {
            textToAdd += txt[i];
        }
    }
    return result;
}

bool checkAgain(){
    bool status;
    while(true){
        cout << "\n";
        string again = msgInputStr("choice if u wanna try again (y/n)");
        if(again == "y"){
            status = true;
            break;
        } else if(again == "n"){
            status = false;
            break;
        } else {
            cout << "invalid choice\n-----------\n";
            continue;
        }
    } return status;
}
void welcome(string appName = ""){cout << "\nwelcome to our " << appName << " app...\n";}

int main(){
    map<string, long long> data = {
        {"zero", 0},
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9},
        {"ten", 10},
        {"eleven", 11},
        {"twelve", 12},
        {"thirteen", 13},
        {"fourteen", 14},
        {"fifteen", 15},
        {"sixteen", 16},
        {"seventeen", 17},
        {"eighteen", 18},
        {"nineteen", 19},
        {"twenty", 20},
        {"thirty", 30},
        {"forty", 40},
        {"fifty", 50},
        {"sixty", 60},
        {"seventy", 70},
        {"eighty", 80},
        {"ninety", 90},
        {"hundred", 100},
        {"thousand", 1000},
        {"million", 1000000},
        {"billion", 1000000000}
    };

    welcome("text to number");
    while(true){
        string inp = allLower(msgInputStr("english numbers"));
        replace(inp.begin(), inp.end(), '-', ' ');
        replace(inp.begin(), inp.end(), ',', ' ');
        vector<string> splittedText = splitString(inp);

        long long total = 0, curr = 0;
        bool err = false;
        for(int i = 0; i < splittedText.size(); i++){
            if(splittedText.at(i) == "and") continue;
            if(splittedText.at(i) == "point") break;
            try {
                if(data.find(splittedText.at(i)) != data.end()){
                    long long numericValue = data.find(splittedText.at(i))->second;
                    if(numericValue >= 100){
                        if(curr == 0) curr = 1;
                        if(numericValue == 100) curr *= 100;
                        else {
                            total += curr * numericValue;
                            curr = 0;
                        }
                    } else curr +=numericValue;
                } else {
                    string errorTxt = "\"" + splittedText.at(i) + "\" is undefined";
                    throw invalid_argument(errorTxt);
                }
            } catch (const exception& e){cerr << "error: " << e.what() << "\n"; err = true; break;}
        }
        !err ? (cout << "the result: " << total + curr << "\n") : cout << "";

        bool status = checkAgain();
        if(status){
            cout << "--------------------\n";
            continue;
        } else {
            cout << "k thx for using our app...\n\n";
            break;
        }
    }
}