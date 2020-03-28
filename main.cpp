#include <iostream>

using namespace std;
class gauss {
public:
    double** kof = nullptr;
    int str;
    int stol;
    int vb;
    int l;
   bool isBasis (int h){
            for (int i=0; i < str; i++){
                for (int p=0; p < stol; p++){
                    if (kof[i][p] != 0){
                        l = p;
                        break;
                    }
                }
                if (l == h){
                    return true;
                }
            }
            return false;
   }

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
            bool l = false;
            for (int p=0; p < stol; p++){
                if (kof[i][p] != 0){
                    l = true;
                    break;
                }
            }
            if ( (!l) && kof [i][stol+1] != 0){
                cout << "Несовместная. Не решу. Я что, бог?"<< endl;
                return nullptr;
            }
            break;
        }
        int z = 0;
        for (int i=0; i < stol; i++){
            if (isBasis(i)){
                z++;
            }
        }
        int l = 0;

       double **x = new double *[stol];
    for (int i = 0; i <  stol ; i++) {
        x[i] = new double[stol - z + 1];
    }
    int u = 0;

    for(int i=0; i < stol; i++){
        if (!isBasis(i)){
            x[i][u] = 1;
            u++;
        }
    }
    for(int i=0; i<stol-1; i++){

        if (isBasis(i)){
            for (int q=0; q < str-1; q++){ //213213213
                // uslobie stroki bazisa
                int w=0;
                bool ww;
                for (int s=0; s<stol; s++){
                    if(kof[q][s] !=0){
                        w=s;
                        break;
                    }
                }
                if(w == i )
                {
                    for(int c=0; c< stol; c++){
                        if (kof[q][c]!=0 && isBasis(c) && kof[q+1][c] != 0 ){
                            sum (q+1,q, -(kof[q][c]/kof[q+1][c]));
                        }
                    }
                }
            }
        }
    }
    for(int e=0; e < stol; e++){
        x[e][stol-z] = kof[e][stol];
    }
    for (int c=0; c < stol; c++){
        for (int v=0; v < z+1; v++){
            for(int o=0; o< stol; o++){
                if (kof[o][c]!=0){
                    x[c][v]= -kof[c][o];
                    break;
                }
            }

        }
    }
    vb = z;
    return x;
    };

};


int main() {

    int stol = 0,  str = 0 ;
    cout << "количество переменных:";
    cin >> stol;
    cout<< "количество уравнений:";
    cin >>  str ;
   gauss a(stol,str);
   a.sysout();
   cout<< endl;
   double **x = a.answer();
   a.sysout();
   for (int i=0; i < a.stol; i++ ){
       for (int j=0; j < a.stol - a.vb +1; j++){
           cout << x[i][j]<< ' ';
       }
       cout<< endl;
   }
}