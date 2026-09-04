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
    ll n;
    cin >> n;
    vector<vll> A(n, vll(3));
    fr(i, 0, n)
    {
        cin >> A[i][0] >> A[i][1];
        A[i][2] = i;
    }
    map<ll, vpll> arr_dept;
    fr(i, 0, n)
    {
        arr_dept[A[i][0]].pb({A[i][1], i});
        A[i] = {A[i][1], A[i][0], i};
    }
    map<vll, ll> allocation;
    sort(A);
    ll ans = 0;
    ll j = 0;
    queue<ll> available;
    for (auto &i : arr_dept)
    {
        ll arrival = i.first;
        ll required = i.second.size();
        sort(i.second);
        ll init = ans;
        while (j < n && A[j][0] < arrival) // rooms freed till today
        {
            available.push(allocation[{A[j][1], A[j][0], A[j][2]}]);
            j++;
        }
        required -= available.size();
        ans += max(required, (ll)0);
        fr(k, init + 1, ans + 1) // new rooms created
        {
            available.push(k);
        }
        fr(k, 0, i.second.size())
        {
            allocation[{i.first, i.second[k].first, i.second[k].second}] = available.front();
            available.pop();
        }
    }
    fr(i, 0, n)
    {
        reverse(A[i]);
    }
    sort(A);
    cout << ans << endl;
    fr(i, 0, n)
    {
        cout << allocation[{A[i][1], A[i][2], i}] << " ";
    }
    cout << endl;
}