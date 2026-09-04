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
    vector<string> names(n);
    fr(i, 0, n)
    {
        cin >> names[i];
    }
    ll ans = 1;
    fr(i, 0, m)
    {
        set<char> temp;
        fr(j, 0, n)
        {
            temp.insert(names[j][i]);
        }
        ans = (ans * temp.size()) % mod;
    }
    cout << ans << endl;
}