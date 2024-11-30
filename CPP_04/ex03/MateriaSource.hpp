#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <cstring>

#include "IMateriaSource.hpp"

#define MAX_MATERIAS 10

class MateriaSource : public IMateriaSource {
public:
	MateriaSource();
	MateriaSource(const MateriaSource& cpy);
	~MateriaSource();

	MateriaSource&	operator=(const MateriaSource& cpy);

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
private:
	unsigned int	materia_count;
	AMateria*		materias[MAX_MATERIAS];
};

#endif