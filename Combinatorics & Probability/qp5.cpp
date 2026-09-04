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

ll binpow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * a;
        }
        a = (a * a);
        b >>= 1;
    }
    return ans;
}

int main()
{
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    ll n = s1.length();
    ll expected = 0;
    fr(i, 0, n)
    {
        if (s1[i] == '+')
        {
            expected++;
        }
        else
        {
            expected--;
        }
    }
    ll exact = 0, count = 0;
    fr(i, 0, n)
    {
        if (s2[i] == '+')
        {
            exact++;
        }
        else if (s2[i] == '-')
        {
            exact--;
        }
        else
        {
            count++;
        }
    }
    vll fact(count + 1, 1);
    fr(i, 1, count + 1)
    {
        fact[i] = fact[i - 1] * i;
    }
    ld num, den = binpow(2, count);
    if (expected == exact)
    {
        if (count & 1)
        {
            num = 0;
        }
        else
        {
            num = fact[count] / (fact[count / 2] * fact[count / 2]);
        }
    }
    else if (expected > exact)
    {
        ll diff = expected - exact;
        if (diff > count)
        {
            num = 0;
        }
        else
        {
            if ((count + diff) & 1)
            {
                num = 0;
            }
            else
            {
                num = fact[count] / (fact[(count + diff) / 2] * fact[(count - diff) / 2]);
            }
        }
    }
    else
    {
        ll diff = exact - expected;
        if (diff > count)
        {
            num = 0;
        }
        else
        {
            if ((count + diff) & 1)
            {
                num = 0;
            }
            else
            {
                num = fact[count] / (fact[(count + diff) / 2] * fact[(count - diff) / 2]);
            }
        }
    }
    cout << setprecision(10) << (num / den) << endl;
}