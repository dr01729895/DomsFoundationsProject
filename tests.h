#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include <vector> 
#include <iomanip>
#include "char.h"
#include "dfa.h"

using namespace std;

void TEST_no_strings(DFA d){
    vector<Char> list = {'0'};

    cout << "\n 1. No Strings Tests: " << endl;

    cout << test_dfa(d, list) << " - String:  ";
    printListChar(list);
    list = {'1'};
    cout << test_dfa(d, list) << " - String:  ";
    printListChar(list);

}

void TEST_empty_string(DFA d){
    vector<Char> list = {'e'};

    cout << "\n 2. Empty String Tests: " << endl;

    cout << test_dfa(d, list) << " - String:  ";
    printListChar(list);
    list = {'A'};
    cout << test_dfa(d, list) << " - String:  ";
    printListChar(list);

}

void TEST_only_char(DFA d){
    vector<Char> list = {'A'};

    cout << "\n 3. Only Char Tests: " << endl;

    cout << test_dfa(d, list) << " - String:  ";
    printListChar(list);
    list = {'B'};
    cout << test_dfa(d, list) << " - String:  ";
    printListChar(list);
    list = {'C'};
    cout << test_dfa(d, list) << " - String:  ";
    printListChar(list);
}

void TEST_even_length(DFA d){
    vector<Char> list = {'e'};

    cout << "\n 4. Even Length Tests: " << endl;

    //First 11 tests
    for(int i=0;i<11;i++){
        cout << setw(2) << i+1 << " - Out: " << test_dfa(d, list) << " - String:  ";
        printListChar(list);
        list = nextWord( {'0','1'}, list);
    }
    //Final test to get 6 false and 6 true
    list = {'0','0','1','0'};
    cout << setw(2) << 12 << " - Out: " << test_dfa(d, list) << " - String:  ";
    printListChar(list);
}

void TEST_odd_length(DFA d){
    vector<Char> list = {'e'};

    cout << "\n 5. Odd Length Tests: " << endl;

    //First 11 tests
    for(int i=0;i<11;i++){
        cout << setw(2) << i+1 << " - Out: " << test_dfa(d, list) << " - String:  ";
        printListChar(list);
        list = nextWord( {'0','1'}, list);
    }
    //Final test to get 6 false and 6 true
    list = {'0','0','1','0'};
    cout << setw(2) << 12 << " - Out: " << test_dfa(d, list) << " - String:  ";
    printListChar(list);
}

void TEST_even_binary(DFA d){
    vector<Char> list = {'e'};

    cout << "\n 6. Even Binary Number Tests: " << endl;

    //First 11 tests
    for(int i=0;i<11;i++){
        cout << setw(2) << i+1 << " - Out: " << test_dfa(d, list) << " - String:  ";
        printListChar(list);
        list = nextWord( {'0','1'}, list);
    }
    //Final test to get 6 false and 6 true
    list = {'1','1','1'};
    cout << setw(2) << 12 << " - Out: " << test_dfa(d, list) << " - String:  ";
    printListChar(list);
}

void TEST_odd_binary(DFA d){
    vector<Char> list = {'e'};

    cout << "\n 7. Odd Binary Number Tests: " << endl;

    //First 11 tests
    for(int i=0;i<11;i++){
        cout << setw(2) << i+1 << " - Out: " << test_dfa(d, list) << " - String:  ";
        printListChar(list);
        list = nextWord( {'0','1'}, list);
    }
    //Final test to get 6 false and 6 true
    list = {'1','1','1'};
    cout << setw(2) << 12 << " - Out: " << test_dfa(d, list) << " - String:  ";
    printListChar(list);
}

void TEST_Dom_string(DFA d){
    vector<Char> list = {'D', 'o', 'm'};
    cout << "\n 8. Dom String Tests: " << endl;
    cout << test_dfa(d, list) << " - String: ";
    printListChar(list);
    list = {'J', 'a', 'y'};
    cout << test_dfa(d, list) << " - String: ";
    printListChar(list);
}

void TEST_third_from_last_one(DFA d){
    vector<Char> list = {'0', '1', '0', '0'};

    cout << "\n 9. Third From Last is a 1 Tests: " << endl;

    for(int i=0;i<8;i++){
        cout << setw(2) << i+1 << " - Out: " << test_dfa(d, list) << " - String:  ";
        printListChar(list);
        list = nextWord( {'0','1'}, list);
    }

    list = {'0','0','1','0','0','1','1','0'};
    for(int i=0;i<4;i++){
        cout << setw(2) << i+9 << " - Out: " << test_dfa(d, list) << " - String:  ";
        printListChar(list);
        list = nextWord( {'0','1'}, list);
    }
}

void TEST_contains_even(DFA d){
    vector<Char> list = {'3', '0'};

    cout << "\n10. Contains an Even Number Tests: " << endl;

    for(int i=0;i<10;i++){
        cout << setw(2) << i+1 << " - Out: " << test_dfa(d, list) << " - String:  ";
        printListChar(list);
        list = nextWord( {'0', '1', '2', '3', '4', '5', '6', '7', '8' ,'9'}, list);
    }

    list = {'1','3','5','7','9'};
    cout << setw(2) << 11 << " - Out: " << test_dfa(d, list) << " - String:  ";
    printListChar(list);
    list = {'2','3','6','7','9'};
    cout << setw(2) << 12 << " - Out: " << test_dfa(d, list) << " - String:  ";
    printListChar(list);
}

