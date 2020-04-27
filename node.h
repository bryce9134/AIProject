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
        int parentSpace;
};

#endif