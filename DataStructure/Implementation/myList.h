struct node
{
	int data;
	node* next;
};

class myList
{
private:
	node* head, * tail;
public:
	myList() :head(nullptr), tail(nullptr) {};
};