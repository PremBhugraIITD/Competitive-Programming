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

int main()
{
    ll n, k;
    cin >> n >> k;
    vpll A(n);
    fr(i, 0, n)
    {
        cin >> A[i].second >> A[i].first;
    }
    sort(A);
    multiset<ll> people;
    fr(i, 0, k)
    {
        people.insert(0);
    }
    ll count = 0;
    fr(i, 0, n)
    {
        ll start = A[i].second, end = A[i].first;
        auto it = people.upper_bound(start);
        if (it != people.begin())
        {
            count++;
            --it;
            people.erase(it);
            people.insert(end);
        }
        else
        {
            continue;
        }
    }
    cout << count << endl;
}