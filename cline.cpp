#include <iostream>
#include <deque>
using namespace std;
deque<int> cows;
int main()
{
    int n=1, s;
    char c, d;
    int k=0;
    cin>>s;
    for(int i=0; i<s; i++){
        cin>>c;
        if(c == 'A'){
            cin>>d;
            if(d == 'L'){
                cows.push_front(n);
            }
            if(d == 'R'){
                cows.push_back(n);
            }
            n++;
        }
        if(c == 'D'){
            cin>>d>>k;
            if(d == 'L'){
                for(int j=0; j<k; j++){
                    cows.pop_front();
                }
            }
            if(d == 'R'){
                for(int j=0; j<k; j++){
                    cows.pop_back();
                }
            }
        }
    }
    for(int i=0; !cows.empty() ; i++){
        cout<<cows.front()<<endl;
        cows.pop_front();
    }
}