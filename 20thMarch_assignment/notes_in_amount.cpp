#include<iostream>
using namespace std;

int main(){
    int amount;
    int n1,n2,n5,n10,n50,n100,n500;
    n1=n2=n5=n10=n50=n100=n500=0;
    cout<<"Enter your amount:";
    cin>>amount;
    switch(amount>=500){
        case 1:
        n500=amount/500;
        amount-=n500*500;
        break;
    }
    switch(amount>=100){
        case 1:
        n100=amount/100;
        amount-=n100*100;
        break;
    }
    switch(amount>=50){
        case 1:
        n50=amount/50;
        amount-=n50*50;
        break;
    }
    switch(amount>=10){
        case 1:
        n10=amount/10;
        amount-=n10*10;
        break;
    }
    switch(amount>=5){
        case 1:
        n5=amount/5;
        amount-=n5*5;
        break;
    }
    switch(amount>=2){
        case 1:
        n2=amount/2;
        amount-=n2*2;
        break;
    }
    switch(amount>=1){
        case 1:
        n1=amount/1;
        break;
    }
    cout<<"500="<<n500<<" 100="<<n100<<" 50="<<n50<<" 10="<<n10<<" 5="<<n5<<" 2="<<n2<<" 1="<<n1;
    return 0;
}