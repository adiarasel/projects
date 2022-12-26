#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string>
int n, cowpos[1001], ans;
using namespace std;
int main()
{
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>cowpos[i];
    }
    sort(cowpos, cowpos + n);
    int a, b, x,y,z;
    for(int i=0; i<n; i++){
        x = cowpos[i];
        for(int j=i+1; j<n; j++){
            y=cowpos[j];
            a= y-x;
            for(int k=i+2; k<n; k++){
                z=cowpos[k];
                b=z-y;
                //cout<<"x = "<<x<<" y = "<<y<<" z = "<<z<<endl;
                if (b >= a && b <= 2 * a){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
}