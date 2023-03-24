//
//  RomanNumeral.hpp
//  Romen Numeral Converter C++
//
//  Created by William D'Olier on 24/3/2023.
//

#ifndef RomanNumeral_hpp
#define RomanNumeral_hpp

#include <iostream>
#include <map>
#include <vector>
#include <regex>

#endif /* RomanNumeral_hpp */

using namespace std;
class RomanNumeral {
private:
    int intNum;
    string stringNum;
    
    string getNumeral(string char1, string char2, string char3, int num);
    
    map<char, int> numerals{
        {'i', 1},
        {'v', 5},
        {'x', 10},
        {'l', 50},
        {'c', 100},
        {'d', 500},
        {'m', 1000}
    };
    
    int calculateInt();
    string calculateString();
public:
    RomanNumeral(int num);
    RomanNumeral(string num);
    
    int getInt();
    string getString();
};
