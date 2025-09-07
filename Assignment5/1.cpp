#include<iostream>
using namespace std;
class Node{
public:
int data;
 Node* next;};
void display(Node *p){
if(p!=NULL){
cout<<p->data<<"->";
display(p->next);}
else
cout<<"NULL"<<endl;}

Node* insertAtBeginning(Node* head, int value){
Node* newNode = new Node;
newNode->data = value;
newNode->next = head;
return newNode;}

Node* insertAtEnd(Node* head, int value){
Node* newNode = new Node;
newNode->data = value;
newNode->next = nullptr;
if(head == nullptr)
return newNode;
Node* temp = head;
while(temp->next != nullptr)
temp = temp->next;
temp->next = newNode;
return head;
}
Node* insertAfterValue(Node* head, int value, int newValue){
Node* temp = head;
 while(temp != nullptr && temp->data != value)
temp = temp->next;
 if(temp != nullptr){
Node* newNode = new Node;
newNode->data = newValue;
newNode->next = temp->next;
temp->next = newNode;
cout<<"Inserted "<<newValue<<" after "<<value<<endl;}
else
cout<<"Value "<<value<<" not found!"<<endl;
return head;}

Node* insertBeforeValue(Node* head, int value, int newValue)
{
    if(head == nullptr)
    {
        cout<<"List is empty!"<<endl;
        return head;
    }
    
    if(head->data == value)
    {
        return insertAtBeginning(head, newValue);
    }
    
    Node* temp = head;
    while(temp->next != nullptr && temp->next->data != value)
    {
        temp = temp->next;
    }
    
    if(temp->next != nullptr)
    {
        Node* newNode = new Node;
        newNode->data = newValue;
        newNode->next = temp->next;
        temp->next = newNode;
        cout<<"Inserted "<<newValue<<" before "<<value<<endl;
    }
    else
    {
        cout<<"Value "<<value<<" not found!"<<endl;
    }
    return head;
}

Node* deleteFromBeginning(Node* head)
{
    if(head == nullptr)
    {
        cout<<"List is empty!"<<endl;
        return head;
    }
    
    Node* temp = head;
    head = head->next;
    cout<<"Deleted "<<temp->data<<" from beginning"<<endl;
    delete temp;
    return head;
}

Node* deleteFromEnd(Node* head)
{
    if(head == nullptr)
    {
        cout<<"List is empty!"<<endl;
        return head;
    }
    
    if(head->next == nullptr)
    {
        cout<<"Deleted "<<head->data<<" from end"<<endl;
        delete head;
        return nullptr;
    }
    
    Node* temp = head;
    while(temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    cout<<"Deleted "<<temp->next->data<<" from end"<<endl;
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node* deleteSpecificNode(Node* head, int value)
{
    if(head == nullptr)
    {
        cout<<"List is empty!"<<endl;
        return head;
    }
    
    if(head->data == value)
    {
        Node* temp = head;
        head = head->next;
        cout<<"Deleted "<<value<<endl;
        delete temp;
        return head;
    }
    
    Node* temp = head;
    while(temp->next != nullptr && temp->next->data != value)
    {
        temp = temp->next;
    }
    
    if(temp->next != nullptr)
    {
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        cout<<"Deleted "<<value<<endl;
        delete nodeToDelete;
    }
    else
    {
        cout<<"Value "<<value<<" not found!"<<endl;
    }
    return head;
}

int searchNode(Node* head, int value)
{
    Node* temp = head;
    int position = 1;
    
    while(temp != nullptr)
    {
        if(temp->data == value)
        {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;
}

int main()
{
    Node* head = nullptr;
    int choice, value, newValue, position;
    
    while(true)
    {
        cout<<"\nSINGLY LINKED LIST OPERATIONS"<<endl;
        cout<<"1. Insert at beginning"<<endl;
        cout<<"2. Insert at end"<<endl;
        cout<<"3. Insert before a specific value"<<endl;
        cout<<"4. Insert after a specific value"<<endl;
        cout<<"5. Delete from beginning"<<endl;
        cout<<"6. Delete from end"<<endl;
        cout<<"7. Delete specific node"<<endl;
        cout<<"8. Search for a node"<<endl;
        cout<<"9. Display all nodes"<<endl;
        cout<<"10. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        
        switch(choice)
        {
            case 1:
                cout<<"Enter value to insert at beginning: ";
                cin>>value;
                head = insertAtBeginning(head, value);
                break;
                
            case 2:
                cout<<"Enter value to insert at end: ";
                cin>>value;
                head = insertAtEnd(head, value);
                break;
                
            case 3:
                cout<<"Enter value to search for: ";
                cin>>value;
                cout<<"Enter new value to insert before: ";
                cin>>newValue;
                head = insertBeforeValue(head, value, newValue);
                break;
                
            case 4:
                cout<<"Enter value to search for: ";
                cin>>value;
                cout<<"Enter new value to insert after: ";
                cin>>newValue;
                head = insertAfterValue(head, value, newValue);
                break;
                
            case 5:
                head = deleteFromBeginning(head);
                break;
                
            case 6:
                head = deleteFromEnd(head);
                break;
                
            case 7:
                cout<<"Enter value to delete: ";
                cin>>value;
                head = deleteSpecificNode(head, value);
                break;
                
            case 8:
                cout<<"Enter value to search: ";
                cin>>value;
                position = searchNode(head, value);
                if(position != -1)
                {
                    cout<<"Value "<<value<<" found at position "<<position<<" from head"<<endl;
                }
                else
                {
                    cout<<"Value "<<value<<" not found!"<<endl;
                }
                break;
                
            case 9:
                cout<<"Linked List: ";
                display(head);
                break;
                
            case 10:
                cout<<"Exiting program..."<<endl;
                return 0;
                
            default:
                cout<<"Invalid choice! Please try again."<<endl;
        }
    }
    return 0;
}