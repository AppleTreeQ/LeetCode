//
//  3Sum.h
//  LeetCode
//
//  Created by ipuser on 2014/12/28.
//  Copyright (c) 2014年 ipuser. All rights reserved.
//

#ifndef LeetCode__ThreeSum_h
#define LeetCode__ThreeSum_h
#include <iostream>
#include <vector>
using namespace std;
class ThreeElements {
private:
    int x, y, z;
public:
    ThreeElements(int i, int j, int k) { x = i; y = j; z = k;}
    bool compare(ThreeElements &s) {
        if ((x != s.getX()) || (y != s.getY()) || (z != s.getZ()))
            return false;
        else
            return true;
    }
    int getX() {return x;}
    int getY() {return y;}
    int getZ() {return z;}
};
class ThreeSum {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > result;
        if (num.size() < 3)
            return result;
        vector<ThreeElements> eleVect;
        bool hasSame = false;
        for (int i = 0; i < num.size() - 2; i ++) {
            for (int j = i + 1; j < num.size() - 1; j ++) {
                for (int k = j + 1; k < num.size(); k ++) {
                    hasSame = false;
                    if (num[k] == -(num[i] + num[j])) {
                        ThreeElements e = ThreeElements(num[i], num[j], num[k]);
                        if ( eleVect.size() > 0) {
                            for (int m = 0; m < eleVect.size(); m ++) {
                                if (eleVect[m].compare(e)) {
                                    hasSame = true;
                                    break;
                                }
                            }
                        }
                        if (!hasSame) {
                            eleVect.push_back(e);
                            vector<int> *re = new vector<int>();
                            re->push_back(num[i]);
                            re->push_back(num[j]);
                            re->push_back(num[k]);
                            result.push_back(*re);
                        }
                    }
                    else if (num[k] > -(num[i] + num[j]))
                        break;
                }
            }
        }
        return result;
    }
    vector<vector<int> > threeSum2(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > result;
        if (num.size() < 3)
            return result;
        for (int i = num.size() - 1; i >= 2; i --) {
            if ( i < num.size() - 1 && num[i] == num[i + 1])
                continue;
            for ( int j = 0, k = i - 1; j < k; ) {
                if ( j > 0 && num[j] == num[j-1]) {
                    j ++;
                    continue;
                }
                if(k < i - 1 && num[k] == num[k+1]) {
                    k --;
                    continue;
                }
                int sum = num[j] + num[k] + num[i];
                if (sum > 0) {
                    k --;
                    continue;
                }
                if (sum < 0) {
                    j ++;
                    continue;
                }
                if (sum == 0) {
                    vector<int> *e = new vector<int>();
                    e->push_back(num[j]);
                    e->push_back(num[k]);
                    e->push_back(num[i]);
                    result.push_back(*e);
                    j ++;
                    k --;
                }
            }
        }
        return result;
    }
};

class ThreeSumTest {
public:
    void test() {
        int S[] = {-2, 0, 1, 1, 2};
        vector<int> t;
        for (int i = 0; i < sizeof(S)/sizeof(int); i++)
            t.push_back(S[i]);
        ThreeSum solution;
        vector<vector<int> > re = solution.threeSum2(t);
        for (int i = 0; i < re.size(); i ++) {
            vector<int> a = re[i];
            cout << a[0] << ", " << a[1] << ", " << a[2] << endl;
        }
    }
};
#endif
