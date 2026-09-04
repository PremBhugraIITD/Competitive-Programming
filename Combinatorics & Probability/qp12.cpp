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
    string s;
    cin >> s;
    ll n = s.length();
    ll countA = 0, countB = 0;
    fr(i, 0, n)
    {
        if (s[i] == 'a')
        {
            countA++;
        }
        else if (s[i] == 'b')
        {
            countB++;
        }
    }
    if (countA == 0)
    {
        cout << 0 << endl;
    }
    else if (countB == 0)
    {
        cout << countA << endl;
    }
    else
    {
        ll start = 0;
        while (start < n && s[start] != 'a')
        {
            start++;
        }
        ll end = n - 1;
        while (end >= 0 && s[end] != 'a')
        {
            end--;
        }
        string t;
        fr(i, start, end + 1)
        {
            if (s[i] == 'a')
            {
                t.pb('a');
            }
            else if (s[i] == 'b')
            {
                if (t.back() == 'b')
                {
                    continue;
                }
                else
                {
                    t.pb('b');
                }
            }
        }
        ll count = 0;
        ll ans = 1;
        fr(i, 0, t.size())
        {
            if (t[i] == 'a')
            {
                count++;
            }
            else
            {
                ans = (ans * (count + 1)) % mod;
                count = 0;
            }
        }
        ans = (ans * (count + 1)) % mod;
        cout << ans - 1 << endl;
    }
}