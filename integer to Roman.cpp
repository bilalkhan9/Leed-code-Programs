#include <iostream>
#include <string>


struct ValueSymbol {
    int value;
    std::string symbol;
};


std::string intToRoman(int num) {
    
    const ValueSymbol valueSymbolPairs[] = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    };

    std::string result;

    
    for (int i = 0; i < 13; ++i) {
        while (num >= valueSymbolPairs[i].value) {
            result += valueSymbolPairs[i].symbol;
            num -= valueSymbolPairs[i].value;
        }
    }

    return result;
}

int main() {
    int num = 3749; 
    std::string roman = intToRoman(num);

    std::cout << "Input number: " << num << std::endl;
    std::cout << "Roman numeral: " << roman << std::endl;
	system("pause");
    return 0;
}
