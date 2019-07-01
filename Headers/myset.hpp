#ifndef MYSET_HPP
#define MYSET_HPP

#include <utility> //std::move
#include <memory>


struct set_Node 
{
	set_Node(int d = 0, set_Node *p = nullptr,
	     std::unique_ptr<set_Node> l = nullptr, std::unique_ptr<set_Node> r = nullptr)
		: data(d)
		, parent(p)
		, left(std::move(l))
		, right(std::move(r))	
	{
	}

	int data;
	set_Node *parent;
	std::unique_ptr<set_Node> left;
	std::unique_ptr<set_Node> right;
};


class MySet
{
public:
	MySet();
	~MySet();

	bool insert(int);
	
	set_Node* find_max(set_Node *);
	set_Node* find_min(set_Node *);
	set_Node* find(int);

	bool remove_helper(set_Node *, int);
	bool remove(set_Node *&);
	bool remove(int);

	void print_inorder_helper(set_Node *);
	void print_inorder();

	unsigned int get_size() const;
	set_Node * get_root() const;

private:
	set_Node *root;
	unsigned int size;
};

#endif
