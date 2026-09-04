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

ll solve(vpll A)
{
    ll n = A.size();
    ll ans = 0;
    fr(i, 0, n)
    {
        ll x = A[i].first, h = A[i].second;
        if (i == 0)
        {
            A[i] = {x - h, x};
            ans++;
        }
        else if (i == n - 1)
        {
            A[i] = {x, x + h};
            ans++;
        }
        else
        {
            if (x - h > A[i - 1].second) // if the tree can fall to the left, make it fall
            {
                A[i] = {x - h, x};
                ans++;
            }
            // tree cannot fall to the left
            else if (x + h >= A[i + 1].first) // if the tree cannot fall to the right even when the next tree is still standing
            {
                A[i] = {x, x};
            }
            // tree cannot fall to the left and can fall to the right if the next tree is still standing
            else if (x + h < A[i + 1].first - A[i + 1].second) // if the tree can fall to the right and the next tree can still fall to the left, make it fall
            {
                A[i] = {x, x + h};
                ans++;
            }
            else if (x >= A[i + 1].first - A[i + 1].second) // if the next tree cannot fall to the left even when the current tree is still standing
            {
                A[i] = {x, x + h};
                ans++;
            }
            // only one of the current and the next trees can occupy this segment
            else
            {
                A[i] = {x, x + h};
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    ll n;
    cin >> n;
    vpll A(n);
    fr(i, 0, n)
    {
        cin >> A[i].first >> A[i].second;
    }
    ll ans = solve(A);
    vpll B(n);
    fr(i, 0, n)
    {
        B[i].second = A[n - i - 1].second;
        if (i == 0)
        {
            B[i].first = 1;
        }
        else
        {
            B[i].first = B[i - 1].first + (A[n - (i - 1) - 1].first - A[n - i - 1].first);
        }
    }
    ans = max(ans, solve(B));
    cout << ans << endl;
}