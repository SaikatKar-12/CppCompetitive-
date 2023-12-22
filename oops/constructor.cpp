#include<iostream>
using namespace std;
class bike{
    public:
    int tyreSize;
    int engineSize;
    bike(int tyreSize,int engineSize){
        this->tyreSize=tyreSize;
        this->engineSize=engineSize;
    }
    ~bike(){
        cout<<"destructor call hua"<<endl;
    }
};
int main(){
    bike tvs(17,300);
    bike yamaha(12,400);
    bike moto(19,250);
    cout<<tvs.engineSize<<" "<<tvs.tyreSize<<endl;
    cout<<yamaha.engineSize<<" "<<yamaha.tyreSize<<endl;
    cout<<moto.engineSize<<" "<<moto.tyreSize<<endl;
    return 0;
}