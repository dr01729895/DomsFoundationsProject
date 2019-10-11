#ifndef NFA_H 
#define NFA_H

#include <iostream>
#include <vector>
#include "char.h"
#include "dfa.h"
#include "tests.h"

using namespace std;

class NFA{
    public:
        NFA();
    private:
        vector<Char> Alpha;
        vector<Char> Nodes;
        Char Start;
        vector<Char> Accepting;
        //Had to make this a 3d vector to store a list of possible transition nodes
        vector< vector< vector<Char> > > Delta;
        //Delta = [ column, column ... column ]
        //each column = [trans for node 0, trans for node 1 ... trans for last node ]
        //each trans is a list of what other nodes it could go to
        //This boils down to a 3d array, which will be very complicated but is the only way I know how to code this
};

#endif