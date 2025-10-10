#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

struct Data
{
<<<<<<< HEAD
    private:
        int data;
    public:
        Data();
        Data(int val);
        ~Data();
        Data(const Data &other);
        Data &operator=(const Data &other);
        static Data *createData(int val);
        int getData();
=======
private:
	int data;
	Data();
	Data(int val);

public:
	~Data();
	static Data *createData(int val);
	int getData();
>>>>>>> 40c9b09bff01b4e86af4261a1377fbf73e948c95
};

#endif // DATA_HPP
