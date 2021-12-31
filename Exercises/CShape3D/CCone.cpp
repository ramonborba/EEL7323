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

class CCone : public CShape3d {
    private:
        float r, h;                  // Attributes for radius (r) and height (h)
    public:
        CCone(float, float);      // Constructor for CCone, receiving r and h as parameters
        float volume();
};

CCone::CCone(float r, float h){

}

float CCone::volume(){
    
}