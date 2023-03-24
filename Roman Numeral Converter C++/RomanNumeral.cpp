//
//  RomanNumeral.cpp
//  Romen Numeral Converter C++
//
//  Created by William D'Olier on 24/3/2023.
//

#include "RomanNumeral.hpp"
#include <iostream>
#include <map>
#include <vector>
#include <regex>

using namespace std;
int RomanNumeral::calculateInt() {
    int total = 0;
    for(int i = 0; i < this->stringNum.length(); i++) {
        int value = this->numerals[this->stringNum[i]];
        if(this->numerals[this->stringNum[i+1]] > value) {
            total -= value;
        } else {
            total += value;
        }
    }
    
    this->intNum = total;
        
    return total;
}

string RomanNumeral::getNumeral(string char1, string char2, string char3, int num) {
    string result = "";
    switch (num) {
        case 0:
            break;
        case 1:
            result += char1;
            break;
        case 2:
            result += (char1 + char1);
            break;
        case 3:
            result += (char1 + char1 + char1);
            break;
        case 4:
            result += (char1 + char2);
            break;
        case 5:
            result += (char2);
            break;
        case 6:
            result += (char2 + char1);
            break;
        case 7:
            result += (char2 + char1 + char1);
            break;
        case 8:
            result += (char2 + char1 + char1 + char1);
            break;
        case 9:
            result += (char1 + char3);
            break;
        default:
            break;
    }
    
    return result;
}

string RomanNumeral::calculateString() {
    string result = "";
    
    int thousands = this->intNum / 1000;
    int hundreds = this->intNum / 100 % 10;
    int tens = this->intNum / 10 % 10;
    int ones = this->intNum % 10;
    
    for(int i = 0; i < thousands; i++) {
        result += "M";
    }
    result += this->getNumeral("C", "D", "M", hundreds);
    result += this->getNumeral("X", "L", "C", tens);
    result += this->getNumeral("I", "V", "X", ones);
    
    this->stringNum = result;
    return result;
}

RomanNumeral::RomanNumeral(int num) {
    this->intNum = num;
    
    this->calculateString();
    return;
}
RomanNumeral::RomanNumeral(std::string num) {
    transform(num.begin(), num.end(), num.begin(),
        [](unsigned char c){ return tolower(c); });
    regex test("^m*(cm|cd|d?c{0,3})(xc|xl|l?x{0,3})(ix|iv|v?i{0,3})$");
    bool isValid = regex_match(num, test);
    if(isValid) {
        this->stringNum = num;
        this->calculateInt();
    } else {
        std::runtime_error invalid("Invalid Number!");
        throw invalid;
        return;
    }
}
    
int RomanNumeral::getInt() {
    return this->intNum;
}
    
string RomanNumeral::getString() {
    return this->stringNum;
}

