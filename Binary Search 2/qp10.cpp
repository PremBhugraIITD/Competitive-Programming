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
#define fr(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 1000000007

ll lcm(ll a, ll b)
{
    return (a * b) / __gcd(a, b);
}

bool solve(ll m, ll x, ll a, ll y, ll b, ll k, vll &P)
{
    ll c = lcm(a, b);
    ll z = x + y;
    ll tempc = m / c;
    ll tempa = m / a - tempc;
    ll tempb = m / b - tempc;
    ll i = 0;
    ll count = 0;
    ll sum = 0;
    while (count < tempc)
    {
        sum += z * P[i];
        if (sum >= k)
        {
            return true;
        }
        count++;
        i++;
    }
    ll tempp, p, tempq, q;
    if (x > y)
    {
        p = x;
        tempp = tempa;
        q = y;
        tempq = tempb;
    }
    else
    {
        p = y;
        tempp = tempb;
        q = x;
        tempq = tempa;
    }
    count = 0;
    while (count < tempp)
    {
        sum += p * P[i];
        if (sum >= k)
        {
            return true;
        }
        count++;
        i++;
    }
    count = 0;
    while (count < tempq)
    {
        sum += q * P[i];
        if (sum >= k)
        {
            return true;
        }
        count++;
        i++;
    }
    return false;
}

int main()
{
    ll q;
    cin >> q;
    while (q--)
    {
        ll n;
        cin >> n;
        vll P(n);
        fr(i, 0, n)
        {
            cin >> P[i];
            P[i] /= 100;
        }
        sort(P);
        reverse(P);
        ll x, a;
        cin >> x >> a;
        ll y, b;
        cin >> y >> b;
        ll k;
        cin >> k;
        ll l = 0, r = n;
        ll ans = -1;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            if (solve(mid, x, a, y, b, k, P))
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
}