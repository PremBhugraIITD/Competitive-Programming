#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iomanip>
#include <stack>
#include <queue>
#include <map>
using namespace std;

#define ll long long int
#define ld long double
#define vll vector<long long int>
#define vpll vector<pair<long long int, long long int>>
#define pll <pair<long long int, long long int>>
#define mll map<long long int, long long int>
#define mcl map<char, long long int>
#define fr(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 1000000007

int main()
{
    ll n, k;
    cin >> n >> k;
    vll A(n);
    fr(i, 0, n)
    {
        cin >> A[i];
    }
    queue<ll> q;
    fr(i, 0, k)
    {
        if (A[i] < 0)
        {
            q.push(i);
        }
    }
    vll ans;
    if (q.empty())
    {
        ans.push_back(-1);
    }
    else
    {
        ans.push_back(q.front());
    }
    fr(i, k, n)
    {
        if (A[i] < 0)
        {
            q.push(i);
        }
        if (i - q.front() >= k)
        {
            q.pop();
        }
        if (q.empty())
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(q.front());
        }
    }
    fr(i, 0, ans.size())
    {
        cout << (ans[i] == -1 ? -1 : ans[i] + 1) << " ";
    }
    cout << endl;
}