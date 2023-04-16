struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
        {
            return l2;
        }
        if (l2 == nullptr)
        {
            return l1;
        }

        ListNode head(-1);
        ListNode *headPtr = &head;

        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                headPtr->next = l1;
                l1 = l1->next;
            }
            else
            {
                headPtr->next = l2;
                l2 = l2->next;
            }
            headPtr = headPtr->next;
        }

        headPtr->next = l1 == nullptr ? l2 : l1;
        return head.next;
    }
};