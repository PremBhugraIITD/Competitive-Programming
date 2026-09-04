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

int main()
{
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vll zeroes;
    fr(i, 0, n)
    {
        if (s[i] == '0')
        {
            zeroes.pb(i);
        }
    }
    k++;
    n = zeroes.size();
    ll ans = max(abs(zeroes[0] - zeroes[0]), abs(zeroes[0] - zeroes[k - 1]));
    ll i = 0, j = k - 1;
    while (j < n)
    {
        while (i <= j && (max(abs(zeroes[i + 1] - zeroes[j - k + 1]), abs(zeroes[i + 1] - zeroes[j])) <= max(abs(zeroes[i] - zeroes[j - k + 1]), abs(zeroes[i] - zeroes[j]))))
        {
            i++;
        }
        if (i <= j)
        {
            ans = min(ans, max(abs(zeroes[i] - zeroes[j - k + 1]), abs(zeroes[i] - zeroes[j])));
        }
        j++;
    }
    cout << ans << endl;
}