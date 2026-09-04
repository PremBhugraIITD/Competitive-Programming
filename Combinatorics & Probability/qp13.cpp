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

ld binpow(ld a, ll b)
{
    ld ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}

int main()
{
    ld m;
    ll n;
    cin >> m >> n;
    ld ans = 0;
    fr(i, 1, m + 1)
    {
        ans += i * (binpow(i / m, n) - binpow((i - 1) / m, n));
    }
    cout << setprecision(10) << ans << endl;
}