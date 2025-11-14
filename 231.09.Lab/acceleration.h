/***********************************************************************
 * Header File:
 *    ACCELERATION 
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about acceleration
 ************************************************************************/


#pragma once

class Angle;
class TestVelocity;
class TestAcceleration;


/*********************************************
 * Acceleration
 * Let's get moving
 *********************************************/
class Acceleration
{

public:

    friend TestVelocity;
    friend TestAcceleration;

   // constructors
   Acceleration() {
       ddx = 0.0;
       ddy = 0.0;
   }
   Acceleration(double ddx, double ddy) {
       this->ddx = ddx;
       this->ddy = ddy;
   }

   // getters
   double getDDX() const {
       return ddx;
   }
   double getDDY() const {
       return ddy;
   }
                                     
   // setters                        
    void setDDX(double ddx) {
        this->ddx = ddx;
   }
   void setDDY(double ddy) {
        this->ddy = ddy;
   }
   void set(const Angle & a, double magnitude);
   void addDDX(double ddx) {
       this->ddx = this->ddx + ddx;
    }
   void addDDY(double ddy) {
       this->ddy = this->ddy + ddy;
    }
   void add(const Acceleration& rhs);

private:
   double ddx;     // horizontal acceleration
   double ddy;     // vertical acceleration
};
