#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

public:
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Convert an Array to a Linked List
static Node* convertArrToLL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// Traverse and Print a Linked List
static void printLL(Node* head) {
    Node* temp = head;
    while (temp) {
        if (temp->next == nullptr) {
            cout << temp->data << endl;
            return;
        }
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

// Get the length of an Linked List
static int lengthOfLL(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp) {
        temp = temp->next;
        count++;
    }
    return count;
}

// Search of an Element in a Linked List
static bool checkIfPresent(Node* head, int val) {
    Node* temp = head;
    while (temp) {
        if (temp->data == val) return true;

        temp = temp->next;
    }
    return false;
}


int main()
{
    vector<int> arr = { 11, 5, 8, 17 };

    /*
    Node* x = new Node(arr[1], nullptr); // directly giving the memory location of the given data
    cout << x << endl;
    cout << x->data << " - " << x->next << endl;

    Node y = Node(arr[0]); // creating an object of Node class
    cout << y.data << " - " << y.next << endl;
    */

    Node* head = convertArrToLL(arr);
    printLL(head);
    cout << "Length of the Linked List: " << lengthOfLL(head) << "\n";
    cout << checkIfPresent(head, 5) << "\n";

    return 0;
}
