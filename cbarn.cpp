#include <iostream>
#include <fstream>
using namespace std;
int r[1001];
int main()
{
    ifstream fin("cbarn.in");
    ofstream fout("cbarn.out");
    int n, minisum=-1;
    fin>>n;
    for(int j=0; j<n; j++){
        fin>>r[j];
    }
    for(int i=0; i<n;i++){
        int sum=0;
        for(int j=0; j <n; j++){
            sum += r[(i+j) % n] * j;
        }
        if(i==0 || sum < minisum){
            minisum=sum;
        }
    }
    fout<<minisum;
}