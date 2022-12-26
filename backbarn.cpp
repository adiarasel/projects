#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int r, c, k;
int dirr[4] = {0, 0, 1, -1};
int dirc[4] = {1, -1, 0, 0};

char forest[10][10];
int nways = 0;

void count (int ir, int ic, int len) {
    int i, newr, newc, old;
    if (len > k) return;
    if (ir == r-1 & ic == c-1) {
        nways++;
        return;
    }
    old = forest[ir][ic];
    forest[ir][ic] = 'x';
    for (i = 0; i < 4; i++) {
        newr = ir + dirr[i];
        if (newr < 0 || newr >= r) continue;
        newc = ic + dirc[i];
        if (newc < 0 || newc >= c) continue;
        if (forest[newr][newc] != '.')
            continue;
        count (newr, newc, len+1);
    }
    forest[ir][ic] = old;
}

int main(){
        int i, j;
        cin>>r>>c>>k;
        for (i = 0; i < r; i++)
            cin>>forest[i];
        count(0, 0, 1);
        cout<<nways<<endl;
        //cerr<<stderr<<endl;
}
// 58/100