#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main()
{
    ifstream fin("censor.in");
    ofstream fout("censor.out");
    string s, r;
    fin>>s>>r;
    int b=s.find(r);
    int x=r.length();
    while(b!=-1){
        s.erase(b, x);
        if(b-x+1 >= 0){
            b=s.find(r, b-x+1);
        }
        else{
            b=s.find(r);
        }
    }
    fout<<s;
}