#include <iostream>
using namespace std;

int mySqrt(int x)
{
    long long int l = 1, r = x;
    long long int ans;
    while (l <= r)
    {
        long long int mid = l + (r - l) / 2;
        if (mid * mid <= x)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}

int main()
{
    long long int n;
    cin >> n;
    cout << mySqrt(n) << endl;
}