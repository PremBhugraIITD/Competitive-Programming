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
    int m;
    cin >> m;
    while (m--)
    {
        ll n, t, a, b;
        cin >> n >> t >> a >> b;
        vpll A(n);
        ll countEasy = 0, countHard = 0;
        fr(i, 0, n)
        {
            cin >> A[i].second;
        }
        fr(i, 0, n)
        {
            cin >> A[i].first;
            if (A[i].second == 0)
            {
                countEasy++;
            }
            else
            {
                countHard++;
            }
        }
        sort(A);
        ll ans = 0;
        ll easy = 0, hard = 0;
        fr(i, 0, n)
        {
            ll time = A[i].first, level = A[i].second;
            if (i == 0 || (A[i].first != A[i - 1].first))
            {
                ll available = time - 1, required = easy * a + hard * b;
                if (required <= available)
                {
                    ll count = easy + hard;
                    ll extra = available - required;
                    ll remEasy = countEasy - easy, remHard = countHard - hard;
                    if (extra >= a)
                    {
                        count += min(remEasy, extra / a);
                        extra -= min(remEasy, extra / a) * a;
                    }
                    if (extra >= b)
                    {
                        count += min(remHard, extra / b);
                        extra -= min(remHard, extra / b) * b;
                    }
                    ans = max(ans, count);
                }
            }
            if (level == 0)
            {
                easy++;
            }
            else
            {
                hard++;
            }
        }
        ll available = t, required = easy * a + hard * b;
        if (required <= available)
        {
            ll count = easy + hard;
            ll extra = available - required;
            ll remEasy = countEasy - easy, remHard = countHard - hard;
            if (extra >= a)
            {
                extra -= min(remEasy, extra / a) * a;
                count += min(remEasy, extra / a);
            }
            if (extra >= b)
            {
                extra -= min(remHard, extra / b) * b;
                count += min(remHard, extra / b);
            }
            ans = max(ans, count);
        }
        cout << ans << '\n';
    }
}