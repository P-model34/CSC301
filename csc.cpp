#include  <iostream>
#include <algorithm> // for sort()
using namespace std;

// Function for Linear Search
int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Function for Binary Search (array must be sorted)
int binarySearch(int arr[], int size, int key)
{
    int low = 0, high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    int scores[20]; // extra space for insert
    int size = 10;
    int sum = 0;

    cout << "Enter 10 student scores:\n";
    for (int i = 0; i < 10; i++)
    {
        cin >> scores[i];
        sum += scores[i];
    }

    // 1. Traverse and compute the average
    cout << "\nStudent Scores: ";
    for (int i = 0; i < size; i++)
    {
        cout << scores[i] << " ";
    }

    double average = (double)sum / size;
    cout << "\nAverage Score: " << average << endl;

    // 2. Insert a new score at the 5th position
    int newScore;
    cout << "\nEnter a new score to insert at 5th position: ";
    cin >> newScore;

    for (int i = size; i >= 4; i--)
    {
        scores[i] = scores[i - 1];
    }
    scores[4] = newScore;
    size++;

    cout << "\nScores after inserting at 5th position: ";
    for (int i = 0; i < size; i++)
    {
        cout << scores[i] << " ";
    }

    // 3. Delete the lowest score
    int minIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (scores[i] < scores[minIndex])
            minIndex = i;
    }

    for (int i = minIndex; i < size - 1; i++)
    {
        scores[i] = scores[i + 1];
    }
    size--;

    cout << "\n\nScores after deleting lowest score: ";
    for (int i = 0; i < size; i++)
    {
        cout << scores[i] << " ";
    }

    // 4. Linear and Binary Search
    int searchKey;
    cout << "\n\nEnter a score to search: ";
    cin >> searchKey;

    // Linear Search
    int linearResult = linearSearch(scores, size, searchKey);
    if (linearResult != -1)
        cout << "Linear Search: Score found at index " << linearResult << endl;
    else
        cout << "Linear Search: Score not found.\n";

    // Binary Search (must sort first)
    sort(scores, scores + size);

    int binaryResult = binarySearch(scores, size, searchKey);
    if (binaryResult != -1)
        cout << "Binary Search: Score found at index " << binaryResult << endl;
    else
        cout << "Binary Search: Score not found.\n";

    return 0;
}