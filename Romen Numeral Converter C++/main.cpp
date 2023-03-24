//
//  main.cpp
//  Romen Numeral Converter C++
//
//  Created by William D'Olier on 23/3/2023.
//

#include <iostream>
#include <map>
#include <vector>
#include <regex>
#include "RomanNumeral.hpp"

using namespace std;
int main(int argc, const char * argv[]) {
    
    RomanNumeral rn(10000);
    cout << rn.getString() << "\n";
    
//    string input;
//    cout << "Please enter a roman numeral to convert: ";
//    cin >> input;
//
//    RomanNumeral rn(input);
//
//    cout << rn.getInt() << endl;
    
    return 0;
}
