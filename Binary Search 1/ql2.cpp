#include <iostream>
#include <vector>
using namespace std;

bool solve(long long int limit, long long int k, vector<long long int> A)
{
    long long int sum = 0;
    long long int i = 0;
    for (; i < A.size(); i++)
    {
        if (A[i] > limit)
        {
            return false;
        }
        if (sum + A[i] > limit)
        {
            sum = 0;
            i--;
            k--;
            if (k == 0)
            {
                break;
            }
        }
        else
        {
            sum += A[i];
        }
    }
    if (i == A.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

long long int getmMinMaxWorkload(long long int limit, vector<long long int> A)
{
    long long int sum = 0;
    long long int maxi = 0;
    for (long long int i = 0; i < A.size(); i++)
    {
        if (sum + A[i] > limit)
        {
            maxi = max(maxi, sum);
            sum = 0;
            i--;
        }
        else
        {
            sum += A[i];
        }
    }
    maxi = max(maxi, sum);
    return maxi;
}

int main()
{
    long long int n;
    cin >> n;
    long long int k;
    cin >> k;
    vector<long long int> A(n);
    long long int l = 0, r = 0;
    for (long long int i = 0; i < n; i++)
    {
        cin >> A[i];
        r += A[i];
    }
    long long int ans;
    while (l <= r)
    {
        long long int mid = (l + r) / 2;
        if (solve(mid, k, A))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    ans = getmMinMaxWorkload(ans, A);
    cout << ans << endl;
}