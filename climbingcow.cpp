#include <iostream>
#include <fstream>
int sum=0, counter=0;
using namespace std;
int main()
{
    ifstream fin("climbingcow.in");
    ofstream fout("climbingcow.out");
    int s, u, d;
    fin>>s>>u>>d;
    while(sum < s){
        sum += u;
        counter+=u;
        if(sum>=s){
            break;
        }
        counter+=d;
        sum -=d;
    }
    fout<<counter;
}