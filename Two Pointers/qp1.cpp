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
    ll n, m;
    cin >> n >> m;
    vll A(n), B(m);
    fr(i, 0, n)
    {
        cin >> A[i];
    }
    fr(i, 0, m)
    {
        cin >> B[i];
    }
    ll i = 0, j = 0;
    ll ans = 0;
    if (m == 1)
    {
        fr(i, 0, n)
        {
            if (A[i] == B[j])
            {
                ans++;
            }
        }
    }
    else
    {
        ll k = 0, l = 0;
        while (i < n)
        {
            if ((i == n - 1) || (A[i] != A[i + 1]))
            {
                while ((j < m) && (B[j] <= A[i]))
                {
                    if (j == m - 1 || B[j] != B[j + 1])
                    {
                        if (A[i] == B[j])
                        {
                            ans += (j - k + 1) * (i-l+1);
                        }
                        k = j + 1;
                    }
                    j++;
                }
                l = i + 1;
            }
            i++;
        }
    }
    cout << ans << endl;
}