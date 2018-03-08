#include<stdio.h>
#include<stdlib.h> 
#include<string.h>


int evaluer(int *tab, int *tmin, int *tmax, int **mt, int nb){
  int time = 0;
  int retard = 0;
  int i=1;
  
  for(i=1;i<nb;i++){
      int sor = tab[i-1];
      int des = tab[i];
      time+=mt[sor][des];
      if(time < tmin[des])retard += tmin[des] - time;
      else if(time > tmax[des])retard += time - tmax[des];
  }
  
  return retard;
}

void affiche(int *tab, int nb){
  int i=0;
  
  for(i=0;i<nb;i++){
    printf("%d ",tab[i]);
  }
  printf("\n");
}


int *glouton_fonct(int *tmin, int *tmax, int **mt, int nb){
      int ems[nb-1];
      int i = 0;
      
      for (i=1; i<nb; i++){
		ems[i-1] = i;
	
      }
      
      int *res = malloc(nb*sizeof(int));
      res[0] = 0;
      printf ("\nok\n");
      
      for (i=1;i < nb; i++){
	  int min = 10000000;
	  int j,numb_next;
	  for (j = 0; j < nb-1; j++){
	      if(ems[j]==0)continue;
	      res[i] = ems[j];
	      int evl = evaluer(res,tmin,tmax,mt,i+1);
	      if(evl<min){
		numb_next = ems[j];
		min = evl;
	      }
	    
	  }
	  
	  res[i] = numb_next;
	  ems[numb_next-1] = 0;
	
      }
      printf("Sequence Glouton :"); 
		affiche(res,nb);
      return res;
  
}


