#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool solve(long long int t, vector<long long int> K, long long int time)
{
    long long int n = K.size();
    for (long long int i = 0; i < n; i++)
    {
        long long int currMachine = K[i];
        if (currMachine > time)
        {
            return false;
        }
        else
        {
            long long int built = time / currMachine;
            t -= built;
            if (t <= 0)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    long long int n, t;
    cin >> n >> t;
    vector<long long int> K(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> K[i];
    }
    sort(K.begin(), K.end());
    long long int ans;
    long long int l = 0, r = t * K[n - 1];
    while (l <= r)
    {
        long long int mid = l + (r - l) / 2;
        if (solve(t, K, mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            // cout<<"here"<<endl;
            l = mid + 1;
        }
    }
    cout << ans << endl;
}