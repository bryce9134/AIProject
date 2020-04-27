#include "interface.h"

int interface::chooseInitialState(){
    //Does text output to screen and 
    

    std::cout << "Hello, welcome to Project 2 for Artificial Intelligence!\n" << std::endl;
 	
 	//main will tell controller which initial state to use.
 	//---make a while loop here so the user can decide to run the other initial
 	//---state or to exit the program and look at the results.
 	std::cout << "Would you like to run the initial state 1 or 2\n";
 	std::cout << "Please enter either 1 or 2\n";
 	int a; //user inputs the state they want to use here
 	std::cin >> a;
 	return a;



}
void interface::printNode(node n) {
        for (int i = 0; i < 9; i++) {
            std::cout << n.eightState.at(i) << " ";
            if ((i==2)||(i==5))
                std::cout << "\n";
        }
        std::cout<< "\n";
    }


void interface::printAll(std::vector<node> m){

    for (int i = 0; i< m.size(); i++){
        std::cout <<"Array Number: " << i << "\n";
        printNode(m.at(i));
        std::cout <<"\n";
    }
}

void interface::printData(double arr[][7]) {
    std::cout<<"\n    ET     NG      NE     d      b*     MO\n";


    //for (int i = 0; i < 4; i++){
        //if (arr[i][6]==1){
    std::cout<< std::fixed << std::setprecision(1) <<"\n    "<<arr[1][0];
    std::cout<<"    "<<arr[1][1]<<"    "<<arr[1][2];
    std::cout<<"    "<<arr[1][3]<<"    "<<arr[1][4]<<"    "<<arr[1][5]<<"\n";
       // }


    std::cout<<"Please note that if the time is less than one tenth of a second, it will not be displayed.\n";
    std::cout<<"This should only be the case when initial choice 1 is taken\n";

}

int interface::chooseH() {
    int a;
    std::cout<<"Now, choose the H function you would like to use:\n";
    std::cout<<"It must be an integer between 1 and 4\n";
    std::cin>>a;
    return a;
}