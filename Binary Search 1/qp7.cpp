#include <iostream>
#include <vector>
using namespace std;

bool solve(long long int m, vector<long long int> A)
{
    long long int count = 0;
    for (long long int i = 0; i < A.size(); i++)
    {
        if (A[i] <= m)
        {
            count++;
            if (count > m)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    long long int n;
    cin >> n;
    vector<long long int> A(n + 1);
    for (long long int i = 0; i < n + 1; i++)
    {
        cin >> A[i];
    }
    long long int l = 1, r = n;
    long long int ans;
    while (l <= r)
    {
        long long int mid = l + (r - l) / 2;
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
