#include <iostream>
#include <string>
using namespace std;

int main()
{
    string data;
    int m, r = 0;

    cout << "Enter data bits: ";
    cin >> data;

    m = data.length();

    // Calculate number of redundant bits
    while ((1 << r) < (m + r + 1))
        r++;

    int n = m + r;

    cout << "\nData Word: " << data;
    cout << "\nNo. of Redundant Bits: " << r;
    cout << "\nTotal No. of Bits in Codeword: " << n << endl;

    // Hamming code positions
    int code[20] = {0};

    // Place data bits from right to left
    // Positions 1,2,4,8 are reserved for parity
    int j = m - 1;

    for (int pos = 1; pos <= n; pos++)
    {
        if (pos == 1 || pos == 2 || pos == 4 || pos == 8)
        {
            code[pos] = 0;
        }
        else
        {
            code[pos] = data[j] - '0';
            j--;
        }
    }

    cout << "\n----------------------------------";
    cout << "\nCalculating Redundant Bits";
    cout << "\n----------------------------------";

    // R1
    int count = 0;

    for (int pos = 1; pos <= n; pos++)
    {
        if (pos & 1)
        {
            if (pos != 1)
                count += code[pos];
        }
    }

    code[1] = count % 2;

    cout << "\n\n1) R1";
    cout << "\nConsider R1, D3, D5, D7, D9, D11";
    cout << "\nD3 D5 D7 D9 D11 = ";

    for (int pos : {3, 5, 7, 9, 11})
        cout << code[pos];

    cout << "\nSet R1 = " << code[1];

    // R2
    count = 0;

    for (int pos = 1; pos <= n; pos++)
    {
        if ((pos & 2) && pos != 2)
            count += code[pos];
    }

    code[2] = count % 2;

    cout << "\n\n2) R2";
    cout << "\nConsider R2, D3, D6, D7, D10, D11";
    cout << "\nD3 D6 D7 D10 D11 = ";

    for (int pos : {3, 6, 7, 10, 11})
        cout << code[pos];

    cout << "\nSet R2 = " << code[2];

    // R4
    count = 0;

    for (int pos = 1; pos <= n; pos++)
    {
        if ((pos & 4) && pos != 4)
            count += code[pos];
    }

    code[4] = count % 2;

    cout << "\n\n3) R4";
    cout << "\nConsider R4, D5, D6, D7";
    cout << "\nD5 D6 D7 = ";

    for (int pos : {5, 6, 7})
        cout << code[pos];

    cout << "\nSet R4 = " << code[4];

    // R8
    count = 0;

    for (int pos = 1; pos <= n; pos++)
    {
        if ((pos & 8) && pos != 8)
            count += code[pos];
    }

    code[8] = count % 2;

    cout << "\n\n4) R8";
    cout << "\nConsider R8, D9, D10, D11";
    cout << "\nD9 D10 D11 = ";

    for (int pos : {9, 10, 11})
        cout << code[pos];

    cout << "\nSet R8 = " << code[8];

    // Final codeword
    cout << "\n\n----------------------------------";
    cout << "\nFinal Codeword / Codeword Transmitted:";
    cout << "\n----------------------------------\n";

    for (int pos = n; pos >= 1; pos--)
        cout << code[pos];

    cout << endl;

    return 0;
}