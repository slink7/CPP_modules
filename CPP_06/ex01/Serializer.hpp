#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <cstring>

#include "Data.hpp"

class Serializer {
public:
	static uintptr_t	serialize(Data *data);
	static uintptr_t	true_serialize(Data *data);
	static Data			*deserialize(uintptr_t raw);
	static Data			*true_deserialize(uintptr_t raw);

private:
	Serializer();
};

#endif