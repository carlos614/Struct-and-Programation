#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

struct carro{
char nome[30];
char marca[30];
int ano;
float preco;
};

struct No{
int numero;
struct carro x;
struct No *esquerda;
struct No *direita;

};
typedef struct No No;

void criarArvore(No **pRaiz){
*pRaiz = NULL;
}

void inserir(No **pRaiz, int numero, struct carro x){
if(*pRaiz == NULL){
*pRaiz = (No *) malloc(sizeof(No));
(*pRaiz)->esquerda = NULL;
(*pRaiz)->direita = NULL;
(*pRaiz)->numero = numero;
(*pRaiz)->x = x;
}else{
if(numero < (*pRaiz)->numero)
inserir(&(*pRaiz)->esquerda, numero, x);
if(numero > (*pRaiz)->numero)
inserir(&(*pRaiz)->direita, numero, x);
}
}

No *MaiorDireita(No **no){
if((*no)->direita != NULL)
return MaiorDireita(&(*no)->direita);
else{
No *aux = *no;
if((*no)->esquerda != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esquerda!
*no = (*no)->esquerda;
else
*no = NULL;
return aux;
}
}

No *MenorEsquerda(No **no){
if((*no)->esquerda != NULL)
return MenorEsquerda(&(*no)->esquerda);
else{
No *aux = *no;
if((*no)->direita != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da direita!
*no = (*no)->direita;
else
*no = NULL;
return aux;
}
}

void remover(No **pRaiz, int numero){
if(*pRaiz == NULL){ // esta verificacao serve para caso o numero nao exista na arvore.
printf("Numero nao existe na arvore!");
getch();
return;
}
if(numero < (*pRaiz)->numero)
remover(&(*pRaiz)->esquerda, numero);
else
if(numero > (*pRaiz)->numero)
remover(&(*pRaiz)->direita, numero);
else{ // se nao eh menor nem maior, logo, eh o numero que estou procurando! ??
No *pAux = *pRaiz; // quem programar no Embarcadero vai ter que declarar o pAux no inicio do void! :[
if (((*pRaiz)->esquerda == NULL) && ((*pRaiz)->direita == NULL)){ // se nao houver filhos…
free(pAux);
(*pRaiz) = NULL;
}
else{ // so tem o filho da direita
if ((*pRaiz)->esquerda == NULL){
(*pRaiz) = (*pRaiz)->direita;
pAux->direita = NULL;
free(pAux); pAux = NULL;
}
else{ //so tem filho da esquerda
if ((*pRaiz)->direita == NULL){
(*pRaiz) = (*pRaiz)->esquerda;
pAux->esquerda = NULL;
free(pAux); pAux = NULL;
}
else{ //Escolhi fazer o maior filho direito da subarvore esquerda.
pAux = MaiorDireita(&(*pRaiz)->esquerda); //se vc quiser usar o Menor da esquerda, so o que mudaria seria isso:
pAux->esquerda = (*pRaiz)->esquerda; // pAux = MenorEsquerda(&(*pRaiz)->direita);
pAux->direita = (*pRaiz)->direita;
(*pRaiz)->esquerda = (*pRaiz)->direita = NULL;
free((*pRaiz)); *pRaiz = pAux; pAux = NULL;
}
}
}
}
}

void exibirEmOrdem(No **pRaiz){
if((*pRaiz) != NULL){
exibirEmOrdem(&(*pRaiz)->esquerda);
printf("\n%i", (*pRaiz)->numero);
exibirEmOrdem(&(*pRaiz)->direita);
}

}

void exibirPreOrdem(No **pRaiz){
if((*pRaiz) != NULL){
printf("\n%i", (*pRaiz)->numero);
exibirPreOrdem(&(*pRaiz)->esquerda);
exibirPreOrdem(&(*pRaiz)->direita);
}
}

void exibirPosOrdem(No **pRaiz){
if((*pRaiz) != NULL){
exibirPosOrdem(&(*pRaiz)->esquerda);
exibirPosOrdem(&(*pRaiz)->direita);
printf("\n%i", (*pRaiz)->numero);
}

}

int contarNos(No **pRaiz){
if((*pRaiz) == NULL)
return 0;
else
return 1 + contarNos(&(*pRaiz)->esquerda) + contarNos(&(*pRaiz)->direita);
}

int contarFolhas(No **pRaiz){
if((*pRaiz) == NULL)
return 0;
if((*pRaiz)->esquerda == NULL && (*pRaiz)->direita == NULL)
return 1;
return contarFolhas(&(*pRaiz)->esquerda) + contarFolhas(&(*pRaiz)->direita);
}

int maior(int a, int b){
if(a > b)
return a;
else
return b;
}

int altura(No **pRaiz){
if(((*pRaiz) == NULL) || ((*pRaiz)->esquerda == NULL && (*pRaiz)->direita == NULL))
return 0;
else
return 1 + maior(altura(&(*pRaiz)->esquerda), altura(&(*pRaiz)->direita));
}

int main (){

struct carro ca;
int c;
No *pRaiz;
criarArvore(&pRaiz);
;
int op;
do{
printf("\n\n1 INSERIR CARRO: \n");
printf("2 REMOVER CARRO: \n");
printf("3 MOSTRAR CARROS EM ORDEM: \n");
printf("4 MOSTRAR CARROS EM PRE-ORDEM: \n");
printf("5 MOSTRA CARROS EM POS-ORDEM: \n");
printf("6 CONTAR NOS\n");
printf("7 CONTAR FOLHAS\n");
printf("8 ALTURA DA ARVORE\n");
printf("9 LIMPAR TELA\n");
printf("0 SAIR\n");
printf("DIGITE UMA OPCAO: ");
scanf("%d", &op);
switch(op){
case 1:
printf("\nNOME: ");
scanf("%s", &ca.nome);
printf("\nMARCA: ");
scanf("%s",&ca.marca);
printf("\nPRECO DO CARRO: ");
scanf("%f", &ca.preco);
printf("\nDIGITE UM NUMERO: ");
scanf("%d",&c);

inserir(&pRaiz,c,ca);
break;
case 2:
printf("\nDIGITE UM NUMERO: ");
scanf("%d",&c);
remover(&pRaiz,c);
break;
case 3:
exibirEmOrdem(&pRaiz);
break;
case 4:
exibirPreOrdem(&pRaiz);
break;

case 5:
exibirPosOrdem(&pRaiz);
break;

case 6:
printf("\nCONTAR NOS: %d\n\n",contarNos(&pRaiz));
break;
case 7:
printf("\nCONTAR FOLHAS: %d\n\n",contarFolhas(&pRaiz));
break;
case 8:
printf("\nALTURA: %d\n\n",altura(&pRaiz));
break;

case 9:
system("cls");
break;
case 0:
break;

default:
printf("Opção Invalida.");
break;
}
}while(op!=0);

return 0;
}
