#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iomanip>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define ll long long int
#define ld long double
#define vll vector<long long int>
#define vpll vector<pair<long long int, long long int>>
#define pll pair<long long int, long long int>
#define mll map<long long int, long long int>
#define fr(i, a, b) for (long long int(i) = (a); (i) < (b); (i)++)
#define frr(i, a, b) for (long long int(i) = (a); (i) >= (b); (i)--)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 1000000007

vector<int> findOriginalArray(vector<int> &changed)
{
    int n = changed.size();
    sort(changed);
    map<int, int> count;
    for (int i = 0; i < n; i++)
    {
        count[changed[i]]++;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        long long int small = changed[i];
        if (count[small])
        {
            count[small]--;
            if (count[2 * small])
            {
                count[2 * small]--;
                ans.push_back(small);
            }
            else
            {
                return {};
            }
        }
        else
        {
            continue;
        }
    }
    return ans;
}

int main()
{
    ll n;
    cin >> n;
    vector<int> A(n);
    fr(i, 0, n)
    {
        cin >> A[i];
    }
    vector<int> ans = findOriginalArray(A);
    fr(i, 0, ans.size())
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}