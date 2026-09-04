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
#define fr(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define frr(i, a, b) for (int(i) = (a); (i) >= (b); (i)--)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 1000000007

vll smmallestPrimeFactor(ll n)
{
    vll isPrime(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    vll ans(n, INT_MAX);
    for (long long int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            ans[i - 1] = i;
            for (ll j = i * i; j <= n; j += i)
            {
                isPrime[j] = 0;
                ans[j - 1] = min(i, ans[j - 1]);
            }
        }
    }
    return ans;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    vll status(n, 0);
    vll spf = smmallestPrimeFactor(n);
    vll count(n, 0);
    map<ll, vll> multiples;
    while (m--)
    {
        char op;
        ll i;
        cin >> op >> i;
        if (op == '+')
        {
            if (status[i - 1])
            {
                cout << "Already on" << endl;
            }
            else
            {
                if (i == 1)
                {
                    status[i - 1] = 1;
                    cout << "Success" << endl;
                }
                else
                {
                    bool found = false;
                    ll prime = -1;
                    ll temp = i;
                    while (temp > 1)
                    {
                        ll p = spf[temp - 1];
                        if (count[p - 1] > 0)
                        {
                            found = true;
                            prime = p;
                            break;
                        }
                        while (temp % p == 0)
                        {
                            temp /= p;
                        }
                    }
                    if (found)
                    {
                        while (!status[multiples[prime].back() - 1])
                        {
                            multiples[prime].pop_back();
                        }
                        cout << "Conflict with " << multiples[prime].back() << endl;
                    }
                    else
                    {
                        status[i - 1] = 1;
                        temp = i;
                        while (temp > 1)
                        {
                            ll p = spf[temp - 1];
                            multiples[p].pb(i);
                            count[p - 1]++;
                            while (temp % p == 0)
                            {
                                temp /= p;
                            }
                        }
                        cout << "Success" << endl;
                    }
                }
            }
        }
        else
        {
            if (!status[i - 1])
            {
                cout << "Already off" << endl;
            }
            else
            {
                status[i - 1] = 0;
                ll temp = i;
                while (temp > 1)
                {
                    ll p = spf[temp - 1];
                    count[p - 1]--;
                    while (temp % p == 0)
                    {
                        temp /= p;
                    }
                }
                cout << "Success" << endl;
            }
        }
    }
}