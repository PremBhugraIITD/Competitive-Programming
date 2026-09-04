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
    ll a, b;
    cin >> a >> b;
    if (a > b)
    {
        ll n = a - b;
        ll ans = 0;
        for (ll i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                if (i > b)
                {
                    ans++;
                }
                if ((n / i != i) && (n / i > b))
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    else if (a == b)
    {
        cout << "infinity" << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}