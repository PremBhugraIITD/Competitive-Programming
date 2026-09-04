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
#define pll <pair<long long int, long long int>>
#define mll map<long long int, long long int>
#define mcl map<char, long long int>
#define fr(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define frr(i, a, b) for (int(i) = (a); (i) >= (b); (i)--)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 1000000007

void balance(multiset<int> &low, multiset<int> &high)
{
    if (low.size() < high.size())
    {
        low.insert(*high.begin());
        high.erase(high.find(*high.begin()));
    }
    else if (low.size() > high.size() + 1)
    {
        high.insert(*low.rbegin());
        low.erase(low.find(*low.rbegin()));
    }
}
vector<double> medianSlidingWindow(vector<long long int> &nums, int k)
{
    multiset<int> low, high;
    vector<double> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (low.empty() || (nums[i] < *low.rbegin()))
        {
            low.insert(nums[i]);
        }
        else
        {
            high.insert(nums[i]);
        }
        balance(low, high);
        if (i >= k)
        {
            if (nums[i - k] <= *low.rbegin())
            {
                low.erase(low.find(nums[i - k]));
            }
            else
            {
                high.erase(high.find(nums[i - k]));
            }
        }
        balance(low, high);
        if (i >= k - 1)
        {
            double median;
            if (k % 2 == 0)
            {
                median = ((double)*low.rbegin() + (double)*high.begin()) / 2.0;
            }
            else
            {
                median = *low.rbegin();
            }
            ans.push_back(median);
        }
    }
    return ans;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    vll A(n);
    fr(i, 0, n)
    {
        cin >> A[i];
    }
    vector<double> ans = medianSlidingWindow(A, k);
    fr(i, 0, ans.size())
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}