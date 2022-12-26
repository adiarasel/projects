#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int freq[676][676];
string city, state;
int main()
{
    int n, citynum, statenum;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>city>>state;
        citynum = (city[0] - 'A') * 26 + (city[1] - 'A');
        statenum = (state[0] - 'A') * 26 + (state[1] - 'A');
        freq[citynum][statenum]++;
    }
    long long sum=0;
    for(int i=0; i<676; i++){
        for(int j=i+1; j<676; j++){
            sum+= freq[i][j] * freq[j][i];
        }
    }
    cout<<sum<<endl;
}