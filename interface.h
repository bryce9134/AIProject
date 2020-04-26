//
// Created by AL865 on 4/18/2020.
//

#ifndef PROJECT_2_STUFF_INTERFACE_H
#define PROJECT_2_STUFF_INTERFACE_H

#include <iostream>
#include "node.h"

class interface{
    //Command line interface only
private:
    enum hFunction{
        h1 = 1, h2 = 2, h3 = 3,
        h4 = 4, h5 = 5, 
        h0 = 7                    //h() function will only return 0. To test g() only.
                                  //May have a flag to disable h0
    };
 
    enum dataPoint{
        et = 0, ng = 1, ne = 2,
        d = 3, b = 4, mo = 5
    };

public:
    //interface();
    void printNode(node n);
    int chooseInitialState();
    int shouldWeCreateGraphs();

    //Should create the tables and output them to the command line
    void printAll(std::vector<node>);
};



#endif //PROJECT_2_STUFF_INTERFACE_H
