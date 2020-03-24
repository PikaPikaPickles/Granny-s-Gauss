#include <iostream>
#include <string>
using namespace std;
double* guss (double **a,int per,int ur){
    int g=0;
    double *x = new double [per];
    for (int i=0;  i < per; i++) {
        for (int j = i; j < ur; j++) {
            if (a[i][j] != 0) {
                g = j;
            }
        }
        if (a[i][g] != 0) {
            for (int j = i+1; j < ur; j++) {
                    for (int l = i; l < per + 1; l++) {
                        a[j][l] = a[j][l] - a[j][g] * (a[i][j] / a[i][g]);
                    }
            }
        }
    }
}
void Ssout (double **p, int per, int ur){
    for (int y=0; y < ur; y++){
        for (int x=0; x < per+1; x++){
            cout<< p[y][x]<< ' ';
        }
        cout<< endl;
    }
}
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
    guss (kof, per, ur);
    Ssout(kof, per, ur);
}