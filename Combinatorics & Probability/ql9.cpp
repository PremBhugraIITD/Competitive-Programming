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
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
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

vector<ll> waysToFillArray(vector<vector<ll>> &queries)
{
    long long int size = queries.size();
    long long int N = 1e5;
    vector<long long int> fact(N + 1, 1), inv_fact(N + 1, 1);
    for (long long int i = 1; i <= N; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    inv_fact[N] = binpow(fact[N], mod - 2, mod);
    for (long long int i = N - 1; i >= 0; i--)
    {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
    }
    vector<long long int> isPrime(N + 1, 1), spf(N + 1, INT_MAX);
    isPrime[0] = isPrime[1] = 0;
    for (long long int i = 2; i <= N; i++)
    {
        if (isPrime[i])
        {
            spf[i] = i;
            for (long long int j = i * i; j <= N; j += i)
            {
                isPrime[j] = 0;
                spf[j] = min(i, spf[j]);
            }
        }
    }
    vector<ll> ans;
    for (long long int i = 0; i < size; i++)
    {
        long long int n = queries[i][0];
        long long int k = queries[i][1];
        map<long long int, long long int> primes;
        long long int temp = k;
        while (temp > 1)
        {
            long long int p = spf[temp];
            while (temp % p == 0)
            {
                primes[p]++;
                temp /= p;
            }
        }
        long long int tempAns = 1;
        for (auto j : primes)
        {
            long long int q = j.second;
            tempAns =
                (tempAns * ((((fact[q + n - 1] * inv_fact[n - 1]) % mod) *
                             inv_fact[q]) %
                            mod)) %
                mod;
        }
        ans.push_back(tempAns);
    }
    return ans;
}

int main()
{
    ll n;
    cin >> n;
    vector<vll> queries(n, vll(2));
    fr(i, 0, n)
    {
        cin >> queries[i][0] >> queries[i][1];
    }
    vll ans = waysToFillArray(queries);
    fr(i, 0, ans.size())
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}