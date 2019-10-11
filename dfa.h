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
        DFA inverted(void);
        //Returns the union
        friend DFA unioned(DFA, DFA);
        //Returns the intersect
        friend DFA intersected(DFA, DFA);
        void print(void);
        friend bool operator== (DFA, DFA);

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

DFA DFA::inverted(void){

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

DFA unioned(DFA d1, DFA d2){

    //Alpha stays the same
    //Nodes is now d1 * d2
    //Start will be start of d1, start of d2
    //Accepted will be anything that was accepted in d1 or d2
    //Delta rows stay the same, but delta columns will be d1 + d2

    for(int i=0;i<d1.Alpha.size();i++){
        if(d1.Alpha.at(i).getChar() != d2.Alpha.at(i).getChar()){
            cout << "Alphabet not the same" << endl;
            exit(1);
        }
    }

    vector<Char> NewNodes;

    for(int i=0;i<d1.Nodes.size()*d2.Nodes.size();i++){
        //New nodes will start with A because it is simple and i like it
        NewNodes.push_back('A'+i);
    }

    //get index of each start
    int x = get_index(d1.Nodes, d1.Start);
    int y = get_index(d2.Nodes, d2.Start);

    Char NewStart = NewNodes.at(x*y);

    vector<vector <Char> > NewDelta;

    for(int i=0;i<d1.Delta.size();i++){
        NewDelta.push_back( vector<Char>{} );
        for(int j=0;j<d1.Delta.at(i).size();j++){
            for(int k=0;k<d2.Delta.size();k++){
                for(int l=0;l<d2.Delta.at(k).size();l++){

                    x = get_index(d1.Nodes, d1.Delta.at(i).at(j));
                    y = get_index(d2.Nodes, d2.Delta.at(k).at(l));

                    NewDelta.at(NewDelta.size()-1).push_back(NewNodes.at(y+x*d1.Delta.size()));
                            
                }
            }
        }
    }

    vector<Char> NewAccepting;

    for(int i=0;i<d1.Accepting.size();i++){
        int z = get_index(d1.Nodes, d1.Accepting.at(i));
        for(int j=0;j<=d2.Accepting.size();j++){
            NewAccepting.push_back(NewNodes.at(d1.Nodes.size()*z + j));
        }
    }

    for(int i=0;i<d2.Accepting.size();i++){
        int z = get_index(d2.Nodes, d2.Accepting.at(i));
        for(int j=0;j<=d1.Accepting.size();j++){
            //Check if it is already in NewAccepting
            int contains = 0;
            for(int k=0;k<NewAccepting.size();k++){
                if(NewAccepting.at(k).getChar() == NewNodes.at(z+j*d1.Nodes.size()).getChar()){
                    contains = 1;
                }
            }
            if(contains == 0){
                NewAccepting.push_back(NewNodes.at(z+j*d1.Nodes.size()));
            }
        }
    }

    // for(int i=0;i<NewAccepting.size();i++){
    //     cout << NewAccepting.at(i).getChar();
    // }

    return { d1.Alpha, NewNodes, NewStart, NewAccepting, NewDelta };

}

DFA intersected(DFA d1, DFA d2){

    //Alpha stays the same
    //Nodes is now d1 * d2
    //Start will be start of d1, start of d2
    //Accepted will be anything that was accepted in d1 AND d2
    //Delta rows stay the same, but delta columns will be d1 + d2

    for(int i=0;i<d1.Alpha.size();i++){
        if(d1.Alpha.at(i).getChar() != d2.Alpha.at(i).getChar()){
            cout << "Alphabet not the same" << endl;
            exit(1);
        }
    }

    vector<Char> NewNodes;

    for(int i=0;i<d1.Nodes.size()*d2.Nodes.size();i++){
        //New nodes will start with A because it is simple and i like it
        NewNodes.push_back('A'+i);
    }

    //get index of each start
    int x = get_index(d1.Nodes, d1.Start);
    int y = get_index(d2.Nodes, d2.Start);

    Char NewStart = NewNodes.at(x*y);

    vector<vector <Char> > NewDelta;

    for(int i=0;i<d1.Delta.size();i++){
        NewDelta.push_back( vector<Char>{} );
        for(int j=0;j<d1.Delta.at(i).size();j++){
            for(int k=0;k<d2.Delta.size();k++){
                for(int l=0;l<d2.Delta.at(k).size();l++){

                    x = get_index(d1.Nodes, d1.Delta.at(i).at(j));
                    y = get_index(d2.Nodes, d2.Delta.at(k).at(l));

                    NewDelta.at(NewDelta.size()-1).push_back(NewNodes.at(y+x*d1.Delta.size()));
                            
                }
            }
        }
    }

    vector<Char> NewAccepting;

    for(int i=0;i<d1.Accepting.size();i++){
        for(int j=0;j<d2.Accepting.size();j++){
            x = get_index(d1.Nodes, d1.Accepting.at(i));
            y = get_index(d2.Nodes, d2.Accepting.at(j));
            
            if(x == y){
                NewAccepting.push_back(NewNodes.at(y+x*d1.Accepting.size()));
            }
        }
    }

    return { d1.Alpha, NewNodes, NewStart, NewAccepting, NewDelta };

}

void DFA::print(void){
    cout << "Alpha: ";
    printListChar(Alpha);
    cout << "Nodes: ";
    printListChar(Nodes);
    cout << "Start: " << Start << endl;
    cout << "Accepting: ";
    printListChar(Accepting);
    
    cout << "Delta: " << endl;

    for(int i=0;i<Delta.size();i++){
        for(int j=0;j<Delta.at(i).size();j++){
            cout << Delta.at(i).at(j);
        }
        cout << endl;
    }

}

bool subset(DFA d1, DFA d2){    
    return d2.eval(d1.find_accepted());
}

bool operator== (DFA d1, DFA d2){
    bool equal = true;

    if(d1.Alpha.size() != d2.Alpha.size()){ equal = false; }
    if(d1.Accepting.size() != d2.Accepting.size()){ equal = false; }
    if(d1.Nodes.size() != d2.Nodes.size()){ equal = false; }

    if(d1.Start.getChar() != d2.Start.getChar()){ equal = false; }

    for(int i=0;i<d1.Alpha.size();i++){
        if(d1.Alpha.at(i).getChar() != d2.Alpha.at(i).getChar()){ equal = false; }
    }
    for(int i=0;i<d1.Accepting.size();i++){
        if(d1.Accepting.at(i).getChar() != d2.Accepting.at(i).getChar()){ equal = false; }
    }
    for(int i=0;i<d1.Nodes.size();i++){
        if(d1.Nodes.at(i).getChar() != d2.Nodes.at(i).getChar()){ equal = false; }
    }
    for(int i=0;i<d1.Delta.size();i++){
        for(int j=0;j<d1.Delta.at(i).size();j++){
            if(d1.Delta.at(i).at(j).getChar() != d2.Delta.at(i).at(j).getChar()){ equal = false; }
        }
    }

    return equal;
}


#endif