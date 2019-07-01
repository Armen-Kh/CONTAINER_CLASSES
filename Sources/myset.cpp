#include <myset.hpp>

#include <iostream>

MySet::MySet() : root(nullptr), size(0)	
{
	std::cout << "MySet object created\n";
}

MySet::~MySet()
{
	std::cout <<"MySet object deleted!\n";	
	delete root;
}

bool MySet::insert(int d) {
	if(0 == size) {
		root = new set_Node(d);
		++size;
		return true;
	}

	set_Node *current = root;
	//set_Node *curr_parent;
	while(1) {
		if(d == current -> data) { //item already exists in this set
			return false;
		}

		//curr_parent = current;

		if(d > current -> data) {
			if(current -> right) {
				current = (current -> right).get();
				continue;
			}
			else {
				++size;
				current -> right = std::make_unique<set_Node> (d, current);
				return true;
			}	
		}
		
		if(d < current -> data) {
			if(current -> left) {
				current = (current -> left).get();
			}
			else {
				++size;
				current -> left = std::make_unique<set_Node> (d, current);
				return true;
			}
		}
	}
}


set_Node* MySet::find_max(set_Node * rptr)
{
	if( nullptr == rptr) {
		return nullptr;
	}

	if( nullptr == rptr -> right) {
		return rptr;
	}
	else {
		return find_max( (rptr -> right).get() );
	}
}


set_Node* MySet::find_min(set_Node * rptr)
{
        if( nullptr == rptr) {
                return nullptr;
        }

        if( nullptr == rptr -> left) {
                return rptr;
        }
        else {
                return find_min( (rptr -> left).get() );
        }
}


set_Node* MySet::find(int d)
{
        set_Node *temp = root;
        while(temp) {
                if(d == temp -> data) {
                        return temp;
                }

                if(d > temp -> data) {
                        temp = (temp -> right).get();
                }

                if(d < temp -> data) {
                        temp = (temp -> left).get();
                }
        }

        return nullptr;
}


bool MySet::remove_helper(set_Node * rptr, int d) {
	if(nullptr == rptr) {
		return false;
	}

	if(d == rptr -> data) {
		if(nullptr == rptr -> left) {
		       if (nullptr == rptr -> right) {
       			       if( nullptr != rptr -> parent) {
       				       if( ((rptr -> parent) -> left).get() == rptr) {
		       			       (rptr -> parent) -> left = nullptr;
				       }
			       	       else {
			       		       (rptr -> parent) -> right = nullptr;
				       }
			       } 
			       delete rptr;
			       rptr = nullptr;
			       return true;			       	       
       		       }
		       else {
			       rptr -> data = find_min((rptr -> right).get()) -> data;
			       remove_helper((rptr -> right).get(), rptr -> data);
       			       return true;
		       }
		}
		else {
			rptr -> data = find_max((rptr -> left).get()) -> data;
			remove_helper((rptr -> left).get(), rptr -> data);
			return true;			
		}
	}

	if(d < rptr -> data) {
		return remove_helper( (rptr -> left).get(), d );
	}
	else {
		return remove_helper( (rptr -> right).get(), d );
	}
}


bool MySet::remove(set_Node *& n) 
{
	if(remove_helper(n, n -> data)) {
		--size;
		return true;
	}
	return false;
}


bool MySet::remove(int d) {
	set_Node *temp = find(d);
	return remove(temp);
}


void MySet::print_inorder_helper(set_Node * rptr)
{
	if(rptr == root) {
		if(nullptr == rptr) {
			std::cout << "Set is empty!";
		}
		else {
			std::cout << "Set (size = " << size << "): ";
		}
	}

	if(nullptr == rptr) {
		return;
	}

	print_inorder_helper( (rptr -> left).get());
	std::cout << rptr -> data << " ";
	print_inorder_helper( (rptr -> right).get());
}

void MySet::print_inorder()
{
	print_inorder_helper(root);
}


unsigned int MySet::get_size() const
{
	return size;
}

set_Node* MySet::get_root() const
{
	return root;
}




