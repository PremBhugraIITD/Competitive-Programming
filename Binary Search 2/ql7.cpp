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

int main()
{
    ll n;
    cin >> n;
    ll l = 0, r = n - 1;
    ll ans;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        cout << "? " << mid + 1 << endl;
        ll index;
        cin >> index;
        ll left = INT_MAX, right = INT_MIN;
        if (mid != 0)
        {
            cout << "? " << mid << endl;
            cin >> left;
        }
        if (mid != n - 1)
        {
            cout << "? " << mid + 2 << endl;
            cin >> right;
        }
        if (index < min(left, right))
        {
            ans = mid + 1;
            break;
        }
        else if (index < right && index > left)
        {
            r = mid - 1;
        }
        else if (index < left && index > right)
        {
            l = mid + 1;
        }
        else
        {
            l = mid + 1;
            // r = mid - 1;
        }
    }
    cout << "! " << ans << endl;
}