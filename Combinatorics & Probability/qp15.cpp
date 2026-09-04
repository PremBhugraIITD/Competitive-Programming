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
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        ll n = s.length();
        vll prefixSum(n, 0);
        prefixSum[0] = (s[0] == '0') ? -1 : 1;
        fr(i, 1, n)
        {
            if (s[i] == '0')
            {
                prefixSum[i] = prefixSum[i - 1] - 1;
            }
            else
            {
                prefixSum[i] = prefixSum[i - 1] + 1;
            }
        }
        map<ll, pll> countSum;
        countSum[0] = {1, -1};
        ll ans = 0;
        fr(i, 0, n)
        {
            ll curr = prefixSum[i];
            ll right = n - i;
            ll left = (countSum[curr].second + (2 * countSum[curr].first) % mod) % mod;
            ans = (ans + (left * right) % mod) % mod;
            countSum[curr].first++;
            countSum[curr].second += i;
        }
        cout << ans << endl;
    }
}