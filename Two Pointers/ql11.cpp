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

ll solve(vll &A, vll &B, vll &C)
{
    ll a = A.size(), b = B.size(), c = C.size();
    ll i = 0, j = 0, k = 0;
    ll ans = LLONG_MAX;
    while (j < b)
    {
        while (i < a && A[i] <= B[j])
        {
            i++;
        }
        if (i == a)
        {
            i = a - 1;
        }
        else
        {
            i--;
            i = max(i, (ll)0);
        }
        while (k < c && A[i] > C[k])
        {
            k++;
        }
        k = min(k, c - 1);
        ans = min(ans, (B[j] - A[i]) * (B[j] - A[i]) + (C[k] - A[i]) * (C[k] - A[i]) + (C[k] - B[j]) * (C[k] - B[j]));
        j++;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll nr, ng, nb;
        cin >> nr >> ng >> nb;
        vll R(nr), G(ng), B(nb);
        fr(i, 0, nr)
        {
            cin >> R[i];
        }
        fr(i, 0, ng)
        {
            cin >> G[i];
        }
        fr(i, 0, nb)
        {
            cin >> B[i];
        }
        sort(R);
        sort(G);
        sort(B);
        ll ans = LLONG_MAX;
        ans = min(ans, solve(R, G, B));
        ans = min(ans, solve(R, B, G));
        ans = min(ans, solve(G, R, B));
        ans = min(ans, solve(G, B, R));
        ans = min(ans, solve(B, R, G));
        ans = min(ans, solve(B, G, R));
        cout << ans << endl;
    }
}