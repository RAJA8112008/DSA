        #include<iostream>
using namespace std;

    int dectobinary(int num){
        int ans=0; pow=1;
        while(dec>0){
            int rem=dec num%2;
            dec num/=2;

            ans=+(rem*num);
            pow*=10;
        }
        return ans;
        
    }
    int main(){
        int decnum=50;
        cout<<dectobinary(decnum)<<endl;
        return 0;
    }
