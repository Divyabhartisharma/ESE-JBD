#include"Parking.h"

bool CParking::OpenGates(bool gateopen)
{
    if(gateopen==false)
    {
        cout << "Gate is closed hence opening the gate" << endl;
        gateopen=true;
    }
    else
    {
        cout << "Gate is already opened" << endl;
    }
    return gateopen;
}

VehicleState CParking::CheckingSlotAvailability(int p1,int p2,int p3)
{
    VehicleState nextState;
    ///cout << "function call" << endl;
    if(p1>50 & p2>50 & p3>50)
    {
        cout << "All slots are available "<< endl;

        nextState=VehicleState::Parking;
    }

   else if((p1>50 & p2>50)|(p2>50 & p3>50 )|( p3>50 & p1>50))
   {
        cout << "Two slots are available" << endl;
        if(p1>50 & p2>50)
        cout << "Parking 1,2 are free" << endl; 
        else if(p2>50 & p3>50)
        cout << "Parking 2,3 are free" << endl; 
        else if(p3>50 & p1>50)
        cout << "Parking 2,3 are free" << endl;
        
        nextState=VehicleState::Parking;
    }
    else if ((p1<50 & p2<50 & p3<50))
    {
         cout << "Parking full " << endl; 

         nextState=VehicleState::NoParking;  
    }
    else if((p1<50 & p2<50)|(p2<50 & p3<50)|(p1<50 & p3<50))
    {    
        cout << "One slot available" << endl;   
       
        if(p1>50) 
        cout << "FIrst slot available" << endl;   
        else if(p2>50)
        cout << "Second slot available" << endl;   
        else 
        cout << "Third slot available" << endl;   
        
        nextState=VehicleState::Parking; 
    }
    return nextState;
}
