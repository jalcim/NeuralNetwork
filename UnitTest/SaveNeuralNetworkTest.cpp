﻿#pragma once
#include "GTestTools.h"
#include "neuralNetwork.h"

using namespace std;

// ReSharper disable CppInconsistentNaming CppLocalVariableMayBeConst CppUseAuto

TEST(SaveNeuralNetwork, DISABLED_EqualTest)
{
	const vector<int> structureOfNetwork {5, 20, 10, 3};
	const vector<activationFunctionType> activationFunctionByLayer{iSigmoid, tanH, sigmoid};
	NeuralNetwork A(structureOfNetwork, activationFunctionByLayer, 0.03f, 0.78f);
	NeuralNetwork C(structureOfNetwork, activationFunctionByLayer, 0.03f, 0.78f);
	NeuralNetwork B = A;

	EXPECT_TRUE(A == B) << "A == B";
	EXPECT_TRUE(&A != &B) << "A != B";

	EXPECT_TRUE(*A.getLayer(0) == *B.getLayer(0)) << "Value : A.layers[0] == B.layers[0]";
	EXPECT_TRUE(A.getLayer(0) != B.getLayer(0)) << "Address : A.layers[0] != B.layers[0]";

	EXPECT_TRUE(*A.getLayer(0)->getNeuron(0) == *B.getLayer(0)->getNeuron(0)) << "Value : A.Layers[0].neurons[0] == B.Layers[0].neurons[0]";
	EXPECT_TRUE(A.getLayer(0)->getNeuron(0) != B.getLayer(0)->getNeuron(0)) << "Address : A.Layers[0].neurons[0] != B.Layers[0].neurons[0]";
	
	EXPECT_TRUE(*A.getLayer(0)->getNeuron(0)->getActivationFunction() == *B.getLayer(0)->getNeuron(0)->getActivationFunction()) << "Value : A.Layers[0].neurons[0] == B.Layers[0].neurons[0]";
	EXPECT_TRUE(A.getLayer(0)->getNeuron(0)->getActivationFunction() != B.getLayer(0)->getNeuron(0)->getActivationFunction()) << "Address : A.Layers[0].neurons[0] != B.Layers[0].neurons[0]";

	EXPECT_TRUE(A != C) << "A != C";

	const vector<float> inputs {1.5, 0.75, -0.25, 0, 0};
	const vector<float> desired {1, 0, 0.5, 0};

	A.train(inputs, desired);

	EXPECT_TRUE(A != B) << "A != B";

	B.train(inputs, desired);

	EXPECT_TRUE(A == B) << "A == B";
}

TEST(SaveNeuralNetwork, Save)
{
	const vector<int> structureOfNetwork {5, 20, 10, 3};
	const vector<activationFunctionType> activationFunctionByLayer{iSigmoid, tanH, sigmoid};
	NeuralNetwork A(structureOfNetwork, activationFunctionByLayer, 0.03f, 0.78f);

	A.saveAs("./testSave.bin");

	NeuralNetwork B = NeuralNetwork::loadFrom("./testSave.bin");

	EXPECT_TRUE(A == B) << "A == B";
}