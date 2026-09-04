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

ll maxSubSum(vll &A)
{
    ll ans = INT_MIN, sum = 0, n = A.size();
    fr(i, 0, n)
    {
        sum += A[i];
        ans = max(sum, ans);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vll A(n);
        ll y_sum = 0;
        fr(i, 0, n)
        {
            cin >> A[i];
            y_sum += A[i];
        }
        vll temp(n - 1);
        fr(i, 0, n - 1)
        {
            temp[i] = A[i];
        }
        ll a_sum = maxSubSum(temp);
        fr(i, 1, n)
        {
            temp[i - 1] = A[i];
        }
        a_sum = max(a_sum, maxSubSum(temp));
        if (y_sum > a_sum)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}