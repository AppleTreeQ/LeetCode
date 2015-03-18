//
//  FindingFrequentlyOccurringCharacters.h
//  LeetCode
//
//  Created by ipuser on 2015/03/07.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_FindingFrequentlyOccurringCharacters_h
#define LeetCode_FindingFrequentlyOccurringCharacters_h
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct CharAndFrequence
{
    char cha;
    int freq;
    CharAndFrequence(): cha(0), freq(0) {}
}
bool myfunction (CharAndFrequence i,CharAndFrequence j) { return (i.freq > j.freq); }
void main()
{
    string input;
    cin >> input;
    int length = input.size();
    vector<CharAndFrequence> res;
    for (int i = 0; i < 26; i ++) {
        CharAndFrequence temp;
        temp.cha = 'a' + i;
        temp.freq = 0;
        res.push_back(temp);
    }
    for (int i = 0; i < length; i ++) {
        int index = input[i] - 'a';
        res[index].freq ++;
    }
    std::sort(res.begin(), res.end(), myfunction);
    for (int i = 0; i < res.size(); i ++) {
        cout >> res[i].cha << endl;
    }
}
#endif
