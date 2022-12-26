#include <iostream>
#include <algorithm>
using namespace std;
long long n, a, b, c, d, e, f, g, h, m;
struct cowtype {
    long long wght;
    long long util;
};
cowtype cows[1500000];
bool comp(cowtype a , cowtype b) //custom sort
{
    if(a.util > b.util){
        return true;
    }
    else if(a.util == b.util){
        if(a.wght < b.wght){
            return true;
        }
        return false;
    }
    return false;
}
long long pwr(long long x, long long y, long long z) //modified pwr function so that x^y % z is small
{
    long long ans = x % z;
    for(long long i=1; i<y; i++){
        ans = ((ans % z) * (x % z)) % z;
    }
    return ans;
}
long long calcwght(long long cow) // calculates the weight of a cow
{
    long long poe5 = a * (pwr(cow, 5, d)) % d;
    long long poe2 = b * (pwr(cow, 2, d)) % d;
    long long ans = (poe5 + poe2 + c) % d;
    return ans;
}
long long calcutil(long long cow) // calculates the weight of a cow
{
    long long poe5 = e * (pwr(cow, 5, h)) % h;
    long long poe2 = f * (pwr(cow, 3, h)) % h;
    long long ans = (poe5 + poe2 + g) % h;
    return ans;
}
int main()
{
    cin>>n>>a>>b>>c>>d>>e>>f>>g>>h>>m;
    long long sum = 0;
    for(long long i = 0; i < 3 * n; i++){
        cows[i].wght = calcwght(i);
        cows[i].util = calcutil(i);
    }
    sort(cows, cows + 3 * n, comp);
    for(long long i=0; i<n; i++){
        sum += cows[i].wght;
    }
    cout << sum % m;
    
}