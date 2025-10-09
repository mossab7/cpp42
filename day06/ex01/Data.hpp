#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

struct Data
{
private:
	int data;
	Data();
	Data(int val);

public:
	~Data();
	static Data *createData(int val);
	int getData();
};

#endif // DATA_HPP
