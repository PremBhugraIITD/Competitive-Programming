#include <iostream>
using namespace std;

bool solve(long long int x)
{
    cout << "? 1 " << x << endl;
    long long int area;
    cin >> area;
    return !(area == x);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int l = 1, r = 1000;
        long long int ans;
        while (l <= r)
        {
            long long int mid = (l + r) / 2;
            if (solve(mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << "! " << ans << endl;
        cout.flush();
    }
}