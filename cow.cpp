#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main()
{
    ifstream fin("cow.in");
    ofstream fout("cow.out");
    string s;
    int n, counter=0;
    long long total;
    long long combo; // second variable used for counting co combos
    fin>>n>>s;
    for(int i=0; i < n; i++){
        if(s[i]=='O'){//COUNTING CO COMBOS
            for(int j=i-1; j>=0; j--){
                if(s[j]=='C'){
                    combo++;
                }
            }
        }
        if(s[i]=='W'){
            total+=combo;
            //ADDING TO THE TOTAL then resetting counter
        }
        //fout<<"combo = "<<combo<<" total = "<<total<<endl;
    }
    fout<<total;
}