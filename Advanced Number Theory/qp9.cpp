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

int main()
{
    ll n;
    cin >> n;
    if (n < 2)
    {
        cout << 0 << endl;
    }
    else if (n & 1)
    {
        ll count5 = 0, count2 = 0;
        ll i = 5;
        while (n / i)
        {
            count5 += (n / i);
            i *= 5;
        }
        ll m = n / 2;
        i = 5;
        while (m / i)
        {
            count5 -= (m / i);
            i *= 5;
        }
        i = 2;
        while (n / i)
        {
            count2 += (n / i);
            i *= 2;
        }
        i = 2;
        while (m / i)
        {
            count2 -= (m / i);
            i *= 2;
        }
        count2 -= m;
        cout << min(count5, count2) << endl;
    }
    else
    {
        ll m = n / 2;
        ll ans = 0;
        ll i = 5;
        while (m / i)
        {
            ans += (m / i);
            i *= 5;
        }
        cout << ans << endl;
    }
}