#include <iostream>

#include "myvector.hpp"
#include "myvector_utility.hpp"

#include "mylist.hpp"
#include "mylist_utility.hpp"

#include "myset.hpp"
#include "myset_utility.hpp"

//#include <mysortedvector.hpp>
//#include <mysortedvector_utility.hpp>

int main()
{
        std::cout << "Enter a container size to create a container with random generated integer data: ";
        unsigned int size;
        std::cin >> size;
 
	MyVector vec(size);
        Generate_MyVector(vec);
        MyVector_Demonstration(vec);

        MyList list(size);
        Generate_MyList(list);
        MyList_Demonstration(list);

	MySet my_set;
        Generate_MySet(my_set, size);
        MySet_Demonstration(my_set);

	/*
        MySortedVector svec(size);
        Generate_MySortedVector(svec);
	MySortedVector_Demonstration(svec);
       */
       	return 0;
}

