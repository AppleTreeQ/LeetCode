//
//  Pow(xn).h
//  LeetCode
//
//  Created by ipuser on 2015/01/20.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*Implement pow(x, n).*/

#ifndef LeetCode_Pow_xn__h
#define LeetCode_Pow_xn__h
class Pow_xn {
public:
    double pow(double x, int n) {
        long int times = (long int) n;
        double res = 1.0;
        if (x == 1) {
            return 1.0;
        }
        if (x == -1) {
            if (times & 0x1)
                return -1.0;
            else
                return 1.0;
        }
        if (times == 0)
            return 1.0;
        if (times < 0) {
            cout << (-1)*times << endl;
            return 1 / pow(x, (-1)*times);
        }
        if (times == 1)
            return x;
        if (times & 1) {
            double r = pow(x, (times - 1) / 2);
            res = r * r * x;
        } else {
            double r = pow(x, times / 2);
            res = r * r;
        }
        return res;
    }
};
class Pow_xnTest {
public:
    void test() {
        Pow_xn s;
        double res = s.pow(8.88023, 3);
        cout << res << endl;
    }
};
#endif
