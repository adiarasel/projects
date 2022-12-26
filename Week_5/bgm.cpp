#include <iostream>
#include <fstream>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
long long n;
long long freqtable[7][7]; // 0 row is 0 mod 7, 1 is 1 mod 7, etc., 0- 6 is B E S I G O M in that order
int main()
{
    ifstream fin("bgm.in");
    ofstream fout("bgm.out");
    fin>>n;
    int x;
    char ch;
    FOR(j, n){
        fin>>ch>>x;
            if(ch == 'B'){
                freqtable[0][(x%7 + 7)%7]++;
            }
            if(ch == 'E'){
                freqtable[1][(x%7 + 7)%7]++;
            }
            if(ch == 'S'){
                freqtable[2][(x%7 + 7)%7]++;
            }
            if(ch == 'I'){
                freqtable[3][(x%7 + 7)%7]++;
            }
            if(ch == 'G'){
                freqtable[4][(x%7 + 7)%7]++;
            }
            if(ch == 'O'){
                freqtable[5][(x%7 + 7)%7]++;
            }
            if(ch == 'M'){
                freqtable[6][(x%7 + 7)%7]++;
            }

    }
    // FOR(i, 7){
    //     FOR(j, 7){
    //         cout<<freqtable[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    long long ans = 0;
    FOR(i1, 7){ // b
        FOR(i2, 7){ // e
            FOR(i3, 7){ // s
                FOR(i4, 7){ // i
                    FOR(i5, 7){ // g 
                        FOR(i6, 7){ // o
                            FOR(i7, 7){ // m
                                if(((i1 + 2 * i2 + 2 * i3 + i4) * (i5 + i6 + i2 + i3) * (i7 + 2 * i6)) % 7 == 0){
                                    ans += freqtable[0][i1] * freqtable[1][i2] * freqtable[2][i3] * freqtable[3][i4] * freqtable[4][i5] * freqtable[5][i6] * freqtable[6][i7];
                                    // cout<<ans<<endl;
                                }
                                // if(i1 == 2 && i2 == 5 && i3 == 0 && i4 == 2 && i5 == 1 && i6 == 2 && i7 == 5){
                                //     cout<<freqtable[i1][0]<<freqtable[i2][1]<<freqtable[i3][2]<<freqtable[i4][3]<<freqtable[i5][4]<<freqtable[i6][5]<<freqtable[i7][6]<<endl;
                                // }
                            }
                        }
                    }
                }
            }
        }
    }
    fout<<ans<<endl;
    fin.close();
    fout.close();
    return 0;
}