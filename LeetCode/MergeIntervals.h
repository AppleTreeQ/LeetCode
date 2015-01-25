//
//  MergeIntervals.h
//  LeetCode
//
//  Created by ipuser on 2015/01/25.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given a collection of intervals, merge all overlapping intervals.
 
 For example,
 Given [1,3],[2,6],[8,10],[15,18],
 return [1,6],[8,10],[15,18].
 */
#ifndef LeetCode_MergeIntervals_h
#define LeetCode_MergeIntervals_h

//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
bool mysort(Interval i, Interval j) {
	if (i.start < j.start)
		return true;
	if (i.start == j.start)
		return (i.end < j.end);
	return false;
		
}
class MergeIntervals {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size() < 2) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), mysort);
        vector<Interval> res;
        Interval a, b, lastone = intervals[0];
        for (int i = 1; i < intervals.size(); i ++) {
            a = lastone;
            b = intervals[i];
            if (a.end < b.start) {
                res.push_back(a);
                lastone = b;
                continue;
            }
            if (a.end >= b.start && a.end <= b.end) {
                lastone = Interval(a.start, b.end);
                continue;
            }
            if (a.end > b.end) {
                lastone = a;
                continue;
            }
        }
        res.push_back(lastone);
        return res;
    }
};
class MergeIntervalsTest {
public:
    void test() {
        vector<Interval> inte;
        inte.push_back(Interval(8,10));
        inte.push_back(Interval(15,18));
        inte.push_back(Interval(2,6));
        inte.push_back(Interval(1,3));
        MergeIntervals s;
        vector<Interval> res = s.merge(inte);
        for (int i = 0; i < res.size(); i ++) {
            Interval t = res[i];
            cout << t.start << ", " << t.end << endl;
        }
    }
};
#endif
