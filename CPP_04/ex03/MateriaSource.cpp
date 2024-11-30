#include "MateriaSource.hpp"

MateriaSource::MateriaSource() :
	materia_count(0),
	materias({0})
{}

MateriaSource::MateriaSource(const MateriaSource &cpy) :
	MateriaSource()
{
	for (int k = 0; k < cpy.materia_count; k++)
		learnMateria(cpy.materias[k]->clone());
}

MateriaSource::~MateriaSource()
{
	for (int k = 0; k < materia_count; k++)
		delete (materias[k]);
}

MateriaSource &MateriaSource::operator=(const MateriaSource &cpy)
{
	for (int k = 0; k < materia_count; k++)
		delete (materias[k]);
	materia_count = 0;
	for (int k = 0; k < cpy.materia_count; k++)
		learnMateria(cpy.materias[k]->clone());
}

void MateriaSource::learnMateria(AMateria *materia) {
	if (materia_count >= MAX_MATERIAS)
		return ;
	materias[materia_count++] = materia;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int k = 0; k < materia_count; k++)
		if (!materias[k]->getType().compare(type))
			return (materias[k]);
	return nullptr;
}
