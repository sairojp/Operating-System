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
  float flag = 0;



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
    flag = 1;
    return  CT;
  }

  void calculateTAT(){
    TAT = CT - AT ;
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
bool compareByAT(Process p1, Process p2) {
  return p1.AT < p2.AT ;
}

int main() {
  Process P[10];
  int n;
  cout <<"Enter the number of processes : ";
  cin >> n;

  for(int i = 0; i < n; i++){
    P[i].getData();
  }
float temp = 0;
float temp1;

sort(P,P+n,compareByAT);
temp1 = P[0].calculateCT(temp);
sort(P,P+n,compareByBT);
temp = temp1;
float num = 0;

jump:
for (int i=0 ;i<n;i++){
  if(P[i].AT <= temp1 && P[i].flag == 0 ){
    temp1 = P[i].calculateCT(temp);
    temp = temp1;
    num++;
  }
}

if(num != n-1){
 goto jump;
}

for (int i=0 ;i<n;i++){
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