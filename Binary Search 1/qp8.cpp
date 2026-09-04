#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

bool solve(long long int d, long long int c, vector<long long int> A)
{
    long long int n = A.size();
    long long int prev = A[0];
    c--;
    for (long long int i = 1; i < n; i++)
    {
        if (c == 0)
        {
            return true;
        }
        else
        {
            if (A[i] - prev >= d)
            {
                c--;
                prev = A[i];
            }
            else
            {
                continue;
            }
        }
    }
    if (c == 0)
    {
        return true;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, c;
        cin >> n >> c;
        vector<long long int> S(n);
        long long int mini = INT_MAX;
        long long int maxi = INT_MIN;
        for (long long int i = 0; i < n; i++)
        {
            cin >> S[i];
            mini = min(mini, S[i]);
            maxi = max(maxi, S[i]);
        }
        sort(S.begin(), S.end());
        long long int ans;
        long long int l = 1, r = maxi - mini;
        while (l <= r)
        {
            long long int mid = (l + r) / 2;
            // cout<<l<<" "<<r<<" "<<mid<<endl;
            if (solve(mid, c, S))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        cout << ans << endl;
    }
}