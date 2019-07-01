#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP


class MyVector
{
public:
	MyVector(unsigned int s = 0);

	~MyVector();

	void insert(unsigned int i, int v);

	void remove(const unsigned int i);
	
	int& operator[] (const unsigned int i);
	int& operator[] (const unsigned int i) const;

	//return the first appropriate index or size if the value does not exist
	unsigned int find(int v) const;

	unsigned int get_size() const;

private:
	unsigned int size;
	unsigned int capacity;
	int * data;
};

#endif
