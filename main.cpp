# include <iostream>
# include <sstream>
# include <string>
# include <array>
# include "PrefixConvert.h"

using namespace std;

// Function used to count number of spaces
int space_counter(string input){
    int counter = 0;
    for (int i = 0; i < input.length(); i++){
        if (isspace(input.at(i)))
            counter ++;
    }
    return counter;
}

int main () {
    string S, temp; 
    getline(cin, S);
    stringstream X(S);
    int size = 0;
    int space_counted = space_counter(S);
    string input_element[space_counted + 1];
    while (getline(X, temp, ' ')) {
        input_element[size] = temp;
        size++;
    }   
    
    PrefixConvert pf;
    cout << pf.convert(input_element, size);

}

// g++ -o main.out -std=c++11 -O2 -Wall *.cpp