#pragma once
#include <QObject>
#include "neuralNetwork.h"
#include "Data.h"

using namespace data;

class Controller : public QObject
{
Q_OBJECT

private :

	std::unique_ptr<Data> data;
	std::unique_ptr<NeuralNetwork> neuralNetwork;

	void initializeData();

public:

	Controller(Data& data);
	virtual ~Controller() = default;

	

	void initializeNeuralNetwork();

	void compute(bool* stop);

	NeuralNetwork& getNeuralNetwork() const;
	Data& getData() const;

	struct Inputs
	{
		std::vector<unsigned int> structure;
		std::vector<activationFunction> activationFunction;
		float learningRate;
		float momentum;
		uint numberOfTrainbyRating;

	} inputs;

	struct Ouputs
	{
		uint currentIndex = 0;
		int numberOfIteration = 0;
		float clusteringRate = -1.0f;
		float clusteringRateMax = -1.0f;

	} outputs;

signals :

	void updateNumberOfIteration();
};
