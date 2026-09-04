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
        ll n, c, d;
        cin >> n >> c >> d;
        vll A(n);
        fr(i, 0, n)
        {
            cin >> A[i];
        }
        mll count;
        fr(i, 0, n)
        {
            count[A[i]]++;
        }
        ll ans = 0;
        for (auto i : count)
        {
            if (i.second > 1)
            {
                ans += (i.second - 1) * c;
            }
        }
        // cout<<ans<<endl;
        ll prev = 0;
        ll leftAdditionCost = 0, rightRmemovalCost = 0, temp = 1e18;
        ll rem = count.size() - 1;
        for (auto i : count)
        {
            ll curr = i.first;
            leftAdditionCost += (curr - prev - 1) * d;
            rightRmemovalCost = rem * c;
            temp = min(temp, leftAdditionCost + rightRmemovalCost);
            prev = curr;
            rem--;
        }
        if (count.begin()->first != 1)
        {
            temp = min(temp, d + (ll)count.size() * c);
        }
        ans += temp;
        cout << ans << endl;
    }
}