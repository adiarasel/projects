#include <iostream>
#include <fstream>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
long long n;
long long freqtable[2][7]; // 0 row is even, 1 is odd, 0- 6 is B E S I G O M in that order
int main()
{
    ifstream fin("geteven.in");
    ofstream fout("geteven.out");
    fin>>n;
    int x;
    char ch;
    FOR(j, n){
        fin>>ch>>x;
        if(ch == 'B' && x % 2 == 0) freqtable[0][0]++; 
        if(ch == 'B' && x % 2 == 1) freqtable[1][0]++;
        if(ch == 'E' && x % 2 == 0) freqtable[0][1]++;
        if(ch == 'E' && x % 2 == 1) freqtable[1][1]++;
        if(ch == 'S' && x % 2 == 0) freqtable[0][2]++;
        if(ch == 'S' && x % 2 == 1) freqtable[1][2]++;
        if(ch == 'I' && x % 2 == 0) freqtable[0][3]++;
        if(ch == 'I' && x % 2 == 1) freqtable[1][3]++;
        if(ch == 'G' && x % 2 == 0) freqtable[0][4]++;
        if(ch == 'G' && x % 2 == 1) freqtable[1][4]++;
        if(ch == 'O' && x % 2 == 0) freqtable[0][5]++;
        if(ch == 'O' && x % 2 == 1) freqtable[1][5]++;
        if(ch == 'M' && x % 2 == 0) freqtable[0][6]++;
        if(ch == 'M' && x % 2 == 1) freqtable[1][6]++;
    }
    long long ans = 0;
    FOR(i1, 2){ // b
        FOR(i2, 2){ // e
            FOR(i3, 2){ // s
                FOR(i4, 2){ // i
                    FOR(i5, 2){ // g 
                        FOR(i6, 2){ // o
                            FOR(i7, 2){ // m
                                if(((i1 + 2 * i2 + 2 * i3 + i4) * (i5 + i6 + i2 + i3) * (i7 + 2 * i6)) % 2 == 0){
                                    ans += freqtable[i1][0] * freqtable[i2][1] * freqtable[i3][2] * freqtable[i4][3] * freqtable[i5][4] * freqtable[i6][5] * freqtable[i7][6];
                                }
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