/**
 * Author: Daiwei Chen
 * Date: 2017-6-11
 */

#include "Node.h"
#include "Weight.h"

/* Constructs the node */
Node::Node()
{

}

/* Constructs a node that pre-sets the value and the bias,
 * otherwise, both values will be 0 */
Node::Node(double v, double b)
    : val(v), bias(b)
{
    
}

/* Destroys every connection after */ 
Node::~Node()
{
    for(auto & connection : fConnections)
        delete connection;
}

/* This function takes in a forward node, backward node, and a weight to 
 * set the new weight value. This function will create a new weight with
 * all the connections and values, and add the said weight to the back 
 * of the fConnections vector.
 */
void Node::addForward(Node * forward, Node * back, double weight = 0)
{
    fConnections.push_back(new Weight(forward, back, weight));
}

/* This function will take in a weight pointer and add the said weight onto
 * the bConnections vector.
 */
void Node::addBackwards(Weight * weight)
{
    bConnections.push_back(weight);
}

/* This function is used to connect up the network.
 * Returns the last connection made forwards.
 */
Weight * Node::getLastForward()
{
    return fConnections.back();
}

/* This function is used to connect up the network.
 * Returns the last connection made forwards.
 */
Weight * Node::getLastBackwards()
{
    return bConnections.back();
}

/* This function calculates the value of *this* node based on its many connections.
 * The value of the current node will be changed to the sum of all its connected 
 * weights times the weight's connected node values.
 */
void calculate()
{
    double sum;
    for(auto weight : bConnections) {
        sum += weight->value() * weight->bNode()->value();
    }
    val = sum + bias;
}

/* This function changes the bias. */
void setBias(double b)
{
    bias = b;
}
