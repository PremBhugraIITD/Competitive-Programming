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
        if (n == 1)
        {
            cout << (A[0] == 0 ? 0 : 1) << endl;
        }
        else
        {
            ll count = 0, ans = 0;
            fr(i, 0, n)
            {
                if (A[i] > 0)
                {
                    count++;
                    if (A[i] >= 5)
                    {
                        A[i] = 0;
                        ans++;
                    }
                    else if (A[i] >= 3)
                    {
                        A[i] = 4;
                    }
                    else
                    {
                        A[i] = 2;
                    }
                }
            }
            ll i = 0;
            ll state;
            // 0-not affected
            // 1-first two rows
            // last two rows
            while (i < n)
            {
                if (i == 0)
                {
                    if (A[i] == 0)
                    {
                        state = 0;
                    }
                    else if (A[i] == 2)
                    {
                        state = 1;
                        ans++;
                    }
                    else
                    {
                        state = 0;
                        ans++;
                    }
                }
                else
                {
                    vll temp = {0, 0};
                    if (state == 1)
                    {
                        temp[0] = 1;
                    }
                    else if (state == 2)
                    {
                        temp[1] = 1;
                    }
                    if (A[i] == 0)
                    {
                        temp[0] = temp[1] = 1;
                    }
                    else if (A[i] == 2)
                    {
                        temp[1] = 1;
                    }
                    ll tempCount = 0;
                    fr(j, 0, 2)
                    {
                        if (!temp[j])
                        {
                            tempCount++;
                        }
                    }
                    if (tempCount == 1)
                    {
                        ans++;
                        if (!temp[0])
                        {
                            state = 1;
                        }
                        else
                        {
                            state = 2;
                        }
                    }
                    else if (tempCount == 2)
                    {
                        ans++;
                        state = 0;
                        A[i] = 0;
                    }
                    else
                    {
                        state = 0;
                    }
                }
                // cout << i << " " << ans << endl;
                i++;
            }
            cout << min(ans, count) << endl;
        }
    }
}