void TEST_only_vowels(DFA d){
    vector<Char> list = {'A'};

    cout << "\n11. Contains Only Vowels Tests: " << endl;

    for(int i=0;i<6;i++){
        cout << setw(2) << i+1 << " - Out: " << test_dfa(d, list) << " - String:  ";
        printListChar(list);
        list = nextWord( {'A', 'E', 'I', 'O', 'U'}, list);
    }

    list = {'N'};
    for(int i=0;i<6;i++){
        cout << setw(2) << i+7 << " - Out: " << test_dfa(d, list) << " - String:  ";
        printListChar(list);
        list.push_back('O');
    }

}

void TEST_everything(DFA d){
    vector<Char> list = {'W'};

    cout << "\n12. Everything Tests: " << endl;

    for(int i=0;i<12;i++){
        cout << setw(2) << i+1 << " - Out: " << test_dfa(d, list) << " - String:  ";
        printListChar(list);
        list.push_back('A' + i);
    }
}

void Do_TESTS(void){

    DFA dfa_no_strings(
        {'e'},  //Alphabet
        {'A'},  //Nodes
        'A',    //Start
        {},     //Accepting
        { {} }  //Delta
    );

    TEST_no_strings(dfa_no_strings);

    DFA dfa_empty_string(
        {'e'},      //Alphabet
        {'A','B'},  //Nodes
        'A',        //Start
        {'A'},      //Accepting
        { {} }      //Delta
    );

    TEST_empty_string(dfa_empty_string);

    DFA dfa_only_char = onlyChar('A');

    TEST_only_char(dfa_only_char);

    DFA dfa_even_length_binary(
        {'0', '1'},  //Alphabet
        {'A', 'B'},  //Nodes
        'A',         //Start
        {'A'},       //Accepting
        { {'B', 'A'}, {'B', 'A'} }  //Delta
    );

    TEST_even_length(dfa_even_length_binary);

    DFA dfa_odd_length_binary(
        {'0', '1'},  //Alphabet
        {'A', 'B'},  //Nodes
        'A',         //Start
        {'B'},       //Accepting
        { {'B', 'A'}, {'B', 'A'} }  //Delta
    );

    TEST_odd_length(dfa_odd_length_binary);

    DFA dfa_even_binary_number(
        {'0', '1'},  //Alphabet
        {'A', 'B'},  //Nodes
        'A',         //Start
        {'A'},       //Accepting
        { {'A', 'A'}, {'B', 'B'} }  //Delta
    );

    TEST_even_binary(dfa_even_binary_number);

    DFA dfa_odd_binary_number(
        {'0', '1'},  //Alphabet
        {'A', 'B'},  //Nodes
        'A',         //Start
        {'B'},       //Accepting
        { {'A', 'A'}, {'B', 'B'} }  //Delta
    );

    TEST_odd_binary(dfa_odd_binary_number);

    DFA dfa_my_name_strings(
        {'D', 'o', 'm'},            //Alphabet
        {'A', 'B', 'C', 'D', 'X'},  //Nodes
        'A',                        //Start
        {'D'},                      //Accepting
        { {'B'}, {'X', 'C'}, {'X', 'X', 'D'} }  //Delta
    );

    TEST_Dom_string(dfa_my_name_strings);

    DFA dfa_third_from_last_one(
        {'0', '1'},                                 //Alphabet
        {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'},   //Nodes
        'A',                                        //Start
        {'E', 'F', 'G', 'H'},                       //Accepting
        { {'A', 'C', 'H', 'G', 'C', 'G', 'H', 'A'}, {'B', 'D', 'E', 'F', 'D', 'F', 'E', 'B'} }  //Delta
    );

    TEST_third_from_last_one(dfa_third_from_last_one);

    DFA dfa_contains_even_num(
        {'0', '1', '2', '3', '4', '5', '6', '7', '8' ,'9'}, //Alphabet
        {'A', 'B'},                                         //Nodes
        'A',                                                //Start
        {'B'},                                              //Accepting
        { {'B','B'},{'A','B'},{'B','B'},{'A','B'},{'B','B'},{'A','B'},{'B','B'},{'A','B'},{'B','B'},{'A','B'} }  //Delta
    );

    TEST_contains_even(dfa_contains_even_num);

    DFA dfa_only_vowels(
        {'A', 'E', 'I', 'O', 'U'},  //Alphabet
        {'A', 'B'},                 //Nodes
        'A',                        //Start
        {'B'},                      //Accepting
        { {'B', 'B'},{'B', 'B'},{'B', 'B'},{'B', 'B'},{'B', 'B'} }  //Delta
    );

    TEST_only_vowels(dfa_only_vowels);

    DFA dfa_everything(
        {},     //Alphabet
        {'A'},  //Nodes
        'A',    //Start
        {'A'},  //Accepting
        { {} }  //Delta
    );

    TEST_everything(dfa_everything);
}

#endif