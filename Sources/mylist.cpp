#include "mylist.hpp"

#include <iostream>
#include <cassert>
#include <memory>

MyList::MyList(unsigned int s)	
{
	assert(s >= 0 && "List size cannot be negative.\n");
	if(s == 0) {
		size = 0;
		head = nullptr;
		tail = nullptr;
	}
	else {
		size = s;
		head = new Node();
		Node *temp = head;
		Node *n_temp;
		for(unsigned int i = 0; i < s - 1; ++i) {
			//n_temp = new Node();
			temp -> next = std::make_unique<Node>();
			n_temp = (temp -> next).get();
			n_temp -> prev = temp;
			temp = n_temp;
		}
		tail = temp;
		temp = nullptr;
		n_temp = nullptr;
	}
}


MyList::~MyList()
{
	delete head;
}


void MyList::insert(Node * item_ptr, int value)
{
	assert(item_ptr != nullptr && "Cannot place in front of nullptr.\n");
	Node * temp = new Node(value);
	
	temp -> next = std::move((item_ptr -> prev) -> next);
	temp -> prev = item_ptr -> prev;
	item_ptr -> prev = temp;

	if(temp -> prev) {
		(temp -> prev) -> next = std::unique_ptr<Node> (temp);
	}
	else {
		head = temp;
	}
	
	temp = nullptr; // No need, just for safety.
	++size;
}


void MyList::insert_back(int value)
{
	if(tail) {
		tail -> next = std::make_unique<Node> (value);
                (tail -> next) -> prev = tail;
                tail = (tail -> next).get();
	}
	else {
		tail = new Node(value);
                head = tail;
	}
	++size;
}


void MyList::remove(Node *item_ptr)
{
	assert(item_ptr != nullptr && "nullptr is not removable :-)\n");

	if(item_ptr -> next) {
		(item_ptr -> next) -> prev = item_ptr -> prev; 
		(item_ptr -> prev) -> next = std::move(item_ptr -> next);
	}
	else {
		(item_ptr -> prev) -> next = std::move(std::unique_ptr<Node>());
	}

	delete item_ptr;
	--size;
}


Node * MyList:: operator[] (unsigned int p)
{
	assert(p >= 0 && p < size && "the chain of nodes has no such position\n");
	Node * item_ptr = head;

	for(int i  = 0; i < p; ++ i) {
		item_ptr = (item_ptr -> next).get();
	}

	return item_ptr;
}


const Node * MyList:: operator[] (unsigned int p) const
{
	assert(p >= 0 && p < size && "\n");
	Node * item_ptr = head;

	for(int i  = 0; i < p; ++ i) {
		item_ptr = (item_ptr -> next).get();
	}

	return item_ptr;
}


Node* MyList::find(int value)
{
	Node *temp = head;
	for(int i = 0; i < size && temp != nullptr; ++i) { //the same as (int i = 0; i < size && temp; ++i)
		if(temp -> data == value) {
			return temp;
		}
		else {
			temp = (temp -> next).get();
		}
	}

	return nullptr;
}

