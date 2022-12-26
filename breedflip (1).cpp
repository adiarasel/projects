#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;
int n;
string A_A,B_B;
int OWO[1001];
int main()
{
    ifstream fin("breedflip.in");
    ofstream fout("breedflip.out");
    fin>>n;
    fin>>A_A>>B_B;
    int ans=0;
    for(int i=0; i<n; i++){
        if(A_A[i]!=B_B[i]){
            OWO[i]=1;
        }
    }
    /*for(int i=0; i<n; i++){
        fout<<OWO[i]<<endl;
    }*/
    for(int i=0; i<n; i++){
        if(OWO[i]==1 && OWO[i+1]==0){
            ans++;
        }
    }
    fout<<ans;
}