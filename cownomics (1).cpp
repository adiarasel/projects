#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main()
{
    ifstream fin("cownomics.in");
    ofstream fout("cownomics.out");
    int n, m, ans=0;
    char spotty[100][100], plain[100][100];
    int numbers[100];
    fin>>n>>m;
    for(int l=0; l<n; l++){
        for(int y=0; y<m; y++){
            fin>>spotty[l][y];
        }
    }
    for(int l=0; l<n; l++){
        for(int y=0; y<m; y++){
            fin>>plain[l][y];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m;j++){
            for(int k=0; k<n; k++){
                if(plain[k][j]==spotty[i][j]){
                    numbers[j]++;
                }
                //fout<<"i = "<<i<<" j = "<<j<<" k = "<<k<<endl;
            }
        }
    }
    for(int a=0; a<m; a++){
        if(numbers[a]==0){
            ans++;
        }
    }
    fout<<ans;
}