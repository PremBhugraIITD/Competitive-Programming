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

int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 += nums1[i];
        sum2 += nums2[i];
    }
    int maxi1 = 0, maxi2 = 0;
    int subSum1 = 0, subSum2 = 0;
    int maxSum1 = sum1, maxSum2 = sum2;
    for (int i = 0; i < n; i++)
    {
        if (subSum1 + nums1[i] < subSum2 + nums2[i])
        {
            subSum1 += nums1[i];
            subSum2 += nums2[i];
        }
        else
        {
            subSum1 = 0;
            subSum2 = 0;
        }
        maxSum1 = max(maxSum1, sum1 - subSum1 + subSum2);
        maxSum2 = max(maxSum2, sum2 - subSum2 + subSum1);
    }
    maxi1 = max(maxSum1, maxSum2);
    subSum1 = 0, subSum2 = 0;
    maxSum1 = sum1, maxSum2 = sum2;
    for (int i = 0; i < n; i++)
    {
        if (subSum1 + nums1[i] > subSum2 + nums2[i])
        {
            subSum1 += nums1[i];
            subSum2 += nums2[i];
        }
        else
        {
            subSum1 = 0;
            subSum2 = 0;
        }
        maxSum1 = max(maxSum1, sum1 - subSum1 + subSum2);
        maxSum2 = max(maxSum2, sum2 - subSum2 + subSum1);
    }
    maxi2 = max(maxSum1, maxSum2);
    return max(maxi1, maxi2);
}

int main()
{
    ll n;
    cin >> n;
    vector<int> A(n), B(n);
    fr(i, 0, n)
    {
        cin >> A[i];
    }
    fr(i, 0, n)
    {
        cin >> B[i];
    }
    cout << maximumsSplicedArray(A, B) << endl;
}