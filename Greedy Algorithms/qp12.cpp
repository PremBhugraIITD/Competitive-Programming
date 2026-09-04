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
    string s;
    cin >> s;
    string target = "hello";
    ll i = 0, j = 0;
    while (i < s.length())
    {
        if (j < 5 && s[i] == target[j])
        {
            j++;
        }
        i++;
    }
    if (j == 5)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}