#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
int n;
struct pos{
    int x;
    int y;
};
pos cows[50000];
int x[50000], y[50000];
long long best = 10e17;
int main()
{
    ifstream fin("reduce.in");
    ofstream fout("reduce.out");
    fin>>n;
    FOR(i, n){
        fin>>cows[i].x>>cows[i].y;
        x[i] = cows[i].x;
        y[i] = cows[i].y;
    }
    int counter = 0;
    sort(x, x + n);
    sort(y, y + n);
    FOR(i, 4){ // x min
        for(int j = n-1; j > n-4; j--){ // x max
            FOR(k, 4){ // y min
                for(int l = n-1; l > n-4; l--){ // y max
                    counter = 0;
                    FOR(p ,n){
                        if(cows[p].x >= x[i] && cows[p].x <= x[j] && cows[p].y >= y[k] && cows[p].y <= y[l]){
                            //check for all points in the fence
                            counter++;
                        }
                    }
                    if(counter >= n - 3){ // check for validity
                        long long area = (x[i] - x[j]) * (y[k] - y[l]);
                        best = min(best, area); // find smallest answer;
                    }
                }
            }
        }
    }
    fout<<best<<endl;
    fin.close();
    fout.close();
    return 0;
}