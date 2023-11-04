#include <iostream>
#include <vector>
using namespace std;
void merge(int arr[], int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    vector<int> temp;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {

            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}
void partition(int arr[], int low, int high)
{

    if (low <= high)
    {

        int mid = (low + high) / 2;
        partition(arr, low, mid);
        partition(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main(int argc, char const *argv[])
{

    int a = 2;
    int b = 3;
    int c = 4;

    cout << a + b << endl;
    cout << "working" << endl;

    int temp[] = {1, 3, 5, 6, 8, 1, 2, 4};
    int siz = sizeof(temp) / sizeof(int);
    partition(temp, 0, siz - 1);

    for (int i = 0; i < siz; i++)
    {

        cout << temp[i] << endl;
    }

    return 0;
}
