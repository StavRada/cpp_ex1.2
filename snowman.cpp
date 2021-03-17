#include "snowman.hpp"
#include <iostream>
#include <string>
#include <array>
#include <exception>
using namespace std;

const int SIZE_NUMBER = 8,
 HAT=0, 
 NOSE=1,
 LEFT_EYE=2,
 RIGHT_EYE=3,
 LEFT_ARM=4,
 RIGHT_ARM=5,
 TORSO=6,
 BASE= 7,
 MAX_SIZE=44444444,
 MIN_SIZE=11111111,
 MAX_INT=4,
 MIN_INT=1;

 void check_input(int n){
    if(n > MAX_SIZE || n < MIN_SIZE){
        throw std::out_of_range("size is out of range");
    }
    for (int i = SIZE_NUMBER; i > 0; --i) {
        if(n % 10 < 1 || n % 10 > 4){
            throw std::out_of_range("value out of range");
        }
        n = n/10;
    }
}

array<int,SIZE_NUMBER> input_digits(int n){
    array<int,SIZE_NUMBER> arr = {};
    arr.at(0) = 0;
    const int base=10;
            
    for(int i = SIZE_NUMBER; i > 0; i--){
        arr.at(i-1) = n % base-1;
        n /= base;
    }
    return arr;
}

const array<std::string,4> hats = {" _===_","  ___\n .....", "   _\n  /_\\","  ___\n (_*_)"};
const array<std::string,4> noses = {",",".","_"," "};
const array<std::string,4> eyes = {".","o","O","-"};
const array<std::string,4> left_arm_tops = {" ","\\"," "," "};
const array<std::string,4> left_arms = {"<"," ","/"," "};
const array<std::string,4> right_arm_tops = {" ","/"," "," "};
const array<std::string,4> right_arms = {">"," ","\\"," "};
const array<std::string,4> torsos = {" : ", "] [","> <", "   "};
const array<std::string,4> bases = {" : ", "\" \"", "___","   "};


std::string build_base(int n){
    std::string low = "("+bases.at(n)+ ")";
    return low;
}

std::string build_body(array<int,SIZE_NUMBER> n){
    std::string body =left_arms.at(n.at(LEFT_ARM))+"("+torsos.at(n.at(TORSO))+")"+right_arms.at(n.at(RIGHT_ARM));
    return body;
}

std::string build_face(array<int,SIZE_NUMBER> n){
    std::string face = left_arm_tops.at(n.at(LEFT_ARM))+"("+eyes.at(n.at(LEFT_EYE))+noses.at(n.at(NOSE))+eyes.at(n.at(RIGHT_EYE))+")"+right_arm_tops.at(n.at(RIGHT_ARM));
    return face;
}

std::string build_snowman(array<int,SIZE_NUMBER> n){
    //create the base
    std::string base = build_base(n.at(BASE));
    //create torso
    std::string body = build_body(n);
    //create the hat
    std::string hat = hats.at(n.at(HAT));
    //create the face
    std::string face = build_face(n);
    return hat+"\n"+face+"\n"+body+"\n "+base+"\n";
}

namespace ariel {

    string snowman(int str){      

        check_input(str);
        array<int,SIZE_NUMBER> Digits = input_digits(str);
        return build_snowman(Digits);

    }  

}
//int main(){
 //   std::cout<< ariel::snowman(14134411);
  //  return 0;
//}