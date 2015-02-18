//
//  Triangle.h
//  LeetCode
//
//  Created by ipuser on 2015/02/18.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_Triangle_h
#define LeetCode_Triangle_h
class Triangle {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int size = triangle.size();
        if (size < 1)
            return 0;
        int res[size], sum = 0;
        memset(res, 0, sizeof(int)*size);
        res[0] = triangle[0][0];
        sum = res[0];
        for (int i = 1; i < size; i ++) {
            vector<int> v = triangle[i];
            int temp = INT_MAX;
            for (int j = v.size() - 1; j >= 0; j --) {
                if (j > 0 && j < (v.size() - 1)) {
                    res[j] = (res[j - 1] < res[j] ? res[j - 1]:res[j]) + v[j];
                } else if (j <= 0) {
                    res[j] = res[j] + v[j];
                } else {
                    res[j] = res[j - 1] + v[j];
                }
                temp = temp < res[j] ? temp : res[j];
                sum = temp;
            }
        }
        return sum;
    }
};
class TriangleTest {
public:
    void test() {
        Triangle s;
        vector<int> v1, v2, v3, v4;
        vector<vector<int> > res;
        v1.push_back(2);
        v2.push_back(3);
        v2.push_back(4);
        v3.push_back(6);
        v3.push_back(5);
        v3.push_back(7);
        v4.push_back(4);
        v4.push_back(1);
        v4.push_back(8);
        v4.push_back(3);
        res.push_back(v1);
        res.push_back(v2);
        res.push_back(v3);
        res.push_back(v4);
        cout << s.minimumTotal(res) << endl;
    }
};
#endif
