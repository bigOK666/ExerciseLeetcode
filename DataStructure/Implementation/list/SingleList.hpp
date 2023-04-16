/*generates a single linked list*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedList
{
private:
    /* data */
    ListNode *head;
    int size;

public:
    LinkedList(/* args */);
    ~LinkedList();

    void insertAtHead(int val)
    {
        ListNode *newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
        ++size;
    }

    void insertAtTail(int val)
    {
        ListNode *newNode = new ListNode(val);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            ListNode *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }

        ++size;
    }

    void insertAt(int val, int index)
    {
        if (index < 0 || index > size)
        {
            return;
        }

        if (index == 0)
        {
            insertAtHead(val);
        }

        ListNode *newNode = new ListNode(val);
        ListNode *current = head;
        int i = 0;
        while (i < index - 1)
        {
            current = current->next;
            i++;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void deleteNode(int val)
    {
        if (head == nullptr)
        {
            return;
        }

        if (head->val == val)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        ListNode *current = head;
        while (current->next != nullptr)
        {
            if (current->next->val == val)
            {
                break;
            }
            current = current->next;
        }

        if (current->next == nullptr)
        {
            return;
        }

        ListNode *toBeDeleted = current->next;
        current->next = toBeDeleted->next;
        delete toBeDeleted;
        size--;
    }

    void reverse()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }

        ListNode *prev = nullptr;
        ListNode *current = head;
        ListNode *next = nullptr;
        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }
};

LinkedList::LinkedList() : head(nullptr), size(0)
{
}

LinkedList::~LinkedList()
{
    if (head == nullptr)
    {
        return;
    }

    while (head->next != nullptr)
    {
        ListNode *toBeDeleted = head->next;
        head->next = toBeDeleted->next;
        delete toBeDeleted;
    }

    size = 0;
}