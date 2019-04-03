class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* sum = new ListNode(0);
    ListNode* ret = new ListNode(0);
    ret = sum;
    while(l1&&l2)
    {
        sum->val = l1->val + l2->val;
        if(l1->next&&l2->next)
        {
            sum->next = new ListNode(0);
            sum = sum->next;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    if(l1)
    {
        sum->next = l1;
        l1 = nullptr;
    }
    if(l2)
    {
        sum->next = l2;
        l2 = nullptr;
    }
    for(sum = ret; sum ; sum = sum->next)
    {
        if(sum->val >= 10 && sum->next)
        {
            sum->val -= 10;
            sum->next->val += 1;
        }
        else if(sum->val >= 10 && sum->next == nullptr)
        {
            sum->val -= 10;
            sum->next = new ListNode(1);
        }
    }
        return ret;
    }
};