#include <iostream>

using namespace std;


class ListNode {
public:
    int val;
    ListNode* next;
    

    ListNode(int x) : val(x), next(NULL) {} 
};


ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0); 
    dummy.next = head;
    ListNode* first = &dummy;
    ListNode* second = &dummy;

    
    for (int i = 0; i <= n; ++i) {
        if (first != NULL) { 
            first = first->next;
        }
    }

    
    while (first != NULL) { 
        first = first->next;
        second = second->next;
    }

    
    ListNode* nodeToDelete = second->next;
    second->next = second->next->next;
    delete nodeToDelete;

    return dummy.next;
}


void printList(ListNode* head) {
    while (head != NULL) { 
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


ListNode* addNode(ListNode* head, int value) {
    if (head == NULL) return new ListNode(value); 

    ListNode* current = head;
    while (current->next != NULL) { 
        current = current->next;
    }
    current->next = new ListNode(value);
    return head;
}


int main() {
    
    ListNode* head = NULL; 
    head = addNode(head, 1);
    head = addNode(head, 2);
    head = addNode(head, 3);
    head = addNode(head, 4);
    head = addNode(head, 5);

    int n = 2;
    cout << "Original List: ";
    printList(head);

    head = removeNthFromEnd(head, n);

    cout << "Modified List: ";
    printList(head);

    
    while (head != NULL) { 
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
	system("pause");
    return 0;
}
