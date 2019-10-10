#ifndef DFA_H
#define DFA_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "char.h"

using namespace std;

class DFA{
    public:
        //Inits
        DFA(vector<Char>, vector<Char>, Char, vector<Char>, vector< vector<Char> >);
        //Run the DFA with a string
        bool eval(vector<Char>);
        //Run the DFA and return strings of nodes visited
        vector<Char> eval_trace(vector<Char>);
        //Return an accepted string
        vector<Char> find_accepted(void);
        //Returns the compliment
        DFA invert(void);
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

    //Check DFA accepts all
    if(Accepting.size() == 1 && Accepting.at(0).getChar() == Start.getChar() && Alpha.size() == 0){
        return true;
    }

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

//Will return if the DFA returns true or false for the list
bool test_dfa(DFA d, vector<Char> list){
    return d.eval(list);
}

vector<Char> DFA::eval_trace(vector<Char> list){

    vector<Char> Trace;

    //Check if empty string is given and in accepted
    if(list.size() == 0 || (list.size() == 1 && list.at(0).getChar() == 'e')){
        for(int i=0;i<Accepting.size();i++){
            if(Start.getChar() == Accepting.at(i).getChar()){
                Trace.push_back(Start);
                return Trace;
            }
        }
        return Trace;
    }

    Char currNode = Start;
    Trace.push_back(Start);

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

        //If Delta does not contain the next step return trace already done
        if(indexString == -1 || indexNode == -1){ return Trace; }
        if(indexString >= Delta.size() || indexNode >= Delta.at(indexString).size()){ return Trace; }

        //node = delta[row][column]
        currNode = Delta.at(indexString).at(indexNode);
        //Remove the read term
        list.erase(list.begin());
        //Add to trace
        Trace.push_back(currNode);

    }

    //If nothing worked, return false
    return Trace;
}

//Will return accepted string or an empty string if nothing is accepted
//If an empty string would normally be accepted, will return a string with just epsilon
vector<Char> DFA::find_accepted(void){
    // Alpha, Nodes, Start, Accepting, Delta

    vector<Char> Accept;

    //Check if accepting nodes has any node
    if(Accepting.size() == 0 ){ return Accept; } 

    //Check if accepting is a node
    int accept_exists = 0;
    for(int i=0;i<Nodes.size();i++){
        for(int j=0;j<Accepting.size();j++){
            if(Nodes.at(i).getChar() == Accepting.at(j).getChar()){
                accept_exists = 1;
            }
        }
    }

    //If accepting isnt a node, you cannot go to it
    if(accept_exists == 0){ return Accept; }

    //If the start node is accepting, just return epsilon
    for(int i=0;i<Accepting.size();i++){
        if(Start.getChar() == Accepting.at(i).getChar()){
            Accept.push_back('e');
            return Accept;
        }
    }

    vector<Char> Visited;
    Visited.push_back(Start);

    while(true){        
        //for all visited,
        //find its index in alpha,
        //for all columns in Delta, add delta[all][index] if it is not already in visited
        //Check if any nodes are in accepted
        //if they are, find a way to get from start to that node

        //Check if any visited nodes are accepted
        for(int i=0;i<Visited.size();i++){
            for(int j=0;j<Accepting.size();j++){
                if(Visited.at(i).getChar() == Accepting.at(j).getChar()){
                    
                    Char target = Visited.at(i);
                    
                    while(true){                    

                        for(int x=0;x<Delta.size();x++){
                            for(int y=0;y<Delta.at(x).size();y++){
                                if(Delta.at(x).at(y).getChar() == target.getChar()){
                                    target = Nodes.at(y);
                                    Accept.push_back(Alpha.at(x));
                                    
                                    if(target.getChar() == Start.getChar()){
                                        reverse(Accept.begin(), Accept.end());
                                        return Accept;
                                    }
                                }
                            }
                        }

                    }

                }
            }
        }
        


            //Loop on all visited
        for(int i=0;i<Visited.size();i++){
            //Find Visited.at(i)'s index within the Alpha
            int index = -1;
            for(int j=0;j<Nodes.size();j++){
                if(Visited.at(i).getChar() == Nodes.at(j).getChar()){
                    index = j;
                }
            }

            //Loop all columns of Delta
            for(int j=0;j<Delta.size();j++){
                if(Delta.at(j).size() > index){
                    Char Next = Delta.at(j).at(index);
                    int found_in_vis = 0;

                    //Find out if Next is in Visited
                    for(int k=0;k<Visited.size();k++){
                        if(Visited.at(k).getChar() == Next.getChar()){
                            found_in_vis = 1;
                        }
                    }
                    
                    //If not found, add to Visited
                    if(found_in_vis == 0){
                        Visited.push_back(Next);
                    }
                }
            }
        }
    }
    //Just in case
    return {'e'};
}

DFA DFA::invert(void){

    vector<Char> newAccepting;

    int new_a = 0;

    for(int i=0;i<Nodes.size();i++){
        for(int j=0;j<Accepting.size();j++){
            if(Nodes.at(i).getChar() == Accepting.at(j).getChar()){
                new_a = 1;
            }
        }
        if(new_a == 0){
            newAccepting.push_back(Nodes.at(i));
        }
    }

    return {Alpha, Nodes, Start, newAccepting, Delta};

}


#endif