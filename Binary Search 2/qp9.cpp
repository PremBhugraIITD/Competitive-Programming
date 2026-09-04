#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iomanip>
#include <stack>
#include <queue>
#include <map>
using namespace std;

#define ll long long int
#define ld long double
#define vll vector<long long int>
#define vpll vector<pair<long long int, long long int>>
#define fr(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define pb push_back
#define mod 1000000007

bool solve(ll x, vpll A)
{
    ll n = A.size();
    ll right = x - 1, left = 0;
    fr(i, 0, n)
    {
        if (A[i].first >= right && A[i].second >= left)
        {
            right--;
            left++;
            if (right < 0)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vpll A(n);
        fr(i, 0, n)
        {
            cin >> A[i].first >> A[i].second;
        }
        ll l = 0, r = n;
        ll ans;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            // cout << l << " " << r << " " << mid << endl;
            if (solve(mid, A))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        cout << ans << endl;
    }
}