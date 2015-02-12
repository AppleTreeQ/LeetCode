//
//  LargestRectangleInHistogram.h
//  LeetCode
//
//  Created by ipuser on 2015/02/09.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_LargestRectangleInHistogram_h
#define LeetCode_LargestRectangleInHistogram_h
class LargestRectangleInHistogram {
public:
    // 这个方法用了剪枝
    int largestRectangleArea(vector<int> &height) {
        if (height.size() < 1) {
            return 0;
        }
        int area = 0, h = 0, maxarea = 0;
        for (int i = 0; i < height.size(); i ++) {
            if (i < height.size() - 1 && height[i] <= height[i + 1])
                continue;
            h = height[i];
            area = 0;
            for (int j = i; j >= 0; j --) {
                if (h <= height[j]) {
                    area += h;
                } else {
                    area = (i - j + 1) * height[j];
                    h = height[j];
                }
                maxarea = maxarea > area? maxarea : area;
            }
        }
        maxarea = maxarea > area? maxarea : area;
        return maxarea;
    }
};
class LargestRectangleInHistogram2 {
public:
    // 用stack，这个方法太特别巧妙，不好想
    int largestRectangleArea(vector<int> &height) {
        if (height.size() < 1) {
            return 0;
        }
        vector<int> temp;
        height.push_back(0);
        int area = 0;
        for (int i = 0; i < height.size(); i ++) {
            if (temp.empty() || height[temp.back()] < height[i]) {
                temp.push_back(i);
                continue;
            }
            int h = temp.back();
            temp.pop_back();
            area = max(area, height[h]*(temp.empty()? i : (i-temp.back() - 1)));
            i --;
        }
        return  area;
    }
};
class LargestRectangleInHistogramTest {
public:
    void test() {
        LargestRectangleInHistogram2 s;
        int a[] = {1,3,2,5};
        vector<int> v;
        for (int i = 0; i < sizeof(a)/sizeof(int); i ++) {
            v.push_back(a[i]);
        }
        int res = s.largestRectangleArea(v);
        cout << res << endl;
    }
};
#endif
