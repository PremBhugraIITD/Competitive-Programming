#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

bool solve(long long int k, vector<pair<long long int, long long int>> &A)
{
    long long int n = A.size();
    long long int mini = 0, maxi = 0;
    for (long long int i = 0; i < n; i++)
    {
        mini = mini - k;
        maxi = maxi + k;
        mini = max(mini, A[i].first);
        maxi = min(maxi, A[i].second);
        if (mini > maxi)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        vector<pair<long long int, long long int>> A(n);
        long long int maxi = INT_MIN;
        for (long long int i = 0; i < n; i++)
        {
            cin >> A[i].first >> A[i].second;
            maxi = max(maxi, A[i].second);
        }
        long long int l = 0, r = maxi;
        long long int ans;
        while (l <= r)
        {
            long long int mid = (l + r) / 2;
            if (solve(mid, A))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
}