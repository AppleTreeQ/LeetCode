//
//  NextPermutation.h
//  LeetCode
//
//  Created by ipuser on 2015/01/03.
//  Copyright (c) 2015年 ipuser. All rights reserved.
//

#ifndef LeetCode_NextPermutation_h
#define LeetCode_NextPermutation_h

class NextPermutation {
public:
    void nextPermutation(vector<int> &num) {
        int size = num.size();
        if (size < 2)
            return;
        int i, pos;
        for (i = size - 2; i >= 0; i --) {
            if (num[i] < num[i + 1])
                break;
        }
        pos = i;
        if (pos < 0) {
            sort(num[0], num[size -1]);
            return;
        }
        for (i = size - 1; i > pos; i --) {
            if (num[pos] < num[i]) {
                swap(num[pos], num[i]);
                break;
            }
        }
        sort(num[pos +1], num[size -1]);
        return;
    }
private:
    void swap (int &a, int &b) {
        int c;
        c = a;
        a = b;
        b = a;
        return;
    }
};
class NextPermutationTest {
public:
    void test() {
        NextPermutation solution;
        vector<int> a;
        a.push_back(1);
        a.push_back(2);
        a.push_back(3);
        solution.nextPermutation(a);
        for (int i = 0; i < a.size(); i ++) {
            cout << a[i] << ",";
        }
        cout << endl;
    }
};
#endif
