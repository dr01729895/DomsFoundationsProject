#include <iostream>
#include <vector>
#include "char.h"
#include "dfa.h"

using namespace std;

int main(int argc, char* argv[]){

    vector<Char> Alpha{'0','1','2','3'};

    vector<Char> list;
    vector< vector<Char> > Delta; //Must be a vector of a vector of Chars, [ <column> <column> ... <column>]

    //WIll not accept any string
    //DFA - Alpha, Nodes, Start, Accepting, Delta Function
    DFA dfa_no_strings(Alpha, {'A'}, 'A', {}, {{}});

    //WIll not accept any string
    //DFA - Alpha, Nodes, Start, Accepting, Delta Function
    DFA dfa_empty_string(Alpha, {'A','B'}, 'A', {'A'}, {{}});

    cout << dfa_no_strings.eval({'1','0','2','3'}) << endl;
    cout << dfa_no_strings.eval({'3'}) << endl;
    cout << dfa_no_strings.eval({'e'}) << endl;
    cout << dfa_no_strings.eval({'1','2','0'}) << endl;
    cout << dfa_no_strings.eval({}) << endl;

    cout << endl;

    cout << dfa_empty_string.eval({'1','0','2','3'}) << endl;
    cout << dfa_empty_string.eval({'3'}) << endl;
    cout << dfa_empty_string.eval({'1','2','0'}) << endl;
    cout << dfa_empty_string.eval({'e'}) << endl;
    cout << dfa_empty_string.eval({}) << endl;

    cout << endl;

    DFA only = onlyChar('7');
    cout << only.eval({'7'}) << endl;
    cout << only.eval({'5'}) << endl;
    cout << only.eval({'7', '5'}) << endl;
    cout << only.eval({'5', '5'}) << endl;
    cout << only.eval({'W', '7'}) << endl;

    cout << endl;

    only = onlyChar('W');
    cout << only.eval({'W'}) << endl;
    cout << only.eval({'e'}) << endl;
    cout << only.eval({'7'}) << endl;
    cout << only.eval({}) << endl; 


    return 0;
}