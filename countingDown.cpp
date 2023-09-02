#include<iostream>
#include <unistd.h> 

using namespace std;
int main(){


    int num;
    cin>>num;
     const int microToSeconds = 1000000;   // 1 second = 1,000,000 microseconds
    const double delay1 = 1 * microToSeconds; // 1 second delay
    for (int i = num; i > 0; i--)//counting down
    {
        cout<<i<<endl;//print the number
        if(i!=1){
        usleep(delay1);//delay for 1 second
        }

    }
    cout<<"Blast off to the moob!"<<endl;



    return 0;
}