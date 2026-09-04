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
#define pll <pair<long long int, long long int>>
#define mll map<long long int, long long int>
#define mcl map<char, long long int>
#define fr(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define frr(i, a, b) for (int(i) = (a); (i) >= (b); (i)--)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 1000000007

bool solve(ll x, ll k, vll A)
{
    ll n = A.size();
    ll sum = 0;
    fr(i, 0, n)
    {
        sum += A[i];
    }
    ll diff = sum - k;
    if (diff - x <= 0)
    {
        return true;
    }
    else
    {
        sort(A);
        ll first = A[0];
        ll j = 1;
        frr(i, n - 1, 1)
        {
            if (j > x)
            {
                break;
            }
            first -= (x - j);
            diff -= (x - j);
            diff -= (A[i] - first);
            diff += (j - 1);
            if (diff <= 0)
            {
                return true;
            }
            first += (x - j);
            diff += (x - j);
            j++;
        }
        return false;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vll A(n);
        ll sum = 0;
        fr(i, 0, n)
        {
            cin >> A[i];
            sum += A[i];
        }
        ll l = 0, r = sum;
        ll ans;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            // cout << l << " " << r << " " << mid << endl;
            if (solve(mid, k, A))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
}