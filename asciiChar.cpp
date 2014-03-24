#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void split(vector<string> &tokens, const string &text, char sep);
char convertHexPair(string hex);

int main() {
    string guestComment = "48-65-79-20-67-69-72-6c-2c-20-49-20-61-6c-77-61-79-73-20-74-68-6f-75-67-68-74-20-4c-6f-76-65-20-77-61-73-20-61-20-73-74-61-74-69-63-20-63-6c-61-73-73-20-75-6e-74-69-6c-20-79-6f-75-20-6d-61-64-65-20-61-6e-20-69-6e-73-74-61-6e-63-65-20-6f-66-20-69-74";
    vector<string> guestArr;
    split(guestArr, guestComment, '-');
    for(int i = 0; i < guestArr.size(); ++i) {
        //char chrz = guestArr[i];
        cout<<convertHexPair(guestArr[i]);
    }
    cout<<endl;
    return 0;
}

char convertHexPair(string hex) {
    long lNum = strtol(hex.c_str(), NULL, 16);
    return (char)lNum;
}

//https://stackoverflow.com/questions/236129/how-to-split-a-string-in-c
void split(vector<string> &tokens, const string &text, char sep) {
  int start = 0, end = 0;
  while ((end = text.find(sep, start)) != string::npos) {
    tokens.push_back(text.substr(start, end - start));
    start = end + 1;
  }
  tokens.push_back(text.substr(start));
}