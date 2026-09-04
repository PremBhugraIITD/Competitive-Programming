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
#define mcl map<char, long long int>
#define fr(i, a, b) for (long long int(i) = (a); (i) < (b); (i)++)
#define frr(i, a, b) for (long long int(i) = (a); (i) >= (b); (i)--)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 1000000007

bool canJump(vector<int> &nums)
{
    int n = nums.size();
    int maxi = 0;
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, i + nums[i]);
        if (i < n - 1)
        {
            if (maxi >= i + 1)
            {
                continue;
            }
            else
            {
                found = true;
                break;
            }
        }
    }
    if (found)
    {
        return false;
    }
    else
    {
        return true;
    }
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
    cout << canJump(A) << endl;
}