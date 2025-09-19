#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *data) {
	return (reinterpret_cast<uintptr_t>(data));
}

uintptr_t Serializer::true_serialize(Data *data) {
	uintptr_t	out = (uintptr_t)new char[sizeof(Data)];
	std::memcpy((void*)out, data, sizeof(Data));
	return (out);
}

Data *Serializer::deserialize(uintptr_t data) {
	return (reinterpret_cast<Data *>(data));
}

Data *Serializer::true_deserialize(uintptr_t raw) {
	Data	*out = new Data();
	std::memcpy(out, (void*)raw, sizeof(Data));
	return (out);
}
