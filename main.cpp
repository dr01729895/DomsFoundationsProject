#include <iostream>
#include <vector>
#include "lib.h"

using namespace std;

int main(int argc, char* argv[]){

    //Setting epsilon, it will always be represented as 'e'
    Char epsilon('e');

    //Setting my Alphabet
    vector<Char> Alpha;
    Alpha.push_back(Char('0'));
    Alpha.push_back(Char('1'));
    Alpha.push_back(Char('2'));
    Alpha.push_back(Char('3'));

    //Using C++'s vectors as my Strings
    vector<Char> list;

    //Used to test the returnLexPos function
    for(int i=1;i<=50;i++){
        list = returnLexPos(Alpha, i);
        cout << i << " : ";
        printListChar(list);
    }

    return 0;
}