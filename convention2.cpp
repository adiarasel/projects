#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
struct entry{
    int id;
    int arr;
    int dur;
};
entry cows[100009], org[100009];
set<int> waitlist;
int n, totaltime, waitime, ans, firstcow;
bool comp(entry a, entry b)
{
    if(a.arr != b.arr){
        return a.arr < b.arr;
    }
    else{
        return a.id < b.id;
    }
}
int main()
{
    cin>>n;
    int c, d;
    for(int i=0; i<n; i++){
        cin>>c>>d;
        cows[i].id = i;
        org[i].id = i;
        cows[i].arr = c;
        org[i].arr = c;
        cows[i].dur = d;
        org[i].dur = d;
    }
    sort(cows, cows + n, comp);
    for(int i=0; i<n; i++){
        cout<<cows[i].arr<<"  "<<cows[i].dur<<endl;
    }
    for(int i=0; i<n; i++){
        cout<<org[i].arr<<"  "<<org[i].dur<<endl;
    }
    firstcow = cows[0].id;
    totaltime = cows[0].arr + cows[0].dur;
    int counter = 1, current, pick;
    while(cows[counter].arr < totaltime && counter < n){
        waitlist.insert(cows[counter].id);
        if(waitlist.empty()){
            current = counter;
            totaltime += cows[current].arr + cows[current].dur;
        }
        else{
            pick = *waitlist.begin();
            waitlist.erase(*waitlist.begin());
            waitime = totaltime - org[pick].arr;
            if(ans <= waitime){
                ans = waitime;
            }
            totaltime += org[pick].dur;
        }
        
    }
    cout<<ans<<endl;
}
/*
5
25 3
105 30
20 50
10 17
100 10
*/