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

ld power(ld a, ld b)
{
    ld ans = 1;
    while (b > 0)
    {
        ans *= a;
        b -= 1;
    }
    return ans;
}

int main()
{
    ld n, k;
    cin >> n >> k;
    ld ans = 0;
    for (long double i = 1; i <= k; i += 1)
    {
        ans += i * (power(i, n) - power(i - 1, n));
    }
    ans /= power(k, n);

    ld scale = 1e6;
    ld scaled = ans * scale;
    ll flo = floor(scaled);
    ld frac = scaled - flo;
    ld eps = 1e-12;
    ll rounded;
    if (frac > 0.5 + eps)
    {
        rounded = flo + 1;
    }
    else if (frac < 0.5 - eps)
    {
        rounded = flo;
    }
    else
    {
        if (flo & 1)
            rounded = flo + 1;
        else
            rounded = flo;
    }
    ans = rounded / scale;
    cout << fixed << setprecision(6) << ans << endl;
}
