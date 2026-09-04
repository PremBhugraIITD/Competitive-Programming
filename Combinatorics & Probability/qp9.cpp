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
    ll n, m;
    cin >> n >> m;
    vll fact(n + 1, 1);
    fr(i, 1, n + 1)
    {
        fact[i] = (fact[i - 1] * i) % m;
    }
    vll values(n + 1, 0);
    fr(i, 1, n + 1)
    {
        values[i] = (fact[i] * (n - i + 1)) % m;
        values[i] = (values[i] * fact[n - i]) % m;
    }
    vll prefixSum(n + 1, 0);
    fr(i, 1, n + 1)
    {
        prefixSum[i] = (prefixSum[i - 1] + values[i]) % m;
    }
    ll ans = 0;
    fr(i, 1, n + 1)
    {
        ans = (ans + prefixSum[i]) % m;
    }
    cout << ans << endl;
}