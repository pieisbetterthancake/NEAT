/*
 * Author: Pete Canfield
 * Date: 2017-7-19
 */

#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include "Genome.h"
#include "Node.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include <string>
#include <thread>
#include <mutex>
#include <atomic>


class NeuralNetwork
{
public:
    NeuralNetwork(unsigned int=rand());
    NeuralNetwork(std::string,unsigned int=rand());
    NeuralNetwork(Genome,unsigned int=rand());

    NeuralNetwork * operator+(NeuralNetwork*);

    ~NeuralNetwork();

    void updateStructure();
    void randomMutation(float,float,float);
	void mutateAddWeight(unsigned int, unsigned int);
    void mutateAddNode(unsigned int, unsigned int);
    void mutateAddBias(unsigned int);

    void setInputs(std::vector<double>);
    void setTraining(std::vector<double>);
    void runForward();
    void runForward(unsigned int);
    void gradientDecent(double);

    double getLMSError();

    void saveNetwork(std::string);
    void loadFromFile(std::string);
    std::vector<double> getNetworkOutput();

    void visualize(unsigned int, unsigned int, unsigned int=5);
	void updateGeneration();

	Genome getGenome() {return *dna; }
private:
    Node * findNodeWithID(unsigned int);
    void processForward(unsigned int,unsigned int);
    unsigned int findNumInLayer(unsigned int);
    std::vector<Node*> & getLayer(unsigned int);
    unsigned int findLayerFromNodeID(unsigned int);

    void lockFunc(std::atomic<unsigned int> &, unsigned int);
    void displayWindow(unsigned int, unsigned int,unsigned int);
    float calcDistance(unsigned int, unsigned int, float);
    void updateGene(Node *, unsigned int &);
    void updateBias(Node *, unsigned int &);

    void addWeight(Node *, Node *, double);
	
	unsigned int generateRandomNodeID(bool=true);

    std::vector<Node*> inputs;
    std::vector<std::vector<Node*>> hiddenLayer;
    std::vector<Node*> outputs;
    std::vector<double> training;

    Genome * dna;

    unsigned int generation;
	unsigned int lastGeneratedLayer;

    //multithreading
    std::vector<std::thread*> threads;
    std::thread * vThread;
    bool isVisualized = false;
    std::mutex mLock;
    std::atomic<unsigned int> completed;


};

#endif
