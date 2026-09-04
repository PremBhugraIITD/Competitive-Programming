#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
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
#define frr(i, a, b) for (int(i) = (a); (i) >= (b); (i)--)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 1000000007

vector<long long int> maxSlidingWindow(vector<long long int> &nums, int k)
{
    long long int n = nums.size();
    vector<long long int> ans;
    deque<int> dq;
    for (int i = 0; i < n; i++)
    {
        while (!dq.empty() && nums[dq.back()] <= nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i - dq.front() >= k)
        {
            dq.pop_front();
        }
        if (i >= k - 1)
        {
            ans.push_back(nums[dq.front()]);
        }
    }
    return ans;
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
    vll ans = maxSlidingWindow(A, k);
    fr(i, 0, ans.size())
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}