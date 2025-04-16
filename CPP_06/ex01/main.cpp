
#include <string>

#include "Data.hpp"
#include "Serializer.hpp"

int main() {
	Data data = {42, 0.0001f, 'c'};

	uintptr_t serialized_data = Serializer::serialize(&data);

	Data *deserialized_data = Serializer::deserialize(serialized_data);

	std::cout << data << "\n";
	std::cout << *deserialized_data << "\n";

	delete[] ((char *)serialized_data);
	delete (deserialized_data);

}