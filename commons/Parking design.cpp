/*
    uname: karankulx
    companies: mainly asked in screening or phone interviews by Google
    qlink: https://leetcode.com/problems/design-parking-system/description/
    qname: Design Parking System
*/

class ParkingSystem {
public:
    int b, m, s;
    ParkingSystem(int big, int medium, int small) {
        b = big;
        m = medium;
        s = small;
    }
    
    bool addCar(int c) {
       if(c == 1) {
           if(b > 0) {
               b--;
               return true;
           } else return false;
       } else if(c == 2) {
           if(m > 0) {
               m--;
               return true;
           } else return false;
       } else if(c == 3) {
           if(s > 0) {
               s--;
               return true;
           } else false;
       }
       return false; 
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */