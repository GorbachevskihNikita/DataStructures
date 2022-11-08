#include <iostream>

template<class T>
class Node
{
public:
    Node* _next;
    T _data;

    Node(T data = T(), Node* next = nullptr)
    {
        this->_data = data;
        this->_next = next;
    }
};

template <class T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void push_back(T data);
    void pop_front();
    void push_front(T data);
    void insert(T data, int index);
    void removeAt(int index);
    void pop_back();
    Node<T>* findPrevByIndex(int index);
    void clear();
    int getSize() { return _size; }
    T& operator[](const int index);

private:
    int _size;
    Node<T>* _head;

};

template<class T>
LinkedList<T>::LinkedList()
{
    _size = 0;
    _head = nullptr;
}

template<class T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template<class T>
void LinkedList<T>::push_back(T data)
{
    if (_head == nullptr)
    {
        _head = new Node<T>(data);
    }
    else
    {
        Node<T>* current = this->_head;
        while (current->_next != nullptr)
        {
            current = current->_next;
        }
        current->_next = new Node<T>(data);
    }
    _size++;
}

template<class T>
T &LinkedList<T>::operator[](const int index)
{
    int counter = 0;

    Node<T>* current = this->_head;

    while(current != nullptr)
    {
        if (counter == index)
        {
            return current->_data;
        }
        current = current->_next;
        counter++;
    }
}

template<class T>
void LinkedList<T>::pop_front()
{
    Node<T>* temp = this->_head;
    _head = _head->_next;
    delete temp;
    _size--;
}

template<class T>
void LinkedList<T>::clear()
{
    while (_size)
    {
        pop_front();
    }
}

template<class T>
void LinkedList<T>::push_front(T data)
{
    _head = new Node<T>(data, _head);
    _size++;
}

template<class T>
void LinkedList<T>::insert(T data, int index)
{
    if (index == 0)
    {
        push_front(data);
    }
    else
    {
        Node<T>* previous = findPrevByIndex(index);
        previous->_next = new Node<T>(data, previous->_next);
        _size++;
    }


}

template<class T>
void LinkedList<T>::removeAt(int index)
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        Node<T>* previous = findPrevByIndex(index);
        Node<T>* toDelete = previous->_next;
        previous->_next = toDelete->_next;
        delete toDelete;
        _size--;
    }
}

template<class T>
Node<T> *LinkedList<T>::findPrevByIndex(int index)
{
    Node<T>* previous = this->_head;
    for (int i = 0; i < index - 1; i++)
    {
        previous = previous->_next;
    }
    return previous;
}

template<class T>
void LinkedList<T>::pop_back()
{
    removeAt(_size - 1);
}

int main()
{
    LinkedList<int> list;
    list.push_back(5);
    list.push_back(10);
    list.push_back(22);

    int numberCount;

    std::cout << "List have three elements, its: first - 5, second - 10, third - 22" << std::endl;
    std::cout << "Input number which be added count of element" << std::endl;
    std::cin >> numberCount;

    for (int i = 0; i < numberCount; i++)
    {
        list.push_back(rand()%15);
    }

    std::cout << "Current list have " << list.getSize() << " elements:" << std::endl;
    for (int i = 0; i < list.getSize(); i++)
    {
        std::cout << list[i] << " ";
    }

    std::cout << std::endl;
    std::cout << "====================" << std::endl;
    std::cout << "Run pop_front method" << std::endl;
    list.pop_front();
    std::cout << "Now list have " << list.getSize() << " elements: " << std::endl;

    for (int i = 0; i < list.getSize(); i++)
    {
        std::cout << list[i] << " ";
    }

    std::cout << std::endl;
    std::cout << "====================" << std::endl;
    std::cout << "Run push_front method" << std::endl;
    list.push_front(120);
    std::cout << "Now list have " << list.getSize() << " elements: " << std::endl;

    for (int i = 0; i < list.getSize(); i++)
    {
        std::cout << list[i] << " ";
    }

    std::cout << std::endl;
    std::cout << "====================" << std::endl;
    std::cout << "Run insert method" << std::endl;
    list.insert(1005, 1);
    std::cout << "Now list have " << list.getSize() << " elements: " << std::endl;

    for (int i = 0; i < list.getSize(); i++)
    {
        std::cout << list[i] << " ";
    }

    std::cout << std::endl;
    std::cout << "====================" << std::endl;
    std::cout << "Run removeAt method" << std::endl;
    list.removeAt(2);
    std::cout << "Now list have " << list.getSize() << " elements: " << std::endl;

    for (int i = 0; i < list.getSize(); i++)
    {
        std::cout << list[i] << " ";
    }

    std::cout << std::endl;
    std::cout << "====================" << std::endl;
    std::cout << "Run pop_back method" << std::endl;
    list.pop_back();
    std::cout << "Now list have " << list.getSize() << " elements: " << std::endl;

    for (int i = 0; i < list.getSize(); i++)
    {
        std::cout << list[i] << " ";
    }
    return 0;
}