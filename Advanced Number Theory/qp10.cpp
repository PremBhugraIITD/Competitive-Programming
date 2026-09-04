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
    vll isPrime(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    vll ans;
    fr(i, 2, n + 1)
    {
        if (isPrime[i])
        {
            ll prime = i;
            while (prime <= n)
            {
                ans.pb(prime);
                prime *= i;
            }
            for (ll j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    cout << ans.size() << endl;
    fr(i, 0, ans.size())
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}