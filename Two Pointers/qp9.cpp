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
    ll n, p;
    cin >> n >> p;
    vll A(n);
    ll total = 0;
    fr(i, 0, n)
    {
        cin >> A[i];
        total += A[i];
    }
    fr(i, 0, n)
    {
        A.pb(A[i]);
    }
    ll sum = 0;
    ll i = 0, j = 0;
    ll ans = 1e18;
    ll index = -1;
    while (j < 2 * n)
    {
        sum += A[j];
        while (i <= j && sum >= p % total) // This ensures that a valid window of size <= n will be found
        {
            if (j - i + 1 < ans)
            {
                ans = j - i + 1;
                index = i;
            }
            sum -= A[i];
            i++;
        }
        j++;
    }
    if (p % total == 0)
    {
        ans = 0;
        index = 0;
    }
    ans += (p / total) * n;
    cout << index + 1 << " " << ans << endl;
}