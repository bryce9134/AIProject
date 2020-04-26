#include "aStar.h"
#include "interface.h"
#include <utility>
#include <iostream>


//Number of misplaced tiles from the goal
int aStar::h1(node node){
   int numberOfMissedTiles = 0;

   for(int i = 0; i < MAX_CELLS; i++){
       if(node.eightState[i] != GOAL_STATE[i]){
            numberOfMissedTiles++;
       }
   }
   return numberOfMissedTiles;
}

//sum of Manhattan Distance of each tile
int aStar::h2(node node) {
    int h2 = 0, position, goal_index;
    bool neighbor_is_goal;
    std::vector<int> currentNeighbors;

    for(int i = 0; i < MAX_CELLS; i++){
        neighbor_is_goal = false;

        if(node.eightState[i] != GOAL_STATE[i]) {
            position = i;
            std::cout << "Position: " << position << "\n";

            for(int j = 0; j < MAX_CELLS; j++) {
                if (node.eightState[position] == GOAL_STATE[j]) {
                    goal_index = j;
                    std::cout << "Goal Index: " << goal_index << "\n";
                }
            }

            currentNeighbors = neighbors.at(position);
            for(int i = 0; i < currentNeighbors.size(); i++){
                if(currentNeighbors[i] == goal_index)
                    neighbor_is_goal = true;
            }

            if(!neighbor_is_goal){
                if(position == 4){
                    if(goal_index%2 == 0)
                        h2++;
                    else
                        h2+=2;
                } else if(position%2 == 0){
                    if(goal_index%2 == 1)
                        h2+=3;
                    else if(position + goal_index == 8)
                        h2+=4;
                    else
                        h2+=2;
                } else
                    if(goal_index%2 == 0)
                        h2+=3;
                    else
                        h2+=2;
            } else
                h2++;
        }
        std::cout << "current h2: " << h2 << "\n\n";
    }

    std::cout << "h2 Value is: " << h2 << "\n";
    return h2;
}

//number of tiles out of row + number of tiles out of column
int aStar::h3(node node) {
    int rows = aStar::rowsCols(node, 0, 3, 1) +
               aStar::rowsCols(node, 3, 6, 1) +
               aStar::rowsCols(node, 6, 9, 1);

    int cols = aStar::rowsCols(node, 0, 7, 3) +
               aStar::rowsCols(node, 1, 8, 3) +
               aStar::rowsCols(node, 2, 9, 3);

    std::cout << "h4 value: " << rows + cols << "\n";
    return rows + cols;
}

int aStar::rowsCols(node n, int beg, int end, int inc) {
    bool found;
    char value;
    int out = 0;

    for(int i = beg; i < end; i+=inc){
        found = false;
        value = n.eightState[i];
        for(int j = beg; j < end; j+=inc){
            if(value == GOAL_STATE[j])
                found = true;
        }
        if(!found)
            out++;
    }
    return out;
}


int aStar::h4(node node){
    char value, successor;
    int sValue = 0;

    for(int i = 0; i <= MAX_CELLS; i++){
        value = node.eightState[i];
        successor = node.eightState[i+1];
        if(value == '1' && successor != '2')
            sValue++;
        if(value == '2' && successor != '3')
            sValue++;
        if(value == '3' && successor != '8')
            sValue++;
        if(value == '4' && successor != '7')
            sValue++;
        if(value == '6' && successor != '5')
            sValue++;
        if(value == '7' && successor != '6')
            sValue++;
        if(value == '8' && successor != '*')
            sValue++;
    }

    std::cout<< "S value is: " << sValue << "\n";
    return sValue;

//    int firstTwo,
//        lastTwo;
//
//    firstTwo = std::max(h1(node), h2(node));
//    lastTwo = std::max(h3(node), h4(node));
//
//    return std::max(firstTwo, lastTwo);
}


//generates all the possible nodes that can be created from initial (children)
void aStar::generateSuccessors(node parent, std::vector<node> &children, int index){

    node temp;
    int emptySpace, child = 0;

    for(int i = 0; i < MAX_CELLS; i++){
        if(parent.eightState[i] == '*'){
            emptySpace = i;
        }
    }

    std::vector<int> currentNeighbors = neighbors.at(emptySpace);

    for(int i = 0; i < currentNeighbors.size(); i++){
        temp.eightState = parent.eightState;
        temp.gValue = parent.gValue +1;
        temp.parent = index;
        std::cout<<"empty, i: "<< emptySpace<<" "<<currentNeighbors[i]<<"\n";
        std::swap(temp.eightState[emptySpace], temp.eightState[currentNeighbors[i]]);

        children.push_back(temp);

        child++;
    }
}

void aStar::addNode(node n){
    masterNodeList.push_back(n);

}

int aStar::runAlg(node n, int r){
    int hvalue;
    switch (r) {
        case 1: hvalue=h1(n);
            break;
        case 2: hvalue=h2(n);
            break;
        case 3: hvalue=h3(n);
            break;
        case 4: hvalue=h4(n);
            break;
        case 5: hvalue=h5(n);
            break;
    }
    return hvalue;
}