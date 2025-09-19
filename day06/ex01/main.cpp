#include "Serialization.hpp"

int main(void)
{
    Data *data = Data::createData(42);
    std::cout << "Created data with value: " << data->getData()
    << " with address: " << data << std::endl;
    uintptr_t raw = Serialization::serialize(data);
    std::cout << "Serialized data to raw: " << raw  << ", in Hex: " << std::hex << raw << std::endl;
    Data *deserializedData = Serialization::deserialize(raw);
    std::cout << "Deserialized raw to data with value: " << deserializedData->getData()
    << " with address: " << deserializedData << std::endl;
    delete data;
    return 0;
}