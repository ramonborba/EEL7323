/**
 * File: CCone.cpp
 * 
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 15/12/2021
 * 
 * Description: CCone class for CShape3d assingment
 * 
 */
#ifndef _PI_
#define PI 3.1415926536
#endif /* _PI_ */

class CCone : public CShape3d {
    private:
        float r, h;                 // Attributes for radius (r) and height (h)
    public:
        CCone(float, float);        // Constructor for CCone, receiving r and h as parameters
        float volume();             // Implementation of volume() method for cone shape
};

CCone::CCone(float r, float h){
    this->r = r;
    this->h = h;
}

float CCone::volume(){
    return PI*r*r*h/3;
}