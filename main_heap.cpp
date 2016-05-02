#include <iostream>
#include "Heap.h"

int main()
{
    //Maxheap
    Heap<int, Lower<int> > maxHeap = Heap<int, Lower<int> >(100);

    maxHeap.insert(23);
    maxHeap.insert(47);
    maxHeap.insert(6);
    maxHeap.insert(1);
    maxHeap.insert(5);
    maxHeap.insert(10);
    maxHeap.insert(33);
    maxHeap.insert(3);
    maxHeap.insert(89);

    cout << "Elementele din MaxHeap sunt:\n";

    maxHeap.print();

    cout << "Elementele in ordine descrescatoare sunt:\n";
    cout << maxHeap.Peek() << "\n";
    maxHeap.Pop();

    while (!maxHeap.IsEmpty())
        cout << maxHeap.Pop() << "\n";

    cout << "\n";

    //Minheap
    Heap<int, Greater<int> > minHeap = Heap<int, Greater<int> >(100);

    minHeap.insert(23);
    minHeap.insert(47);
    minHeap.insert(6);
    minHeap.insert(1);
    minHeap.insert(5);
    minHeap.insert(10);
    minHeap.insert(33);
    minHeap.insert(3);
    minHeap.insert(89);

    cout << "Elementele din MinHeap sunt:\n";

    minHeap.print();

    cout << "Elementele in ordine crescatoare sunt:\n";
    cout << minHeap.Peek() << "\n";
    minHeap.Pop();

    while (!minHeap.IsEmpty())
        cout << minHeap.Pop() << "\n";

    return 0;
}
