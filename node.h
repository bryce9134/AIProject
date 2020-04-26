#ifndef PROJECT_2_STUFF_NODE_H
#define PROJECT_2_STUFF_NODE_H

#include <utility>
#include <vector>


struct node{
    std::vector<char> eightState;
        int    hValue,
               gValue,
               fValue;
        int parent;
        bool hasChildren = false;
};

enum positions{
        p11 = 1, p12 = 2, p13 = 3,
        p21 = 4, p22 = 5, p23 = 6,
        p31 = 7, p32 = 8, p33 = 9
};

enum dataPoint{
        et = 0, ng = 1, ne = 2,
        d = 3, b = 4, mo = 5
};

enum treeLength{
    beginning = 1,
    middle1 = 2,
    middle2 = 3,
    end = 4
};

 //            node position, children position in masterList
typedef std::pair<int, std::vector<int>> nodeAndChildrenByIndex;
typedef std::pair<node, std::vector<node>> nodeAndChildren;

#endif