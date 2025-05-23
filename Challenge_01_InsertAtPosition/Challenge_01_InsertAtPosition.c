
/*
Challenge: Challenge 1: InsertAtPosition

Description:
Insert value X at position P in a singly linked list.

Function Signature:
struct Node* solve(struct Node* head, int param);

Displayed Test Case:
Input:
5\n10 20 30 40 50\n2 99
Output:
10 20 99 30 40 50

Hidden Test Case Hints:
- Inserting at head (P = 0)
- Inserting at end (P = N)
- Invalid position

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
    int position = 0;
    struct Node* temp = head;
    struct Node* previous = head;
    while (temp) {
        if (position == param) {
            int value;
            struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
            scanf("%d", &value);
            new_node->data = value;
            new_node->next = temp;
            previous = new_node;
            return head;
        }
        previous = temp;
        temp = temp->next;
        position++;
    }
    return head;
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
