#include <iostream>
#include <vector>
#include "char.h"
#include "dfa.h"
#include "tests.h"

using namespace std;

int main(int argc, char* argv[]){

    //Odd Binary Number DFA
    DFA d(
        {'0', '1'},  //Alphabet
        {'A', 'B'},  //Nodes
        'A',         //Start
        {'B'},       //Accepting
        { {'A', 'A'}, {'B', 'B'} }  //Delta
    );
    vector<Char> list;

    list = d.find_accepted();

    printListChar(list);

    d = d.invert();

    list = d.find_accepted();

    printListChar(list);

    return 0;
}