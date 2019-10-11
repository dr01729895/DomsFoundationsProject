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

void DO_TESTS1(void){

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

void union_test(DFA d){

    vector<Char> list = {'0', '1'};

    for(int i=0;i<12;i++){
        cout << setw(3) << i+1 << " : " << d.eval(list) << " : ";
        printListChar(list);
        list = nextWord({'0','1'}, list);
    }

    cout << endl;
}

void DO_TESTS2(void){

    DFA dfa_even_length_binary(
        {'0', '1'},  //Alphabet
        {'A', 'B'},  //Nodes
        'A',         //Start
        {'A'},       //Accepting
        { {'B', 'A'}, {'B', 'A'} }  //Delta
    );

    DFA dfa_odd_length_binary(
        {'0', '1'},  //Alphabet
        {'A', 'B'},  //Nodes
        'A',         //Start
        {'B'},       //Accepting
        { {'B', 'A'}, {'B', 'A'} }  //Delta
    );

    DFA dfa_even_binary_number(
        {'0', '1'},  //Alphabet
        {'A', 'B'},  //Nodes
        'A',         //Start
        {'A'},       //Accepting
        { {'A', 'A'}, {'B', 'B'} }  //Delta
    );

    DFA dfa_odd_binary_number(
        {'0', '1'},  //Alphabet
        {'A', 'B'},  //Nodes
        'A',         //Start
        {'B'},       //Accepting
        { {'A', 'A'}, {'B', 'B'} }  //Delta
    );
    
    DFA d1 = unioned(dfa_even_binary_number, dfa_even_binary_number);
    DFA d2 = unioned(dfa_even_length_binary, dfa_even_binary_number);
    DFA d3 = unioned(dfa_even_binary_number, dfa_even_length_binary);
    DFA d4 = unioned(dfa_even_length_binary, dfa_even_length_binary);

    DFA d5 = unioned(dfa_odd_binary_number, dfa_odd_binary_number);
    DFA d6 = unioned(dfa_odd_binary_number, dfa_odd_length_binary);
    DFA d7 = unioned(dfa_odd_length_binary, dfa_odd_binary_number);
    DFA d8 = unioned(dfa_odd_length_binary, dfa_odd_length_binary);

    DFA d9 = unioned(dfa_even_binary_number, dfa_odd_binary_number);
    DFA d10 = unioned(dfa_even_length_binary, dfa_odd_binary_number);
    DFA d11 = unioned(dfa_even_binary_number, dfa_odd_length_binary);
    DFA d12 = unioned(dfa_even_length_binary, dfa_odd_length_binary);

    DFA d13 = unioned(dfa_even_binary_number, dfa_odd_binary_number);
    DFA d14 = unioned(dfa_even_length_binary, dfa_odd_binary_number);
    DFA d15 = unioned(dfa_even_binary_number, dfa_odd_length_binary);
    DFA d16 = unioned(dfa_even_length_binary, dfa_odd_length_binary);


    union_test(d1);
    union_test(d2);
    union_test(d3);
    union_test(d4);
    union_test(d5);
    union_test(d6);
    union_test(d7);
    union_test(d8);
    union_test(d9);
    union_test(d10);
    union_test(d11);
    union_test(d12);
    union_test(d13);
    union_test(d14);
    union_test(d15);
    union_test(d16);

}

void intersect_test(DFA d){

    vector<Char> list = {'0', '1'};

    for(int i=0;i<12;i++){
        cout << setw(3) << i+1 << " : " << d.eval(list) << " : ";
        printListChar(list);
        list = nextWord({'0','1'}, list);
    }

    cout << endl;
}

void DO_TESTS3(void){

    DFA dfa_even_length_binary(
        {'0', '1'},  //Alphabet
        {'A', 'B'},  //Nodes
        'A',         //Start
        {'A'},       //Accepting
        { {'B', 'A'}, {'B', 'A'} }  //Delta
    );

    DFA dfa_odd_length_binary(
        {'0', '1'},  //Alphabet
        {'A', 'B'},  //Nodes
        'A',         //Start
        {'B'},       //Accepting
        { {'B', 'A'}, {'B', 'A'} }  //Delta
    );

    DFA dfa_even_binary_number(
        {'0', '1'},  //Alphabet
        {'A', 'B'},  //Nodes
        'A',         //Start
        {'A'},       //Accepting
        { {'A', 'A'}, {'B', 'B'} }  //Delta
    );

    DFA dfa_odd_binary_number(
        {'0', '1'},  //Alphabet
        {'A', 'B'},  //Nodes
        'A',         //Start
        {'B'},       //Accepting
        { {'A', 'A'}, {'B', 'B'} }  //Delta
    );
    
    DFA d1 = intersected(dfa_even_binary_number, dfa_even_binary_number);
    DFA d2 = intersected(dfa_even_length_binary, dfa_even_binary_number);
    DFA d3 = intersected(dfa_even_binary_number, dfa_even_length_binary);
    DFA d4 = intersected(dfa_even_length_binary, dfa_even_length_binary);

    DFA d5 = intersected(dfa_odd_binary_number, dfa_odd_binary_number);
    DFA d6 = intersected(dfa_odd_binary_number, dfa_odd_length_binary);
    DFA d7 = intersected(dfa_odd_length_binary, dfa_odd_binary_number);
    DFA d8 = intersected(dfa_odd_length_binary, dfa_odd_length_binary);

    DFA d9 = intersected(dfa_even_binary_number, dfa_odd_binary_number);
    DFA d10 = intersected(dfa_even_length_binary, dfa_odd_binary_number);
    DFA d11 = intersected(dfa_even_binary_number, dfa_odd_length_binary);
    DFA d12 = intersected(dfa_even_length_binary, dfa_odd_length_binary);

    DFA d13 = intersected(dfa_even_binary_number, dfa_odd_binary_number);
    DFA d14 = intersected(dfa_even_length_binary, dfa_odd_binary_number);
    DFA d15 = intersected(dfa_even_binary_number, dfa_odd_length_binary);
    DFA d16 = intersected(dfa_even_length_binary, dfa_odd_length_binary);


    intersect_test(d1);
    intersect_test(d2);
    intersect_test(d3);
    intersect_test(d4);
    intersect_test(d5);
    intersect_test(d6);
    intersect_test(d7);
    intersect_test(d8);
    intersect_test(d9);
    intersect_test(d10);
    intersect_test(d11);
    intersect_test(d12);
    intersect_test(d13);
    intersect_test(d14);
    intersect_test(d15);
    intersect_test(d16);

}

void DO_TESTS4(void){

    vector<DFA> DFAS = {
        {
            {'0', '1'},  //Alphabet
            {'A', 'B'},  //Nodes
            'A',         //Start
            {'A'},       //Accepting
            { {'B', 'A'}, {'B', 'A'} }  //Delta
        },

        {
            {'0', '1'},  //Alphabet
            {'A', 'B'},  //Nodes
            'A',         //Start
            {'B'},       //Accepting
            { {'B', 'A'}, {'B', 'A'} }  //Delta
        },

        {
            {'0', '1'},  //Alphabet
            {'A', 'B'},  //Nodes
            'A',         //Start
            {'A'},       //Accepting
            { {'A', 'A'}, {'B', 'B'} }  //Delta
        },

        {
            {'0', '1'},  //Alphabet
            {'A', 'B'},  //Nodes
            'A',         //Start
            {'B'},       //Accepting
            { {'A', 'A'}, {'B', 'B'} }  //Delta
        },
    };
    
   for(int i=0;i<DFAS.size();i++){
       for(int j=0;j<DFAS.size();j++){
           cout << (DFAS.at(i) == DFAS.at(j)) << endl;
       }
   }

}

void DO_TESTS5(void){

    DFA d1( //Third from the Last is 1
        {'0', '1'},                                 //Alphabet
        {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'},   //Nodes
        'A',                                        //Start
        {'E', 'F', 'G', 'H'},                       //Accepting
        { {'A', 'C', 'H', 'G', 'C', 'G', 'H', 'A'}, {'B', 'D', 'E', 'F', 'D', 'F', 'E', 'B'} }  //Delta
    );

    DFA d2( //Third from the Last is 0
        {'0', '1'},                                 //Alphabet
        {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'},   //Nodes
        'A',                                        //Start
        {'E', 'F', 'G', 'H'},                       //Accepting
        { {'B', 'D', 'E', 'F', 'D', 'F', 'E', 'B'}, {'A', 'C', 'H', 'G', 'C', 'G', 'H', 'A'}}  //Delta
    );

    DFA d3 = d1.inverted(); //should be d2
    DFA d4 = d2.inverted(); //should be d1
    
    DFA d5 = unioned(d1, d3); //should be all strings at least 3 long
    DFA d6 = unioned(d2, d4); //should be all strings at least 3 long

    DFA d7 = intersected(d1, d3); //should be no strings
    DFA d8 = intersected(d2, d4); //should be no strings

}

#endif