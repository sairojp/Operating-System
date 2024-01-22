#include <stdio.h>
int main (){

int processId[10];
int bt[10];
int at[10];
int n;
printf("Enter the number of processes :");
scanf("%d",&n);

printf("Enter the process id of the processes :");
for(int i=0;i<n;i++){
    scanf("%d",&processId[i]);
}
printf("Enter the burst time  of the processes :");
for(int i=0;i<n;i++){
    scanf("%d",&bt[i]);
}

printf("Enter the arrival time  of the processes :");
for(int i=0;i<n;i++){
    scanf("%d",&at[i]);
}


int i , ct[n],wt[n],tat[n];
int temp = 0;
for(int i=0;i<n;i++){
    ct[i]=temp+bt[i];
    temp = ct[i];
    }

    for(int i=0;i<n;i++){
    tat[i]=ct[i]-at[i];
    }

    for(int i=0;i<n;i++){
    wt[i]=tat[i]-bt[i];
    }

printf("ProcessID     Burst time      Completion time      TAT       WT  ");
printf("\n");
for(int i=0;i<n;i++){
    printf("%d\t\t",processId[i]);
    printf("%d\t\t",bt[i]);
    printf("%d\t\t",ct[i]);
    printf("%d\t\t",tat[i]);
    printf("%d\t\t",wt[i]);
    printf("\n");
}
float atat =0 ,awt = 0;

for(int i=0;i<n;i++){
    atat = atat + tat[i];
    awt = awt + wt[i];
    }
atat = atat/n;
awt = awt/n;
printf("Avg TAT = %f",atat);
printf("Avg WT = %f",awt);



return 0;
}