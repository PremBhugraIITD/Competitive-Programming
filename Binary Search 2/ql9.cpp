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

bool solve1(ll prevIndex, ll mid)
{
    cout << "? " << prevIndex + 1 << " " << mid + 1 << endl;
    ll index;
    cin >> index;
    index--;
    if (index == prevIndex)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool solve2(ll prevIndex, ll mid)
{
    cout << "? " << mid + 1 << " " << prevIndex + 1 << endl;
    ll index;
    cin >> index;
    index--;
    if (index == prevIndex)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    ll n;
    cin >> n;
    cout << "? 1 " << n << endl;
    ll prevIndex;
    cin >> prevIndex;
    prevIndex--;
    ll ans;
    ll l, r;
    if (prevIndex == 0)
    {
        l = prevIndex + 1, r = n - 1;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            if (solve1(prevIndex, mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
    }
    else
    {
        cout << "? 1 " << prevIndex + 1 << endl;
        ll index;
        cin >> index;
        index--;
        if (index == prevIndex)
        {
            l = 0, r = prevIndex - 1;
            while (l <= r)
            {
                ll mid = (l + r) / 2;
                if (solve2(prevIndex, mid))
                {
                    ans = mid;
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
        else
        {
            l = prevIndex + 1, r = n - 1;
            while (l <= r)
            {
                ll mid = (l + r) / 2;
                if (solve1(prevIndex, mid))
                {
                    ans = mid;
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
        }
    }
    cout << "! " << ans + 1 << endl;
}