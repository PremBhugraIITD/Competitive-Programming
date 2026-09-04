#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main()
{
    long long int x = 1e7;
    vector<int> spf(x + 1, INT_MAX);
    vector<int> isPrime(x + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (long long int i = 2; i <= x; i++)
    {
        if (isPrime[i])
        {
            spf[i] = i;
            for (long long int j = i * i; j <= x; j += i)
            {
                isPrime[j] = 0;
                spf[j] = min((int)i, spf[j]);
            }
        }
    }
    vector<int> primesA(x + 1, 0), primesB(x + 1, 0);
    int n, m;
    cin >> n >> m;
    vector<int> A(n), B(m);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        int temp = A[i];
        while (temp > 1)
        {
            int p = spf[temp];
            while (temp % p == 0)
            {
                primesA[p]++;
                temp /= p;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> B[i];
        int temp = B[i];
        while (temp > 1)
        {
            int p = spf[temp];
            while (temp % p == 0)
            {
                primesB[p]++;
                temp /= p;
            }
        }
    }
    for (int i = 0; i < x + 1; i++)
    {
        primesA[i] = min(primesA[i], primesB[i]);
        primesB[i] = primesA[i];
    }
    for (int i = 0; i < n; i++)
    {
        int temp = A[i];
        while (temp > 1)
        {
            int p = spf[temp];
            while (temp % p == 0)
            {
                if (primesA[p])
                {
                    A[i] /= p;
                    primesA[p]--;
                }
                temp /= p;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        int temp = B[i];
        while (temp > 1)
        {
            int p = spf[temp];
            while (temp % p == 0)
            {
                if (primesB[p])
                {
                    B[i] /= p;
                    primesB[p]--;
                }
                temp /= p;
            }
        }
    }
    cout << n << " " << m << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        cout << B[i] << " ";
    }
    cout << endl;
}