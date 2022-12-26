#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
struct rectangle{
    int x1, y1, x2, y2;
};
int area(rectangle r)
{
    int are = (r.x2-r.x1) * (r.y2-r.y1);
    return are;
}
int intersection(rectangle p, rectangle q){
    int x_overlap = max(0,min(p.x2,q.x2)-max(p.x1, q.x1));
    int y_overlap = max(0,min(p.y2,q.y2)-max(p.y1, q.y1));
    return x_overlap * y_overlap;
}
int main()
{
    
    ifstream fin("billboard.in");
    ofstream fout("billboard.out");
    rectangle a, g, t; // alfalfa billboard, grain billboard, steak truck
    fin>>a.x1>>a.y1>>a.x2>>a.y2;
    fin>>g.x1>>g.y1>>g.x2>>g.y2;
    fin>>t.x1>>t.y1>>t.x2>>t.y2;
    int ans = area(a)+ area(g) - intersection(a,t)-intersection(g,t);
    fout<<ans;
}