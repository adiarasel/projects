#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int n, counter;
int a[100];
int main()
{
    ifstream fin("fjandcows.in");
    fin>>n;
    for(int i=0; i<n;i++){
        fin>>a[i];
    }
    sort(a, a + n);
    for(int i=n-1; i>=0; i--){
        counter++;
        if(a[i]!= a[i-1]){
            cout<<counter<<endl;
            break;
        }
    }
}