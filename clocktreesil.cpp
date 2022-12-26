#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <queue>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
int n;
vector<int> edges[100000];
int d[100000];
int A[100000];
int s0,s1,n0,n1;

void dfs(int i,int depth,int par)
{
	d[i] = depth;
	for(int j=0;j<edges[i].size();j++)
		if(edges[i][j]!=par)
			dfs(edges[i][j],depth+1,i);
}
int main()
{
    ifstream fin("clocktree.in");
    ofstream fout("clocktree.out");
    int a,b;
	fin >> n;
	for(int i=0;i<n;i++)
		fin >> A[i];
	for(int i=1;i<n;i++)
	{
		fin >> a >> b;
		a--,b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs(0,0,-1);
	for(int i=0;i<n;i++)
	{
		if(d[i]%2) s1 += A[i], n1++;
		else s0 += A[i], n0++;
	}
	if((s0%12) == (s1%12))
		fout << n << '\n';
	else if((s0+1)%12 == (s1%12))
		fout << n1 << '\n';
	else if((s0%12) == ((s1+1)%12))
		fout << n0 << '\n';
	else
		fout << 0 << '\n';
	return 0;
}