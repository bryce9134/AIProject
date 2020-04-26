#include "controller.h"
#include "aStar.h"
#include <iostream>

void controller::start() {
    //initialize variables. Also needs to empty masterNodeList on
    //every run after the first.
    a.createNeighborPairs();
    runs++;
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

    while (sorted != true) {
        children.clear();
        //Compare all F values
       // ui.printAll(a.masterNodeList);
       current = compareF( a.masterNodeList );
       //std::cout<<"current: " << current;//debugging

 //Generate Successors--------------------------------------------

        a.generateSuccessors(a.masterNodeList[current], children, current);
        a.masterNodeList[current].hasChildren = true;
       // std::cout<<"hello1\n";
 //Get H values of children---------------------------------------

        for (int i = 0; i < children.size(); i++){
           children[i].hValue = a.runAlg(children[i], runs);
        }
       // std::cout<<"hello2\n";
 //if h value of a child is 0 then set sorted=true-----------------

           for(int i = 0; i < children.size(); i++)
            {   children[i].fValue = children[i].hValue + children[i].gValue;
                if (children[i].hValue == 0){
                sorted = true;
                final = i;
                std::cout<<"congratulations\n";
                ui.printNode(children[i]);
                }
            }
       // std::cout<<"hello3\n";
           for(int i = 0; i < children.size(); i++){
               a.addNode(children[i]);
           }
       // std::cout<<"hello4\n";

       //creat F values




    //ui.printAll(a.masterNodeList);
    //sorted = true; //This forces the loop to exit after one run for debugging reasons
    }
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
                std::cout<<"fvalue:"<<m[i].fValue<<"\n"; //debugging
            }
        }
    }
return index;
}