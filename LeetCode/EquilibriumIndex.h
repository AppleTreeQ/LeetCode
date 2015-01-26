//
//  EquilibriumIndex.h
//  LeetCode
//
//  Created by ipuser on 2015/01/13.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_EquilibriumIndex_h
#define LeetCode_EquilibriumIndex_h
class EquilibriumIndex {
public:
    int solution(int K, int L, int M, int N, int P, int Q, int R, int S) {
        // write your code in C++11
        /*int area = 0;
        int aarea = 0, barea = 0, carea = 0;
        aarea = (M - K)*(N - L), carea = (R - P)*(S - Q);
        barea = */
        double long longK = K, longL = L, longM = M, longN = N;
        double long longP = P, longQ = Q, longR = R, longS = S;
        double long area1 = (longM - longK) * (longN - longL);
        double long area2 = (longR - longP) * (longS - longQ);
        
        double long commonX;
        int beginX = (longK > longP) ? longK : longP;
        int endX = (longM < longR) ? longM : longR;
        commonX = endX - beginX;
        
        double long commonY;
        int beginY = (longL > longQ) ? longL : longQ;
        int endY = (longN < longS) ? longN : longS;
        commonY = endY - beginY;
        
        if (commonX < 0)
            commonX = 0;
        if (commonY < 0)
            commonY = 0;
        double long commonArea = commonX * commonY;
        double long sumArea = area1 + area2 - commonArea;
        
        int maxInt = ~(1 << 31);
        if (sumArea > (double long)maxInt) {
            sumArea = -1;
        }
        return sumArea;
    }
};
class EquilibriumIndexTest {
public:
    void test(){
        EquilibriumIndex s;
        int area = s.solution(-4, 1, 2, 6, -4, -1, 2000000000, 2000000000);
        cout << area << endl;
    }
};
#endif
