/*循环链表，支持增删操作*/

struct Node
{
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList
{
public:
    CircularLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~CircularLinkedList()
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
    void insert(int data)
    {

        Node *newNode = new Node(data);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            tail->next = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
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
        Node *previous = nullptr;

        do
        {
            if (current->data == data)
            {
                if (previous == nullptr)
                {
                    head = current->next;
                    tail->next = head;
                }
                else
                {
                    previous->next = current->next;
                    if (current == tail)
                    {
                        tail = previous;
                    }
                }
                delete current;
                --size;
                return true;
            }
            previous = current;
            current = current->next;

        } while (current != head);
        return false;
    }

private:
    Node *head;
    Node *tail;
    int size;
};