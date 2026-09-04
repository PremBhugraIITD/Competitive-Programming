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
#include <deque>
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

int main()
{
    ll n, a, b;
    cin >> n >> a >> b;
    vll A(n);
    fr(i, 0, n)
    {
        cin >> A[i];
    }
    vll prefixSum(n, 0);
    prefixSum[0] = A[0];
    fr(i, 1, n)
    {
        prefixSum[i] = prefixSum[i - 1] + A[i];
    }
    // fr(i, 0, n)
    // {
    //     cout << prefixSum[i] << " ";
    // }
    // cout << endl;
    ll k = b - a + 1;
    ll maxi = -1e18;
    deque<ll> dq;
    fr(i, 0, n)
    {
        while (!dq.empty() && (prefixSum[dq.back()] <= prefixSum[i]))
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i - dq.front() >= k)
        {
            dq.pop_front();
        }
        if (i - k + 1 - a + 1 >= 0)
        {
            ll temp = i - k + 1 - a >= 0 ? prefixSum[dq.front()] - prefixSum[i - k + 1 - a] : prefixSum[dq.front()];
            maxi = max(maxi, temp);
        }
    }
    // cout << maxi << endl;
    ll l = n - 1 - b + 1 + a - 1;
    priority_queue<pair<long long int, long long int>> maxiRem;
    fr(i, l, n)
    {
        maxiRem.push({prefixSum[i], i});
    }
    ll i = n - 1 - b + 1 - 1;
    ll j = l - 1;
    while (!maxiRem.empty())
    {
        if (maxiRem.top().second <= j)
        {
            maxiRem.pop();
        }
        else
        {
            maxi = max(maxi, maxiRem.top().first - prefixSum[i]);
            i++;
            j++;
        }
    }
    cout << maxi << endl;
}