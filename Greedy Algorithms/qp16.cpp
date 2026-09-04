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
    ll n;
    cin >> n;
    vector<pair<ld, string>> A;
    string ans = "";
    fr(i, 0, n)
    {
        string temp;
        cin >> temp;
        ll s_count = 0;
        fr(j, 0, temp.length())
        {
            if (temp[j] == 's')
            {
                s_count++;
            }
        }
        if (s_count == temp.length())
        {
            ans += temp;
        }
        else
        {
            ll h_count = 0;
            fr(j, 0, temp.length())
            {
                if (temp[j] == 'h')
                {
                    h_count++;
                }
            }
            ld score = ((ld)s_count) / h_count;
            A.pb({score, temp});
        }
    }
    n = A.size();
    sort(A);
    reverse(A);
    fr(i, 0, n)
    {
        ans += A[i].second;
        // cout << A[i].first << endl;
    }
    // cout << ans << endl;
    ll h_count = 0, result = 0;
    n = ans.length();
    frr(i, n - 1, 0)
    {
        if (ans[i] == 'h')
        {
            h_count++;
        }
        else
        {
            result += h_count;
        }
    }
    cout << result << endl;
}