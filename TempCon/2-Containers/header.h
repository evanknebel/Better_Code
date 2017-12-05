#pragma once

class intVector
{
	int * data;
	size_t capacity;
	size_t size;

public:
	intVector();
	~intVector();

	int& at(size_t idx);  

	int& append(int val); 
};