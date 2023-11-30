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

// Deletion of the head Node
static Node* removesHead(Node* head) {
    if (head == NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

// Delete the tail of the Linked List
static Node* removesTail(Node* head) {
    if (head == NULL) return head;

    Node* temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;

    return head;
}

// Delete the k-th element of the Linked List
static Node* removesKthElement(Node* head, int k) {
    if(head == NULL) return head;
    if(k == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int counter = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL) {
        counter++;
        if(counter == k) {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        if(temp->next == nullptr && counter < k) {
            cout << "Invalid position to remove a Node.\n";
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    return head;
}

// Delete the value from the Linked List
static Node* removesTheValue(Node* head, int val) {
    if(head == NULL) return head;
    if(head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL) {
        if(temp->data == val) {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;

        if(temp->next == nullptr && temp->data != val) {
            cout << "The value is not present in the Linked List.\n";
            break;
        }
    }

    return head;
}

// Insert a new Head into the Linked List
static Node* insertHead(Node* head, int val) {
    return new Node(val, head);
}

// Insert a new Tail at end of the Linked List
static Node* insertTail(Node* head, int val) {
    if(head == NULL) return new Node(val);

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;

    return head;
}

// Insert a new Node at k-th position in the Linked List
static Node* insertAtPositionK(Node* head, int val, int pos) {
    if(head == NULL) {
        if(pos == 1) {
            return new Node(val);
        } else {
            cout << "Not a valid position for the Linked List!\n";
            return head;
        }
    }

    if(pos == 1) return new Node(val, head);

    int counter = 0;
    Node* temp = head;
    while(temp != NULL) {
        counter++;
        if(counter == pos-1) {
            Node* newNode = new Node(val, temp->next);
            temp->next = newNode;
            break;
        }
        if(temp->next == NULL && counter < pos-1) {
            cout << "Not a valid position for the Linked List!\n";
            break;
        }
        temp = temp->next;
    }

    return head;
}

// Insert a new Node before the value x in the Linked List
static Node* insertBeforeValue(Node* head, int val, int x) {
    if(head->data == x) return new Node(val, head);
    if(head == NULL) return NULL;

    Node* temp = head;
    while(temp != NULL) {
        if(temp->next->data == x) {
            Node* newNode = new Node(val, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;

        if(temp->next == nullptr && temp->data != x) {
            cout << x << " is not present in the Linked List!\n";
            break;
        }
    }

    return head;
}



int main()
{
    vector<int> arr = { 11, 5, 8, 17, 29, 46, 30, 71 };

    /*
    Node* x = new Node(arr[1], nullptr); // directly giving the memory location of the given data
    cout << x << endl;
    cout << x->data << " - " << x->next << endl;

    Node y = Node(arr[0]); // creating an object of Node class
    cout << y.data << " - " << y.next << endl;
    */

    Node* head = convertArrToLL(arr);
    printLL(head);
    // cout << "Length of the Linked List: " << lengthOfLL(head) << "\n";
    // cout << checkIfPresent(head, 5) << "\n";

    head = removesHead(head);
    printLL(head);

    head = removesTail(head);
    printLL(head);

    head = removesKthElement(head, 6);
    printLL(head);

    head = removesTheValue(head, 29);
    printLL(head);

    head = insertHead(head, 510);
    printLL(head);

    head = insertTail(head, 99);
    printLL(head);

    head = insertAtPositionK(head, 777, 2);
    printLL(head);

    head = insertBeforeValue(head, 555, 8);
    printLL(head);

    return 0;
}
