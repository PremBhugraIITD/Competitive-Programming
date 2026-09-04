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
#define pll <pair<long long int, long long int>>
#define mll map<long long int, long long int>
#define mcl map<char, long long int>
#define fr(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define frr(i, a, b) for (int(i) = (a); (i) >= (b); (i)--)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 1000000007

bool solve(ll x, vll H)
{
    ll n = H.size();
    ll minIndex = 0;
    ll mini = INT_MAX;
    fr(i, 0, n)
    {
        if (H[i] < mini)
        {
            mini = H[i];
            minIndex = i;
        }
    }
    vpll A(n);
    fr(i, 0, n)
    {
        A[i].first = H[i];
        A[i].second = H[i];
    }
    frr(i, n - 1, 2)
    {
        ll d = max((ll)0, min((A[i].first - x) / 3, A[i].second / 3));
        A[i].first -= 3 * d;
        A[i - 1].first += d;
        A[i - 2].first += 2 * d;
    }
    mini = INT_MAX;
    fr(i, 0, n)
    {
        mini = min(mini, A[i].first);
    }
    return mini >= x;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vll H(n);
        fr(i, 0, n)
        {
            cin >> H[i];
        }
        ll sum = 0;
        fr(i, 0, n)
        {
            sum += H[i];
        }
        ll l = 0, r = sum;
        ll ans;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            // cout << l << " " << r << " " << mid << endl;
            if (solve(mid, H))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        cout << ans << endl;
    }
}