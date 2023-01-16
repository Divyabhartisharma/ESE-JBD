
#include<stdio.h>
#include<iostream>
#include"enum.h"

using namespace std;
class CParking
{
    public:
    bool OpenGates(bool gateopen);
    VehicleState CheckingSlotAvailability(int p1,int p2,int p3);
};

