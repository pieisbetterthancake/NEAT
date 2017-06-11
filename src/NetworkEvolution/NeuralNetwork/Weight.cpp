/**
 * Author: Daiwei Chen
 * Date: 2017-6-11
 */

#include "Node.h"
#include "Weight.h"

Weight::Weight()
{

}

Weight::Weight(Node * forward, Node * backwards)
{
    fconnection = forward;
    bconnection = backwards;
}

Weight::~Weight()
{
    //This is a weird situation it might not need to be freed here.
    //delete fconnection;
    //delete bconnection;
}

