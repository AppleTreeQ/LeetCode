//
//  IntegertoRoman.h
//  LeetCode
//
//  Created by ipuser on 2014/12/28.
//  Copyright (c) 2014年 qzhai. All rights reserved.
//
/*
 Given an integer, convert it to a roman numeral.
 Input is guaranteed to be within the range from 1 to 3999.
 */
#ifndef LeetCode_IntegertoRoman_h
#define LeetCode_IntegertoRoman_h
class IntegertoRoman {
public:
    string intToRoman(int num) {
        if (num < 1 || num > 3999)
            return "error!";
        string res = "";
        int bak = num, divi = 0, index = 0;
        string roman[4][9] = {{"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}, {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}, {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}, {"M", "MM", "MMM"}};
        while (bak > 0) {
            divi = bak % 10;
            if (divi >= 1)
                res = roman[index][divi-1] + res;
            bak = bak / 10;
            index ++;
        }
        return res;
    }
    
    // --------
    string intToRoman2(int num) {
        if (num < 1 || num > 3999) {
            return "Error";
        }
        string result = "";
        int p = 0;
        while (num > 0) {
            int n = num % 10;
            result = getRomanNum(n, p) + result;
            p++;
            num /= 10;
        }
        return result;
    }
    
    string getRomanNum(int num, int position) {
        string romanNum[4][3] = {
            {"I","V","X"},
            {"X","L","C"},
            {"C","D","M"},
            {"M","S","B"}
        };
        string* rIndex = romanNum[position];
        string res = "";
        switch (num) {
            case 0:
                break;
            case 1:
                res = rIndex[0];
                break;
            case 2:
                res = rIndex[0] + rIndex[0];
                break;
            case 3:
                res = rIndex[0] + rIndex[0] + rIndex[0];
                break;
            case 4:
                res = rIndex[0] + rIndex[1];
                break;
            case 5:
                res = rIndex[1];
                break;
            case 6:
                res = rIndex[1] + rIndex[0];
                break;
            case 7:
                res = rIndex[1] + rIndex[0] + rIndex[0];
                break;
            case 8:
                res = rIndex[1] + rIndex[0] + rIndex[0] + rIndex[0];
                break;
            case 9:
                res = rIndex[0] + rIndex[2];
                break;
            default:
                break;
        }
        return res;
    }
    
};


class IntegertoRomanTest {
public:
    void test() {
        IntegertoRoman solution;
        for (int i = 1; i < 4000; ++i) {
            cout << i << ", " << solution.intToRoman(i) << ", " << solution.intToRoman2(i) << endl;
        }
    }
};
#endif
