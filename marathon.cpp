#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
int x[100000], y[100000];
int n;
int dist(int a, int b) // function for calculating Manhattan distance between indexes of an x n y array
{
    return abs(x[b]-x[a]) + abs(y[b]-y[a]);
}

int main()
{
    ifstream fin("marathon.in");
    ofstream fout("marathon.out");
    int skip = -1, sum = 0;
    fin>>n;
    FOR(i, n){
        fin>>x[i]>>y[i];
    }
    for(int i = 1; i < n; i++) {
        sum += dist(i, i-1);
    }
    for(int i = 1; i < n-1; i++) {
        int noSkipDistance = dist(i+1, i) + dist(i, i-1);
        int skipDistance = dist(i+1, i-1);
        skip = max(skip, noSkipDistance - skipDistance);
    }
    fout<<sum - skip<<endl;
    fin.close();
    fout.close();
    return 0;
}