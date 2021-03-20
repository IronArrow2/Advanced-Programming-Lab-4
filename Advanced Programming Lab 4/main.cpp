#include <iostream>
#include <string>
#include <random>
#include <time.h>
using namespace std;

void reverseString(string& s, int beginning, int length)
{
    if (beginning > length / 2)
    {
        return;
    }
    else
    {
        swap(s[beginning], s[length - beginning]);
        reverseString(s, ++beginning, length);
    }
}

bool isPalindrome(string s)
{
    string temp = s;
    reverseString(temp, 0, temp.length() - 1);

    return temp == s;
}

template <class T>
int partition(T arr[], int low, int high)
{
    T pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

template <class T>
void quickSort(T arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    srand(time(NULL));
    bool exitloop = false;
    string input, output;
    while (!exitloop)
    {
        cout << "Welcome to the menu! Please enter a number between 1 and 4 to test the program!\n1: Reverse a string\n2: Sort an array of randomly-generated integers\n3: Test to see if a string is a palindrome\n4: Exit the program\n";
        cin >> input;

        if (stoi(input) == 1)
        {
            cout << "Enter a string to reverse!\n";
            cin >> input;
            output = input;
            reverseString(output, 0, output.length() - 1);
            cout << input << " reversed is " << output << endl;
        }
        else if (stoi(input) == 2)
        {
            cout << "How many numbers to generate?\n";
            cin >> input;
            int num = stoi(input);
            int* randomNumbers = new int[num];

            for (int i = 0; i < num; i++)
            {
                randomNumbers[i] = rand() % 100 + 1;
            }

            cout << "Unsorted random numbers: \n";
            for (int i = 0; i < num; i++)
            {
                cout << randomNumbers[i] << ", ";
            }
            cout << endl;

            quickSort(randomNumbers, 0, --num);

            num++;
            cout << "Sorted random numbers: \n";
            for (int i = 0; i < num; i++)
            {
                cout << randomNumbers[i] << ", ";
            }
            cout << endl;
        }
        else if (stoi(input) == 3)
        {
            cout << "Enter a string and the program will tell you if it's a palindrome or not!\n";
            cin >> input;
            bool palindromeCheckResult = isPalindrome(input);
            if(palindromeCheckResult)
            {
                cout << input << " is a palindrome!" << endl;
            }
            else if(!palindromeCheckResult)
            {
                cout << input << " is not a palindrome!" << endl;
            }
        }
        else if (stoi(input) == 4)
        {
            exitloop = true;
        }
        else
        {
            cout << "Please enter a number between 1 and 4\n";
        }
    }
    return 0;
}