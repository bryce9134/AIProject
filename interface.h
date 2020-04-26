//
// Created by AL865 on 4/18/2020.
//

#ifndef PROJECT_2_STUFF_INTERFACE_H
#define PROJECT_2_STUFF_INTERFACE_H

#include <iostream>
#include "node.h"
#include <iomanip>

class interface{
    //Command line interface only
private:


public:
    //interface();
    void printNode(node n);
    int chooseInitialState();
    int shouldWeCreateGraphs();
    void printData(double[][7]);

    //Should create the tables and output them to the command line
    void printAll(std::vector<node>);
};



#endif //PROJECT_2_STUFF_INTERFACE_H
