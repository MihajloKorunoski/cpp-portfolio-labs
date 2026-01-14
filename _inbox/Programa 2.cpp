#include <iostream>
using namespace std;
class LS
{
public:
    int RecursiveLS(int arr[], int value, int index, int n)
    {
        int pos = 0;
        if(index >= n)
        {
            return 0;
        }
        if(arr[n-1] == value)
        {
            pos = n;
            return pos;
        }
        else if (arr[index] == value)
        {
            pos = index + 1;
            return pos;
        }
        else
        {
            return RecursiveLS(arr, value, index+1, n-1);
        }
        return pos;
    }
};
int main()
{
    LS l1;
    int n, value, pos, m = 0, arr[100];
    cout<<"Enter the total elements in the array  ";
    cin>>n;
    cout<<"Enter the array elements  ";
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the element to search  ";
    cin>>value;
    pos =  l1.RecursiveLS(arr, value, 0, n);
    if (pos != 0)
    {
        cout<<"Element found at pos  "<<pos;
    }
    else
    {
        cout<<"Element not found";
    }
    return 0;
}
