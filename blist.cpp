#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, start[101], ennd[101], b[101], t[202];
int main()
{
    ifstream fin("blist.in");
    ofstream fout("blist.out");
    fin>>n;
    for(int i=0; i<n; i++){
        fin>>start[i]>>ennd[i]>>b[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(start[i]<start[j]){
                swap(start[i], start[j]);
                swap(ennd[i], ennd[j]);
                swap(b[i], b[j]);
            }
        }
    }
    for(int i=0; i<n; i++){
        fout<<start[i]<<" "<<ennd[i]<<" "<<b[i]<<endl;
    }
    for(int i=0; i<n; i++){
        t[i]=start[i];
    }
    for(int i=n; i<2*n; i++){
        t[i]=ennd[i-n];
    }
    sort(t, t+2*n);
    
}