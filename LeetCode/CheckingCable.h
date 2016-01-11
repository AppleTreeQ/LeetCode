//
//  CheckingCable.h
//  LeetCode
//
//  Created by ipuser on 2015/03/07.
//  Copyright (c) 2015年 ipuser. All rights reserved.
//

#ifndef LeetCode_CheckingCable_h
#define LeetCode_CheckingCable_h
const int MaxNumEdges = 50;
const int maxNumVertices = 10;
class Graph {
private:
    int Edge[maxNumVertices][maxNumVertices];
    int currentEdges;
public:
    Graph(int sz = maxNumVertices);
    int insertEdge(int v1, int v2, int weight);
}
Graph::Graph(int sz) {
    for (int i = 0; i < sz; i ++) {
        for (int j = 0; j < sz; j ++) {
            Edge[i][j] = 0;
        }
    }
    currentEdges = 0;
}
int Graph::insertEdge(int v1, int v2, int weight) {
    Edge[v1][v2]  = weight;
    
}
#endif
