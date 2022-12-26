#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("cowsignal.in");
    ofstream fout("cowsignal.out");
    int m, n, k; 
    fin>>m>>n>>k;
    string s, temp="";
    for(int a=0; a<m; a++){
        fin>>s;
        for(int i=0; i< s.length(); i++){
            for(int j=0; j<k; j++){
                temp=temp+s[i];
            }
        }
        for(int i=0; i<k; i++){
            fout<<temp<<endl;
        }
        temp="";
    }
}