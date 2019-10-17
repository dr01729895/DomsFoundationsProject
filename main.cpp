#include <iostream>
#include <vector>
#include "char.h"
#include "dfa.h"
#include "nfa.h"
#include "tests.h"

using namespace std;

int main(int argc, char* argv[]){

    //Alpha, Nodes, Start, Accepting, Delta Function
    //Delta = [Column 1  Column 2 ... Column n]
    //Column = [possible nodes]
    NFA third_from_last_one(
        //Alphabet
        {'0','1'},
        //List of Nodes
        {'A','B','C','D'},
        //Starting Node
        'A',
        //Accepting Nodes
        {'D'},
        //Delta Function
        {
            //Transition if first alphabet char is found 
            {
                //a0=a, b0=c, c0=d, d0=a 
                {'A'}, {'C'}, {'D'}, {'A'}
            },
            //Transition if second alphabet char is found 
            { 
                //a1=a or b, b1=c, c1=d, d1=a
                {'A','B'}, {'C'}, {'D'}, {'A'} 
            } 
        }
    );

    NFA third_from_last_zero(
        //Alphabet
        {'0','1'},
        //List of Nodes
        {'A','B','C','D'},
        //Starting Node
        'A',
        //Accepting Nodes
        {'D'},
        //Delta Function
        {
            //Transition if first alphabet char is found 
            {
                //a0=a or b, b0=c, c0=d, d0=a 
                {'A','B'}, {'C'}, {'D'}, {'A'}
            },
            //Transition if second alphabet char is found 
            { 
                //a1=a, b1=c, c1=d, d1=a
                {'A'}, {'C'}, {'D'}, {'A'} 
            } 
        }
    );

    NFA contains_zero_one_zero(
        //Alphabet
        {'0','1'},
        //List of Nodes
        {'A','B','C','D'},
        //Starting Node
        'A',
        //Accepting Nodes
        {'D'},
        //Delta Function
        {
            //Transition if first alphabet char is found 
            {
                //a0=a or b, b0=a, c0=d, d0=d 
                {'A','B'}, {'A'}, {'D'}, {'D'}
            },
            //Transition if second alphabet char is found 
            { 
                //a1=a, b1=c, c1=a, d1=d
                {'A'}, {'C'}, {'A'}, {'D'} 
            } 
        }
    );

    third_from_last_one.print();
    third_from_last_zero.print();
    contains_zero_one_zero.print();

    return 0;
}