#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iomanip>
#include <stack>
#include <queue>
#include <map>
using namespace std;

#define ll long long int
#define ld long double
#define vll vector<long long int>
#define vpll vector<pair<long long int, long long int>>
#define fr(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define pb push_back
#define mod 1000000007

int main()
{
    int t;
    cin >> t;
    // ll c = 1;
    while (t--)
    {
        // cout << "test" << c++ << endl;
        ll n, m;
        cin >> n >> m;
        cout << "? 1 1" << endl;
        ll distance;
        cin >> distance;
        ll y1 = min(m, 1 + distance);
        ll x1 = 1 + (1 + distance - y1);
        cout << "? " << x1 << " " << y1 << endl;
        ll distance1;
        cin >> distance1;
        ll x2 = min(n, 1 + distance);
        ll y2 = 1 + (1 + distance - x2);
        cout << "? " << x2 << " " << y2 << endl;
        ll distance2;
        cin >> distance2;
        ll tempx = x1, tempy = y1;
        tempy -= distance1 / 2;
        distance1 -= distance1 / 2;
        tempx += distance1;
        cout << "? " << tempx << " " << tempy << endl;
        ll tempDistance;
        cin >> tempDistance;
        if (tempDistance == 0)
        {
            cout << "! " << tempx << " " << tempy << endl;
        }
        else
        {
            tempx = x2, tempy = y2;
            tempx -= distance2 / 2;
            distance2 -= distance2 / 2;
            tempy += distance2;
            cout << "! " << tempx << " " << tempy << endl;
        }
    }
}