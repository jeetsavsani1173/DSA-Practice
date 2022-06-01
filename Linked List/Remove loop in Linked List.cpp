// problem link --> https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1#

void removeLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    if (fast == NULL || fast->next == NULL)
        return;
    else
    {
        Node *curr = head;
        while (curr != slow)
        {
            curr = curr->next;
            slow = slow->next;
        }
        Node *prev = curr;

        while (1)
        {
            prev = curr;
            curr = curr->next;
            if (curr == slow)
                break;
        }
        prev->next = NULL;
    }
}