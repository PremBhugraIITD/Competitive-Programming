#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iomanip>
#include <stack>
#include <queue>
#include <map>
using namespace std;

#define ll long long int
#define ld long double
#define vll vector<long long int>
#define vpll vector<pair<long long int, long long int>>
#define pll <pair<long long int, long long int>>
#define mll map<long long int, long long int>
#define mcl map<char, long long int>
#define fr(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 1000000007

int main()
{
    ll n, k;
    cin >> n >> k;
    vll A(n);
    fr(i, 0, n)
    {
        cin >> A[i];
    }
    mll count;
    ll i = 0;
    while (i < k)
    {
        count[A[i]]++;
        i++;
    }
    ll maxi = count.size();
    ll size = count.size();
    ll index = 0;
    while (i < n)
    {
        ll incoming = A[i];
        ll outgoing = A[i - k];
        count[outgoing]--;
        if (count[outgoing] == 0)
        {
            count.erase(outgoing);
        }
        count[incoming]++;
        size = count.size();
        if (size > maxi)
        {
            maxi = size;
            index = i - k + 1;
        }
        i++;
    }
    fr(j, 0, k)
    {
        cout << A[index + j] << " ";
    }
    cout << endl;
}