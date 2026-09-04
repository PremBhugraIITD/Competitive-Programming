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
    ll n;
    cin >> n;
    vll A(n);
    fr(i, 0, n)
    {
        cin >> A[i];
    }
    ll ans = 0, l = 0;
    vpll segments;
    mll count;
    fr(i, 0, n)
    {
        count[A[i]]++;
        if (count[A[i]] == 2)
        {
            ans++;
            segments.pb({l, i});
            l = i + 1;
            count.clear();
        }
    }
    if (!segments.size())
    {
        cout << -1 << endl;
    }
    else
    {
        if (count.size())
        {
            segments[segments.size() - 1] = {segments[segments.size() - 1].first, n - 1};
        }
        cout << ans << endl;
        fr(i, 0, segments.size())
        {
            cout << segments[i].first + 1 << " " << segments[i].second + 1 << endl;
        }
    }
}