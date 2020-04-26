//
// Created by AL865 on 4/18/2020.
//

#ifndef PROJECT_2_STUFF_ASTAR_H
#define PROJECT_2_STUFF_ASTAR_H

#include <vector>
#include <utility>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include "node.h"

class aStar{
private:
    const std::vector<char> GOAL_STATE = {'1', '2', '3',
                                          '8', '*', '4',
                                          '7', '6', '5'};


    static const char SPACE = '*';
    static const int MAX_CELLS = 9;

    //Stores position of parents
    std::set<int> closedList;
    std::queue<int> openQueue;

    std::stack<nodeAndChildrenByIndex> pathAsIndexs;

    int depthOfTree,
        nodesGenerated,
        effectiveBranchFactor,
        currentNode = 0;

    int h1(node node);
    int h2(node node);
    int h3(node node);
    int h4(node node);
    int h0();
    //int g(std::stack path);

    int rowsCols(node n, int beg, int end, int inc);

    double calculateBranchFactor();
    std::stack<nodeAndChildren> buildActualPath(); //uses pathAsIndexs

    //map of neighboring cells for swapping
    std::map<int, std::vector<int>> neighbors;
    
    //set up neighbors map


public:
    void createNeighborPairs(){
        neighbors.insert(std::make_pair(0, std::vector<int>{1, 3}));
        neighbors.insert(std::make_pair(1, std::vector<int>{0, 2, 4}));
        neighbors.insert(std::make_pair(2, std::vector<int>{1, 5}));
        neighbors.insert(std::make_pair(3, std::vector<int>{4, 0, 6}));
        neighbors.insert(std::make_pair(4, std::vector<int>{3, 5, 1, 7}));
        neighbors.insert(std::make_pair(5, std::vector<int>{4, 2, 8}));
        neighbors.insert(std::make_pair(6, std::vector<int>{7, 3}));
        neighbors.insert(std::make_pair(7, std::vector<int>{6, 8, 4}));
        neighbors.insert(std::make_pair(8, std::vector<int>{7, 5}));
    };


    std::vector<nodeAndChildren> parentNodes;
    std::vector<node> masterNodeList;
    
    int runAlg(node n, int r);
    void addNode(node n);
    void generateSuccessors(node, std::vector<node> &children, int);
    std::vector<int> returnSpecialData();
    std::stack<nodeAndChildren> * returnThePath();  //Check to make sure pointer stuff works

};






#endif //PROJECT_2_STUFF_ASTAR_H
