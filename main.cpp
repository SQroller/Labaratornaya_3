#include <iostream>
#include "LogElement.h"

using namespace std;

int main() {
    //LogElement elementEmpty();
    //LogElement elementOnlySize(1);
    int number = 1;
    char **massiv = new char * [number];
    for (int i = 0; i < number; ++i) {
        massiv[i] = new char [3];
    }
    for (int i = 0; i < number; ++i) {
        for (int j = 0; j < 3; ++j) {
            massiv[i][j] = '1';
        }
    }
    LogElement elementMassiv(1,massiv);
    cout<<"ADD CLEAT\n";
    //elementMassiv.addCleat();
    elementMassiv-(1);
    cout<<elementMassiv;
    elementMassiv+(1);
    cout<<elementMassiv;
//    elementOnlySize.addCleat();
//    elementOnlySize.outputMass();
    return 0;
}
