#include <iostream>
#include <fstream>
int sum=0, counter=0;
using namespace std;
int main()
{
    ifstream fin("flyingchicken.in");
    ofstream fout("flyingchicken.out");
    int s, u, d;
    fin>>s>>u>>d;
    while(sum < s){
        sum = sum + u - d;
        counter++;
    }
    fout<<counter-1;
}