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

vector<long long int> findIndices(vector<long long int> &nums, int indexDifference, int valueDifference)
{
    int n = nums.size();
    if (indexDifference >= n)
    {
        return {-1, -1};
    }
    long long int mini = INT_MAX, maxi = INT_MIN;
    long long int minIndex = -1, maxIndex = -1;
    for (int i = 0; i < n; i++)
    {
        if (i - indexDifference >= 0)
        {
            ll last = nums[i - indexDifference];
            if (last < mini)
            {
                mini = last;
                minIndex = i - indexDifference;
            }
            if (last > maxi)
            {
                maxi = last;
                maxIndex = i - indexDifference;
            }
            if (abs(nums[i] - nums[minIndex]) >= valueDifference)
            {
                return {i, minIndex};
            }
            else if (abs(nums[i] - nums[maxIndex]) >= valueDifference)
            {
                return {i, maxIndex};
            }
        }
    }
    return {-1, -1};
}

int main()
{
    ll n, a, b;
    cin >> n >> a >> b;
    vll A(n);
    fr(i, 0, n)
    {
        cin >> A[i];
    }
    vll ans = findIndices(A, a, b);
    cout << ans[0] << " " << ans[1] << endl;
}