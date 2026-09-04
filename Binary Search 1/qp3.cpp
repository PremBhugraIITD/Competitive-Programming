#include <iostream>
using namespace std;

bool solve(long long int m, long long int n)
{
    long long int count = 0;
    for (long long int i = 1; i <= n; i++)
    {
        count += min(n, m / i);
        if (count >= 1 + (n * n / 2))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    long long int n;
    cin >> n;
    long long int ans;
    long long int l = 1, r = n * n;
    while (l <= r)
    {
        long long int mid = l + (r - l) / 2;
        if (solve(mid, n))
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