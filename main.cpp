#include <iostream>
#include <string>
using namespace std;
class gauss {
private:

    double** kof;
    int str;
    int stol;
public:

    gauss ( int stol,int  str ) {
        this->str = str;
        this->stol =stol;
    double **kof = new double *[ str ];
    for (int i = 0; i <  str ; i++) {
        kof[i] = new double[stol + 1];
    }
    for (int j=0; j< stol; j++) {
        for (int i = 0; i <  str ; i++) {
            cout << "a["<< i<< ']' << '['<< j <<"] =";
            cin >> kof[i][j];
        }
    }
    for (int i=0; i <  str ; i++){
        cout << 'b' <<'[' << i << "] = " ;
        cin >> kof[i][stol];
    }
    this->kof = kof;
    }
    void umn_ch (int str_1, double mn){
        for(int i = 0; i < stol+1; i++ ){
            kof[str_1][i] = kof[str_1][i] * mn;
        }
    }
    void sysout (){ // вывод матрицы на экран;
        for (int y=0; y <  this->str ; y++) {
            for (int x = 0; x < this->stol + 1; x++) {
                cout << this->kof[y][x] << ' ';
            }
            cout<< endl;
        }

    }
    void swap (int str_1, int str_2){
        double k;
        for(int i=0; i < this->stol+1; i++ ){
            k = kof[str_1][i];
            kof[str_1][i] = kof[str_2][i];
            kof[str_2][i] = k;
        }

    }
    void sum (int str_1, int str_2, double n){
        for(int i=0; i < this->stol+1; i++ ){
            kof[str_2][i] = kof[str_1][i]*n +kof[str_2][i] ;
        }
    }
    double* answer (){
        int nenul;
        for (int i=0; i < stol+1; i++){
            for (int j=i; j < str; i++ ){
                if (a[j][i]!=0){
                    nenul = i;
                }
            }
        }

    }

};

int main() {

    int stol,  str ;
    cout << "количество переменных:";
    cin >> stol;
    cout<< "количество уравнений:";
    cin >>  str ;
   gauss a(stol,str);
   a.swap(0,1);
   a.sysout();
}