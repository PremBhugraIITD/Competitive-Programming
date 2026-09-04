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
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        ll ans = 0;
        ll l = 0, r = k - 1;
        while (l <= r)
        {
            vll count(26, 0);
            for (ll i = l; i < n; i += k)
            {
                count[s[i] - 'a']++;
            }
            for (ll i = r; i < n; i += k)
            {
                count[s[i] - 'a']++;
            }
            ll maxi = 0;
            fr(i, 0, 26)
            {
                maxi = max(maxi, count[i]);
            }
            if (l == r)
            {
                ans += (n / k) - (maxi / 2);
            }
            else
            {
                ans += 2 * (n / k) - maxi;
            }
            l++;
            r--;
        }
        cout << ans << endl;
    }
}