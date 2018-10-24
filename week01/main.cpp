#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;

int main() {

    char buff[50];
    char* str;
    int n;
    ifstream fin("../INPUT.TXT");
    fin.getline(buff, 50);
    n = atoi(buff);
    cout << n;
    char sym = ' ', ch; //
    int counter = 0;

    do
    {
        ch = fin.get();

        str[counter++] = ch;
    } while( ch != sym || counter < n || !fin.eof() );
    str[counter] = '\0';

    cout << n;
    return 0;
}