#ifndef NFA_H 
#define NFA_H

#include <iostream>
#include <vector>
#include "char.h"
#include "dfa.h"

using namespace std;

class NFA {
    public:
        NFA(vector<Char>, vector<Char>, Char, vector<Char>, vector< vector< vector<Char> > >);
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

//   NFA          Alpha,          Nodes,   Start,      Accepting,                      Delta Function
NFA::NFA(vector<Char> A, vector<Char> Q, Char Q0, vector<Char> F, vector< vector< vector<Char> > > D){
    Alpha = A;
    Nodes = Q;
    Start = Q0;
    Accepting = F;
    Delta = D;
}

//Will return an NFA that is equivalent to the given DFA
NFA dfa_t_nfa(DFA d){
    vector<vector<vector<Char> > > NewDelta;
    for(int i=0;i<d.getDelta().size();i++){
        NewDelta.push_back( vector<vector<Char> >{} );
        for(int j=0;j<d.getDelta().at(i).size();j++){
            NewDelta.at(i).push_back( vector<Char>{} );
            NewDelta.at(i).at(j).push_back(d.getDelta().at(i).at(j).getChar());
        }
    }
    NFA n = {d.getAlpha(), d.getNodes(), d.getStart(), d.getAccepting(), NewDelta};
    return n;
}

#endif