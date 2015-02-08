//
//  WordSearch.h
//  LeetCode
//
//  Created by ipuser on 2015/02/08.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_WordSearch_h
#define LeetCode_WordSearch_h
class WordSearch {
public:
    bool exist(vector<vector<char> > &board, string word) {
        bool res = false;
        if (word.size() == 0 || board.size() == 0) {
            return res;
        }
        int leny = board.size(), lenx = board[0].size();
        vector<vector<int> > flag(leny, vector<int>(lenx, 0));
        res = helper(flag, board, word, 0, 0, 0);
        return res;
    }
    bool helper(vector<vector<int> > &flag, vector<vector<char> > &board, string word, int start, int x, int y) {
        if (start == word.size()) {
            return true;
        }
        int leny = board.size(), lenx = board[0].size();
        bool result = false;
        if (start == 0) {
            for (int i = 0; i < leny; i ++) {
                for (int j = 0; j < lenx; j ++) {
                    if(board[i][j] == word[start]) {
                        flag[i][j] = 1;
                        if (!helper(flag, board, word, start + 1, j, i))
                            flag[i][j] = 0;
                        else
                            return true;
                    }
                        
                }
            }
            return result;
        }
        int neighbor[4][2] = {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};
        for (int i = 0; i < 4; i ++) {
            if (neighbor[i][0]>=0 && neighbor[i][0] < lenx && neighbor[i][1] >= 0 && neighbor[i][1] < leny && flag[neighbor[i][1]][neighbor[i][0]] == 0 && board[neighbor[i][1]][neighbor[i][0]] == word[start]) {
                flag[neighbor[i][1]][neighbor[i][0]] = 1;
                if (!helper(flag, board, word, start + 1, neighbor[i][0], neighbor[i][1])) {
                    flag[neighbor[i][1]][neighbor[i][0]] = 0;
                }
                else
                    return true;
            }
        }
        return result;
    }
};
class WordSearchTest {
public:
    void test() {
        WordSearch s;
        vector<vector<char> > board;
        char c[3][5] = {"ABCE", "SFCS", "ADEE"};
        for (int i = 0; i < 3; i ++) {
            vector<char> v;
            v.insert(v.end(), c[i], c[i] + 4);
            board.push_back(v);
        }
        bool res = s.exist(board, "ABCB");
        cout << res << endl;
    }
};
#endif
