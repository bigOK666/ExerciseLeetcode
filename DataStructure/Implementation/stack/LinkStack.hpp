struct Node
{
    int data;
    Node *next;
    Node(int data) : data(data), next(nullptr) {}
};

class LinkStack
{
public:
    LinkStack() : head(nullptr) {}
    ~LinkStack()
    {
        if (head == nullptr)
        {
            return;
        }
        while (head != nullptr)
        {
            Node *toDelete = head;
            head = head->next;
            delete toDelete;
        }
    }

    void push(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    int pop()
    {
        Node *toBeDeleted = head;
        head = head->next;
        int result = toBeDeleted->data;
        delete toBeDeleted;
        return result;
    }

private:
    Node *head;
};