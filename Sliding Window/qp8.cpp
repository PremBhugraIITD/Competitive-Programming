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
#define pll <pair<long long int, long long int>>
#define mll map<long long int, long long int>
#define mcl map<char, long long int>
#define fr(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define frr(i, a, b) for (int(i) = (a); (i) >= (b); (i)--)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 1000000007

void reverseArr(vector<long long int> &nums, int l, int r)
{
    while (l < r)
    {
        swap(nums[l++], nums[r--]);
    }
}

void rotate(vector<long long int> &nums, int k)
{
    int n = nums.size();
    reverseArr(nums, 0, k - 1);
    reverseArr(nums, k, n - 1);
    reverseArr(nums, 0, n - 1);
}

vector<long long int> getAverages(vector<long long int> &nums, int k)
{
    int n = nums.size();
    vector<long long int> ans;
    long long int sum = 0;
    int temp = k;
    k = 2 * k + 1;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (i >= k)
        {
            sum -= nums[i - k];
        }
        if (i >= k - 1)
        {
            ans.push_back(sum / k);
        }
        else
        {
            ans.push_back(-1);
        }
    }
    if (temp <= n)
    {
        rotate(ans, temp);
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
    vll ans = getAverages(A, k);
    fr(i, 0, n)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}