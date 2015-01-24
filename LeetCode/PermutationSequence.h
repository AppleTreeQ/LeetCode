//
//  PermutationSequence.h
//  LeetCode
//
//  Created by ipuser on 2015/01/22.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 The set [1,2,3,…,n] contains a total of n! unique permutations.
 By listing and labeling all of the permutations in order,
 We get the following sequence (ie, for n = 3):
 "123"
 "132"
 "213"
 "231"
 "312"
 "321"
 Given n and k, return the kth permutation sequence.
 Note: Given n will be between 1 and 9 inclusive.
 */
#ifndef LeetCode_PermutationSequence_h
#define LeetCode_PermutationSequence_h
class PermutationSequence {
public:
    string getPermutation(int n, int k) {
        string str = "";
        int times = 1, remains = k - 1, bak = remains, base = n;
        int flag[n];
        memset(flag, 0, sizeof(int) * n);
        for (int i = 0; i < n; i ++) {
            times *= (i + 1);
        }
        if (k > times || k < 1)
            return str;
        while (base > 0) {
            times /= base;
            base --;
            bak = remains;
            bak /= times;
            remains -= bak * times;
            char c = getChar(flag, bak, n);
            str += c;
        }
        return str;
    }
    char getChar(int flag[], int bak, int n) {
        int i, count;
        for (i = 0, count = 0; i < n; i ++) {
            if (flag[i] == 1)
                continue;
            if (count == bak)
                break;
            if (count < bak)
                count ++;
        }
        if (count == bak) {
            flag[i] = 1;
            return ('1' + i % n);
        }

        return '\0';
    }
};
class PermutationSequenceTest {
public:
    void test() {
        PermutationSequence s;
        string str = s.getPermutation(3, 6);
        //string str = "";
        cout << str << endl;
    }
};
#endif
