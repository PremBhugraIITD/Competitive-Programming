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

int main()
{
    ll n;
    cin >> n;
    mll primes;
    ll temp = n;
    for (ll i = 2; i * i <= n; i++)
    {
        while (temp % i == 0)
        {
            temp /= i;
            primes[i]++;
        }
    }
    if (temp > 1)
    {
        primes[temp]++;
    }
    ll ans = 0;
    for (auto i : primes)
    {
        ll k = i.second;
        ll j = 1;
        while (k - j >= 0)
        {
            k -= j;
            j++;
            ans++;
        }
    }
    cout << ans << endl;
}