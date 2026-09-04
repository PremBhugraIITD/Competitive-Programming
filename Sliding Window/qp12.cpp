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
#define fr(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define frr(i, a, b) for (int(i) = (a); (i) >= (b); (i)--)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 1000000007

int main()
{
    string s, t;
    cin >> s >> t;
    if (s == t)
    {
        cout << 0 << endl;
    }
    else
    {
        vll front;
        vll back;
        ll n = s.length(), m = t.length();
        ll i = 0, j = 0;
        while (i < n && j < m)
        {
            if (s[i] == t[j])
            {
                front.pb(i);
                j++;
            }
            i++;
        }
        i = n - 1, j = m - 1;
        while (i >= 0 && j >= 0)
        {
            if (s[i] == t[j])
            {
                back.pb(i);
                j--;
            }
            i--;
        }
        reverse(back);
        ll ans = 0;
        ans = max(ans, front[0]);
        ans = max(ans, n - 1 - front[m - 1]);
        ans = max(ans, back[0]);
        ans = max(ans, n - 1 - back[m - 1]);
        fr(i, 0, m - 1)
        {
            ans = max(ans, back[i + 1] - front[i] - 1);
        }
        cout << ans << endl;
    }
}