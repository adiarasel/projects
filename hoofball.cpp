#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int n,x[100],passto[100]; //n is #cows
int target(int i)//returns where cow will next throw ball if recieved
{
    int leftnbr=-1, rightnbr=-1, leftdist=1000, rightdist=1000;
    for(int j=0; j<n;j++)
        if(x[j]<x[i] && x[i]-x[j]<leftdist) { leftnbr=j; leftdist=x[i]-x[j]; }
    for(int j=0; j<n;j++)
        if(x[j]>x[i] && x[j]-x[i]<rightdist) { rightnbr=j; rightdist=x[j]-x[i]; }
    
    if(leftdist<=rightdist) return leftnbr;
    return rightnbr;
}
int main()
{
    ifstream fin("hoofball.in");
    ofstream fout("hoofball.out");
    fin>>n;
    for(int i=0; i<n; i++){
        fin>>x[i];
    }
    for(int i=0; i<n; i++){
        passto[target(i)]++;
    }
    int ans=0;
    for(int i=0; i<n; i++){
        if(passto[i]==0) ans++; //+1 for every source cow
        if(i<target(i) && target(target(i))==i && passto[i]==1 && passto[target(i)]==1){
            ans++; //+1 for every isolated pair
        }
    }
    fout<<ans;
    return 0;
}