#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* swapPairs(ListNode* head) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;
    
    while (head != NULL && head->next != NULL) {
        ListNode* first = head;
        ListNode* second = head->next;
        
        prev->next = second;
        first->next = second->next;
        second->next = first;
        
        prev = first;
        head = first->next;
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
    
    cout << "Original list: ";
    printList(head);
    
    
    ListNode* swappedHead = swapPairs(head);
    
    cout << "Swapped list: ";
    printList(swappedHead);
    
    
    system("pause");
    return 0;
}
