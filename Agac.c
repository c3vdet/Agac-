#include<stdio.h>
#include<stdlib.h>

struct n{
    int veri;
    struct n*sol;
    struct n*sag;
    
};

typedef struct n node;
 node*ekle (node*agac,int x){
 	if(agac==NULL){
 		node*root=(node*)malloc(sizeof(node));
 		root->sag=NULL;
 		root->sol=NULL;
 		root->veri=x;
 		return root;
	 }
	 if(agac->veri<x){
	 	agac->sag=ekle(agac->sag,x);
	 	return agac;	 	
	 }
	 agac->sol=ekle(agac->sol,x);
	 return agac;
 }
 void dolas (node*agac){
 	if(agac==NULL)
 		return ;
 	dolas(agac->sol);
 	printf("%d ",agac->veri);
 	dolas(agac->sag);
 	}

int bul (node*agac, int aranan){
    if(agac==NULL)
    return -1;
    if(agac->veri==aranan)
    return 1;
    if(bul(agac->sag,aranan)==1)
    return 1;
    if(bul(agac->sag,aranan)==1)
    return 1;

}
int max(node*agac){
	while(agac->sag!=NULL)
	agac=agac->sag;
	return agac->veri;
}
int min(node*agac){
	while(agac->sol!=NULL)
	agac=agac->sol;
	return agac->veri;
}
node*sil (node*agac, int x){
	if(agac==NULL)
	return NULL;
	if(agac->veri==x){
	if(agac->sol==NULL && agac->sag==NULL)
	return NULL;
	if(agac->sag!=NULL){
	agac->veri=min(agac->sag);
	agac->sag=sil(agac->sag,min(agac->sag));
	return agac;
}
	agac->veri = max(agac->sol);
	agac->sol=sil(agac->sol,max(agac->sol));
	return agac;
}
	if(agac->sag<x){
	agac->sag=sil(agac->sag,x);
	return agac;
}
	agac->sol=sil(agac->sol,x);
	return agac;
}
	
int main()
{
	node*agac=NULL;
	agac=ekle(agac,100);
	agac=ekle(agac,150);
	agac=ekle(agac,200);
	agac=ekle(agac,50);
	agac=ekle(agac,300);
	agac=ekle(agac,25);
	dolas(agac);
	printf("\nMax: %d \nMin: %d\n", max(agac),min(agac));
	agac=sil(agac,50);
	dolas(agac);
	printf("\nMax: %d \nMin: %d\n", max(agac),min(agac));
	agac=sil(agac,25);
	dolas(agac);
	printf("\nMax: %d \nMin: %d\n", max(agac),min(agac));
	agac=sil(agac,300);
	dolas(agac);
	printf("\nMax: %d \nMin: %d\n", max(agac),min(agac));
	
	
}
	 
	 
 