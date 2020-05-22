#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList linkedList;
    linkedList.Add(3);
    linkedList.Add(3);
    linkedList.Add(2);
    linkedList.Add(8);
    linkedList.Add(4);
    linkedList.Add(13);
    linkedList.Add(1);

    for (auto i = 0; i < linkedList.Count; i++)
        cout << linkedList[i] << endl;
    cout << "Second from the end: " << endl << linkedList.SearchFromEnd(2) << endl;
    cout << endl;
    linkedList.RemoveDuplicates();
    cout << "Without dublicates:" << endl;
    for (auto i = 0; i < linkedList.Count; i++)
        cout << linkedList[i] << endl;
    cout << "Third from the end: " << endl << linkedList.SearchFromEnd(3);
	return 0;
}
