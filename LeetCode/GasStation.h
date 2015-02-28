//
//  GasStation.h
//  LeetCode
//
//  Created by ipuser on 2015/02/26.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_GasStation_h
#define LeetCode_GasStation_h
class GasStation {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        vector<int> remainings;
        int remain = 0;
        int index = 0, max = 0;
        for (int i = 0; i < gas.size(); i ++) {
            remainings.push_back(gas[i] - cost[i]);
            remain += remainings[i];
            max += remainings[i];
            if (max < 0) {
                max = 0;
                index = i + 1;
            }
        }
        if (remain < 0)
            return -1;
        else
            return index;
    }
};
class GasStationTest {
public:
    void test() {
        GasStation s;
        
    }
};
#endif
