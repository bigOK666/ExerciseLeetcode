/*双向链表，支持增删操作*/
#include <stdexcept>
struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoubleLinkedList
{
public:
    DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~DoubleLinkedList()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }

    void insert(int data, int position)
    {
        if (position < 0 || position > size)
        {
            throw std::out_of_range("Invalid index.");
        }

        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else if (position == 0)
        {

            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else if (position == size)
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else
        {
            Node *current = head;
            for (int i = 0; i < position - 1; ++i)
            {
                current = current->next;
            }

            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
        }

        ++size;
    }

    bool remove(int data)
    {
        if (head == nullptr)
        {
            return false;
        }

        Node *current = head;

        while (current != nullptr)
        {
            if (current->data == data)
            {
                if (current == head)
                {
                    head = current->next;
                    if (head != nullptr)
                    {
                        head->prev = nullptr;
                    }
                    else
                    {
                        tail = nullptr;
                    }
                }
                else if (current == tail)
                {
                    tail = current->prev;
                    tail->next = nullptr;
                }
                else
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                --size;
                return true;
            }

            current = current->next;
        }

        return false;
    }

private:
    Node *head;
    Node *tail;
    int size;
};