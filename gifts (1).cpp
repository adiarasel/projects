#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int n, b, maxprice=-1;
int p[1000], s[1000], temp[1000];
void pairsort(int a[], int c[], int num) 
{ 
    pair<int, int> pairt[num]; 
    for (int i = 0; i < num; i++)  { 
        pairt[i].first = a[i]; 
        pairt[i].second = c[i]; 
    } 
    sort(pairt, pairt + num);  
    for (int i = 0; i < num; i++)  { 
        a[i] = pairt[i].first; 
        c[i] = pairt[i].second; 
    } 
}
int main()
{
    ifstream fin("gifts.in");
    ofstream fout("gifts.out");
    fin>>n>>b;
    int counter=0, sum=0, j, maxcows=-1;
    for(int i=0; i<n; i++){
        fin>>p[i]>>s[i];
        temp[i]=p[i];
    }
    sort(temp, temp+n);
    for(int i=0; i<n; i++){
        temp[i]=temp[i]/2;
        pairsort(temp, s, n);
        for(j=0; j<n; j++){
            if(sum > b){
                fout<<"PASSED BUDGET"<<endl;
                break;
            }
            else{
                sum+=(temp[j]+s[j]);
            }
            fout<<"sum = "<<sum<<" j = "<<j<<endl;
        }
        sum=0;
        maxcows=max(maxcows,j);
        for(int k=0; k<n; k++){
            temp[k]=p[k];
        }
    }
    fout<<maxcows-1;
}
