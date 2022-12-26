#include <iostream>
#include <algorithm>
using namespace std;
int k, n, r; //k cows, n haybales, radius r
int haybales[50001]; //haybale array
int bs()
{
	int min_hay = 0;
	int max_hay = 500000000;
	while(min_hay != max_hay) {
		int mid = (min_hay+max_hay)/2;
		int used = 0; // # used cows
		int last = 0; // first position of unblasted haybale
		while(last < n) {
			used++;
			int curr = last+1;
			while(curr < n && haybales[curr] - haybales[last] <= 2*mid) {
				curr++;
			}
			last = curr;
		}
		if(used <= k) {
			max_hay = mid;
		}
		else {
			min_hay = mid+1;
		}
	}
    return min_hay;
}
int main()
{
    cin>>n>>k;
    int temp=0;
    for(int i=0; i<n; i++){
        cin>>haybales[i];
    }
    sort(haybales, haybales + n);
    cout<<bs()<<endl;
}