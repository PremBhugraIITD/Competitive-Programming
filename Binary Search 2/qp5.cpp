#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool solve(long long int x, vector<long long int> &A, int k)
{
    long long int count = 0;
    long long int n = A.size();
    for (long long int i = 0; i < n; i++)
    {
        count += (upper_bound(A.begin() + i, A.end(), A[i] + x) - (A.begin() + i)) - 1;
        // cout<<count<<" ";
    }
    // cout<<endl;
    // cout<<count<<endl;
    return (count >= k);
}

int smallestDistancePair(vector<long long int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    long long int n = nums.size();
    // for(long long int i=0;i<n;i++){
    //     cout<<nums[i]<<" ";
    // }
    // cout<<endl;
    long long int l = 0, r = nums[n - 1] - nums[0];
    long long int ans;
    while (l <= r)
    {
        long long int mid = (l + r) / 2;
        // cout<<l<<" "<<r<<" "<<mid<<endl;
        if (solve(mid, nums, k))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

int main()
{
    long long int n, k;
    cin >> n >> k;
    vector<long long int> A(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << smallestDistancePair(A, k) << endl;
}