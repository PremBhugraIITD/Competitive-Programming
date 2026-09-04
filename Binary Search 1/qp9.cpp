#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

double findMedianSortedArrays(vector<long long int> &nums1, vector<long long int> &nums2)
{
    long long int n = nums1.size(), m = nums2.size();
    if (n == 0)
    {
        return m & 1 ? (nums2[m / 2])
                     : ((nums2[(m - 1) / 2] + nums2[m / 2]) / 2.0);
    }
    else if (m == 0)
    {
        return n & 1 ? (nums1[n / 2])
                     : ((nums1[(n - 1) / 2] + nums1[n / 2]) / 2.0);
    }
    else if (n > m)
    {
        return findMedianSortedArrays(nums2, nums1);
    }
    else
    {
        long long int l = 0, r = n - 1;
        long long int half = (n + m + 1) / 2;
        while (true)
        {
            long long int mid1, mid2, left1, left2, right1, right2;
            if (r < 0)
            {
                mid1 = -1;
            }
            else if (l > n - 1)
            {
                mid1 = half - 1;
            }
            else
            {
                mid1 = (l + r) / 2;
            }
            mid2 = half - mid1 - 2;
            left1 =
                ((mid1 >= 0) && (mid1 <= n - 1)) ? nums1[mid1] : INT_MIN;
            left2 =
                ((mid2 >= 0) && (mid2 <= m - 1)) ? nums2[mid2] : INT_MIN;
            right1 = ((mid1 + 1 <= n - 1) && (mid1 + 1 >= 0))
                         ? nums1[mid1 + 1]
                         : INT_MAX;
            right2 = ((mid2 + 1 <= m - 1) && (mid2 + 1 >= 0))
                         ? nums2[mid2 + 1]
                         : INT_MAX;
            if ((left1 <= right2) && (left2 <= right1))
            {
                return (n + m) & 1
                           ? (max(left1, left2))
                           : ((max(left1, left2) + (min(right1, right2))) /
                              2.0);
            }
            else if (left2 > right1)
            {
                l = mid1 + 1;
            }
            else
            {
                r = mid1 - 1;
            }
        }
    }
}

int main()
{
    long long int n;
    cin >> n;
    vector<long long int> A(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    long long int m;
    cin >> m;
    vector<long long int> B(m);
    for (long long int i = 0; i < m; i++)
    {
        cin >> B[i];
    }
    cout << findMedianSortedArrays(A, B) << endl;
}