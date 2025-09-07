#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

void display(Node *p)
{
    if(p!=NULL)
    {
        cout<<p->data<<"->";
        display(p->next);
    }
    else
    {
        cout<<"NULL"<<endl;
    }
}

int countOccurrences(Node* head, int key)
{
    if(head == nullptr)
    {
        return 0;
    }
    else
    {
        if(head->data == key)
        {
            return 1 + countOccurrences(head->next, key);
        }
        else
        {
            return countOccurrences(head->next, key);
        }
    }
}

Node* deleteAllOccurrences(Node* head, int key)
{
    
    while(head != nullptr && head->data == key)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    if(head == nullptr)
    {
        return head;
    }
    
    Node* current = head;
    while(current->next != nullptr)
    {
        if(current->next->data == key)
        {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else
        {
            current = current->next;
        }
    }
    
    return head;
}

Node* createList(int arr[], int size)
{
    if(size == 0) return nullptr;
    
    Node* head = new Node;
    head->data = arr[0];
    head->next = nullptr;
    
    Node* last = head;
    Node* temp;
    
    for(int i = 1; i < size; i++)
    {
        temp = new Node;
        temp->data = arr[i];
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    }
    
    return head;
}

int main()
{
    cout<<"COUNT AND DELETE OCCURRENCES"<<endl;
    
    
    int arr[] = {1, 2, 1, 2, 1, 3, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    Node* head = createList(arr, size);
    
    cout<<"Original Linked List: ";
    display(head);
    
    int key = 1;
    cout<<"Key to search and delete: "<<key<<endl;
    
    int count = countOccurrences(head, key);
    cout<<"Count: "<<count<<endl;
    
    head = deleteAllOccurrences(head, key);
    cout<<"Updated Linked List: ";
    display(head);
    
    
    return 0;
}