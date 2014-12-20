//
//  TwoSum.h
//  LeetCode
//
//  Created by ipuser on 2014/11/05.
//  Copyright (c) 2014年 ipuser. All rights reserved.
//

#ifndef __LeetCode__TwoSum__
#define __LeetCode__TwoSum__

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class TwoSum {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> index;
        if(numbers.size() < 2)
            return index;
        for(int i = 0; i < numbers.size(); i ++){
            for(int j = i + 1; j < numbers.size(); j ++){
                if((numbers.at(i) + numbers.at(j)) == target)
                {
                    index.push_back(i + 1);
                    index.push_back(j + 1);
                    return index;
                }
                
            }
        }
        return index;
        
    }
};
/*简化两次for循环, 加入map, 注意重复的数*/
class TwoSumWithMap {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> index;
        map<int, int> mp;
        map<int, int>::iterator it_map;
        if(numbers.size() < 2)
            return index;
        for ( int i = 0; i < numbers.size(); i ++ ){
            it_map = mp.find(target - numbers.at(i));
            if ( it_map != mp.end() ){
                index.push_back(it_map->second);
                index.push_back(i + 1);
                return index;
            }
            it_map = mp.find(numbers.at(i)); // remove the duplicate number
            if(it_map == mp.end()){
                mp[numbers.at(i)] = i + 1;
            }
        }
        return index;
        
    }
};
class TwoSumTest {
public:
    void twoSumTest() {
        vector<int> numbers;
        vector<int> result;
        numbers.push_back(2);
        numbers.push_back(2);
        numbers.push_back(7);
        numbers.push_back(11);
        numbers.push_back(15);
        int target = 9;
        TwoSumWithMap twoSum;
        result = twoSum.twoSum(numbers, target);
        if(result.size() < 2)
            cout << "no index.";
        cout << result.at(0) <<", "<< result.at(1) << endl;
    }
};
#endif /* defined(__LeetCode__TwoSum__) */
