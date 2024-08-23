#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prevGroupEnd = &dummy;
    ListNode* current = head;
    
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    while (count >= k) {
        ListNode* groupStart = prevGroupEnd->next;
        ListNode* groupEnd = groupStart;
        ListNode* nextGroupStart = groupEnd;
        
        for (int i = 1; i < k; ++i) {
            groupEnd = groupEnd->next;
        }
        nextGroupStart = groupEnd->next;
        groupEnd->next = NULL;
        
        ListNode* prev = NULL;
        ListNode* curr = groupStart;
        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        prevGroupEnd->next = prev;
        groupStart->next = nextGroupStart;
        prevGroupEnd = groupStart;
        
        count -= k;
    }
    
    return dummy.next;
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    int k = 3;
    
    cout << "Original list: ";
    printList(head);
    
    ListNode* reversedHead = reverseKGroup(head, k);
    
    cout << "Reversed list in groups of " << k << ": ";
    printList(reversedHead);
	system("pause");    
    return 0;
}
