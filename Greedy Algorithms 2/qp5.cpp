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
        string x;
        cin >> x;
        ll k;
        cin >> k;
        string ans;
        ll n = x.length();
        priority_queue<pair<char, ll>, vector<pair<char, ll>>, greater<pair<char, ll>>> mini;
        vll temp;
        ll last = -1;
        k = n - k;
        fr(i, 0, n)
        {
            mini.push({x[i], i});
            if (i >= n - k)
            {
                while (i == n - k && mini.top().first == '0')
                {
                    temp.pb(mini.top().second);
                    mini.pop();
                }
                while (!mini.empty() && mini.top().second < last)
                {
                    mini.pop();
                }
                ans.pb(mini.top().first);
                last = mini.top().second;
                mini.pop();
                if (i == n - k)
                {
                    fr(j, 0, temp.size())
                    {
                        mini.push({'0', temp[j]});
                    }
                }
            }
        }
        cout << ans << endl;
    }
}