#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
priority_queue <pair<int, int> > waiting;
priority_queue <tuple<int, char, int> > events;
struct entry{
    int arrival;
    int seniority;
    int stay;
};
int n, answer, ind;
entry cows[100009];
bool comp(entry a, entry b)
{
    if(a.arrival != b.arrival){
        return a.arrival < b.arrival;
    }
    else{
        return a.seniority < b.seniority;
    }
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++){
        cows[i].seniority = i;
        cin>>cows[i].arrival>>cows[i].stay;
    }
    for(int i=0; i<n; i++){
        events.push(cows[i].arrival, 'a', i);
    }
    int currentcow = 0;
    int currenttime= 0;
    while(!events.empty() || !waiting.empty()){
        if(currentcow == 0){
            if(waiting.size == 0){
                currentcow = events.top.third();
                events.pop();
            }
            else{
                currentcow = waiting.top.second;
                waiting.pop();
            }
            currenttime = max(currenttime, cows[currentcow].arrival);
            answer = max(answer, currenttime - cows[currentcow].arrival);
            events.push(currenttime + cows[currentcow].stay, 'e', i);
        }
        while(currentcow > 0){
            ind = events.top.third();
            if(events.top.second = 'a'){
                waiting.push(cows[ind].seniority, ind);
            }
            else{
                currentcow = 0;
                currenttime = events.top.first;
            }
            events.pop();
        }
    }
    cout<<answer<<endl;
}
/*
5
25 3
105 30
20 50
10 17
100 10
*/