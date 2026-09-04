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
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vll A(n);
        fr(i, 0, n)
        {
            cin >> A[i];
        }
        ll l = 0, r = n - 1;
        ll x = 0;
        while (l < r)
        {
            x = __gcd(x, abs(A[l] - A[r]));
            l++, r--;
        }
        bool found = false;
        while (l < r)
        {
            if (A[l] % x != A[r] % x)
            {
                found = false;
                break;
            }
            l++, r--;
        }
        if (found)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << x << endl;
        }
    }
}