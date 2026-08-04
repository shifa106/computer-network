#include <iostream>
#include <string>
using namespace std;

int main()
{
    string data, result = "";
    int count = 0;

    cout << "Enter the stuffed data: ";
    cin >> data;

    for (int i = 0; i < data.length(); i++)
    {
        if (data[i] == '1')
        {
            count++;
            result = result + data[i];

            if (count == 5)
            {
                i++;        // Skip the stuffed 0
                count = 0;
            }
        }
        else
        {
            result = result + data[i];
            count = 0;
        }
    }

    cout << "Received Data : " << data << endl;
    cout << "Original Data : " << result << endl;

    return 0;
}
