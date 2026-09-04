#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

long long int solve( long long int n, long long int m, long long int cl, long long int ce, long long int v, vector<long long int> &Cl, vector<long long int> &Ce, long long int x1, long long int y1, long long int x2, long long int y2)
{
    // cout << "time: " << time << endl;
    long long int t = INT_MAX;
    long long int stair = lower_bound(Cl.begin(), Cl.end(), y1) - Cl.begin();
    if (stair != cl)
    {
        long long int time1 = abs(Cl[stair] - y1) + abs(x2 - x1) + abs(Cl[stair] - y2);
        t = min(t, time1);
        // cout << time1 << endl;
    }
    stair--;
    if (stair != -1)
    {
        long long int time2 = abs(Cl[stair] - y1) + abs(x2 - x1) + abs(Cl[stair] - y2);
        t = min(t, time2);
        // cout << time2 << endl;
    }
    long long int elevator = lower_bound(Ce.begin(), Ce.end(), y1) - Ce.begin();
    if (elevator != ce)
    {
        long long int time3 = abs(Ce[elevator] - y1) + (abs(x2 - x1) + v - 1) / v + abs(Ce[elevator] - y2);
        t = min(t, time3);
        // cout << time3 << endl;
    }
    elevator--;
    if (elevator != -1)
    {
        long long int time4 = abs(Ce[elevator] - y1) + (abs(x2 - x1) + v - 1) / v + abs(Ce[elevator] - y2);
        t = min(t, time4);
        // cout << time4 << endl;
    }
    return t;
}

int main()
{
    long long int n, m, cl, ce, v;
    cin >> n >> m >> cl >> ce >> v;
    vector<long long int> Cl(cl);
    if (cl)
    {
        for (long long int i = 0; i < cl; i++)
        {
            cin >> Cl[i];
        }
    }
    vector<long long int> Ce(ce);
    for (long long int i = 0; i < ce; i++)
    {
        cin >> Ce[i];
    }
    long long int q;
    cin >> q;
    while (q--)
    {
        long long int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2)
        {
            cout << abs(y2 - y1) << endl;
        }
        else
        {
            cout<<solve(n,m,cl,ce,v,Cl,Ce,x1,y1,x2,y2)<<endl;
        }
    }
}