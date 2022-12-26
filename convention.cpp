#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m, c, loc[100000]; 
bool check(int x)
{
    int cur_left = 0;
    int bus_count = 0;
    for(int i=0; i<n; i++){
        if(i - cur_left == c || loc[i] - loc[cur_left] > x){
            bus_count++;
            cur_left = i;
        }
    }
    bus_count++;
    if(bus_count <= m){
        return true;
    }
    return false;
}
int main()
{
    cin>>n>>m>>c;
    check(n);
}