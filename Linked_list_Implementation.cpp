#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
   
    Node(int val){
        data=val;
        next=NULL;
    }
    ~Node(){
        cout<<"Node destructor for data="<<data<<endl;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"deleting element ="<<data<<endl;
    }
    //C++ me delete ptr; likhte hi us object ka destructor AUTOMATICALLY call hota hai, phir memory free hoti hai. Isi wajah se delete next; likhne par next jis object ko point kar raha hai, uska ~Node() chal jata hai.
};

class List{
public:
  Node *head;
  Node *tail;
  
    List(){
        head=NULL;
        tail=NULL;
    }
    ~List(){
        cout<<"Destructor of list"<<endl;
        if(head!=NULL){
            delete head;
            head=NULL;
        }
    }
    void push_front(int val){
        Node *newNode=new Node(val);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            newNode->next=head;
            head=newNode;
        }
    }
    void push_back(int val){
        Node *newNode=new Node(val);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    void printList(){
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    void insert(int val,int pos){
        if(pos<0){
            cout<<"Position Invalid!"<<endl;
            return;
        }
        if (pos==0){
            push_front(val);
            return;
        }
        Node *temp=head;
        for(int i=0;i<pos-1;i++){
            if(temp==NULL){
                cout<<"Position Invalid!"<<endl;
                return;
            }
            temp=temp->next;
        }
        if(temp==NULL){
            cout<<"Position Invalid!"<<endl;
            return;
        }
        Node *newNode=new Node(val);
        newNode->next=temp->next;
        temp->next=newNode;
        if(newNode->next==NULL){
            tail=newNode;
        }
        
    }
    void pop_front(){
        if(head==NULL){
            cout<<"List is already empty!!"<<endl;
            return;
        }
        Node *temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        if(head==NULL){
            tail=NULL;
        }
    }
    void pop_back(){
        if(tail==NULL){
            cout<<"Linked list is empty!"<<endl;
        }
        Node *temp= head;
        while(temp->next!=tail){ // incase we dont have tail,use this: if (temp->next->next==NULL)
            temp=temp->next;
        }
        temp->next=NULL;
        delete tail;
        tail=temp;
    }
    int searchItr(int val){
        if(head==NULL){
            cout<<"Linked List is empty!!"<<endl;
            return 0;
        }
        Node *temp=head;
        int i=0;
        while(temp!=NULL){
            if(temp->data ==val){
                return i;
            }
            temp=temp->next;
            i++;
        }
        return -1;
    }
    int helper(Node *head, int val){
        if(head==NULL){
            return -1;
        }
        if(head->data==val){
            return 0;
        }
        int idx=helper(head->next,val);
        if(idx==-1){
            return -1;
        }
        return idx+1;
    }
    int searchRecursively(int val){
        Node *temp=head;
        int idx=helper(temp,val);
        return idx;
    }
    
    Node *reverse(){
        if(head==NULL){
            cout<<"Linked List is empty!"<<endl;
            return head;
        }
        tail=head;
        Node *prev=NULL,*curr=head,*nextPtr=NULL;
        while(curr!=NULL){
            nextPtr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextPtr;
        }
        head=prev;
        return head;
    }
    
    void remove_nth(int n){
        if(head==NULL){
            cout<<"Linked List is empty!!"<<endl;
            return;
        }
        Node *prev=NULL,*curr=head;
        int i=0;
        while(i<n){
            prev=curr;
            curr=curr->next;
            i++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
    int size(){
        int sz=0;
        if(head==NULL){
            return 0;
        }
        Node *temp=head;
        while(temp!=NULL){
            sz++;
            temp=temp->next;
        }
        return sz;
    }
    void remove_nth_from_last(int n){
        if(head==NULL){
            cout<<"Linked List is empty!!"<<endl;
            return;
        }
        if(n<=0){
            cout<<"Position Invalid"<<endl;
            return;
        }
        if(n==1){
            pop_back();
            return;
        }
        int len=size();
        if(n>len){
            cout<<"Position Invalid"<<endl;
            return;
        }
        if(n==len){
            pop_front();
            return;
        }
        Node *prev=head;
        for(int i=0;i<(len-n-1);i++){ //i want to go to its previous element
            prev=prev->next;
        }
        Node *toDel=prev->next;
        cout<<"Element to be deleted : "<<toDel->data<<endl;
        prev->next=prev->next->next;
        toDel->next=NULL;
        delete toDel;
        
    }
    void isPalindrome(){
        if(head==NULL){
            cout<<"Linked List is empty!!"<<endl;
            return;
        }
        Node *temp=head;
        // printList();
        Node *tempRev=reverse();
        while(temp!=NULL){
            if(temp->data!=tempRev->data){
                cout<<"Not Palindrome"<<endl;
                // printList();
                return;
            }
            temp=temp->next;
            tempRev=tempRev->next;
        }
        
        cout<<"It is Plaindrome"<<endl;
    }
    // void isPalindrome(){
    //     if(head==NULL){
    //         cout<<"Linked List is empty!!"<<endl;
    //         return;
    //     }
    //     int len=size();
    //     Node *temp=head;
    //     Node *ptr1=NULL,*ptr2=NULL;
    //     int i;
    //     for (i=0;i<len/2;i++){
    //         temp=temp->next;
    //     }
    //     ptr1=temp->next;
    //     ptr2=ptr1->next;
    //     for(i=len/2;i<n;i++){
            
    //     }
        
    // }
    
    
};

// when we allocate memory using new keyword, we can delete it using delete keyword

int main() {
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(5);
    ll.push_front(2);
    // ll.push_front(3);
    // ll.printList();
    // ll.push_back(4);
    // ll.push_back(5);
    // ll.push_back(6);
    // ll.printList();
    // ll.insert(100,4);
    // ll.printList();
    // ll.pop_front();
    // cout<<"LL after pop front: ";
    // ll.printList();
    // ll.pop_back();
    // cout<<"LL after pop back: ";
    // ll.printList();
    // cout<<"Element 100 found at index: "<<ll.searchItr(100)<<endl;
    // cout<<"Element 5 found at index: "<<ll.searchRecursively(5)<<endl;
    // cout<<"Reversed Linked List: ";
    // List l2;
    // l2.printList();
    // ll.printList();
    // cout<<"Linked list after removing 2nd position element: ";
    // ll.remove_nth(2);
    // ll.printList();
    // cout<<"Linked list after removing 2nd position element from last: ";
    // ll.remove_nth_from_last(2);;
    // ll.printList();
    ll.printList();
    ll.isPalindrome();
    ll.printList();
    return 0;
}
