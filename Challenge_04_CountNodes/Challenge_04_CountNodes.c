
/*
Challenge: Challenge 4: CountNodes

Description:
Count the number of nodes in the linked list.

Function Signature:
struct Node* solve(struct Node* head, int param);

Displayed Test Case:
Input:
6\n1 3 5 7 9 11
Output:
Count: 6

Hidden Test Case Hints:
- Empty list
- Single node
- Long list

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
    // Your logic here
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
