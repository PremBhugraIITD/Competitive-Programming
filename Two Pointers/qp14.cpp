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
    string a, b;
    cin >> a >> b;
    ll n = a.length(), m = b.length();
    ll countB = 0;
    fr(i, 0, m)
    {
        if (b[i] == '1')
        {
            countB++;
        }
    }
    ll ans = 0, countA = 0;
    fr(i, 0, n)
    {
        if (a[i] == '1')
        {
            countA++;
        }
        if (i >= m && a[i - m] == '1')
        {
            countA--;
        }
        if (i >= m - 1)
        {
            ll diff = abs(countA - countB);
            if (!(diff & 1))
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
}