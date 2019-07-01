#include "mylist.hpp"
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <memory>

void Print_MyList(const MyList& list)
{
	
	if(list.get_size() == 0) {
		std::cout << "List is empty!\n";
		return;
	}

	std::cout << "List: (size = " << list.get_size() << "): ";

	Node * item = list.get_head();
	while(item) {
		std::cout << item -> data << " ";
		item = (item -> next).get();
	}
	std::cout << std::endl;	
}


void Generate_MyList(MyList& list)
{
	std::srand(time(0));

	Node * item = list.get_head();
	while (item) {
		item -> data = std::rand() % 199 - 99;  //value [-99, 99]
		item = (item -> next).get();
	}

}


void MyList_Demonstration(MyList& list)
{	
	std::cout << "=============== MyList class demonstration is started!\n";
        Print_MyList(list);

	unsigned int position;
	std::cout << "\nEnter a position of node to return it's value: ";
        std::cin >> position;
	Node * item_ptr = list[position];
        std::cout << "The node at position " << position << " has the value " << item_ptr -> data << ".\n";

        std::cout << "\nEnter a value to insert into the new node, which will be located in front of the node mentioned above: ";
        int value;
        std::cin >> value;
        list.insert(item_ptr, value);

	Print_MyList(list);

	std::cout << "\nEnter a value, which will be lacated in the back: ";
	std::cin >> value;
	list.insert_back(value);

        Print_MyList(list);

	std::cout << "\nEnter a value to search node: ";
        std::cin >> value;
        item_ptr = list.find(value);
        if(item_ptr) {
		Node * ptr = item_ptr;
		unsigned int count = 0;
		while(ptr) {
			++count;
			ptr = (ptr -> next).get();
		}
                std::cout << "The required value belongs to the node at position " << list.get_size() - count << " in the chain of nodes.\n";
        }
        else {
                std::cout << "The required value does not exist.\n";
        }

	std::cout << "\nDeleting found node.\n";
	list.remove(item_ptr);

        Print_MyList(list);

	std::cout << "=============== MyList class demonstration is over!\n\n";
}
