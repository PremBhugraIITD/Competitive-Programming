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
#define fr(i, a, b) for (long long int(i) = (a); (i) < (b); (i)++)
#define frr(i, a, b) for (long long int(i) = (a); (i) >= (b); (i)--)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 1000000007

int main()
{
    ll n, k1, k2;
    cin >> n >> k1 >> k2;
    vll A(n), B(n);
    fr(i, 0, n)
    {
        cin >> A[i];
    }
    fr(i, 0, n)
    {
        cin >> B[i];
    }
    vll differences(n);
    ll sum = 0;
    fr(i, 0, n)
    {
        differences[i] = abs(A[i] - B[i]);
        sum += differences[i];
    }
    ll k = k1 + k2;
    ll ans = 0;
    if (sum > k)
    {
        priority_queue<ll> maxi;
        fr(i, 0, n)
        {
            maxi.push(differences[i]);
        }
        while (k)
        {
            ll top = maxi.top();
            maxi.pop();
            k--;
            maxi.push(top - 1);
        }
        while (!maxi.empty())
        {
            ll top = maxi.top();
            maxi.pop();
            ans += top * top;
        }
    }
    else
    {
        k -= sum;
        if (k & 1)
        {
            ans = 1;
        }
    }
    cout << ans << endl;
}