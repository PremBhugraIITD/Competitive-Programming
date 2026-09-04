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
    ll x = 1e7;
    vll isPrime(x + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    fr(i, 2, x + 1)
    {
        if (isPrime[i])
        {
            for (long long int j = i * i; j <= x; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
    vll primes, sos;
    vll squares(x + 1, 0);
    fr(i, 0, x + 1)
    {
        if (isPrime[i])
        {
            primes.pb(i);
        }
    }
    for (long long int i = 1; i * i <= x; i++)
    {
        if (i * i <= x)
        {
            squares[i * i] = 1;
        }
        if (i * i * i * i <= x)
        {
            sos.pb(i * i * i * i);
        }
    }
    vll isConsistent(x + 1, 0);
    fr(i, 0, primes.size())
    {
        ll prime = primes[i];
        fr(j, 0, sos.size())
        {
            ll s = sos[j];
            if (s < prime)
            {
                if (squares[prime - s] == 1)
                {
                    isConsistent[prime] = 1;
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    vll prefixSum(x + 1, 0);
    fr(i, 1, x + 1)
    {
        prefixSum[i] = prefixSum[i - 1] + isConsistent[i];
    }
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n == 1)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << prefixSum[n] << endl;
        }
    }
}