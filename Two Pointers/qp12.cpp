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
#define fr(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define frr(i, a, b) for (int(i) = (a); (i) >= (b); (i)--)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 1000000007

class Node
{
public:
    ll val;
    ll list;
    ll index;
    Node(ll val, ll list, ll index)
    {
        this->val = val;
        this->list = list;
        this->index = index;
    }
};

class compare
{
public:
    bool operator()(Node a, Node b) { return a.val > b.val; }
};

vector<long long int> smallestRange(vector<vector<long long int>> &nums)
{
    priority_queue<Node, vector<Node>, compare> pq;
    int k = nums.size();
    ll start = INT_MAX, end = INT_MIN;
    for (int i = 0; i < k; i++)
    {
        pq.push(Node(nums[i][0], i, 0));
        start = min((ll)start, nums[i][0]);
        end = max((ll)end, nums[i][0]);
    }
    ll mini = start, maxi = end;
    while (!pq.empty())
    {
        Node top = pq.top();
        pq.pop();
        if (top.index + 1 < nums[top.list].size())
        {
            pq.push(Node(nums[top.list][top.index + 1], top.list,
                         top.index + 1));
            mini = pq.top().val;
            maxi = max((ll)maxi, nums[top.list][top.index + 1]);
            if ((maxi - mini < end - start) ||
                (maxi - mini == end - start && mini < start))
            {
                start = mini;
                end = maxi;
            }
        }
        else
        {
            break;
        }
    }
    return {start, end};
}

int main()
{
    ll k;
    cin >> k;
    vector<vll> A(k);
    fr(i, 0, k)
    {
        ll n;
        cin >> n;
        fr(j, 0, n)
        {
            ll temp;
            cin >> temp;
            A[i].pb(temp);
        }
    }
    vll ans = smallestRange(A);
    cout << ans[0] << " " << ans[1] << endl;
}