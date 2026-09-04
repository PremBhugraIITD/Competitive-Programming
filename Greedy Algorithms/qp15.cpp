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

bool isPalindrome(string &s)
{
    ll l = 0, r = s.length() - 1;
    while (l < r)
    {
        if (s[l] == s[r])
        {
            l++, r--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        bool found = false;
        vector<string> A;
        fr(i, 0, n)
        {
            string s;
            cin >> s;
            if (s.length() == 1)
            {
                found = true;
            }
            else if (isPalindrome(s))
            {
                found = true;
            }
            else
            {
                A.pb(s);
            }
        }
        if (found)
        {
            cout << "YES" << endl;
        }
        else
        {
            n = A.size();
            set<string> st;
            // 2-2
            fr(i, 0, n)
            {
                if (A[i].length() == 2)
                {
                    string curr = A[i];
                    reverse(curr);
                    if (st.find(curr) != st.end())
                    {
                        found = true;
                        // cout << 3 << endl;
                        break;
                    }
                    else
                    {
                        reverse(curr);
                        st.insert(curr);
                    }
                }
            }
            st.clear();
            // 3-3
            fr(i, 0, n)
            {
                if (A[i].length() == 3)
                {
                    string curr = A[i];
                    reverse(curr);
                    if (st.find(curr) != st.end())
                    {
                        found = true;
                        // cout << 4 << endl;
                        break;
                    }
                    else
                    {
                        reverse(curr);
                        st.insert(curr);
                    }
                }
            }
            st.clear();
            // 2-3
            fr(i, 0, n)
            {
                if (A[i].length() == 3)
                {
                    string curr;
                    curr.pb(A[i][2]);
                    curr.pb(A[i][1]);
                    if (st.find(curr) != st.end())
                    {
                        found = true;
                        // cout << 5 << endl;
                        break;
                    }
                }
                else
                {
                    st.insert(A[i]);
                }
            }
            st.clear();
            // 3-2
            frr(i, n - 1, 0)
            {
                if (A[i].length() == 3)
                {
                    string curr;
                    curr.pb(A[i][1]);
                    curr.pb(A[i][0]);
                    if (st.find(curr) != st.end())
                    {
                        found = true;
                        // cout << 5 << endl;
                        break;
                    }
                }
                else
                {
                    st.insert(A[i]);
                }
            }
            if (found)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
}