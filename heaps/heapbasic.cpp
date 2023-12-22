#include<iostream>
#include<vector>
using namespace std;

class MaxHeap{
    vector<int> hp;
    void upheapify(int ci){
        while(ci>0){
            int pi =(ci-1)/2;
            if(hp[pi]<hp[ci]){
                swap(hp[pi],hp[ci]);
                ci=pi;
            }else break;
        }
    }
    void downheapify(int idx){
        while(idx<hp.size()){
            int lc=2*idx+1;
            int rc=2*idx+2;
            if(lc>=hp.size()) break;
            int maxEl=idx;
            if(hp[lc]>hp[maxEl]) maxEl=lc;
            if(rc<hp.size() && hp[rc]>hp[maxEl]) maxEl=rc;
            if(maxEl!=idx){
                swap(hp[maxEl],hp[idx]);
                idx=maxEl;
            }else break;
        }
    }
public:
    void display(){
        for(int i=0;i<hp.size();i++){
            cout<<hp[i]<<" ";
        }
        cout<<endl;
    }

    void push(int val){
        hp.push_back(val);
        upheapify(hp.size()-1);
    }

    void pop(){
        if(hp.size()==0) return;
        swap(hp[0],hp[hp.size()-1]);
        hp.pop_back();
        downheapify(0);
    }

    MaxHeap(vector<int> v){
        hp=v;
        for(int i=1;i<hp.size();i++){
            upheapify(i);
        }
    }
};

int main(){
    vector<int> v = {9,6,1,19,3,2,8,12,5};
    MaxHeap hp(v);
    hp.display();
    return 0;
}