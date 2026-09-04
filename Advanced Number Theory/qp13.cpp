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
#define fr(i, a, b) for (long long int(i) = (a); (i) < (b); (i)++)
#define frr(i, a, b) for (long long int(i) = (a); (i) >= (b); (i)--)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 1000000007

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b;
    cin >> a >> b;
    if (b == 1)
    {
        cout << a << endl;
    }
    else
    {
        ll ans = 0;
        while (a > 0 && b > 0)
        {
            ll mini = min(a, b), maxi = max(a, b);
            ans += maxi / mini;
            maxi -= (maxi / mini) * mini;
            a = mini, b = maxi;
        }
        // ans += a + b;
        cout << ans << endl;
    }
}