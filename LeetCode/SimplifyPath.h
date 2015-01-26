//
//  SimplifyPath.h
//  LeetCode
//
//  Created by ipuser on 2015/01/26.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given an absolute path for a file (Unix-style), simplify it.
 
 For example,
 path = "/home/", => "/home"
 path = "/a/./b/../../c/", => "/c"
 */
#ifndef LeetCode_SimplifyPath_h
#define LeetCode_SimplifyPath_h

class SimplifyPath {
public:
    string simplifyPath(string path) {
        vector<string> vect;
        string res = "";
        char *str=new char[path.size()+1];
        str[path.size()]=0;
        memcpy(str,path.c_str(),path.size());
        char *pch = strtok(str, "/");
        while (pch != NULL) {
            cout << pch << endl;
            string s = pch;
            if (s == "..") {
                if (vect.size() > 0)
                    vect.pop_back();
            }
            else if (s != ".")
                vect.push_back(s);
            pch = strtok (NULL, "/");
        }
        if (vect.size() == 0) {
            return "/";
        }
        for (int i = 0; i < vect.size(); i ++) {
            res += "/" + vect[i];
        }
        return res;
    }
};
class SimplifyPathTest {
public:
    void test() {
        SimplifyPath s;
        string res = s.simplifyPath("/../");
        cout << res << endl;
    }
};
#endif
