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
    double** umn_ch (int str_1, double mn){
        for(int i = 0; i < stol+1; i++ ){
            kof[str_1][i] = kof[str_1][i] * mn;
        }
        return kof;
    }
    void Ssout (){ // вывод матрицы на экран;
        for (int y=0; y <  this->str ; y++) {
            for (int x = 0; x < this->stol + 1; x++) {
                cout << this->kof[y][x] << ' ';
            }
            cout<< endl;
        }

    }
    double** per_str (int str_1, int str_2){

    }
};

int main() {

    int stol,  str ;
    cout << "количество переменных:";
    cin >> stol;
    cout<< "количество уравнений:";
    cin >>  str ;
   gauss a(stol,str);
   a.umn_ch(2, 3);
   a.Ssout();
}