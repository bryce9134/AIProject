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
    //init.hValue = a.runAlg(init, runs);
    init.fValue = init.hValue + init.gValue;
    init.parent = -1;

    //add first node to master list
    a.addNode(init);

    std::vector<node> children;

    ui.printNode(init);
    a.runAlg(init, 4);
    a.generateSuccessors(init, children, 0);
    ui.printAll(children);

    //send to work
    //work();

}

void controller::work() {
    int current; // holds the index value of the node with lowest f value


    while (sorted != true) {
        //Compare all F values
       current = compareF( a.masterNodeList );
       std::cout<<"current: " << current;//debugging

 //Generate Successors--------------------------------------------

        //a.generateSuccessors(a.mast);

 //Get H values of children---------------------------------------

        /*for (int i = 0; i < children.size(); i++){
            a.runAlg(children, runs);
        }*/
 //if h value of a child is 0 then set sorted=true-----------------

           /* for(int i = 0; i < children.size(); i++)
            {
                if (children(i).hvalue = 0){
                sorted = true}
            }*/

    sorted = true; //This forces the loop to exit after one run for debugging reasons
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