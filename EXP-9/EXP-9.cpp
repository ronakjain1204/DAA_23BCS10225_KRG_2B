#include <iostream>
#include <string>
using namespace std;

void rabinKarp(string text, string pattern, int q)
{
    int d = 256; // Number of characters in input alphabet
    int n = text.length();
    int m = pattern.length();
    int p = 0; // Hash value for pattern
    int t = 0; // Hash value for text
    int h = 1;

    // The value of h would be pow(d, m-1) % q
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate hash value for pattern and first window of text
    for (int i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text one by one
    for (int i = 0; i <= n - m; i++)
    {
        // If hash values match, check characters one by one
        if (p == t)
        {
            bool match = true;
            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
                cout << "Pattern found at index " << i << endl;
        }

        // Calculate hash value for next window of text
        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}

int main()
{
    string text = "ABCCDDAEFG";
    string pattern = "CDD";
    int q = 101; // A prime number
    rabinKarp(text, pattern, q);
    return 0;
}