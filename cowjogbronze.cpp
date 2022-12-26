#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int group, counter;
int main()
{
    ifstream fin("cowjog.in");
    ofstream fout("cowjog.out");
    int p, n, pos;
    int cowspd[100002];
    fin>>n;
    pos=n-1;
    for(int t=n; t>0; t--){
        fin>>p>>cowspd[t];
    }
    cowspd[0]=659535345;
    for(int i=1; i<=n; i++){
        if(cowspd[i-1]<cowspd[i]){
            cowspd[i]=cowspd[i-1];
        }
        else{
            group++;
        }
    }
    fout<<group;
}