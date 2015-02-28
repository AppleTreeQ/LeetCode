//
//  CloneGraph.h
//  LeetCode
//
//  Created by ipuser on 2015/02/26.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_CloneGraph_h
#define LeetCode_CloneGraph_h
/**
 * Definition for undirected graph.
 */
#include <map>
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
class CloneGraph {
private:
    map<int, UndirectedGraphNode*> nodes;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL)
            return NULL;
        if (nodes[node->label] != NULL) {
            return nodes[node->label];
        }
        UndirectedGraphNode * root = new UndirectedGraphNode(node->label);
        nodes[root->label] = root;
        for (int i = 0; i < node->neighbors.size(); i ++) {
            root->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return root;
    }
};
class CloneGraphTest {
public:
    void test() {
        CloneGraph s;
        UndirectedGraphNode *one = new UndirectedGraphNode(1);
        UndirectedGraphNode *two = new UndirectedGraphNode(2);
        one->neighbors.push_back(two);
        two->neighbors.push_back(one);
        UndirectedGraphNode * root = s.cloneGraph(one);
        cout << root->label << endl;
        cout << root->neighbors[0]->label << endl;
    }
};
#endif
