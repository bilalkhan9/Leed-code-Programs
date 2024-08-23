#include <iostream>


struct ListNode {
    int val;
    ListNode* next;
    
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0); 
    ListNode* current = &dummy; 
    int carry = 0; 

   
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        current->next = new ListNode(sum % 10);
        current = current->next;
    }

    return dummy.next; 
}


void printList(ListNode* head) {
    while (head != NULL) {
        std::cout << head->val;
        if (head->next != NULL) {
            std::cout << " -> ";
        }
        head = head->next;
    }
    std::cout << std::endl;
}


void deleteList(ListNode* head) {
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    
    ListNode* result = addTwoNumbers(l1, l2);

    
    printList(result);

    
    deleteList(result);
    deleteList(l1);
    deleteList(l2);
    
	system("pause");
    return 0;
}
