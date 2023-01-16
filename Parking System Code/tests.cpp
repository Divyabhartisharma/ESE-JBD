#include"Vehicle.h"
#include <gtest/gtest.h>

CParking parkingobj;  
Vehicle vehicleobj;
TEST(OpenGates,positive1)
{
   
    ASSERT_EQ(true,parkingobj.OpenGates(false));
}

TEST(OpenGates,positive2)
{
   CParking parkingobj;     
    ASSERT_EQ(true,parkingobj.OpenGates(true));
}

TEST(CheckingSlotAvailability,positive3 )
{
    VehicleState previousState;
    const char* str1;
    str1 = vehicleobj.VehicleStatestr(VehicleState::Parking);
    previousState= parkingobj.CheckingSlotAvailability(40,40,100);
    const char* str2= vehicleobj.VehicleStatestr(previousState);
    ASSERT_STREQ(str1,str2);

    previousState= parkingobj.CheckingSlotAvailability(100,40,100);
    const char* str3= vehicleobj.VehicleStatestr(previousState);
    ASSERT_STREQ(str1,str3);

    previousState= parkingobj.CheckingSlotAvailability(100,40,100);
    const char* str4= vehicleobj.VehicleStatestr(previousState);
    ASSERT_STREQ(str1,str4);
}

TEST(CheckingSlotAvailability,negative1 )
{
    VehicleState previousState;
    const char* str1;
    str1 = vehicleobj.VehicleStatestr(VehicleState::NoParking);
    previousState= parkingobj.CheckingSlotAvailability(40,40,40);
    const char* str2= vehicleobj.VehicleStatestr(previousState);
    ASSERT_STREQ(str1,str2);

    previousState= parkingobj.CheckingSlotAvailability(-1,40,40);
    const char* str4= vehicleobj.VehicleStatestr(previousState);
    ASSERT_STREQ(str1,str4);

    previousState= parkingobj.CheckingSlotAvailability(-1,-1,-1);
    const char* str3= vehicleobj.VehicleStatestr(previousState);
    ASSERT_STREQ(str1,str3);
}

