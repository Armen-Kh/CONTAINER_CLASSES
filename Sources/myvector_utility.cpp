#include "myvector.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void Print_MyVector(const MyVector& v)
{
	std::cout << "Vector (size = " << v.get_size() << " ): ";
	for(int i = 0; i < v.get_size(); ++i) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;	
}


void Generate_MyVector(MyVector& v)
{	
	std::srand(time(0));
	for(int i = 0; i < v.get_size(); ++i) {
		v[i] = std::rand() % 199 - 99;
	}

}


void MyVector_Demonstration(MyVector& v)
{		
	std::cout << "=============== MyVector class demonstration is started!\n";
	Print_MyVector(v);
	
	std::cout << "\nEnter an integer value to insert into the vector: ";
	int item;
	std::cin >> item;
	std::cout << "Enter a position to insert the value: ";
	unsigned int position;
	std::cin >> position;
	v.insert(position, item);
	
	Print_MyVector(v);

	std::cout << "\nEnter a position to delete an item: ";
	std::cin >> position;
	v.remove(position);

	Print_MyVector(v);

	std::cout << "\nEnter a position to return a value: ";
        std::cin >> position;
	std::cout << "The item at position " << position << " has the value " << v[position] << ".\n";
	std::cout << "\nEnter a value to search: ";
	std::cin >> item;	
	int r = v.find(item);
	if(r != v.get_size()) {
		std::cout << "The required value is in position " << r << ".\n";
	}
	else {
		std::cout << "The required value does not exist.\n"; 
	}

	std::cout << "=============== MyVector class demonstration is over!\n\n";
}

