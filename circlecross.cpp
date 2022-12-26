#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string>
int start[26], ennd[26], counter[26];
using namespace std;
int main()
{
    ifstream fin("circlecross.in");
    ofstream fout("circlecross.out");
    string s;
    int ans=0;
    fin>>s;
    for(int a=0; a<52; a++){
        counter[s[a]-'A']++;
        if(counter[s[a]-'A']==1){
            start[s[a]-'A']=a;
        }
        else if(counter[s[a]-'A']==2){
            ennd[s[a]-'A']=a;
        }
    }
    /*for(int a=0; a<26; a++){
        cout<<start[a]<<"    "<<ennd[a]<<endl;
    }*/
    for(int i=0; i<26; i++){
        for(int j=0; j<26; j++){
            if(start[i] < start[j] && start[j] < ennd[i] && ennd[i] < ennd[j]){
                //fout<<"i = "<<i<<" j = "<<j<<endl;
                //cout<<start[i]<<"  "<<start[j]<<"  "<<ennd[i]<<"  "<<ennd[j]<<endl;
                ans++;
            }
        }
    }
    fout<<ans;
}