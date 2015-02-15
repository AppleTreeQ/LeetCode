//
//  UniqueBinarySearchTrees.h
//  LeetCode
//
//  Created by ipuser on 2015/02/15.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_UniqueBinarySearchTrees_h
#define LeetCode_UniqueBinarySearchTrees_h
class UniqueBinarySearchTrees {
public:
    int numTrees(int n) {
        if (n <= 1) return 1;
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += numTrees(i) * numTrees(n - i - 1);
        return sum;
    }
};
class UniqueBinarySearchTreesTest {
public:
    void test() {
        
    }
};

#endif
