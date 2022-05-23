#include <iostream>
#include <string.h>
using namespace std;
class HashFunction
{
    typedef struct hash // structure is user defines data type  using typedef we can give name to that structure
    {
        long key;      // as telephone no.
        char name[10]; // for clint name
    } hash;            // new name of the structure
    hash h[10];

public:
    HashFunction(); // constructur (defining class)
    void insert();
    void display();
    int find(long);
    void Delete(long);
};
HashFunction::HashFunction() // :: use to access member of calss outside the class
{
    int i;
    for (i = 0; i < 10; i++)
    {
        h[i].key = -1;
        strcpy(h[i].name, "NULL");
    }
}
void HashFunction::Delete(long k)
{
    int index = find(k);
    if (index == -1)
    {
        cout << "\n\tKey Not Found";
    }
    else // else means we found the number now we have to delete it
    {
        h[index].key = -1;             // make index of key as -1
        strcpy(h[index].name, "NULL"); // replacing null with the value to b deleted , so the value get deleted
        cout << "\n\tKey is Deleted";
    }
}
void HashFunction::display()
{
    int i;
    cout << "\n\t\tKey\t\tName";
    for (i = 0; i < 10; i++)
    {
        cout << "\n\th[" << i << "]\t" << h[i].key << "\t\t" << h[i].name;
    }
}
int HashFunction::find(long k)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        if (h[i].key == k)
        {
            cout << "\n\t" << h[i].key << " is Found at " << i << " Location With Name " << h[i].name;
            return i;
        }
    }
    if (i == 10) // means key not found
    {
        return -1;
    }
}

void HashFunction::insert()
{
    char ans, n[10], ntemp[10];
    long k, temp;
    int v, hi, cnt = 0, flag = 0, i;
    do
    {
        if (cnt = 10)
        // if (cnt >= 10)
        {
            cout << "\n\tHash Table is FULL";
            break;
        }
        cout << "\n\tEnter a Telephone No: ";
        cin >> k;
        cout << "\n\tEnter a Client Name: ";
        cin >> n;
        hi = k % 10;         // hash function
        if (h[hi].key == -1) // to check weather there already exist an element or not (-1 means no element present , as -1 is given by coder)
        {
            h[hi].key = k;
            strcpy(h[hi].name, n);
        }
        else // if any key is present at that location
        {
            if (h[hi].key % 10 != hi) // to check weather the value present is true or not(not current position)
            {
                temp = h[hi].key;  // if not then copy that value in temperory location
                strcpy(ntemp, h[hi].name);  // copy that name in temp location
                h[hi].key = k; // store new key at that empty location
                strcpy(h[hi].name, n); // store new name at that empty locaton
                for (i = hi + 1; i < 10; i++) // now the time comes to store that temperory values in next empty location
                {        // hi + 1 coz we need to find empty space after that location
                    if (h[i].key == -1)  // here we find the empty space for temp data
                    {
                        h[i].key = temp;
                        strcpy(h[i].name, ntemp);
                        flag = 1;
                        break;
                    }
                }
                for (i = 0; i < hi && flag == 0; i++) // if didnt get empty space then to start again from 0 this loop is defined
                {
                    if (h[i].key == -1)
                    {
                        h[i].key = temp;
                        strcpy(h[i].name, ntemp);
                        break;
                    }
                }
            }
            else  // when the value is at correct location no need of replacement
            {
                for (i = hi + 1; i < 10; i++)  // this loop is for searching the empty location after the ggiven value address
                {
                    if (h[i].key == -1)
                    {
                        h[i].key = k;
                        strcpy(h[i].name, n);
                        flag = 1;
                        break;
                    }
                }
                for (i = 0; i < hi && flag == 0; i++)  // this is for again starting from 0 if not found below
                {
                    if (h[i].key == -1)
                    {
                        h[i].key = k;
                        strcpy(h[i].name, n);
                        break;
                    }
                }
            }
        }
        flag = 0;
        cnt++;
        cout << "\n\t..... Do You Want to Insert More Key: y/n";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
}
int main()
{
    long k;
    int ch, index;
    char ans;
    HashFunction obj;
    do
    {
        cout << "\n\t*** Telephone (ADT) *****";
        cout << "\n\t1. Insert\n\t2. Display\n\t3. Find\n\t4. Delete\n\t5. Exit";
        cout << "\n\t..... Enter Your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            obj.insert();
            break;
        case 2:
            obj.display();
            break;
        case 3:
            cout << "\n\tEnter a Key Which You Want to Search: ";
            cin >> k;
            index = obj.find(k);
            if (index == -1)
            {
                cout << "\n\tKey Not Found";
            }
            break;
        case 4:
            cout << "\n\tEnter a Key Which You Want to Delete: ";
            cin >> k;
            obj.Delete(k);
            break;
        case 5:
            break;
        }
        cout << "\n\t..... Do You Want to Continue in Main Menu:y/n ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
}