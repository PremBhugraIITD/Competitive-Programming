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
        ll n;
        cin >> n;
        vll A(n);
        fr(i, 0, n)
        {
            cin >> A[i];
        }
        vll prefixMax(n, 0), suffixMax(n, 1e18);
        prefixMax[0] = A[0] + 0;
        fr(i, 1, n)
        {
            prefixMax[i] = max(prefixMax[i - 1], A[i] + i);
        }
        suffixMax[n - 1] = A[n - 1] - (n - 1);
        frr(i, n - 2, 0)
        {
            suffixMax[i] = max(suffixMax[i + 1], A[i] - i);
        }
        ll ans = -1e18;
        fr(i, 1, n - 1)
        {
            ans = max(ans, prefixMax[i - 1] + A[i] + suffixMax[i + 1]);
        }
        cout << ans << endl;
    }
}