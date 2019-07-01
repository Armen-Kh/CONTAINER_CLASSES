#ifndef MYLIST_HPP
#define MYLIST_HPP

#include <memory>    // std::unique_ptr
#include <utility>   // std::move

struct Node
{
	Node(int d = 0, Node *p = nullptr, std::unique_ptr<Node> n = nullptr)
		: data(d)
		, prev(p)
		, next(std::move(n))
       	{
	}

	int data;
	Node *prev;
	std::unique_ptr<Node> next;
};



class MyList
{
public:
	MyList(unsigned int s = 0);

	~MyList();
	
	void insert(Node *, int); //insert in front of the node pointed to by the first parameter
	void insert_back(int);
	void remove(Node *);

	Node *  operator[] (unsigned int i);
	const Node *  operator[] (unsigned int i) const;

	//return a pointer to a node that has a value as data or nullptr if the value does not exist
	Node* find(int);

	unsigned int get_size() const
	{
		return size;
	}

	Node * get_head() const 
	{
		return head;
	}

	Node * get_tail() const
	{
		return tail;
	}

private:
	Node *head;
	Node *tail;
	unsigned int size;
};

#endif
