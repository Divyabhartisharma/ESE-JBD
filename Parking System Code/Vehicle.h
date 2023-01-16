#include<stdio.h>
#include<iostream>
#include"Parking.h"

using namespace std;

class Vehicle
{
    public:
    const char* VehicleStatestr(VehicleState e);
    void HandleStates(int p1,int p2,int p3,bool gateopen);
};
