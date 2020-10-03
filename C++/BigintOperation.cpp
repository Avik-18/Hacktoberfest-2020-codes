#include <bits/stdc++.h> 
using namespace std; 

struct Node 
{ 

	int data; 

	// Pointers to the previous and next digit 
	struct Node* next; 
	struct Node* prev; 
	Node(int); 
}; 

// To initialize the structure with a single digit 
Node::Node(int val) 
{ 
	data = val; 
	next = prev = NULL; 
} 

class HugeIntLL 
{ 
public: 
	HugeIntLL(); 
	~HugeIntLL(); 

	// To insert a digit in front 
	void insertInFront(int); 

	// To insert a digit at the end 
	void insertInEnd(int); 

	// To display the large number 
	void display(); 

	int length(); 
	void add(HugeIntLL*, HugeIntLL*); 
	void mul(HugeIntLL*, HugeIntLL*); 
	Node* head; 
	Node* tail; 
	int size; 
}; 

// Constructor of the Class 
HugeIntLL::HugeIntLL() 
{ 
	head = tail = NULL; 
	size = 0; 
} 

// To insert at the beginning of the list 
void HugeIntLL::insertInFront(int value) 
{ 
	Node* temp = new Node(value); 

	if (head == NULL) 
		head = tail = temp; 
	else
	{ 
		head->prev = temp; 
		temp->next = head; 
		head = temp; 
	} 
	size++; 
} 

// To insert in the end 
void HugeIntLL::insertInEnd(int value) 
{ 
	Node* temp = new Node(value); 

	if (tail == NULL) 
		head = tail = temp; 
	else
	{ 
		tail->next = temp; 
		temp->prev = tail; 
		tail = temp; 
	} 
	size++; 
} 

void HugeIntLL::display() 
{ 
	Node* temp = head; 

	while (temp != NULL) 
	{ 
		cout << temp->data; 
		temp = temp->next; 
	} 
} 

int HugeIntLL::length() 
{ 
	return size; 
} 

/* Uses simple addition method that we 
follow using carry*/
void HugeIntLL::add(HugeIntLL* a, HugeIntLL* b) 
{ 
	int c = 0, s; 
	HugeIntLL* a1 = new HugeIntLL(*a); 
	HugeIntLL* b1 = new HugeIntLL(*b); 

	// default copy constructor 
	// Copy Constructor - used to copy objects 
	this->head = NULL; 
	this->tail = NULL; 
	this->size = 0; 

	while (a1->tail != NULL || b1->tail != NULL) 
	{ 
		if (a1->tail != NULL && b1->tail != NULL) 
		{ 
			s = ((a1->tail->data) + (b1->tail->data) + c) % 10; 
			c = ((a1->tail->data) + (b1->tail->data) + c) / 10; 
			a1->tail = a1->tail->prev; 
			b1->tail = b1->tail->prev; 
		} 
		else if (a1->tail == NULL && b1->tail != NULL) 
		{ 
			s = ((b1->tail->data) + c) % 10; 
			c = ((b1->tail->data) + c) / 10; 
			b1->tail = b1->tail->prev; 
		} 
		else if (a1->tail != NULL && b1->tail == NULL) 
		{ 
			s = ((a1->tail->data) + c) % 10; 
			c = ((a1->tail->data) + c) / 10; 
			a1->tail = a1->tail->prev; 
		} 

		// Inserting the sum digit 
		insertInFront(s); 
	} 

	// Inserting last carry 
	if (c != 0) 
		insertInFront(c); 
} 
// Normal multiplication is used i.e. in one to all way 
void HugeIntLL::mul(HugeIntLL* a, HugeIntLL* b) 
{ 
	int k = 0, i; 
	HugeIntLL* tpro = new HugeIntLL(); 
	while (b->tail != NULL) 
	{ 
		int c = 0, s = 0; 
		HugeIntLL* temp = new HugeIntLL(*a); 
		HugeIntLL* pro = new HugeIntLL(); 
		while (temp->tail != NULL) 
		{ 
			s = ((temp->tail->data) * (b->tail->data) + c) % 10; 
			c = ((temp->tail->data) * (b->tail->data) + c) / 10; 
			pro->insertInFront(s); 
			temp->tail = temp->tail->prev; 
		} 
		if (c != 0) 
			pro->insertInFront(c); 

		for (i = 0; i < k; i++) 
			pro->insertInEnd(0); 

		add(this, pro); 
		k++; 
		b->tail = b->tail->prev; 
		pro->head = pro->tail = NULL; 
		pro->size = 0; 
	} 
} 

// Driver code 
int main() 
{ 
	HugeIntLL* m = new HugeIntLL(); 
	HugeIntLL* n = new HugeIntLL(); 
	HugeIntLL* s = new HugeIntLL(); 
	HugeIntLL* p = new HugeIntLL(); 
	HugeIntLL* d = new HugeIntLL(); 
	HugeIntLL* q = new HugeIntLL(); 

	string s1,s2;
	cout<<"1st decimal numbers A :"<<endl;
	cin>>s1;
	cout<<"2nd decimal number B:"<<endl;
	cin>>s2;	

	for (int i = 0; i < s1.length(); i++) 
		m->insertInEnd(s1.at(i) - '0'); 

	for (int i = 0; i < s2.length(); i++) 
		n->insertInEnd(s2.at(i) - '0'); 

	// Creating copies of m and n 
	HugeIntLL* m1 = new HugeIntLL(*m); 
	HugeIntLL* n1 = new HugeIntLL(*n); 
	HugeIntLL* m2 = new HugeIntLL(*m); 
	HugeIntLL* n2 = new HugeIntLL(*n); 
	HugeIntLL* m3 = new HugeIntLL(*m); 
	HugeIntLL* n3 = new HugeIntLL(*n); 

	cout << "Sum(A+B) :" << endl; 
	p->add(m1, n1); 
	p->display(); 
	cout << endl; 
     
    cout << "Product(A*B) :" << endl; 
	s->mul(m, n); 
	s->display(); 
	cout << endl; 

	
	return 0; 
} 

