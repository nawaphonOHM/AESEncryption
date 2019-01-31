#include<stdio.h>


 unsigned int bigDot(unsigned int A, unsigned int B);
 unsigned int divbinomial(unsigned int A);
 unsigned int testingMaxbit(unsigned int A);


int main(){
     unsigned int input[4][4] = {
        {0x29, 0x96, 0xb7, 0x7b}, 
        {0xd7, 0x11, 0xea, 0xd8}, 
        {0x02, 0xfc, 0x37, 0xab}, 
        {0x16, 0x3a, 0x46, 0x6a}
    };
     unsigned int constant[4][4] = {
        {0x02, 0x03, 0x01, 0x01}, 
        {0x01, 0x02, 0x03, 0x01}, 
        {0x01, 0x01, 0x02, 0x03}, 
        {0x03, 0x02, 0x01, 0x02}
    };

     unsigned int counterA, counterB, counterC;

     unsigned int temAnswer = 0x0;


    for(counterA = 0; counterA < 4; counterA++){
        for(counterB = 0; counterB < 4; counterB++){
            for(temAnswer = 0, counterC = 0; counterC < 4; counterC++){
                temAnswer = temAnswer ^ bigDot(
                        constant[counterA][counterC], 
                        input[counterC][counterB]
                    );
            }
            temAnswer = divbinomial(temAnswer);
            printf("%02x\t", temAnswer);
        }
        printf("\n");
    }

    return 0;
}

 unsigned int bigDot( unsigned int A,  unsigned int B){
     unsigned int bSmail = 0, tempAns = 0, state = 0, answer = 0;

    while(B > 0){
        bSmail = B % 2;
        B = B >> 1;

        if(bSmail == 1){
            tempAns = A & 0xffffffff;
        }
        else{
            tempAns = A & 0x0;
        }
        tempAns = tempAns << state++;

        answer = answer ^ tempAns;
        tempAns = 0;
    }

    return answer;
}

 unsigned int divbinomial( unsigned int A){
     unsigned int CONSTANT = 0x11b, maxbitCONSTANT = 8;
     unsigned int sampleA = 1, diffdregree = 0;
     unsigned int newValue = 0;
     unsigned int currentBit = testingMaxbit(A);

    while(currentBit >= maxbitCONSTANT){
        diffdregree = currentBit - maxbitCONSTANT;
        newValue = CONSTANT << diffdregree;

        A = A ^ newValue;
        currentBit = testingMaxbit(A);
    }

    return A;
}

unsigned int testingMaxbit(unsigned int A){
    unsigned int tempNum = 1, bit = 0;

    while(tempNum < A){
        tempNum = tempNum << 1;
        bit++;
    }

    return bit - 1;
    
 }
