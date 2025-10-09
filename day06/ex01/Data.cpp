#include "Data.hpp"

Data::Data() : data(0) {}

Data::Data(int val) : data(val) {}

Data::~Data() {}

Data *Data::createData(int val)
{
	Data *data = new Data();
	data->data = val;
	return data;
}

int Data::getData(void)
{
	return data;
}
