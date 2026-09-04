#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int countInRange(long long int l, long long int r, vector<long long int> &A)
{
    long long int n = A.size();
    long long int a = n;
    long long int low = 0, high = n - 1;
    while (low <= high)
    {
        long long int mid = (low + high) / 2;
        // cout << low << " " << high << " " << mid << endl;
        if (A[mid] >= l)
        {
            a = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    // cout<<a<<endl;
    long long int b = -1;
    low = 0, high = n - 1;
    while (low <= high)
    {
        long long int mid = (low + high) / 2;
        // cout << low << " " << high << " " << mid << endl;
        if (A[mid] <= r)
        {
            b = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    // cout<<b<<endl;
    return b - a + 1;
}

bool solve(long long int r, vector<long long int> &A, vector<long long int> &B)
{
    for (long long int i = 0; i < A.size(); i++)
    {
        long long int city = A[i];
        long long int towers = countInRange(A[i] - r, A[i] + r, B);
        if (towers > 0)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    long long int n, m;
    cin >> n >> m;
    vector<long long int> A(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    vector<long long int> B(m);
    for (long long int i = 0; i < m; i++)
    {
        cin >> B[i];
    }
    long long int ans;
    long long int l = 0, r = 1e10;
    while (l <= r)
    {
        long long int mid = (l + r) / 2;
        // cout << l << " " << r << " " << mid << endl;
        if (solve(mid, A, B))
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