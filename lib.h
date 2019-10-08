#ifndef LIB 
#define LIB

#include <iostream>
#include <vector> 

using namespace std;

class Char{
    public:
        //Inits
        Char(void){ c = '\0'; };
        Char(char a){ c = a; };
        //Access / Manip
        char getChar(void){ return c; };
        void setChar(char a){ c = a; };
        //Easy out
        friend ostream& operator<< (ostream& out, Char c){ return out << c.c; };
    private:
        char c;
};

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

    Char lastAc = Alpha.at(Alpha.size()-1);
    Char lastc = Curr.at(Curr.size()-1);
    int len = 0;
    bool resized = false;

    if(Curr.size() == 1 && Curr.at(0).getChar() == 'e'){
        Curr.pop_back();
        Curr.push_back(Alpha.at(0));
        return Curr;
    }

    for(int i=0;lastc.getChar() == lastAc.getChar();i++){
        Curr.pop_back();
        len++;

        if(Curr.empty()){
            Curr.push_back(Alpha.at(0));
            resized = true;
        }
        
        lastc = Curr.at(Curr.size()-1);
    }

    if(!resized){
        lastc = Curr.at(Curr.size()-1);
        Curr.pop_back();
        Curr.push_back(nextLetter(Alpha, lastc));
    }

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