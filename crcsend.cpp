#include <iostream>
#include <string>
using namespace std;

int main()
{
    string data, divisor;

    cout << "Enter the code word: ";
    cin >> data;

    cout << "Enter the divisor: ";
    cin >> divisor;

    int extraBits = divisor.length() - 1;

    // Append (divisor length - 1) zeros
    string dividend = data;
    for (int i = 0; i < extraBits; i++)
        dividend += '0';

    cout << "\nExtra bits added: " << extraBits << endl;
    cout << "After adding zeros: " << dividend << endl;

    // Modulo-2 division
    string remainder = dividend;

    for (int i = 0; i <= dividend.length() - divisor.length(); i++)
    {
        if (remainder[i] == '1')
        {
            for (int j = 0; j < divisor.length(); j++)
            {
                // XOR operation
                if (remainder[i + j] == divisor[j])
                    remainder[i + j] = '0';
                else
                    remainder[i + j] = '1';
            }
        }
    }

    // Last (divisor length - 1) bits are the CRC remainder
    string crc = remainder.substr(remainder.length() - extraBits);

    cout << "CRC: " << crc << endl;

    // Final transmitted codeword
    string codeword = data + crc;

    cout << "Transmitted code word: " << codeword << endl;

    return 0;
}