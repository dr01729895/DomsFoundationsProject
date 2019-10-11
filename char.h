#ifndef CHAR_H 
#define CHAR_H

#include <iostream>
#include <vector> 

using namespace std;

class Char{
    public:
        //Inits
        Char(void){ c = 'e'; };
        Char(char a){ c = a; };
        //Access / Manip
        char getChar(void){ return c; };
        void setChar(char a){ c = a; };
        //Easy out
        friend ostream& operator<< (ostream& out, Char c){ return out << c.c; };
    private:
        char c;
};

int get_index(vector<Char> V, Char c){
    for(int i=0;i<V.size();i++){
        if(V.at(i).getChar() == c.getChar()){
            return i;
        }
    }
    return -1;
}

//Easily print out the Strings
void printListChar(vector<Char> list){
    for(int i=0;i<list.size();i++){
        cout << list.at(i);
    }
    cout << endl;
}

//Will return the next alphabetical character 
//DOES NOT WORK WITH LAST CHARACTER IN ALPHABET, WILL RETURN epsilon 
Char nextLetter(vector<Char> Alpha, Char c){
    for(int i=0;i<Alpha.size();i++){
        if(c.getChar() == Alpha.at(i).getChar()){
            return Alpha.at(i+1);
        }
    }
    return Char('e');
}

//Will return the next lexicographical word
//Uses nextletter function
vector<Char> nextWord(vector<Char> Alpha, vector<Char>& Curr){

    //Grab last Chars and Inits
    Char lastAc = Alpha.at(Alpha.size()-1);
    Char lastc = Curr.at(Curr.size()-1);
    int len = 0;
    bool resized = false;

    //If epsilon, set it to first Char in Alphabet
    if(Curr.size() == 1 && Curr.at(0).getChar() == 'e'){
        Curr.pop_back();
        Curr.push_back(Alpha.at(0));
        return Curr;
    }

    //Check how many Chars from the right are the last in the Alphabet
    for(int i=0;lastc.getChar() == lastAc.getChar();i++){
        Curr.pop_back();
        len++;

        //If all Chars are the last in the Alphabet, a resize is needed to get the next word
        if(Curr.empty()){
            Curr.push_back(Alpha.at(0));
            resized = true;
        }
        
        //Re-grab last Char
        lastc = Curr.at(Curr.size()-1);
    }

    //If all Chars needed to change, make size + 1 length word of all Alphabet's first Char
    if(!resized){
        lastc = Curr.at(Curr.size()-1);
        Curr.pop_back();
        Curr.push_back(nextLetter(Alpha, lastc));
    }

    //Continue of previous step
    for(int i=0;i<len;i++){
        Curr.push_back(Alpha.at(0));
    }

    return Curr;
}

//Will take in a pos int, and return the Nth string in my Alphabet
vector<Char> returnLexPos(vector<Char> Alpha, int a){
    Char c;
    vector<Char> list;
    if(a <= 1){
        c.setChar('e');
        list.push_back(c);
        return list;
    } else {
        a -= 2;
        list.push_back(Alpha.at(0));
        for(int i=0;i<a;i++){
            list = nextWord(Alpha, list);
        }
    }
    return list;
}

#endif