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
#define mcl map<char, long long int>
#define fr(i, a, b) for (long long int(i) = (a); (i) < (b); (i)++)
#define frr(i, a, b) for (long long int(i) = (a); (i) >= (b); (i)--)
#define pb push_back
#define mod 1000000007

long long int binpow(long long int a, long long int b, long long int m)
{
    long long int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}
int minMaxSums(vector<long long int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    long long int n = nums.size();
    vector<long long int> fact(n + 1, 1);
    for (long long int i = 1; i <= n; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    vector<long long int> inv_fact(n + 1, 1);
    inv_fact[n] = binpow(fact[n], mod - 2, mod);
    for (long long int i = n - 1; i >= 0; i--)
    {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
    }
    long long int ans = 0;
    long long int temp = k;
    for (long long int i = 0; i < n; i++)
    {
        k = min((long long int)(k - 1), n - 1 - i);
        for (long long int j = 0; j <= k; j++)
        {
            ans = (ans +
                   (nums[i] * ((((fact[n - 1 - i] * inv_fact[j]) % mod) *
                                inv_fact[n - 1 - i - j]) %
                               mod)) %
                       mod) %
                  mod;
        }
        if (k == -1)
        {
            ans = (ans + nums[i]) % mod;
        }
        k = temp;
    }
    reverse(nums.begin(), nums.end());
    for (long long int i = 0; i < n; i++)
    {
        k = min((long long int)(k - 1), n - 1 - i);
        for (long long int j = 0; j <= k; j++)
        {
            ans = (ans +
                   (nums[i] * ((((fact[n - 1 - i] * inv_fact[j]) % mod) *
                                inv_fact[n - 1 - i - j]) %
                               mod)) %
                       mod) %
                  mod;
        }
        if (k == -1)
        {
            ans = (ans + nums[i]) % mod;
        }
        k = temp;
    }
    return ans;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    vll A(n);
    fr(i, 0, n)
    {
        cin >> A[i];
    }
    cout << minMaxSums(A, k) << endl;
}