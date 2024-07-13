#include "calc.h"
#include "frosting.h"

namespace neural {

	namespace ff {

		class FullyConnectedLayer {

			public:

				calc::Vector biases;
				calc::Operator weights;

				calc::Vector lastInput;
				calc::Vector lastOutput;
				
				int inputCount;
				int outputCount;

				double learningRate;

			private:

				FullyConnectedLayer() {}
				FullyConnectedLayer(int ic, int oc, double learningRate): inputCount(ic), outputCount(oc), biases(calc::Vector(oc)), weights(calc::Operator(ic, oc)), learningRate(learningRate) {
					for (int i = 0; i < outputCount; i++) {
						biases.set(i, frosting::randomValue());
						for (int j = 0; j < inputCount; j++) {
							weights.set(j, i, frosting::randomValue());
						}
					}
				}

				double& bias(int index) { return biases[index]; }
				double& weight(int i, int j) { return weights.get(i, j); }

				calc::Vector forward(calc::Vector input) {
					lastInput = input;
					lastOutput = calc::operate(input, weights);
					for (int i = 0; i < outputCount; i++) { lastOutput[i] = lastOutput[i] + biases[i]; }
					return lastOutput;
				}

				calc::Vector backward(calc::Vector error) {
					// i hate linear algebra SO MUCH, so don't ask me how any of this works, i just know it does.

					// Gradient of the biases ??
					calc::Vector biasGradients = error;

					// Gradient of the weights?
					calc::Operator weightGradients = calc::outerProduct(lastInput, error);

					// Gradient of the input?
					calc::Vector inputGradients(inputCount);
					double s;
					for (int i = 0; i < inputCount; i++) {
						s = 0;
						for (int j = 0; j < outputCount; j++) {
							s += weights.get(i, j) * error[j];
						}
						inputGradients[i] = s;
					}

					// Update weights and biases
					for (int i = 0; i < outputCount; i++) {
						biases[i] = biases[i] - learningRate * biasGradients[i];
						for (int j = 0; j < inputCount; j++) {
							weights.get(j, i) = weights.get(j, i) - learningRate * weightGradients.get(j, i);
						}
					}

					return inputGradients;
				}

		};

	};

};