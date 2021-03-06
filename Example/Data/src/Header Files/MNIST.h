#ifndef MNIST_H
#define MNIST_H

#include <string>
#include <iomanip>
#include <exception>
#include "DataForClassification.h"

class MNIST : public DataForClassification
{
private :
	void readImages(const std::string path_MNIST[]);
	void readSet(const set set, std::ifstream& images, std::ifstream& labels);
	void loadData() override;

public :
	MNIST();
};

template <typename T>
std::string to_string_with_precision(const T value, const int n = 3)
{
	std::ostringstream out;
	out << fixed << std::setprecision(n) << value;
	return out.str();
}

#endif // MNIST_H
