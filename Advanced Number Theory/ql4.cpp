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
    int t;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        vll A(n);
        fr(i, 0, n)
        {
            cin >> A[i];
        }
        ll ans = 1;
        set<ll> s;
        s.insert(1);
        fr(i, 0, n)
        {
            if (x % A[i] == 0)
            {
                bool found = false;
                set<ll> newSet;
                for (int j : s)
                {
                    if (j * A[i] == x)
                    {
                        found = true;
                        break;
                    }
                    else if (x % (j * A[i]) == 0)
                    {
                        newSet.insert(j * A[i]);
                    }
                }
                if (found)
                {
                    s.clear();
                    ans++;
                    s.insert(1);
                    s.insert(A[i]);
                }
                else
                {
                    for (int j : newSet)
                    {
                        s.insert(j);
                    }
                }
            }
        }
        cout << ans << endl;
    }
}