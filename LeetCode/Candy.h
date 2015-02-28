//
//  Candy.h
//  LeetCode
//
//  Created by ipuser on 2015/02/26.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_Candy_h
#define LeetCode_Candy_h
//1,2,1,3,1,4,1
//3,2,1,4,5,5,1
class Candy {
public:
    int candy(vector<int> &ratings) {
        vector<int> res;
        res.push_back(1);
        for (int i = 1; i < ratings.size(); i ++) {
            if (ratings[i] > ratings[i - 1])
                res.push_back(res[i - 1] + 1);
            else if (ratings[i] == ratings[i - 1])
                res.push_back(1);
            else
                helper(ratings, res, i);
        }
        int sum = 0;
        for (int i = 0; i < res.size(); i ++) {
            sum += res[i];
            cout << res[i] << ",";
        }
        cout << endl;
        return sum;
    }
    void helper(vector<int> &ratings, vector<int> &res, int index) {
        res.push_back(1);
        int start = index;
        while (ratings[start] < ratings[start - 1] && res[start] >= res[start - 1] && start>=1) {
            res[start - 1] = res[start] + 1;
            start --;
        }
    }
};
class Candy2 {
public:
    int candy(vector<int> &ratings) {
        vector<int> res;
        res.push_back(1);
        int sum = 1, start = 0, end = 0, flag = 0;
        for (int i = 1; i < ratings.size(); i ++) {
            if (ratings[i] > ratings[i - 1]) {
                res.push_back(res[i - 1] + 1);
                sum += res[i];
            }
            else if (ratings[i] == ratings[i - 1]) {
                res.push_back(1);
                sum += res[i];
            }
            else {
                res.push_back(res[i - 1] - 1);
                if (!flag) {
                    start = i - 1;
                    flag = 1;
                }
                end = i;
            }
            if (flag && (i == ratings.size() -1 || ratings[i+1] >= ratings[i])) {
                if (res[start] >= (1 + end - start))
                    sum += (1+end-start)*(end-start)/2;
                else {
                    sum -= res[start];
                    sum += (1+end-start+1)*(end-start+1)/2;
                }
                res[end] = 1;
                flag = 0;
            }
                
        }
        return sum;
    }
};
class CandyTest {
public:
    void test() {
        Candy s;
        Candy2 s2;
        int a[] = {3,2,1,4,5,5,1};
        vector<int> ratings;
        for (int i = 0; i < sizeof(a)/sizeof(int); i ++) {
            ratings.push_back(a[i]);
        }
        cout << s.candy(ratings) << endl;
        cout << s2.candy(ratings) << endl;
    }
};
#endif
