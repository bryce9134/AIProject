#ifndef PROJECT_2_STUFF_INTERFACE_H
#define PROJECT_2_STUFF_INTERFACE_H

#include <iostream>
#include "node.h"
#include <iomanip>

class interface{
    //Command line interface only
private:

public:
    void printNode(node n);
    int chooseInitialState();
    void printData(double[][7]);

    //Should create the tables and output them to the command line
    void printAll(std::vector<node>);
    int chooseH();
    int choosePrintNodes();
};

#endif //PROJECT_2_STUFF_INTERFACE_H
