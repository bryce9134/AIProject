#include "controller.h"
#include <chrono>
#include "aStar.h"
#include <iostream>
#include <sys/time.h>

void controller::start() {
    //initialize variables. Also needs to empty masterNodeList on
    //every run after the first.
    a.createNeighborPairs();

    sorted = false;
    node init;
    init.gValue = 0;

    //set node.eightState to chosen state
    choice = ui.chooseInitialState();
    if (choice == 1){
        init.eightState.assign(init1.begin(), init1.end());
    }
    else{
        init.eightState.assign(init2.begin(), init2.end());
    }

    runs = ui.chooseH();
    viewNodes = ui.choosePrintNodes();
    //set values for initial node
    init.hValue = a.runAlg(init, runs);
    init.fValue = init.hValue + init.gValue;
    init.parent = -1;

    //add first node to master list
    a.addNode(init);

    //send to work
    work();
}

void controller::work() {
    int current; // holds the index value of the node with lowest f value
    std::vector<node> children;
    timeval start, end;
    gettimeofday(&start, NULL);

    while (sorted != true) {
        children.clear();
        //Compare all F values;
        current = compareF( a.masterNodeList );

        //Generate Successors--------------------------------------------

        a.generateSuccessors(a.masterNodeList[current], children, current);
        a.masterNodeList[current].hasChildren = true;

        //Get H values of children---------------------------------------

        for (int i = 0; i < children.size(); i++){
           children[i].hValue = a.runAlg(children[i], runs);
        }

        //if h value of a child is 0 then set sorted=true-----------------

        for(int i = 0; i < children.size(); i++){
            children[i].fValue = children[i].hValue + children[i].gValue;

            if (children[i].hValue == 0){
                sorted = true;
                final = i;

                if(viewNodes == 'y')
                    ui.printAll(a.masterNodeList);

                std::cout<<"Congratulations! Final State:\n";
                ui.printNode(children[i]);
                gettimeofday(&end, NULL);
                const double time = end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec) / 1000000.0;
                std::cout<<"time: "<<time <<"\n";
                addData(start, end, children[i]);
            }
        }

        for(int i = 0; i < children.size(); i++){
            a.addNode(children[i]);
        }
    }

    ui.printData(arr);
}

//returns the index of node with lowest f value
int controller::compareF(std::vector<node> m){
    int bestF = 1000;
    int index;

    for (int i = 0; i < m.size();i++) {
        if (m[i].hasChildren == false) {
            if (m[i].fValue < bestF) {
                bestF = m[i].fValue;
                index = i;
            }
        }
    }
    return index;
}


void controller::addData(timeval start, timeval end, node n) {
    //get time:
    arr[1][6] = 1;
    const double runtime = end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec) / 1000000.0;
    arr[1][0] = runtime;

    //get total nodes:
    arr[1][1]= a.masterNodeList.size();

    //Get Nodes that were expanded:
    for (int i = 0; i < a.masterNodeList.size(); i++){
        if(a.masterNodeList[i].hasChildren == true)
            arr[1][2] += 1;
    }

    //deepest branch
    arr[1][3] = n.gValue;

    //Branching Factor
    arr[1][4] = (arr[runs][1]/arr[runs][3]);

    //Memory Used
    arr[1][5] = a.masterNodeList.size()*sizeof(node);
}

