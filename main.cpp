#include <iostream>
#include <string>
using namespace std;
class gauss {
private:

    double** kof = nullptr;
    int str;
    int stol;
public:
  void nulling( double tochnost)  {for (int j=0; j< stol+1; j++) {
            for (int i = 0; i <  str; i++) {
                if(abs( kof[i][j] ) < tochnost){
                    kof[i][j] = 0;
                };
            }
        }
  }
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
        for(int i=0; i < stol+1; i++ ){
            k = kof[str_1][i];
            kof[str_1][i] = kof[str_2][i];
            kof[str_2][i] = k;
        }

    }
    void sum (int str_1, int str_2, double n){
        for(int i=0; i < stol+1; i++ ){
            kof[str_2][i] = kof[str_1][i]*n +kof[str_2][i] ;
        }
    }
    double** answer (){
        int g;
        double* x = new double [stol];
        for(int i=0; i<stol+1; i++){
            for(int j=i; i < str; i++) {
                if (kof[j][i] != 0){
                    g = j;
                    this->swap(g, i);
                    break;
                }


            }
            for(int k=i+1; k<str; k++){
                this->sum(g,k,-(kof[k][i]/kof[g][i]) );
            }

        }

        nulling( 0.000001);

        for (int i=0; i < str-1; i++){
            for (int p=0; p<stol; p++){
                if ((kof[i][p] == 0 && kof[i+1][p] != 0) ||(kof[i+1][p] == 0 && kof[i][p] != 0) ){
                    break;
                }
                if (kof[i][p] !=0 && kof[i+1][p] != 0){
                    this->sum( i, i+1, -(kof[i+1][p]/kof[i][p]));
                    break;
                }
            }
        }
         nulling( 0.000001);

        for (int i=0; i < str; i++){
            for (int p=0; p < stol; p++){
                if (kof[i][p] != 0){
                    umn_ch(i,(1/kof[i][p]));
                    break;
                }
            }
        }
        nulling( 0.000001);
        for (int i=0; i < str; i++){
            bool l=true;
            for (int p=0; p < stol-1; p++){
                if (kof[i][p] != 0){
                    l = false;
                    break;
                }
            }
            if ( (!l) && kof [i][stol+1] == 0){
                cout << "Несовместная. Не решу. Я что, бог?"<< endl;
            }
        }
        int z = 0;
        for (int i=0; i < stol; i++){
            int l = 0;
            for (int p=0; p < str; p++){
                if (kof[p][i] != 0){
                    l++;
                }
            }
            if ( l > 1) z++;
        }
        cout << 'd' << z;
    };

};


int main() {

    int stol,  str ;
    cout << "количество переменных:";
    cin >> stol;
    cout<< "количество уравнений:";
    cin >>  str ;
   gauss a(stol,str);
   a.sysout();
   cout<< endl;
   a.answer();
   a.sysout();
}