//
// Created by AL865 on 4/18/2020.
//

#ifndef PROJECT_2_STUFF_CONTROLLER_H
#define PROJECT_2_STUFF_CONTROLLER_H

#include "interface.h"
#include "aStar.h"
#include "grapher.h"
#include "node.h"
#include <sys/time.h>

class controller {
private:
    interface ui;
    aStar a;
    grapher graph;
    int runs;    // holds the amount of times the game has been solved. this is given to
                 // aStar.runAlg() to tell it which hueristic to run.
    bool sorted;
    int choice;
    int final;
    double arr[4][7];


    const std::vector<char> init1 = {'2', '8', '3',
                                     '1', '6', '4',
                                     '*', '7', '5'};

    const std::vector<char> init2 = {'2','1','6',
                                     '4','*','8',
                                     '7','5','3'};
public:
    controller(){
       runs = 0;
    };
    void addData(timeval start, timeval end, node node);
    void start();
    void work();
    int compareF(std::vector<node> m);
};

#endif //PROJECT_2_STUFF_CONTROLLER_H
