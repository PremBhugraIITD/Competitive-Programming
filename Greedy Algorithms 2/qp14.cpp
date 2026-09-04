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

ll solve(string &s, ll t)
{
    ll n = s.length();
    map<char, ll> count;
    ll maxCount = 0;
    for (char c = 'a'; c <= 'z'; c++)
    {
        count[c] = 0;
    }
    for (char c = 'A'; c <= 'Z'; c++)
    {
        count[c] = 0;
    }
    fr(i, 0, n)
    {
        count[s[i]]++;
        maxCount = max(maxCount, count[s[i]]);
    }
    n -= maxCount;
    // cout << maxCount << endl;
    ll ans = 0;
    if (t > n)
    {
        ans = maxCount + n;
        if (t == 1)
        {
            ans--;
        }
    }
    else if (t < n)
    {
        ans = maxCount + t;
    }
    else
    {
        ans = maxCount + n;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    ll scoreA = solve(a, n), scoreB = solve(b, n), scoreC = solve(c, n);
    // cout << a.length() << endl;
    // cout << scoreA << " " << scoreB << " " << scoreC << endl;
    vector<pair<ll, string>> temp = {{scoreA, "Kuro"}, {scoreB, "Shiro"}, {scoreC, "Katie"}};
    sort(temp);
    if (temp[1].first == temp[2].first)
    {
        cout << "Draw" << endl;
    }
    else
    {
        cout << temp[2].second << endl;
    }
}