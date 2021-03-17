#include "snowman.hpp"
#include <string>
#include <stdexcept>
using namespace std;

/**
 * {H,N,L,R,X,Y,T,B}
 * {1,2,3,4,5,6,7,8}
 */

namespace ariel
{
    string snowman(int input)
    {
        if (!check_isvalid(input))
        {
            string msg = "Invalid code '" + to_string(input) + "'";
            throw invalid_argument(msg);
        }
     
        return buildSnowman(input);
    }

    bool check_isvalid(int input)
    {
        int num = input;
        int x = 0;
        if (num > MAX_INPUT || num < MIN_INPUT)
        {
            return false;
        }
        while (num != 0)
        {
            x = num % DIVIDER;
            if (x > MAX_CHAR || x < MIN_CHAR)
            {
                return false;
            }
            num /= DIVIDER;
        }
        return true;
    }
    string buildSnowman(int input)
    {
        array<string, 4> hat = {"       \n _===_ \n", "  ___  \n ..... ", "   _   \n  /_\\\n", "  ___  \n (_*_) \n"};
        array<string, 4> Nose = {",", ".", "_", " "};
        array<string, 4> Left_Eye = {"(.", "(o", "(O", "(-"};
        array<string, 4> Right_Eye = {".)", "o)", "O)", "-)"};
        array<string, 4> Left_Arm = {"<", "\\", "/", " "};
        array<string, 4> Right_Arm = {">", "/", "\\", " "};
        array<string, 4> Torso = {"( : )", "(] [)", "(> <)", "(   )"};
        array<string, 4> Base = {"( : )", "(\" \")", "(___)", "(   )"};

        string s;

        int reversedNumber = 0;
        int remainder = 0;
        int x = 0;
        int c = 1;

        while (input != 0)
        {
            remainder = input % DIVIDER;
            reversedNumber = reversedNumber * DIVIDER + remainder;
            input /= DIVIDER;
        }
        int dupreversedNumber = reversedNumber;
        int i = 0;
        dupreversedNumber /=DIVIDER;
        int keep2=(dupreversedNumber % DIVIDER) - 1;
        dupreversedNumber=reversedNumber;
        while (i != MAX_CHAR)
        {
            dupreversedNumber /= DIVIDER;
            i++;
        }
        int keep5 = (dupreversedNumber % DIVIDER) - 1;
        dupreversedNumber /= DIVIDER;
        int keep6 = (dupreversedNumber % DIVIDER) - 1;
        while (reversedNumber != 0)
        {
            x = (reversedNumber % DIVIDER) - 1;
            reversedNumber /= DIVIDER;
    
            switch (c)
            {
            case H:
                s += hat.at(x);
                break;
            case N:
               // s += Nose.at(x);
                break;
            case L:
            if(keep5==1){
                s += Left_Arm.at(keep5)+Left_Eye.at(x)+Nose.at(keep2);
//"\n_===_\n(.,.)\n( : )\n( : )"
            }
            else
            {
                s +=" "+Left_Eye.at(x)+Nose.at(keep2);
            }
            
                break;
            case R:
             if(keep6==1){
                s += Right_Eye.at(x)+Right_Arm.at(keep6)+"\n";
             }
             else{
                 s +=Right_Eye.at(x)+"\n";
             }
                break;
            case X:
            if(keep5!=1){
                s += Left_Arm.at(keep5);
            }
                break;
            case Y:
            //  if(x!=1){
            //     s += Right_Arm.at(x);
            //  }
                break;
            case T:
            if(keep6!=1){
                s += Torso.at(x)+Right_Arm.at(keep6)+"\n";
            }
            else{
                  s += Torso.at(x)+"\n";
            }
                break;
            case B:
                s += Base.at(x);
                break;
            }
            c++;
        }
        return s;
    }
}
