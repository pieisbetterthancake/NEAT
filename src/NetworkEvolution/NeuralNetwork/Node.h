/**
 * Author: Daiwei Chen
 * Date: 2017-6-11
 */

#ifndef NODE_H
#define NODE_H

#include <vector>
#include <iostream>
#include <math.h>
#include <cstddef>
#include "Weight.h"

class Node
{
public:
    // Constructor and Destructor
    Node(unsigned int);
    Node(double);
    ~Node();

    // Calculating and Learning
    void calculate();
    void backPropogation(double);
    void backPropogation(double,double);
    void updateWeights();

    // Modifying the network
    void removeFConnections();
    void removeBConnections();
    void addForward(Node *, Node *, double=0);
    void addBackwards(Weight *);
    void removeConnection(Node *);
    void removeBackPointer(unsigned int pos);

    // Getter
    Weight * getLastForward();
    Weight * getLastBackwards();
    Weight * getFrowardWeight(unsigned int pos) { return fConnections[pos]; }
    Weight * getBackWeight(unsigned int pos) { return bConnections[pos]; }

    unsigned int getBackWeightSize() { return bConnections.size(); }
    unsigned int getID() { return ID; }

    double & value() { return val; }
    double & bias() { return b; }
    double getDelta() { return delta; }

    unsigned int getForwardSize() { return fConnections.size(); }
    bool isBiasEnabled();
private:

    double sigmoidActivation(double);

    // These are all the connections of the nodes, the weights will act as a middleman
    // for the node, since
    std::vector<Weight*> fConnections;
    std::vector<Weight*> bConnections;

    // The value,bias and sum
    double val,delta;
    double b = 0;

    unsigned int ID;



};

#endif
