#include <iostream>                   
using namespace std;                  

//Creating Node Class
class Node{
    public:
    //Creating Class Objects
    string name;
    int age;
    Node*next; //A node pointer for next node
    Node*prev; //A node pointer for previous node
    //calling constructor
    Node(string name,int age){
        this->name=name;
        this->age=age;
        next=NULL; //initialising next as NULL
        prev=NULL; //initialising prev as NULL
    }
};

//Function to Insert Data at End of Linked List
void append(Node* &head,string name,int age){
    //creating a node pointer and storing address of head in temp
    Node*temp=head;
    //creating a new node and storing name and age in it
    Node*new_node=new Node(name,age);
    //inserting node in empty list
    if(temp==NULL){
        head=new_node;
    }
    //Inserting node in non empty list
    else{
        while(temp->next!=NULL){temp=temp->next;}
        temp->next=new_node;
        new_node->prev=temp;
    }
}

//Function to Insert Data at Start of Linked List
void insert_at_head(Node*&head,string name,int age){
    //creating a Node pointer and storing address of new node in it 
    Node*new_node=new Node(name,age);
    //inserting new node at head
    new_node->next=head;
    head->prev=new_node;
    head=new_node;
}

//Function to Display Data from Start of Linked List
void display_from_start(Node*head){
    Node*temp=head;
    while(temp!=NULL){cout<<"[Name:"<<temp->name<<" Age:"<<temp->age<<"]"<<"<=>";temp=temp->next;}
    cout<<endl;
}

//Function to Display Data From End of Linked List
void display_from_end(Node*head){
    Node*temp=head;
    while(temp->next!=NULL){temp=temp->next;}
    while(temp!=NULL){cout<<"[Name:"<<temp->name<<" Age:"<<temp->age<<"]"<<"<=>";temp=temp->prev;}
    cout<<endl;
}

//Function to Delete any index(0,n-1) Excluding Last Element 
void delete_ind(Node*&head,int i){
    if(i==0){
        Node*temp=head;
        head=temp->next;
        head->prev=NULL;
        delete temp;
    }
    else{
        Node*temp=head;
        for(int j=0;j<i;j++){temp=temp->next;}
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
    }
}

//Function to delete last element
void pop(Node*&head){
    Node*temp=head;
    while(temp->next!=NULL){temp=temp->next;}
    temp->prev->next=NULL;
    delete temp;
}

int main(){
    //Initialising an empty linked list
    Node*head=NULL;
	int no_of_family_mem;
    //Taking no of family mem as input
	cout<<"Enter Number Of Family Members:";cin>>no_of_family_mem;
    //Inserting family members details in doubly linked list
	for(int i=1;i<=no_of_family_mem;i++){
		string name;
		int age;
		cout<<"Enter Family Member "<<i<<" Name:";cin.ignore();getline(cin,name);
		cout<<"Enter Family Member "<<i<<" Age:";cin>>age;
        //appending data name and age in doubly linked list
		append(head,name,age);
	}
    cout<<endl;//For space
    //Displaying Family details
    cout<<"Doubly Linked list with my family members as elements is shown below:"<<endl;
    cout<<endl;
    display_from_start(head);
}

/*BONUS QUESTION

Q.Try to find a way to link the family members' doubly-linked list based on their relationship.

Ans.One way to link the family members doubly-linked list is by sorting the doubly linked list according to age in decending order.By doing so we will get a doubly linked list in which older generation people will be close to head in double linked list and new generation people will be close to tail in doubly linked list.

*/