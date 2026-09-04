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
#define fr(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
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
        ll h, c;
        cin >> h >> c;
        ld temp;
        cin >> temp;
        ld avg = (h + c) / 2.0;
        if (temp <= avg)
        {
            cout << 2 << endl;
        }
        else
        {
            ll l = 1, r = 1e9;
            ll ans;
            while (l <= r)
            {
                ll mid = (l + r) / 2;
                // cout << l << " " << r << " " << mid << endl;
                ll n = 2 * mid - 1;
                ld tempn = avg + (h - c) / (2.0 * n);
                if (tempn >= temp)
                {
                    ans = n;
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            ll n1 = ans;
            ll n2 = n1 + 2;
            ld temp1 = avg + (h - c) / (2.0 * n1);
            ld temp2 = avg + (h - c) / (2.0 * n2);
            ld distance1 = abs(temp - temp1);
            ld distance2 = abs(temp - temp2);
            // cout<<temp1<<" "<<temp2<<endl;
            if (distance2 < distance1)
            {
                ans = n2;
            }
            else
            {
                ans = n1;
            }
            cout << ans << endl;
        }
    }
}