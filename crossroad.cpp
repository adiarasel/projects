#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int counter;
int main()
{
    ifstream fin("crossroad.in");
    ofstream fout("crossroad.out");
    int n, pos[10], id , sid;
    fin>>n;
    for(int r=0; r<10; r++){
        pos[r]=2;
        //fout<<"pos["<<r<<"] = "<<pos[r]<<endl;
    }
    for(int i=0; i<n; i++){
        fin>>id>>sid;
        if(pos[id-1] == 2){
            pos[id-1]=sid;
            /*fout<<endl;
            fout<<"entered beginning if"<<endl;
            for(int r=0; r<10; r++){
                fout<<"pos["<<r<<"] = "<<pos[r]<<endl;
            }*/
        }
        if(pos[id-1] != 2 && pos[id-1]!= sid){
            counter++;
            pos[id-1]=sid;
            /*fout<<"entered not equals if"<<endl;
            for(int r=0; r<10; r++){
                fout<<"pos["<<r<<"] = "<<pos[r]<<endl;
            }
            fout<<endl;*/
        }
    }
    fout<<counter;
}