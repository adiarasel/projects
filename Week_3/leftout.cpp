#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <queue>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
int n;
char grid[1005][1005];
void row(int x){
    FOR(i, n){
        if(grid[x][i] == 'L') grid[x][i] = 'R';
        else grid[x][i] = 'L';
    }
}
void col(int x){
    FOR(i, n){
        if(grid[i][x] == 'L') grid[i][x] = 'R';
        else grid[i][x] = 'L';
    }
}
int main()
{
    ifstream fin("leftout.in");
    ofstream fout("leftout.out");
    FOR(i, n){
        string s;
        fin>>s;
        FOR(j, n){
            grid[i][j] = s[j];
        }
    }

    fin.close();
    fout.close();
    return 0;
}