#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct vote_f {
    int a;
    int b;
    int cownum;
} votes[50000];

int comparea (struct vote_f *a, struct vote_f *b) { return b->a - a->a; }
int compareb (struct vote_f *a, struct vote_f *b) { return b->b - a->b; }

int main() 
{
    ifstream fin("elect.in");
    ofstream fout("elect.out");
    int n, k, i;
    fin>>n>>k;
    for (i = 0; i < n; i++) {
        fin>>votes[i].a>>votes[i].b;
        votes[i].cownum = i;
    }
    qsort(votes, n, sizeof (struct vote_f), comparea);
    qsort(votes, k, sizeof (struct vote_f), compareb);
    fout<<votes[0].cownum+1<<endl;
    exit (0);
}