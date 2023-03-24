//
//  main.cpp
//  Romen Numeral Converter C++
//
//  Created by William D'Olier on 23/3/2023.
//

#include <iostream>
#include "RomanNumeral.hpp"

using namespace std;
int main(int argc, const char * argv[]) {
    string input;
    cout << "Please enter a roman numeral or number to convert: ";
    cin >> input;
    
    try {
        RomanNumeral rn(stoi(input));
        cout << rn.getString() << "\n";
    } catch(exception e) {
        RomanNumeral rn(input);
        cout << rn.getInt() << "\n";
    }
    
    return 0;
}
