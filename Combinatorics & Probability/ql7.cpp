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

long long int permutations(string &s, vector<long long int> &fact,
                           vector<long long int> &inv_fact,
                           long long int m)
{
    vector<long long int> count(26, 0);
    long long int n = s.length();
    long long int ans = fact[n];
    for (long long int i = 0; i < n; i++)
    {
        count[s[i] - 'a']++;
    }
    for (long long int i = 0; i < 26; i++)
    {
        if (count[i])
        {
            ans = (ans * inv_fact[count[i]]) % m;
        }
    }
    return ans;
}

int countAnagrams(string s)
{
    long long int n = s.length();
    long long int i = 0, j = 0;
    long long int ans = 1;
    vector<long long int> fact(n + 1, 1);
    for (long long int i = 1; i <= n; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    vector<long long int> inv_fact(n + 1, 0);
    inv_fact[n] = binpow(fact[n], mod - 2, mod);
    for (long long int i = n - 1; i >= 0; i--)
    {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
    }
    string temp = "";
    while (i < n)
    {
        if (s[i] == ' ')
        {
            ans = (ans * permutations(temp, fact, inv_fact, mod)) % mod;
            temp = "";
        }
        else
        {
            temp += s[i];
        }
        i++;
    }
    ans = (ans * permutations(temp, fact, inv_fact, mod)) % mod;
    return ans;
}

int main()
{
    string s;
    getline(cin, s);
    cout << countAnagrams(s) << endl;
}