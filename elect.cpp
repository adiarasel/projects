#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int rd1[50000], rd2[50000], dummy1[50000], indexx[50000];
long int n, k, counter=0, maxvotes=0;
int main()
{
    ifstream fin("elect.in");
    ofstream fout("elect.out");
    fin>>n>>k;
    for(int i=0; i<n; i++){
        fin>>rd1[i]>>rd2[i];
        // fout<<"rd1 = "<<rd1[i]<<" rd2 = "<<rd2[i]<<endl;
        dummy1[i]=rd1[i];
    }
    sort(dummy1, dummy1 + n);
    // for(int i=0; i<n; i++){
    //     fout<<dummy1[i]<<endl;
    // }
    for(int i=1; i<=k;i++){
        for(int j=0; j<n; j++){
            if(dummy1[n-i]==rd1[j]){
                // fout<<"QUAIFIES FOR 2ND ROUND"<<endl;
                counter=j;
                break;
            }
        }
        indexx[i]=counter;
        // fout<<"indexx = "<<indexx[i]<<endl;
    }
    for(int i=1; i<=k; i++){
        maxvotes=max(maxvotes, rd2[indexx[i]]);
        // fout<<"maxvotes = "<<maxvotes<<endl;
    }
    for(int i=0; i<n; i++){
        if(maxvotes==rd2[i]){
            fout<<i+1;
        }
    }
}