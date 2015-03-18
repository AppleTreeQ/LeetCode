//
//  MaxPointsOnALine.h
//  LeetCode
//
//  Created by ipuser on 2015/03/05.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_MaxPointsOnALine_h
#define LeetCode_MaxPointsOnALine_h
/**
 * Definition for a point.
 */
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
class MaxPointsOnALine {
public:
    int maxPoints(vector<Point> &points) {
        map<int, int> xValues;
        map<int, int> yValues;
        int maxNumX = 0, maxNumY = 0;
        for (int i = 0; i < points.size(); i ++) {
            Point p = points[i];
            if (xValues.find(p.x) != xValues.end())
                xValues[p.x] ++;
            else
                xValues[p.x] = 1;
            if (yValues.find(p.y) != yValues.end())
                yValues[p.y] ++;
            else
                yValues[p.y] = 1;
            maxNumX = maxNumX > xValues[p.x] ? maxNumX : xValues[p.x];
            maxNumY = maxNumY > yValues[p.y] ? maxNumY : yValues[p.y];
        }
        return max(maxNumX,maxNumY);
    }
};
class MaxPointsOnALineTest {
public:
    void test() {
        
    }
};
#endif
