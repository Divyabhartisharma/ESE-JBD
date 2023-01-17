#include"Vehicle.h"
#include <gtest/gtest.h>

const char* Vehicle::VehicleStatestr(VehicleState e)
{
    switch(e)
    {
        case VehicleState::Idle: return "Idle";
        case VehicleState::CheckingState: return "CheckingState";
        case VehicleState::Parking: return "Parking";
        case VehicleState::NoParking: return "NoParking";
        case VehicleState::exit: return "exit";
        default: return "unknown";
    }
}

void Vehicle::HandleStates(int p1,int p2,int p3,bool gateopen)
{
    CParking* parkingobj=new CParking;    
    VehicleState nextState=VehicleState::Idle; // Assuming Vehicle is in IDLE state
    for(int i=0;i<10;i++)
    {
        switch(nextState)
        {
            case VehicleState::Idle:
            /// cout << "entered Vehicle State IDLE" << endl;
          
                if(parkingobj->OpenGates(gateopen)==true)
                {
                    nextState = VehicleState::CheckingState;
                }
                break;

            case VehicleState::CheckingState:
                ///cout << "Checking slot" << endl;
                nextState =parkingobj->CheckingSlotAvailability(p1,p2,p3);
                break;
            
            case VehicleState::Parking:
                nextState= VehicleState::exit;
                break;
            
            case VehicleState::NoParking:
                nextState= VehicleState::exit;
                break;
            
            default :
                cout << "final State" << endl;  
                break;     
        }
    }
}

int main(int argc, char **argv) 
{
    Vehicle obj1;
    CParking obj2;
    //Simulating Sensor Values manually
    int p1=40,p2=40,p3=100;
    bool gateOpen = false;
    ///obj1.HandleStates(p1,p2,p3,gateOpen);

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
