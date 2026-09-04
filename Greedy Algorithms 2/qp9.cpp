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
        vll A(n);
        fr(i, 0, n)
        {
            cin >> A[i];
        }
        ll ans = 0;
        ll last = 0;
        fr(i, 1, n)
        {
            if (A[i] < A[last])
            {
                ll diff = A[last] - A[i];
                ans = max(ans, (ll)ceil(log2l(diff + 1)));
            }
            else
            {
                last = i;
            }
        }
        cout << ans << endl;
    }
}