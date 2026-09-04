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
    ll n, m, k;
    cin >> n >> m >> k;
    vll A(n);
    fr(i, 0, n)
    {
        cin >> A[i];
    }
    if (n == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        k--;
        vll differences;
        fr(i, 0, n)
        {
            if (i > 0)
            {
                differences.pb(A[i] - A[i - 1] - 1);
            }
        }
        sort(differences);
        reverse(differences);
        ll ans = A[n - 1] - A[0] + 1;
        fr(i, 0, n - 1)
        {
            if (k)
            {
                k--;
                ans -= differences[i];
            }
            else
            {
                break;
            }
        }
        cout << ans << endl;
    }
}