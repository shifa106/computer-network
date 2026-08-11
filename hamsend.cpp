#include <iostream>
#include <string>
using namespace std;

int main()
{
    string data;
    
    cout << "Enter data bits: ";
    cin >> data;

    int m = data.length();
    int r = 0;

    // Calculate number of redundant bits
    while ((1 << r) < (m + r + 1))
        r++;

    int n = m + r;

    cout << "\nData Word: " << data;
    cout << "\nNumber of Data Bits: " << m;
    cout << "\nNumber of Redundant Bits: " << r;
    cout << "\nTotal Number of Bits in Codeword: " << n;

    // Array for Hamming code
    // Position 1 is the RIGHTMOST bit
    int bit[100] = {0};

    // ------------------------------------------------
    // Place data bits
    // Parity positions = 1, 2, 4, 8, 16, ...
    // Data is placed from RIGHT to LEFT
    // ------------------------------------------------

    int j = m - 1;

    for (int pos = 1; pos <= n; pos++)
    {
        // Check whether position is power of 2
        if ((pos & (pos - 1)) == 0)
        {
            bit[pos] = 0;       // Redundant bit
        }
        else
        {
            bit[pos] = data[j] - '0';
            j--;
        }
    }

    cout << "\n\n----------------------------------------";
    cout << "\nCalculating Redundant Bits";
    cout << "\n----------------------------------------";

    // ------------------------------------------------
    // Calculate redundant bits using EVEN PARITY
    // ------------------------------------------------

    for (int p = 1; p <= n; p = p * 2)
    {
        int parity = 0;

        cout << "\n\nR" << p << " - Analyze bits at: ";

        for (int pos = 1; pos <= n; pos++)
        {
            if (pos & p)
            {
                cout << pos << " ";

                // Don't include R itself while calculating
                if (pos != p)
                    parity = parity ^ bit[pos];
            }
        }

        bit[p] = parity;

        cout << "\nBits excluding R" << p << ": ";

        for (int pos = 1; pos <= n; pos++)
        {
            if ((pos & p) && pos != p)
                cout << bit[pos];
        }

        cout << "\nSet R" << p << " = " << bit[p];
    }

    // ------------------------------------------------
    // Display final codeword
    // ------------------------------------------------

    cout << "\n\n----------------------------------------";
    cout << "\nFinal Codeword / Codeword Transmitted";
    cout << "\n----------------------------------------";

    cout << "\n";

    for (int pos = n; pos >= 1; pos--)
    {
        cout << bit[pos];
    }

    cout << endl;

    return 0;
}
//Output:
//Enter data bits: 1011   


//Number of Data Bits: 4
//Number of Redundant Bits: 3
//Total Number of Bits in Codeword: 7

//----------------------------------------
//Calculating Redundant Bits
//----------------------------------------

//R1 - Analyze bits at: 1 3 5 7 
//Bits excluding R1: 111
//Set R1 = 1

//R2 - Analyze bits at: 2 3 6 7 
//Bits excluding R2: 101
//Set R2 = 0

//R4 - Analyze bits at: 4 5 6 7 
//Bits excluding R4: 101
//Set R4 = 0

//----------------------------------------
//Final Codeword / Codeword Transmitted
//----------------------------------------
//1010101
