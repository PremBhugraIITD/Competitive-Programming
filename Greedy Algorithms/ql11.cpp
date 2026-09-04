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
        ll n;
        cin >> n;
        string s;
        cin >> s;
        vll temp;
        fr(i, 0, n)
        {
            if (s[i] == '*')
            {
                temp.pb(i + 1);
            }
        }
        if (temp.size() == n)
        {
            cout << 0 << endl;
        }
        else if (temp.size() == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            n = temp.size();
            ll medianIndex = n / 2, median = temp[medianIndex];
            // cout << median << endl;
            ll ans = 0;
            ll l = medianIndex, r = medianIndex;
            l--, r++;
            ll x = 1;
            while (l >= 0)
            {
                // cout << temp[l] << " ";
                ans += median - x - temp[l];
                x++;
                l--;
            }
            // cout << endl;
            x = 1;
            while (r < n)
            {
                // cout << temp[r] << " ";
                ans += temp[r] - (median + x);
                x++;
                r++;
            }
            // cout << endl;
            cout << ans << endl;
        }
    }
}