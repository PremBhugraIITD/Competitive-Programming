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

bool solve(ll l, ll r, ll mid, ll n)
{
    cout << "? " << l + 1 << " " << mid + 1 << endl;
    ll size = mid - l + 1;
    vll temp(size);
    fr(i, 0, size)
    {
        cin >> temp[i];
    }
    ll belonging = 0;
    fr(i, 0, size)
    {
        if (temp[i] >= l + 1 && temp[i] <= mid + 1)
        {
            belonging++;
        }
    }
    return (belonging & 1);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll l = 0, r = n - 1;
        ll ans;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            if (solve(l, r, mid, n))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << "! " << ans + 1 << endl;
    }
}