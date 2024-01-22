#include <iostream>
#include <algorithm>
using namespace std;

class Process
{ 
  public:
  int processID;
  float BT;
  float AT;
  float CT;
  float TAT;
  float WAT;



  void getData(){
    cout << "Enter the processID : " ;
    cin >> processID ;
    cout << "Enter the arrival time : " ;
    cin >> AT;
    cout << "Enter the burst time : " ;
    cin >> BT;
  }

  float calculateCT(float temp){
    CT = temp + BT;
    return  CT;
  }

  void calculateTAT(){
    TAT = CT ;
  }

  void calculateWAT(){
    WAT = TAT - BT;
  }

  void displayData(){
    cout <<"\t" << processID <<"\t"<<AT <<"\t" << BT <<"\t" << CT <<"\t" << TAT <<"\t" << WAT <<endl;
  }


};
bool compareByBT(Process p1, Process p2) {
  return p1.BT < p2.BT ;
}

int main() {
  Process P[10];
  int n;
  cout <<"Enter the number of processes : ";
  cin >> n;

  for(int i = 0; i < n; i++){
    P[i].getData();
  }

sort(P,P+n,compareByBT);

float temp = 0;
float temp1;
for (int i=0 ;i<n;i++){
  temp1 = P[i].calculateCT(temp);
  temp = temp1;
  P[i].calculateTAT();
  P[i].calculateWAT();
}

float ATAT =0 , AWAT =0;
for (int i=0;i<n;i++){
  ATAT = ATAT + P[i].TAT;
  AWAT = AWAT + P[i].WAT;
}
ATAT = ATAT / n;
AWAT = AWAT / n;

cout <<"Process      AT       BT       CT       TAT      WAT"<<endl;
for(int i=0;i<n;i++){
  P[i].displayData();
}


cout<<"Avg ATAT =" << ATAT <<endl;
cout<<"Avg AWAT =" << AWAT;

return 0;
}