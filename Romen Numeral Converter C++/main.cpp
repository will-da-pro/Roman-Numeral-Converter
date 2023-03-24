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

using namespace std;
class RomanNumeral {
private:
    int intNum;
    string stringNum;
    
    map<char, int> numerals{
        {'i', 1},
        {'v', 5},
        {'x', 10},
        {'l', 50},
        {'c', 100},
        {'d', 500},
        {'m', 1000}
    };
public:
    RomanNumeral(int num) {
        this->intNum = num;
    }
    RomanNumeral(std::string num) {
        transform(num.begin(), num.end(), num.begin(),
            [](unsigned char c){ return tolower(c); });
        regex test("m*(cm|cd|d?c{0,3})(xc|xl|l?x{0,3})(ix|iv|v?i{0,3})");
        bool isValid = regex_match(num, test);
        if(isValid) {
            this->stringNum = num;
        } else {
            throw "invalid number";
            return;
        }
    }
    
    int toInt() {
        vector<pair<int, int>> itemList;
        for(int i = 0; i < this->stringNum.length(); i++) {
            int val = this->numerals[this->stringNum[i]];
            cout << "value: " << val << endl;
            if(itemList.size() == 0) {
                cout << "no\n";
                itemList.push_back(make_pair(val, 1));
            } else if(itemList[itemList.size() - 1].first == val) {
                cout << "exists\n";
                itemList[itemList.size() - 1].second += 1;
            } else {
                cout << "empty\n";
                itemList.push_back(make_pair(val, 1));
            }
            cout << "first: " << itemList[itemList.size() - 1].first << endl;
            cout << "last: " << itemList[itemList.size() - 1].second << endl;
            cout << i << ", " << this->stringNum[i] << "\n\n-------------------\n\n";
        }
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    string input;
    cout << "Please enter a roman numeral to convert: ";
    cin >> input;
    
    RomanNumeral rn(input);
    rn.toInt();
    
    return 0;
}
