#include <iostream>
#include <algorithm>
using namespace std;

#define mod 1000000007

long long int lcm(long long int a, long long int b)
{
    return a * b / __gcd(a, b);
}
bool solve(long long int m, long long int n, long long int a, long long int b)
{
    return (m / a + m / b - m / lcm(a, b)) >= n;
}
int nthMagicalNumber(int n, int a, int b)
{
    long long int mini = min(a, b);
    long long int maxi = max(a, b);
    long long int l = mini, r = n * maxi;
    long long int ans;
    while (l <= r)
    {
        long long int mid = l + (r - l) / 2;
        if (solve(mid, n, a, b))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans % mod;
}

int main()
{
    long long int n, a, b;
    cin >> n >> a >> b;
    cout << nthMagicalNumber(n, a, b) << endl;
}