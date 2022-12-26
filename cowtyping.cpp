#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ifstream fin("cowtyping.in");
    ofstream fout("cowtyping.out");
    string keyboard, s;
    fin>>keyboard>>s;
    int pos=0;
    for(int i=0; i < s.length(); i++){
        int x = keyboard.find(s[i]);
        if(x <= pos){
            for(int j=0; j < pos-x; j++){
                fout<<"<";
            }
        }
        if(x > pos){
            for(int j=0; j < x-pos; j++){
                fout<<">";
            }
        }
        fout<<".";
        pos=x;
    }
}