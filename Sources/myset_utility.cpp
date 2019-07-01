#include <myset.hpp>

#include <cstdlib>
#include <chrono>
#include <iostream>


void Generate_MySet(MySet& my_set, unsigned int s)
{
	std::srand(time(0));
	
	std::cout <<"Generated values for MySet: ";
	for(unsigned int i = 0; i < s; ++i) {
		int t = 99 - std::rand() % 199;
		my_set.insert(t);	
		std::cout << t << " ";
	}
	std::cout << "\n";
}


void MySet_Demonstration(MySet& my_set)
{		
        std::cout << "=============== MySet class demonstration is started!\n";
        my_set.print_inorder();

        std::cout << "\n\nEnter a value to insert into the new node, which will be located in set: ";
        int value;
        std::cin >> value;
	my_set.insert(value);
        my_set.print_inorder();

	std::cout << "\n\nNote: entering a value that already exists in the set does not make any changes.\nTry entering an existing value: ";
        std::cin >> value;
        my_set.insert(value);

        my_set.print_inorder();

        std::cout << "\n\nEnter a value to search node: ";
        std::cin >> value;
        set_Node *item_ptr = my_set.find(value);
        if(item_ptr) {
		std::cout << "The required value belongs to the set.\n";
		std::cout << "\nNow deleting the node with the found value.\n";
		my_set.remove(item_ptr);
		my_set.print_inorder();
	}
        else {
                std::cout << "The required value does not exist.\n";
        }
        
	std::cout << "\n\nEnter a value to remove the corresponding node: ";
        std::cin >> value;
	my_set.remove(value);
	my_set.print_inorder();

        std::cout << "\n=============== MyList class demonstration is over!\n\n";
}

