#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iomanip>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define ll long long int
#define ld long double
#define vll vector<long long int>
#define vpll vector<pair<long long int, long long int>>
#define pll pair<long long int, long long int>
#define mll map<long long int, long long int>
#define mcl map<char, long long int>
#define fr(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define frr(i, a, b) for (int(i) = (a); (i) >= (b); (i)--)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 1000000007

bool solve(ll x, vector<pair<ll, pll>> A, ll k)
{
    ll n = A.size();
    vpll dest;
    ll totalCount = 0;
    fr(i, 0, n)
    {
        if (A[i].first > x)
        {
            ll count = A[i].first - x;
            ll cost = A[i].second.first;
            k -= cost * count;
            if (k < 0)
            {
                return false;
            }
            totalCount += count;
        }
        else if (A[i].first < x)
        {
            dest.pb({A[i].second.second, A[i].first});
        }
    }
    sort(dest);
    fr(i, 0, dest.size())
    {
        ll rem = x - dest[i].second;
        ll cost = dest[i].first;
        k -= min(totalCount, rem) * cost;
        if (k < 0)
        {
            return false;
        }
        totalCount -= rem;
        totalCount = max(totalCount, (ll)0);
        if (totalCount == 0)
        {
            break;
        }
    }
    return (totalCount == 0);
}

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, pll>> A(n);
    ll sum = 0;
    fr(i, 0, n)
    {
        cin >> A[i].first >> A[i].second.first >> A[i].second.second;
        sum += A[i].first;
    }
    ll l = 0, r = sum;
    ll ans;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (solve(mid, A, k))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << endl;
}