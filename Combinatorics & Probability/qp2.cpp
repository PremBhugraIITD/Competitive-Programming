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
#define fr(i, a, b) for (long long int(i) = (a); (i) < (b); (i)++)
#define frr(i, a, b) for (long long int(i) = (a); (i) >= (b); (i)--)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 1000000007

ll binpow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a);
        }
        a = (a * a);
        b >>= 1;
    }
    return ans;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vll> table(n, vll(m));
    fr(i, 0, n)
    {
        fr(j, 0, m)
        {
            cin >> table[i][j];
        }
    }
    ll ans = 0;
    fr(i, 0, n)
    {
        ll count = 0;
        fr(j, 0, m)
        {
            if (table[i][j] == 0)
            {
                count++;
            }
        }
        ans += binpow(2, count) - 1;
        ans += binpow(2, m - count) - 1;
    }
    fr(i, 0, m)
    {
        ll count = 0;
        fr(j, 0, n)
        {
            if (table[j][i] == 0)
            {
                count++;
            }
        }
        if (count > 1)
        {
            ans += binpow(2, count) - 1 - count;
        }
        if (n - count > 1)
        {
            ans += binpow(2, n - count) - 1 - (n - count);
        }
    }
    cout << ans << endl;
}