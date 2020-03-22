#include <iostream>
#include <string>
using namespace std;


int main() {

    int per, ur;
    cout << "количество переменных:";
    cin >> per;
    cout<< "количество уравнений:";
    cin >> ur;
    double **kof = new double *[ur];
    for (int i = 0; i < ur; i++) {
        kof[i] = new double[per + 1];
    }
    for (int j=0; j< per; j++) {
        for (int i = 0; i < ur; i++) {
            cout << "a["<< i<< ']' << '['<< j <<"] =";
            cin >> kof[i][j];
        }
    }
    for (int i=0; i < ur; i++){
        cout << 'b' <<'[' << i << "] = " ;
        cin >> kof[i][per];
    }
}