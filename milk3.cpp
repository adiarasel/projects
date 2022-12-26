#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int A, B, C;
int capac[4];
int used[33000];
set<int> Cs;
int getst(int A, int B, int C)
{
    int st = 0;
    st |= A;
    st |= (B << 5);
    st |= (C << 10);
    return st;
}
int getnum(int st, int num)
{
    int mask = 31 << ((num-1) * 5);
    return (st & mask) >> ((num-1) * 5);
}
int setnum(int st, int numb, int nval)
{
    int mask = ~(31 << ((numb-1) * 5));
    st &= mask;
    mask = nval << ((numb-1)*5);
    st |= mask;
    return st;
}
int inc(int st, int numb, int quant)
{
    int curval = getnum(st, numb);
    curval += quant;
    return setnum(st, numb, curval);
}
int decrement(int st, int numb, int quant)
{
    int curval = getnum(st, numb);
    curval -= quant;
    return setnum(st, numb, curval);
}
void DFS(int st)
{
    if(getnum(st, 1) == 0)
    {
        Cs.insert(getnum(st, 3));
    }
    for(int i = 1; i <= 3; ++i)
    {
        vector<int> oths;
        for(int j = 1; j <= 3; ++j)
        {
            if(i == j)continue;
            oths.push_back(j);
        }
        //Now pour from i to the other 2
        int toPour = min(capac[oths[0]] - getnum(st, oths[0]), getnum(st, i));
        int newst = inc(st, oths[0], toPour);
        newst = decrement(newst, i, toPour);
        if(used[newst] == 0)
        {
            used[newst] = 1;
            DFS(newst);
        }
        toPour = min(capac[oths[1]] - getnum(st, oths[1]), getnum(st, i));
        newst = inc(st, oths[1], toPour);
        newst = decrement(newst, i, toPour);
        if(used[newst] == 0)
        {
            used[newst] = 1;
            DFS(newst);
        }

    }
}
int main()
{
    cin >> A >> B >> C;
    capac[1] = A;
    capac[2] = B;
    capac[3] = C;
    int st = getst(0, 0, C);
    used[st] = 1;
    DFS(st);
    int curnum = 1;
    for(set<int>::iterator i = Cs.begin(); i != Cs.end(); ++i, curnum++)
    {
        cout<<*i;
        if(curnum < Cs.size()) cout<<" ";
    }
    cout<<"\n";
    return 0;
}