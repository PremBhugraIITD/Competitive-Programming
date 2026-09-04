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

ll binpow(ll a, ll b, ll m)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vll A(n);
        fr(i, 0, n)
        {
            cin >> A[i];
        }
        sort(A);
        reverse(A);
        ll target = A[k - 1];
        ll a = 0, b = 0;
        fr(i, 0, n)
        {
            if (A[i] == target)
            {
                a++;
                if (i < k)
                {
                    b++;
                }
            }
        }
        // cout << a << " " << b << endl;
        ll ans = 1;
        fr(i, 1, b + 1)
        {
            ans = (ans * (a - b + i)) % mod;
            ans = (ans * binpow(i, mod - 2, mod)) % mod;
        }
        cout << ans << endl;
    }
}