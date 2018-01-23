#include "neuralNetwork.h"

//=====================================================================
//  Getters and setters
//=====================================================================

void NeuralNetwork::setLearningRate(float learningRate)
{
    this->learningRate = learningRate;
}
float NeuralNetwork::getLearningRate() const
{
    return learningRate;
}

void NeuralNetwork::setMomentum(float value)
{
    if(value >= 0.0f && value <= 1.0f)
    {
        this->momentum = value;
    }
    else
    {
        std::cout << "ERROR : Momentum must be in 0 and 1, 0 for don't use momentum." << std::endl;
    }
}
float NeuralNetwork::getMomentum() const
{
    return this->momentum;
}

void NeuralNetwork::setNumberOfSameClusteringAfterReset(unsigned int number)
{
    numberOfSameClusteringAfterReset = number;
}
int NeuralNetwork::getNumberOfSameClusteringAfterReset() const
{
   return numberOfSameClusteringAfterReset;
}

void NeuralNetwork::setLenghtOfShortRuns(unsigned int lenght)
{
    lenghtOfShortRuns = lenght;
}

int NeuralNetwork::getLenghtOfShortRuns() const
{
    return lenghtOfShortRuns;
}


//=====================================================================
//  Only getters
//=====================================================================

int NeuralNetwork::getShortRunCounter() const
{
    return shortRunCounter;
}

int NeuralNetwork::getNumberOfInputs() const
{
    return numberOfInput;
}

int NeuralNetwork::getNumberOfHiddenLayers() const
{
    return numberOfHiddenLayers;
}

int NeuralNetwork::getNumberOfNeuronsInHiddenLayers() const
{
    return numberOfNeuronsInHiddenLayers;
}

int NeuralNetwork::getNumberOfResultsClassifiedWell() const
{
    return numberOfResultsClassifiedWell;
}

int NeuralNetwork::getNumberOfNegativeResultsMisclassefied() const
{
    return numberOfResultsMisclassefied;
}

int NeuralNetwork::getNumberOfOutputs() const
{
    return numberOfOutput;
}

float NeuralNetwork::getClusteringRate() const
{
    return clusteringRate;
}
