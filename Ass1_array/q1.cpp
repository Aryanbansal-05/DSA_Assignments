#include <iostream>

using namespace std;

int arr[100], n = 0;

void create()
{
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void display()
{
    cout << "Array elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insert()
{
    int pos, val;
    cout << "Enter position and value: ";
    cin >> pos >> val;
    for (int i = n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    n++;
}

void deleteElement()
{
    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;
    for (int i = pos; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
}

void linearSearch()
{
    int key, found = 0;
    cout << "Enter element to search: ";
    cin >> key;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << "Found at index " << i << endl;
            found = 1;
            break;
        }
    }
    if (!found)
        cout << "Not Found" << endl;
}

int main()
{
    int choice;
    do
    {
        cout << "1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.SEARCH\n6.EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
            create();
        else if (choice == 2)
            display();
        else if (choice == 3)
            insert();
        else if (choice == 4)
            deleteElement();
        else if (choice == 5)
            linearSearch();
        else if (choice == 6)
            cout << "Exit";
        else
            cout << "Wrong choice";

    } while (choice != 6);
    return 0;
}
