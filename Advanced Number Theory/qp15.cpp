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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x = 1e6;
    vll isPrime(x + 1, 1), spf(x + 1, INT_MAX);
    isPrime[0] = isPrime[1] = 0;
    fr(i, 2, x + 1)
    {
        if (isPrime[i])
        {
            spf[i] = i;
            for (ll j = i * i; j <= x; j += i)
            {
                isPrime[j] = 0;
                spf[j] = min(spf[j], i);
            }
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vll A(n);
        mll count;
        fr(i, 0, n)
        {
            cin >> A[i];
            ll number = A[i];
            while (number > 1)
            {
                ll prime = spf[number];
                ll score = 0;
                while (number % prime == 0)
                {
                    number /= prime;
                    score++;
                }
                count[prime] = max(count[prime], score);
            }
        }
        sort(A);
        if (count.size() >= 2)
        {
            ll divisors = 1;
            ll ans = 1;
            for (auto i : count)
            {
                divisors *= i.second + 1;
                ans *= pow(i.first, i.second);
            }
            if (ans > A[n - 1] && divisors == n + 2)
            {
                cout << ans << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else
        {
            ll prime = count.begin()->first;
            ll temp = 1;
            bool found = false;
            fr(i, 0, n)
            {
                temp *= prime;
                if (A[i] == temp)
                {
                    continue;
                }
                else
                {
                    found = true;
                    cout << -1 << endl;
                    break;
                }
            }
            if (!found)
            {
                cout << temp * prime << endl;
            }
        }
    }
}