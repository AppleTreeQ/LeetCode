//
//  LongestSubstringWithoutRepeatingCharacters.h
//  LeetCode
//
//  Created by ipuser on 2014/11/06.
//  Copyright (c) 2014年 qzhai. All rights reserved.
//

#ifndef LeetCode_LongestSubstringWithoutRepeatingCharacters_h
#define LeetCode_LongestSubstringWithoutRepeatingCharacters_h

#include <string>
#include <iostream>
using namespace std;

class LongestSubstringWithoutRepeatingCharacters {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        if ( s.length() < 2 ) {
            return s.length();
        }
        int start = 0;
        int diff = 0, i;
        for (i = 1; i < s.length(); i ++ ) {
            diff = i - start;
            std::size_t pos = s.substr(start, diff).find(s.at(i));
            if ( pos != std::string::npos ) { // find duplicate character.
                cout << "1start: " << start << ", diff: " << diff << ", i: " << i << endl;
                if ( diff > length ) {
                    length = diff;
                }
                start += pos + 1;
                cout << "2start: " << start << ", diff: " << diff << ", i: " << i << endl;
            } else {
                diff ++;
            }
        }
        return length > diff ? length : diff;
    }
};

class LongestSubstringWithoutRepeatingCharactersTest {
public:
    void test() {
        string s = "abcabcd";
        string s2 = "xyzabcadefg";
        string s3 = "abcabcbb";
        LongestSubstringWithoutRepeatingCharacters solution;
        cout << solution.lengthOfLongestSubstring(s) << endl;
    }
};

#endif
