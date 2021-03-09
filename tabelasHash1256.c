#include <stdio.h>
#include <stdlib.h>

struct lista{
    int v;
    struct lista *prox;
};

struct lista *inserir(struct lista *ini,int v){ 
    struct lista *aux = (struct lista *)malloc(sizeof(struct lista));
    
    aux->v = v;
    aux->prox = NULL;
    
    if(ini==NULL){
        ini = aux;
    }else{
        struct lista *ultimo = ini;
        
        while(ultimo->prox!=NULL){
            ultimo = ultimo->prox;
        }
        
        ultimo->prox = aux;
        aux->prox = NULL;
    }
    
    return ini;
}

void alocar(int vet[],int tamanho,int valorRecebido){ 
    int i;
    int vet2[tamanho];

    for(i=0;i<tamanho;i++){
        vet2[i] = vet[i] % valorRecebido; 
    }

    struct lista *list[valorRecebido];

    for(i=0;i<valorRecebido;i++){
        list[i] = NULL; 
    }

    struct lista *ini = NULL;
    int t=0,j,v=0;
    
    for(i=0;i<tamanho;i++){
        v = vet2[i];

        for(j=0;j<tamanho;j++){
            if(vet2[j]==v && t <= tamanho){
                ini = inserir(ini,vet[j]);
                list[vet2[j]] = ini;
                t++;
            }
        }

        ini = NULL;
        t = 0;
    }

    struct lista *aux = NULL;
    int cont=0;

    for(i=0;i<valorRecebido;i++){
        cont++;
        aux = list[i];
        printf("%d -> ",i);
       
        while(aux!=NULL){
            if(aux->prox!=NULL){
                printf("%d -> ",aux->v);
            }else{
                printf("%d -> \\",aux->v); 
            }

            aux = aux->prox;
        }

        if(list[i]==NULL){
            printf("\\"); 
        }

        if(cont <= valorRecebido-1){
            printf("\n"); 
        }
    }
}

int main(){
    int a,b,i,teste;

    scanf("%d",&teste);

    while(teste--){
        scanf("%d %d",&a,&b);

        int vet[b];
        for(i=0;i<b;i++){

            scanf("%d",&vet[i]);
        }

        alocar(vet,b,a);

        if(teste > 0){
            printf("\n\n");
        }else{
            printf("\n");
        }
    }
    return 0;
}