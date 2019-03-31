#include <iostream>
#include <cmath>
#include <cstdlib>
#include <chrono>
using namespace std;
int checkGuessRepeat(int guessArray[],int digits){
    for(int j=0;j<digits;j++){
            if(guessArray[j]==guessArray[j+1]){
                return 1;
            } 
                return 0; 
        }
    }
int RightAmountDigits(int code,int digits){
    if(digits==3){
        if(code>999){
            return 1;
        }}
    if(digits==4){
        if(code>9999){
            return 1;
        }}  
     if(digits==3){
        if(code>99999){
            return 1;
        }}
return 0;}
void BullsandCows(int *array, int *guess,int* bulls,int* cows, int digits){
int counterB=0;
int counterC=0;
for (int i=0;i<digits;i++){
    if(guess[i]==array[i]){
        counterB++;}
    for (int j=0;j<digits;j++){
        if(guess[j]==array[i]){
            counterC++;}
            }}
    *bulls=counterB;
    *cows=counterC-counterB; 
}
int codeReform(int code,int digits){
int modulus=pow(10,digits+1);
double seperated=code%modulus;
double numbers=seperated/pow(10,digits);
return numbers;   
}
int randomGenerator(){
    return rand()%10;
}
int randomGenerator(int first){
int randNum=rand()%10;
bool breaker=true;
do{
    if (randNum==first){
        randNum= randomGenerator();}
    else{breaker=false;}
}while(breaker==true);
return randNum;
}
int randomGenerator(int first, int second){
int randNum= rand()%10;
bool breaker=true;
do{ 
    if (randNum==first || randNum==second){
        randNum=randomGenerator();}
    else{ breaker=false;}
}while(breaker==true);
return randNum;
}
int randomGenerator(int first, int second, int third){
int randNum= rand()%10;
bool breaker=true;
do{ 
    if (randNum==first || randNum==second || randNum==third){
        randNum= randomGenerator();}
    else{breaker=false;}
}while(breaker==true);
return randNum;
}
int randomGenerator(int first, int second, int third,int fourth){
int randNum=rand()%10;
bool breaker=true;
do{ 
    if (randNum==first || randNum==second|| randNum==third || randNum==fourth){
        randNum= randomGenerator();}
    else{ breaker=false;}
}while(breaker==true);
return randNum;
}
int main(){
    srand(std::chrono::duration_cast<std::chrono::milliseconds>
     (std::chrono::system_clock::now().time_since_epoch()).count()%2000000000); 
    // needed to autograde some test cases in Mimir
int code;
int digits;
int five[5]={0,0,0,0,0};
cout<<"Enter number of digits in code (3, 4 or 5): ";
cin>>digits;
if (digits==0){//Cheat Code 
    cout<<"Enter code: ";
    cin>>code;
    cout<<"Enter number of digits in code: ";
    cin>>digits;
    if (digits==3){//change 29 to 029
        for(int a=2;a>=0;a--){
        five[a]=codeReform(code,a);
        }
        cout<<"Number to guess: ";
        for(int i=digits-1;i>=0;i--){
        cout<<five[i];
        if(i!=0)
            cout<<"-";}
        cout<<endl;
        }
    else if (digits==4){//change 29 to 0029
        for(int b=3;b>=0;b--){
        five[b]=codeReform(code,b);
        }
        cout<<"Number to guess: ";
        for(int i=digits-1;i>=0;i--){
        cout<<five[i];
        if(i!=0)
            cout<<"-";}
        cout<<endl;}
    else if (digits==5){//changing 29 to 00029
        for(int c=4;c>=0;c--){
        five[c]=codeReform(code,c);
        }
        cout<<"Number to guess: ";
        for(int i=digits-1;i>=0;i--){
       cout<<five[i];
        if(i!=0)
            cout<<"-";}
        cout<<endl;
        }}
/*****************************************/
else if (digits==3){//number of digits is 3
    five[2]=randomGenerator();
    five[1]=randomGenerator(five[2]);
    five[0]=randomGenerator(five[1],five[2]);
      cout<<"Number to guess: ";  
    for(int k=digits-1;k>=0;k--){
        cout<<five[k]<<"-";
        cout<<five[k];
        if(k!=0)
            cout<<"-";}
        cout<<endl;
        }
/************************************************/
else if (digits==4){//number of digits is 4
    five[3]=randomGenerator();
    five[2]=randomGenerator(five[3]);
    five[1]=randomGenerator(five[3],five[2]);
    five[0]=randomGenerator(five[3],five[2],five[1]);
        for(int v=digits-1;v>=0;v--){
        cout<<five[v]<<"-";}
}
else if (digits==5){//number of digits is 5
    five[4]=randomGenerator();
    five[3]=randomGenerator(five[4]);
    five[2]=randomGenerator(five[4],five[3]);
    five[1]=randomGenerator(five[4],five[3],five[2]);
    five[0]=randomGenerator(five[4],five[3],five[2],five[1]);  
        for(int k=digits-1;k>=0;k--){
        cout<<five[k]<<"-";
        }
}
int bulls=0;
int cows=0;
bool checkDigits=1;
int guess;
int guessArray[5]={0,0,0,0,0};
do{
   int repeat=1;
   cout<<"Enter Guess: ";
   cin>>guess;
    for(int l=0;l<digits;l++){
        guessArray[l]=codeReform(guess,l);}
    do{ 
        repeat=checkGuessRepeat(guessArray,digits);
        if(repeat){ 
            cout<<"Each number must be different."<<endl;
            cout<<"Enter Guess: ";
            cin>>guess;
            for(int l=0;l<digits;l++){
                guessArray[l]=codeReform(guess,l);}
            repeat=checkGuessRepeat(guessArray,digits);
        }
        else 
            repeat=0;
    }while(repeat);
    do{
        checkDigits=RightAmountDigits(guess,digits);
        if(checkDigits){
            cout<<"You can only enter "<<digits<<" digits."<<endl;
            cout<<"Enter Guess: ";
            cin>>guess;
            for(int l=0;l<digits;l++){
                guessArray[l]=codeReform(guess,l);}
        }
    }while(checkDigits);
    BullsandCows(five,guessArray,&bulls,&cows,digits);
    if(bulls==digits){
    printf("%d bulls... ",bulls); 
        for(int i=digits-1;i>=0;i--){
           cout<<five[i];
            if(i!=0)
                cout<<"-";
            else{
                cout<< " is correct!"<<endl;
            }
        }
    }
    else{printf("%d bulls\n%d cows\n",bulls,cows );}
}while(bulls!=digits);
return 0;}