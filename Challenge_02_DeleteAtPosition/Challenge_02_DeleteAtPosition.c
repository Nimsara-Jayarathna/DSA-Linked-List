
/*
Challenge: Challenge 2: DeleteAtPosition

Description:
Delete the node at position P in a singly linked list.

Function Signature:
struct Node* solve(struct Node* head, int param);

Displayed Test Case:
Input:
6\n1 2 3 4 5 6\n3
Output:
1 2 3 5 6

Hidden Test Case Hints:
- Deleting head
- Deleting last node
- Out of bounds position

Instructions:
Complete the function `solve()` below. The `main()` function and input handling are already provided.
Your function should return the updated linked list head (if applicable).
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// User implements this
struct Node* solve(struct Node* head, int param) {
    struct Node* temp = head;
    struct Node* temp1 = NULL;
    int position = 1;
    if (param == 0) {
        head = head->next;
        free(temp);
        return head;
    }
    while (temp && param > position) {
        position++;
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        return head;
    } 
    temp1 = temp->next;
    temp->next = temp->next->next;
    free(temp1);
    return head;
}

// Utility to append a node to the list
struct Node* append(struct Node* head, int val) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = val;
    new_node->next = NULL;
    if (!head) return new_node;
    struct Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new_node;
    return head;
}

// Utility to print list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, val, param;
    scanf("%d", &n);
    struct Node* head = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = append(head, val);
    }
    scanf("%d", &param);  // Custom parameter per challenge
    head = solve(head, param);
    printList(head);
    return 0;
}
