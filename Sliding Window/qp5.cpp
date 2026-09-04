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
#define frr(i, a, b) for (int(i) = (a); (i) >= (b); (i)--)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 1000000007

bool checkInclusion(string s1, string s2)
{
    long long int n = s1.length();
    long long int m = s2.length();
    if (n > m)
    {
        return false;
    }
    else
    {
        vector<int> count1(26, 0);
        vector<int> count2(26, 0);
        for (int i = 0; i < n; i++)
        {
            count1[s1[i] - 'a']++;
        }
        for (int i = 0; i < m; i++)
        {
            count2[s2[i] - 'a']++;
            if (i >= n)
            {
                count2[s2[i - n] - 'a']--;
            }
            if (i >= n - 1 && count1 == count2)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << checkInclusion(s1, s2) << endl;
}