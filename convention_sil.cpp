#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int n,m,c;
int t[100000];
bool pos(int wait)
{
	int buses = 1;
	int firarr = t[0];
	int firind = 0;
	for(int i=1;i<n;i++)
	{
		if(t[i] - firarr > wait || i + 1 - firind > c)
		{
			buses += 1;
			firarr = t[i];
			firind = i;
		}
	}
	return (buses <= m);
}

int bs(int l,int r)
{
	if(l == r) return l;
	if(l + 1 == r)
	{
		if(pos(l)) return l;
		return r;
	}
	int mid = (l+r)/2;
	if(pos(mid)) return bs(l,mid);
	else return bs(mid+1,r);
}

int main()
{
	ifstream fin("convention.in");
    ofstream fout("convention.out");
    fin >> n >> m >> c;
	for(int i=0;i<n;i++)
		fin >> t[i];
	sort(t,t+n);
	fout << bs(0, 1000000000) << endl;
}