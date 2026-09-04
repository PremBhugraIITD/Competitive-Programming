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
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    // n = 1e6;
    vll W(n);
    ll mini = INT_MAX, maxi = 0;
    fr(i, 0, n)
    {
        cin >> W[i];
        // W[i] = 38394;
        mini = min(mini, W[i]);
        maxi = max(maxi, W[i]);
    }
    vll count(maxi + 30, 0);
    fr(i, 0, n)
    {
        count[W[i]]++;
    }
    ll ans = 0;
    fr(i, mini, count.size())
    {
        count[i + 1] += count[i] / 2;
        ans += (count[i] & 1);
        // cout << i << " " << count[i] << " " << ans << endl;
    }
    cout << ans << endl;
}