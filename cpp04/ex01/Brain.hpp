#pragma once
#include <string>

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	Brain(const Brain& cpy);
	Brain& operator=(const Brain& rhs);
	~Brain();
	std::string getIdeas(int i);
	void addIdea(std::string idea);
	void printIdeas() const;
};

