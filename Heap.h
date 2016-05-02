#ifndef Heap_h
#define Heap_h

using namespace std;

template <typename T>
class Greater   //Functia de comparare pentru MinHeap
{
public:
	bool operator () (const T& node1, const T& node2)
	{
		return node1 > node2;
	}
};

template <typename T>
class Lower     //Functia de comparare pentru MaxHeap
{
public:
	bool operator () (const T& node1, const T& node2)
	{
		return node1 < node2;
	}
};

template <class T, class Comp>
class Heap{
private:

	T* H;
	int capacity;
	int size;
	Comp Compare;

public:

	Heap()
	{
		this->capacity = 1;
		this->size = 0;

		H = new T[this->capacity];
	}

	Heap(int capacity)
	{
		this->size = 0;
		this->capacity = capacity;

		H = new T[this->capacity];
	}

	~Heap()
	{
		delete[] H;
	}

	int Parent(int index)
    {
        return (index - 1) / 2;
    }

    int LeftSon(int index)
    {
        return index * 2 + 1;
    }

    int RightSon(int index)
    {
        return index * 2 + 2;
    }

    T Peek()
    {
        if(size == 0)
        {
            cout<<"Eroare: Heapul este gol!";
            T x;
            return x;
        }
        return H[0];
    }

    void insert(const T &elem)
    {
        if(size == capacity)
        {
            cout << "Eroare: Heapul este plin!\n";
            return ;
        }

        size ++;
        H[size-1] = elem;
        PushUp(size-1);
    }

    T Pop()
    {
        if(size == 0)
        {
            cout << "Eroare: Heapul este gol!\n";
            T x;
            return x;
        }

        T best = H[0];
        H[0] = H[size-1];
        size --;

        if (size > 0)
            PushDown();

        return best;
    }

    bool IsEmpty()
    {
        return size == 0;
    }

    void PushUp(int index)
    {
        int parent;
        parent = Parent(index);

        while(index > 0 && Compare(H[parent],H[index]))
        {
            swap(H[parent],H[index]);

            index = parent;
            parent = Parent(index);
        }
    }

    void PushDown()
    {
        int index = 0;
        while(1)
        {
            if(RightSon(index) > size-1)
            {
                if (LeftSon(index) > size-1)
                    break;
                else
                    if(!Compare(H[LeftSon(index)],H[index]))
                    {
                        swap(H[LeftSon(index)],H[index]);
                        index = LeftSon(index);
                    }
                    else
                        break;
            }
            else
            {
                if(!Compare(H[LeftSon(index)],H[RightSon(index)]) && !Compare(H[LeftSon(index)],H[index]))
                {
                    swap(H[LeftSon(index)],H[index]);
                    index = LeftSon(index);
                }
                else
                    if(!Compare(H[RightSon(index)],H[LeftSon(index)]) && !Compare(H[RightSon(index)],H[index]))
                    {
                        swap(H[RightSon(index)],H[index]);
                        index = RightSon(index);
                    }
                    else
                        break;
            }

        }
    }

    void print()
    {
        int i;
        for (i = 0; i < size; i ++)
            cout<<H[i]<<" ";
        cout<<"\n";
    }
};
#endif
