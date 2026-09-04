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
    ll n, w;
    cin >> n >> w;
    vector<vector<ld>> A(n, vector<ld>(3));
    fr(i, 0, n)
    {
        ld value, weight;
        cin >> value >> weight;
        ld vpw = value / weight;
        A[i][0] = vpw;
        A[i][1] = value;
        A[i][2] = weight;
    }
    sort(A);
    reverse(A);
    ld ans = 0;
    fr(i, 0, n)
    {
        ld vpw = A[i][0], value = A[i][1], weight = A[i][2];
        if (w - weight >= 0)
        {
            w -= weight;
            ans += value;
        }
        else
        {
            ans += w * vpw;
            break;
        }
    }
    cout << ans << endl;
}