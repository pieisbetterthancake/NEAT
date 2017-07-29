/*
 * Author: Pete Canfield & Daiwei Chen
 * Date: 2017-6-15
 */
#ifndef GENOME_H
#define GENOME_H

#include <vector>
#include <string>
#include <fstream>
#include "Gene.h"

class Genome
{
public:
	Genome();
	Genome(unsigned int, unsigned int);
	Genome(std::string);
	void addGene(Gene);
    void addBias(Bias);
	void setInput(unsigned int);
	void setHidden(std::vector<unsigned int>);
	void setOutput(unsigned int);
	void updateConnectionStructure(unsigned int);
	void removeConnection(unsigned int, unsigned int);

	void addInput();
	void addHidden(unsigned int);
	void insertHidden(unsigned int);
	void addOutput();

	void saveGenome(std::string);
	void loadFromFile(std::string);
    void copyIntoGenome(Genome &);

    std::vector<Gene> getGeneVector();
    std::vector<Bias> getBiasVector();
	Gene & getGene(unsigned int);
    Bias & getBias(unsigned int);
	unsigned int getGenomeSize();
    unsigned int getBiasSize();

	unsigned int getInput();
	std::vector<unsigned int> getHidden();
	unsigned int getOutput();

private:
	std::vector<Gene> geneticCode;
    std::vector<Bias> biasInfo;
	unsigned int input;
	std::vector<unsigned int> hiddenLayer;
	unsigned int output;

	const unsigned int INT = sizeof(int);
	const unsigned int DOUBLE = sizeof(double);
};
#endif
