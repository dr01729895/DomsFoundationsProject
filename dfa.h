#ifndef DFA_H
#define DFA_H

#include <iostream>
#include <vector> 
#include "char.h"

using namespace std;

class DFA{
    public:
        //Inits
        DFA(vector<Char>, vector<Char>, Char, vector<Char>, vector< vector<Char> >);
        //Run the DFA with a string
        bool eval(vector<Char>);
    private:
        vector<Char> Alpha;
        vector<Char> Nodes;
        Char Start;
        vector<Char> Accepting;
        vector< vector<Char> > Delta;
};

//   DFA          Alpha,          Nodes,   Start,      Accepting,           Delta Function
DFA::DFA(vector<Char> A, vector<Char> Q, Char Q0, vector<Char> F, vector< vector<Char> > D){
    Alpha = A;
    Nodes = Q;
    Start = Q0;
    Accepting = F;
    Delta = D;
}

bool DFA::eval(vector<Char> list){

    //Check if Accepted exists
    if(Accepting.size() == 0){ return false; }

    //Check if empty string is in Accepted
    if(list.size() == 0 || (list.size() == 1 && list.at(0).getChar() == 'e')){
        for(int i=0;i<Accepting.size();i++){
            if(Start.getChar() == Accepting.at(i).getChar()){
                return true;
            }
        }
        return false;
    }

    Char currNode = Start;

    while(list.size()>0){
        
        //Grab row index
        int indexString = -1;
        for(int i=0;i<Alpha.size();i++){
            if(list.at(0).getChar() == Alpha.at(i).getChar()){
                indexString = i;
            }
        }

        //Grab column index
        int indexNode = -1;
        for(int i=0;i<Nodes.size();i++){
            if(currNode.getChar() == Nodes.at(i).getChar()){
                indexNode = i;
            }
        }

        //If Delta does not contain the next step return false
        if(indexString == -1 || indexNode == -1){ return false; }
        if(indexString >= Delta.size() || indexNode >= Delta.at(indexString).size()){ return false; }

        //node = delta[row][column]
        currNode = Delta.at(indexString).at(indexNode);
        //Remove the read term
        list.erase(list.begin());

    }

    //Check if we are at the Accepting Node
    for(int i=0;i<Accepting.size();i++){
        if(Accepting.at(i).getChar() == currNode.getChar())
            return true;
    }

    //If nothing worked, return false
    return false;
}

//Will return a DFA that only accepts the Char given
DFA onlyChar(Char c){
    //Alphabet is only the given Char,
    //2 Nodes incase an empty string is given
    //To get to the accepting string, you must be the first (and only) Char in the Alphabet
    //Anything after will eval to a -1 on dfa.eval() and will return a false
    return DFA({c}, {'A','B'}, 'A', {'B'}, {  {'B'} });
    //Really proud how simple this one is, even though the rest of my code is too complex
}


#endif