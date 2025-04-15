/*max among 4 number*/

#include<stdio.h>

int main(){

                int a[10]={99,56,54,77,2,1,6,4,3,66};
                int max=0;
                int smax=0, tmax=0;
                for(int i=0;i<10;i++){

                    if(max<a[i]){
                        tmax=smax;
                        smax=max;
                        max=a[i];
                    }
                    else if(smax<a[i]){
                        tmax=smax;
                        smax=a[i];
                    }
                    else if(tmax<a[i]){
                        tmax=a[i];
                    }
                }
                printf("%d %d %d\n",max,smax,tmax);

return 0;
          }
