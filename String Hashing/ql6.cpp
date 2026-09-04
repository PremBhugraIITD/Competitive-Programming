#include <iostream>
#include <vector>
using namespace std;
using ull = unsigned long long;

int binpow(ull a, int b, int m)
{
    ull ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

class Hash
{
public:
    const int m1 = 1000000007;
    const int p1 = 131;
    vector<int> pow1, inv_pow1, prefixHash1;
    Hash(const string &s)
    {
        int n = (int)s.length();
        pow1.assign(n, 1);
        inv_pow1.assign(n, 1);
        prefixHash1.assign(n, 0);
        prefixHash1[0] = s[0] - 'a' + 1;
        int inv_p1 = binpow(p1, m1 - 2, m1);
        for (int i = 1; i < n; i++)
        {
            pow1[i] = (int)(((ull)pow1[i - 1] * p1) % m1);
            inv_pow1[i] = (int)(((ull)inv_pow1[i - 1] * inv_p1) % m1);
            prefixHash1[i] = (int)(((prefixHash1[i - 1] + ((s[i] - 'a' + 1) * (ull)pow1[i]) % m1) % m1));
        }
    }

    inline int getHash(int l, int r) const
    {
        ull first = (ull)prefixHash1[r];
        first += m1;
        first -= l > 0 ? prefixHash1[l - 1] : 0;
        return (int)(((first % m1) * inv_pow1[l]) % m1);
    }
};

inline int compare(int a, int b, const Hash &H, const string &s, int n)
{
    // cout << a << " " << b << endl;
    int l = 0, r = n - 1;
    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (H.getHash(a, a + mid) != H.getHash(b, b + mid))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    // cout << ans << endl;
    return (s[a + ans] <= s[b + ans] ? a : b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.length();
    s += s;
    Hash H(s);
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        int curr = i;
        int start_ = start + n - 1, curr_ = curr + n - 1;
        int ans = H.getHash(start, start_) == H.getHash(curr, curr_) ? start : compare(start, curr, H, s, n);
        if (ans != start)
            start = curr;
    }
    cout << s.substr(start, n) << '\n';
    return 0;
}