//
//  3SumClosest.h
//  LeetCode
//
//  Created by ipuser on 2014/12/29.
//  Copyright (c) 2014年 ipuser. All rights reserved.
//

#ifndef LeetCode__ThreeSumClosest_h
#define LeetCode__ThreeSumClosest_h
class ThreeSumClosest {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        if (num.size() < 3)
            return INT_MIN;
        int delta = INT_MAX;
        int result = 0;
        for (int i = num.size() - 1; i >= 2; i --) {
            if (i < num.size() - 1 && num[i] == num[i + 1]) {
                continue;
            }
            for (int j = 0, k = i -1; j < k; ) {
                if (j > 0 && num[j - 1] == num[j]) {
                    j ++;
                    continue;
                }
                if (k < i - 1 && num[k] == num[k + 1]) {
                    k --;
                    continue;
                }
                int sum = num[j] + num[k] + num[i];
                if ( abs(target - sum) < delta ) {
                    delta = abs(target - sum);
                    result = sum;
                }
                if (sum < target) {
                    j ++;
                    continue;
                }
                if (sum > target) {
                    k --;
                    continue;
                }
                if (sum == target)
                    return sum;
            }
        }
        return result;
    }
};
class ThreeSumClosestTest {
public:
    void test() {
        int S[] = {-1, 2, 1, -4};
        vector<int> t;
        for (int i = 0; i < sizeof(S)/sizeof(int); i++)
            t.push_back(S[i]);
        ThreeSumClosest solution;
        cout << solution.threeSumClosest(t, 1) << endl;
        return;
    }
};
#endif
