/**
 * File: CShape3d.cpp
 * 
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 15/12/2021
 * 
 * Description: CShape3d abstract class for CShape3d assingment
 * 
 */

class CShape3d {
    public:
        virtual float volume() = 0;         // Pure virtual function for volume calculation, to be implemented by derived classes
};