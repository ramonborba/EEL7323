/**
 * File: CCylinder.cpp
 * 
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 15/12/2021
 * 
 * Description: CCylinder class for CShape3d assingment
 * 
 */

class CCylinder : public CShape3d {
    private:
        float r, h;                  // Attributes for radius (r) and height (h)
    public:
        CCylinder(float, float, float);      // Constructor for CCylinder, r and h as parameters
        float volume();
};

CCylinder::CCylinder(float h, float w, float l){

}

float CCylinder::volume(){
    
}