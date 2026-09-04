#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

bool solve(long long int days, vector<long long int> B, long long int m, long long int k)
{
    long long int n = B.size();
    long long int tempK = k;
    for (long long int i = 0; i < n; i++)
    {
        if (B[i] > days)
        {
            k = tempK;
            continue;
        }
        else
        {
            k--;
            if (k == 0)
            {
                m--;
                if (m == 0)
                {
                    return true;
                    break;
                }
                k = tempK;
                continue;
            }
        }
    }
    return false;
}

long long int minDays(vector<long long int> bloomDay, long long int m, long long int k)
{
    long long int product = m * k;
    if (product > bloomDay.size())
    {
        return -1;
    }
    else
    {
        long long int n = bloomDay.size();
        long long int l = INT_MAX, r = INT_MIN;
        for (long long int i = 0; i < n; i++)
        {
            l = min(l, (long long int)bloomDay[i]);
            r = max(r, (long long int)bloomDay[i]);
        }
        long long int ans;
        while (l <= r)
        {
            long long int mid = l + (r - l) / 2;
            if (solve(mid, bloomDay, m, k))
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
}

int main()
{
    long long int n;
    cin >> n;
    vector<long long int> B(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    long long int m, k;
    cin >> m >> k;
    cout << minDays(B, m, k) << endl;
}