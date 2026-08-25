#include <iostream>
#include <string>
using namespace std;

int main()
{
    string codeword, divisor;

    cout << "Enter the received code word: ";
    cin >> codeword;

    cout << "Enter the divisor: ";
    cin >> divisor;

    // Check that divisor is valid
    if (divisor.length() < 2)
    {
        cout << "Invalid divisor!" << endl;
        return 0;
    }

    if (codeword.length() < divisor.length())
    {
        cout << "Code word must be longer than or equal to divisor." << endl;
        return 0;
    }

    // Check that input contains only 0 and 1
    for (char bit : codeword)
    {
        if (bit != '0' && bit != '1')
        {
            cout << "Invalid code word! Enter only 0 and 1." << endl;
            return 0;
        }
    }

    for (char bit : divisor)
    {
        if (bit != '0' && bit != '1')
        {
            cout << "Invalid divisor! Enter only 0 and 1." << endl;
            return 0;
        }
    }

    // Copy received codeword for division
    string remainder = codeword;

    // Modulo-2 division
    for (int i = 0; i <= (int)codeword.length() - (int)divisor.length(); i++)
    {
        if (remainder[i] == '1')
        {
            for (int j = 0; j < (int)divisor.length(); j++)
            {
                // XOR operation
                remainder[i + j] =
                    (remainder[i + j] == divisor[j]) ? '0' : '1';
            }
        }
    }

    // Extract remainder
    int remainderLength = divisor.length() - 1;

    string crc = remainder.substr(
        remainder.length() - remainderLength
    );

    cout << "\nReceived code word: " << codeword << endl;
    cout << "Divisor: " << divisor << endl;
    cout << "Remainder: " << crc << endl;

    // Check remainder
    bool error = false;

    for (char bit : crc)
    {
        if (bit == '1')
        {
            error = true;
            break;
        }
    }

    if (error)
        cout << "Error detected!" << endl;
    else
        cout << "No error detected!" << endl;

    return 0;
}

//Output:
/*Enter the received code word: 11010110111110
Enter the divisor: 10011

Received code word: 11010110111110
Divisor: 10011
Remainder: 0000
No error detected!*/

