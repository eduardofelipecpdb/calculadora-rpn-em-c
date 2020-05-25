#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*Calculadora em notação polonesa reversa*/
#define PI 3.14159265

typedef struct itens {
	float numeros;
	struct itens *prox;
} Itens;

Itens* addnumero(Itens*, float);
void exibetudo (Itens*);
float getultimo (Itens*);
float getpenultimo (Itens*);
float soma (float, float);
float subtracao (float, float);
float multiplicacao (float, float);
float divisao (float, float);
int resto (int, int);
int dec2bin (int);
float pot (float, float);
float raiz (float);
float seno(float);
float coss(float);
float tang(float);
int menu ();

int main ()
{
    Itens* content = NULL;
    int operacao = 0, acao = 0;
    while (operacao != 15)
    {
        printf("\nDigite 1 para adicionar um numero ou 0 para realizar uma operacao:  ");
        scanf("%d",&acao);
        if (acao == 1)
        {
            float number = 0;
            printf("\nDigite o numero que deseja inserir:  ");
            scanf("%f",&number);
            content = addnumero(content, number);
        }
        else
        {
            operacao = menu();
            float ultimo = 0, penultimo = 0;
            ultimo = getultimo(content);
            penultimo = getpenultimo(content);
            switch(operacao)
            {
                case 1:
                    float somando;
                    somando = soma(ultimo,penultimo);
                    content = addnumero(content, somando);
                    break;
                case 2:
                    float subtraindo;
                    subtraindo = subtracao(penultimo, ultimo);
                    content = addnumero(content, subtraindo);
                    break;
                case 3:
                    float multiplicando;
                    multiplicando = multiplicacao(penultimo, ultimo);
                    content = addnumero(content, multiplicando);
                    break;
                case 4:
                    float dividindo;
                    dividindo = divisao(penultimo, ultimo);
                    content = addnumero(content, dividindo);
                    break;
                case 5:
                    printf("\nFuncao ainda não implementada");
                    break;
                case 6:
                    float restou;
                    restou = resto(penultimo, ultimo);
                    content = addnumero(content, restou);
                    break;
                case 7:
                    printf("\nFuncao ainda não implementada");
                    break;
                case 8:
                    float potencia;
                    potencia = pot(penultimo, ultimo);
                    content = addnumero(content, potencia);
                    break;
                case 9:
                    float raizq;
                    raizq = raiz(ultimo);
                    content = addnumero(content, raizq);
                    break;
                case 10:
                    float senoo;
                    senoo = seno(ultimo);
                    content = addnumero(content, senoo);
                    break;
                case 11:
                    float cosseno;
                    cosseno = coss(ultimo);
                    content = addnumero(content, cosseno);
                    break;
                case 12:
                    float tangente;
                    tangente = tang(ultimo);
                    content = addnumero(content, tangente);
                    break;
                case 13:
                    printf("\nFuncao ainda não implementada");
                    break;
                case 14:
                    printf("\nFuncao ainda não implementada");
                    break;
            }
        }
        exibetudo(content);
    }
}

void exibetudo (Itens* lista)
{
    Itens *mostrar = lista;
    for (mostrar = lista; mostrar != NULL; mostrar = mostrar->prox)
	    printf("\n%.2f",mostrar->numeros);
}

float getultimo (Itens* lista)
{
    Itens *mostrar = lista;
    float ultimo = 0;
    for (mostrar = lista; mostrar != NULL; mostrar = mostrar->prox)
        ultimo = mostrar->numeros;
    return ultimo;
}

float getpenultimo (Itens* lista)
{
    Itens *mostrar = lista;
    float ultimo = 0, penultimo = 0;
    for (mostrar = lista; mostrar != NULL; mostrar = mostrar->prox)
    {
        penultimo = ultimo;
        ultimo = mostrar->numeros;
    }
    return penultimo;
}

Itens* addnumero(Itens *Conteudo, float novoitem)
{
	Itens *total = Conteudo;
	if(total == NULL)
	{
		Conteudo = total = (Itens*)malloc( sizeof(Itens));
	}
	else
	{
		while( total->prox != NULL)
		    total = total->prox;
		total->prox = (Itens*)malloc(sizeof(Itens));
		total = total->prox;
	}
	total->numeros = novoitem;
	total->prox = NULL;
	return Conteudo;
}

int menu ()
{
    int entrada = 0;
    printf("\n\nDigite o numero correspondente a operacao que deseja realizar");
    printf("\nSoma: 1");
    printf("\nSubtracao: 2");
    printf("\nMultiplicacao: 3");
    printf("\nDivisao: 4");
    printf("\nDivisao de inteiros: 5");
    printf("\nResto da divisao: 6");
    printf("\nConverter decimal para binario: 7");
    printf("\nPotenciacao: 8");
    printf("\nRaiz quadrada: 9");
    printf("\nSeno: 10");
    printf("\nCosseno: 11");
    printf("\nTangente: 12");
    printf("\nGrau para radiano: 13");
    printf("\nSwap: 14");
    printf("\nSair: 15\n");
    scanf("%d",&entrada);
    printf("\nVoce escolheu: %d\n\n", entrada);
    return entrada;
}
float soma (float valor1, float valor2)
{
    return valor1 + valor2;   
}
float subtracao (float valor1, float valor2)
{
    return valor2 - valor1;   
}
float multiplicacao (float valor1, float valor2)
{
    return valor1 * valor2;   
}
float divisao (float valor1, float valor2)
{
    return valor2 / valor1;   
}
int resto (int valor1, int valor2)
{
    return valor2 % valor1;  
}
float pot (float valor1, float valor2)
{
    return pow(valor2, valor1);
}
float raiz (float valor1)
{
    return sqrt(valor1);   
}
float seno(float param)
{
    float result;
    result = sin(param*PI/180);
    return result;
}
float coss(float param)
{
    float result;
    result = cos(param*PI/180);
    return result;
}
float tang(float param)
{
    float result;
    result = tan(param*PI/180);
    return result;
}