//
//  SurroundedRegions.h
//  LeetCode
//
//  Created by ipuser on 2015/02/25.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_SurroundedRegions_h
#define LeetCode_SurroundedRegions_h
#include <set>
struct position{
    int posx;
    int posy;
    bool operator<(const position & r)
    {
        return (posx < r.posx && posy < r.posy);
    }
    
    bool operator==(const position & r)
    {
        return (posx == r.posx && posy == r.posy);
    }
};

class SurroundedRegions {
public:
    void solve(vector<vector<char>> &board) {
        if (board.size() <3)
            return;
        int size1 = board.size();
        set<position> sets;
        queue<position> que;
        int newPos[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < size1; i ++) {
            if (board[0][i] == 'O') {
                position p;
                p.posx = 0;
                p.posy = i;
                que.push(p);
                sets.insert(p);
            }
            if (board[size1 - 1][i] == 'O') {
                position p;
                p.posx = size1 - 1;
                p.posy = i;
                que.push(p);
                sets.insert(p);
            }
        }
        for (int i = 1; i < size1 - 1; i ++) {
            if (board[i][0] == 'O') {
                position p;
                p.posx = i;
                p.posy = 0;
                que.push(p);
                sets.insert(p);
            }
            if (board[i][size1 - 1] == 'O') {
                position p;
                p.posx = i;
                p.posy = size1 - 1;
                que.push(p);
                sets.insert(p);
            }
        }
        while (!que.empty()) {
            position p = que.front();
            for (int i = 0; i < 4; i ++) {
                position newp;
                newp.posx = p.posx + newPos[i][0];
                newp.posy = p.posy + newPos[i][1];
                if (newp.posx >= 0 && newp.posx < size1 && newp.posy >= 0 && newp.posy < size1) {
                    if (board[newp.posx][newp.posy] == 'O' && sets.find(newp)!=sets.end()) {
                        que.push(newp);
                        sets.insert(newp);
                    }
                }
            }
            que.pop();
        }
        for (int i = 0; i < size1; i ++) {
            for (int j = 0; j < size1; j ++) {
                position newp;
                newp.posx = i;
                newp.posy = j;
                set<position>::iterator it = sets.find(newp);
                if (it != sets.end())
                    sets.erase(it);
                else
                    board[newp.posx][newp.posy] = 'X';
            }
        }
        return;
    }
};
class SurroundedRegionsTest {
public:
    void test() {
        SurroundedRegions s;
        vector<vector<char>> board;
        char cc[4][4] = {{'X','X','X','X'}, {'X','O','O','X'}, {'X','X','O','X'}, {'X','O','X','X'}};
        for (int i = 0; i < 4; i ++) {
            vector<char> v;
            for (int j = 0; j < 4; j ++) {
                v.push_back(cc[i][j]);
            }
            board.push_back(v);
        }
        s.solve(board);
        for (int i = 0; i < 4; i ++) {
            for (int j = 0; j < 4; j ++) {
                cout << board[i][j] << ",";
            }
            cout << endl;
        }
    }
};
#endif
