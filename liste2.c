#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista{

    int id;
    int valore;
    struct lista *next;

}Lista;

typedef struct lista lista;

lista* inserisci(lista* head);
void stampa(lista *head);
lista* inseriscidafile(lista* head);

int main(){

    int cnt=1;
    lista *head=NULL;
    int ctrl;

    while(1){

        printf("\n1 - inserisci in lista\n2 - stampa la lista\n3 - inserisci da file\n");
        scanf("%d",&ctrl);
        switch(ctrl){
            case 1: head = inserisci(head);
                    break;
            case 2: stampa(head);
                    break;
            case 3: head = inseriscidafile(head);
                    break;
            default: return 0;


        }
    }


return 0;}


lista* inserisci(lista* head){

    int id, valore;

    lista* nuovo=NULL;
    nuovo=(lista*)malloc(sizeof(lista));

    printf("\ninserisci l'id dell'elemento\n");
    scanf("%d", &id);
    nuovo->id=id;
    printf("\ninserisci il valore:\n");
    scanf("%d",&valore);
    nuovo->valore=valore;

    nuovo->next=head;
    head=nuovo;



return (head);
}

void stampa(lista* head){

    int cnt=1;

    lista* pt=head;

    while(pt!=NULL){

        printf("\nelem.%d --> id:%d\tvalore:%d\n",cnt,pt->id,pt->valore);
        cnt++;
        pt=pt->next;

    }



return;
}

lista* inseriscidafile(lista* head){

    FILE* fp;
    lista* pt;
    int id, valore, i=1;
    char riga[10];

    fp=fopen("prova.txt","r");


    if(fp!=NULL){
            while(fscanf(fp,"%d %d\n",&id,&valore)!=EOF){

                pt=(lista*)malloc(sizeof(lista));
                pt->id=id;
                pt->valore=valore;

                printf("\ninserimento %d ok\n", i);
                i++;

                pt->next=head;
                head=pt;

                            }
                }else{

                printf("\nerrore apertura file\n");

                    }


    fclose(fp);


return head;
}
