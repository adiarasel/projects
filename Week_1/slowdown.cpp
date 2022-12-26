// two arrays one for time one for distance, sort
// go through those, update speed as you go
#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <vector>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;

vector <int> tim, dist;
int n;
long long total;

int main()
{
    ifstream fin("slowdown.in");
    ofstream fout("slowdown.out");
    char c;
    int x;
    fin>>n;
    FOR(i, n){
        fin>>c>>x;
        if(c == 'T'){
            tim.push_back(x);
        }
        else{
            dist.push_back(x);
        }
    }
    sort(tim.begin(), tim.end());
    sort(dist.begin(), dist.end());
    tim.push_back((int)1e9);
    dist.push_back(1000);
    int timind = 0, distind = 0, speed = 1; //inverse of actual speed, just used 1/speed for actual speed later on
    double pos = 0, times = 0, t = 0, t2 = 0;
    while(distind < dist.size()){
        t = tim[timind] - times;
        t2 = (dist[distind] - pos) * speed;
        if(t < t2){
            pos += t/speed;
            times += t;
            timind++;
            speed++;
        }
        else if (t > t2){
            times += t2;
            pos = dist[distind];
            distind++;
            speed++;
        }
        else{
            pos += t/speed;
            times += t;
            timind++;
            times += t2;
            pos = dist[distind];
            distind++;
            speed+=2;
        }
        
    }
    fout<<(int)round(times)<<endl;

    fin.close();
    fout.close();
    return 0;
}