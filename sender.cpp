#include <iostream>
#include <string>
using namespace std;

int main()
{
    string data, result = "";
    int count = 0;

    cout << "Enter the binary data: ";
    cin >> data;

    for (int i = 0; i < data.length(); i++)
    {
        result = result + data[i];

        if (data[i] == '1')
        {
            count++;
            if (count == 5)
            {
                result = result + '0';
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }
    cout<<"Original Data:"<<data<<endl;
    cout<<"Stuffed Data:"<<result<<endl;
}