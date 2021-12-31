/**
 * File: CBox.cpp
 * 
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 15/12/2021
 * 
 * Description: CBox class for CShape3d assingment
 * 
 */

class CBox : public CShape3d {
    private:
        float h, w, l;                  // Attributes for height (h), width (w) and length (l)
    public:
        CBox(float, float, float);      // Constructor for CBox, receiving h, w and l as parameters
        float volume();                 // Implementation of volume() method for box shape
};

CBox::CBox(float h, float w, float l){

}

float CBox::volume(){

}