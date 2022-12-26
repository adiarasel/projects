#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int n, arr[100], tim[100];
int main()
{
    ifstream fin("cowqueue.in");
    ofstream fout("cowqueue.out");
    fin>>n;
    int total=0/*, grandtotal=0*/;
    for(int u=0; u<n; u++){
        fin>>arr[u]>>tim[u];
    }
    /*for(int u=0; u<n; u++){
        fout<<arr[u]<<"  "<<tim[u]<<endl;
    }*/
    for(int a=0; a<n; a++){
        for(int b=a+1; b<n; b++){
            if(arr[b]<arr[a]){
                swap(arr[a], arr[b]);
                swap(tim[a], tim[b]);
            }
        }
    }
    /*for(int u=0; u<n; u++){
        fout<<arr[u]<<"  "<<tim[u]<<endl;
    }*/
    for(int i=-1; i<n-1; i++){
        if(total<arr[i+1]){
            total = arr[i+1]+tim[i+1];
        }
        else{
            total += tim[i+1];
        }
    }
    fout<<total;
}