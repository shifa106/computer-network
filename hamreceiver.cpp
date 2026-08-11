#include <iostream>
#include <string>
using namespace std;

int main()
{
    string code;

    cout << "Enter received Hamming codeword: ";
    cin >> code;

    int n = code.length();

    // Find number of redundant bits
    int r = 0;

    while ((1 << r) < (n + 1))
        r++;

    // Store bits according to Hamming positions
    // Position 1 is the RIGHTMOST bit
    int bit[100];

    for (int pos = 1; pos <= n; pos++)
    {
        bit[pos] = code[n - pos] - '0';
    }

    cout << "\nNumber of bits in received codeword = " << n;
    cout << "\nNumber of redundant bits = " << r;

    cout << "\n\n--------------------------------";
    cout << "\nAnalyzing Redundant Bits";
    cout << "\n--------------------------------";

    int syndrome = 0;

    // Check every redundant bit
    for (int p = 1; p <= n; p = p * 2)
    {
        int parity = 0;

        // Check all positions covered by this parity bit
        for (int pos = 1; pos <= n; pos++)
        {
            if (pos & p)
            {
                parity = parity ^ bit[pos];
            }
        }

        cout << "\n\nR" << p << " - Analyze bits at: ";

        for (int pos = 1; pos <= n; pos++)
        {
            if (pos & p)
                cout << pos << " ";
        }

        cout << "\nParity value = " << parity;

        // If parity is 1, this parity check has failed
        if (parity == 1)
            syndrome = syndrome + p;
    }

    // Display syndrome
    cout << "\n\n--------------------------------";
    cout << "\nSyndrome = ";

    // Display from highest redundant bit to lowest
    for (int p = 1; p < (1 << r); p = p * 2)
    {
        // Store nothing; syndrome will be printed below
    }

    for (int p = (1 << (r - 1)); p >= 1; p = p / 2)
    {
        cout << ((syndrome & p) ? 1 : 0);
    }

    cout << "\nDecimal equivalent = " << syndrome;

    // Check error
    if (syndrome == 0)
    {
        cout << "\n\nNo error detected.";
        cout << "\nReceived codeword is CORRECT.";
    }
    else if (syndrome > n)
    {
        cout << "\n\nError position is outside the codeword.";
        cout << "\nMore than one error may be present.";
    }
    else
    {
        cout << "\n\nError is located at "
             << syndrome << "th position.";

        // Correct the error
        bit[syndrome] = bit[syndrome] ^ 1;

        // Create corrected codeword
        string corrected = "";

        for (int pos = n; pos >= 1; pos--)
        {
            corrected += char(bit[pos] + '0');
        }

        cout << "\nCorrected codeword is: "
             << corrected;
    }

    cout << endl;

    return 0;
}