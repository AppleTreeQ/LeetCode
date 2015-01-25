//
//  InsertInterval.h
//  LeetCode
//
//  Created by ipuser on 2015/01/25.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 
 You may assume that the intervals were initially sorted according to their start times.
 
 Example 1:
 Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 
 Example 2:
 Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 
 This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 */
#ifndef LeetCode_InsertInterval_h
#define LeetCode_InsertInterval_h
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class InsertInterval {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        if (intervals.size() == 0) {
            res.push_back(newInterval);
            return res;
        }
        Interval temp = newInterval, a;
        int index = -1;
        for (int i = 0; i < intervals.size(); i ++) {
            a = intervals[i];
            if (a.end < temp.start) {
                res.push_back(a);
                continue;
            }
            if (temp.end < a.start) {
                res.push_back(temp);
                index = i;
                break;
            }
            temp = Interval(min(a.start, temp.start), max(a.end, temp.end));
        }
        if (index != -1) {
            for (int i = index; i < intervals.size(); i ++) {
                res.push_back(intervals[i]);
            }
        } else
            res.push_back(temp);
        return res;
    }
};
class InsertIntervalTest {
public:
    void test() {
        vector<Interval> inte;
        inte.push_back(Interval(1,2));
        inte.push_back(Interval(3,5));
        inte.push_back(Interval(6,7));
        inte.push_back(Interval(8,10));
        inte.push_back(Interval(12,16));
        inte.push_back(Interval(17,19));
        InsertInterval s;
        vector<Interval> res = s.insert(inte, Interval(20, 21));
        for (int i = 0; i < res.size(); i ++) {
            Interval t = res[i];
            cout << t.start << ", " << t.end << endl;
        }

    }
};
#endif
