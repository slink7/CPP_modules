
#include <string>

#include "Data.hpp"
#include "Serializer.hpp"

void	true_test() {
	Data data = {42, 0.0001f, 'c'};

	uintptr_t serialized_data = Serializer::true_serialize(&data);

	Data *deserialized_data = Serializer::true_deserialize(serialized_data);

	std::cout << "Original: " << data << "\n";
	std::cout << "Processed: " << *deserialized_data << "\n";

	delete[] ((char *)serialized_data);
	delete (deserialized_data);
}

void	test() {
	Data data = {42, 0.0001f, 'c'};

	uintptr_t serialized_data = Serializer::serialize(&data);

	std::cout << "Original: " << data << "\n";
	std::cout << "Processed: " << *Serializer::deserialize(serialized_data) << "\n";
}

int main() {
	
	std::cout << "\tTest\n";
	test();
	std::cout << "\n\tTrue test\n";
	true_test();

}