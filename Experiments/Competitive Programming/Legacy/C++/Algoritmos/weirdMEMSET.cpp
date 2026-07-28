#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char L;
    int N, M, pares;
    int sapatos[61];

    while(cin >> N){
        pares = 0;
        memset(sapatos, 0, sizeof(sapatos));

        for(int i = 0; i < N; ++i){
            cin >> M >> L;

            if(L == 'D'){
                if(sapatos[M] < 0)  ++pares;
                ++sapatos[M];
            }else{
                if(sapatos[M] > 0)  ++pares;
                --sapatos[M];
            }
        }

        cout << pares << endl;
    }

    return 0;
}