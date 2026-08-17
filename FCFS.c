#include<stdio.h>
struct process{
	int at,ct,bt,tat,wt;
};
void sort(struct process a[],int n){
	int i,j,t;
	for(i=0;i<n;i++){
		for(j=1;j<n;j++){
			if (a[i].at<a[j].at){
				t=a[i].at;
				a[i].at=a[j].at;
				a[j].at=t;		
			}
		}
	}
}
int main()
{
	int n,i,j;
	printf("enter number of processes:\n");
	scanf("%d",&n);
	struct process p[n];
	for(i=0;i<n;i++){
		
	printf("enter arrival and burst time of p%d: \n",i+1);
	scanf("%d %d",&p[i].at,&p[i].bt);
	}
	sort(p,n);
//	complition time
    int currentt=0; 
    for (i=0;i<n;i++){
    	if (currentt<p[i].at){
    		currentt=p[i].at;
		}
		currentt+=p[i].bt;
		p[i].ct=currentt;
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
	}
	printf("\n Arrival time   burst time  complition time  turnaround time  wait time\n");
	for(i=0;i<n;i++){
		printf("      %d            %d              %d             %d     %d     \n",p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	}
}
