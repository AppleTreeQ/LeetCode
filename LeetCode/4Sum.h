//
//  4Sum.h
//  LeetCode
//
//  Created by ipuser on 2014/12/29.
//  Copyright (c) 2014年 ipuser. All rights reserved.
//

#ifndef LeetCode__FourSum_h
#define LeetCode__FourSum_h

class FourSum {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        if ( num.size() < 4 )
            return result;
        for ( int i = num.size() - 1; i >= 3; i -- ) {
            if( i < num.size() -1 && num[i] == num[i + 1] )
                continue;
            for ( int j = i - 1; j >= 2; j -- ) {
                if ( j < i - 1 && num[j] == num[j + 1])
                    continue;
                for ( int k = 0, m = j - 1; k < m; ) {
                    if ( k > 0 && num[k] == num[k - 1]) {
                        k ++;
                        continue;
                    }
                    if ( m < j - 1 && num[m] == num[m + 1] ) {
                        m --;
                        continue;
                    }
                    int sum = num[k] + num[m] + num[j] + num[i];
                    if ( sum < target ) {
                        k ++;
                        continue;
                    }
                    if ( sum > target ) {
                        m --;
                        continue;
                    }
                    if ( sum == target ) {
                        vector<int> * e = new vector<int>();
                        e->push_back(num[k]);
                        e->push_back(num[m]);
                        e->push_back(num[j]);
                        e->push_back(num[i]);
                        result.push_back(*e);
                        k ++;
                        m --;
                    }
                }
            }
        }
        return result;
    }
};
class FourSumTest {
public:
    void test() {
        int S[] = {1, 0, -1, 0, -2, 2};
        vector<int> t;
        for (int i = 0; i < sizeof(S)/sizeof(int); i++)
            t.push_back(S[i]);
        FourSum solution;
        vector<vector<int> > re = solution.fourSum(t, 0);
        for (int i = 0; i < re.size(); i ++) {
            vector<int> a = re[i];
            cout << a[0] << ", " << a[1] << ", " << a[2] << ", " << a[3]<< endl;
        }
    }
};
#endif
