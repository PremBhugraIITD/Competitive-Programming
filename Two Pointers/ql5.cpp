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

int shortestSubarray(vector<long long int> &nums, int k)
{
    int n = nums.size();
    vector<long long int> prefixSum(n, 0);
    prefixSum[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }
    int ans = n + 1;
    deque<int> dq;
    dq.push_back(-1);
    for (int i = 0; i < n; i++)
    {
        while (!dq.empty() &&
               (prefixSum[i] -
                    (dq.front() == -1 ? 0 : prefixSum[dq.front()]) >=
                k))
        {
            ans = min(ans, i - dq.front());
            dq.pop_front();
        }
        while (!dq.empty() &&
               (dq.back() == -1 ? 0 : prefixSum[dq.back()]) >=
                   prefixSum[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    return ans == n + 1 ? -1 : ans;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    vll A(n);
    fr(i, 0, n)
    {
        cin >> A[i];
    }
    cout << shortestSubarray(A, k) << endl;
}