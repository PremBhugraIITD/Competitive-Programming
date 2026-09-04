#include <bits/stdc++.h>
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
#define printVector(v)    \
    for (auto &x : v)     \
        cout << x << ' '; \
    cout << endl;
#define mod 1000000007

int rob(vector<ll> &nums)
{
    int n = nums.size();
    vector<ll> dp(n);
    dp[0] = max(nums[0], (ll)0);
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(nums[i] + (i - 2 >= 0 ? dp[i - 2] : 0),
                    i - 1 >= 0 ? dp[i - 1] : 0);
    }
    return dp[n - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vll A(n);
    fr(i, 0, n)
    {
        cin >> A[i];
    }
    cout << rob(A) << endl;
}