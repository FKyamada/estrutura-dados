#include "No.h"
class Lista
{ //Definição de uma lista de inteiros: ponteiro para o primeiro nó.
	No* primeiro;
public:
	//Construtor
	Lista(); //cria lista vazia
			 //Métodos de Acesso
	No* getPrimeiro(); //retorna o primeiro nó da lista
	void setPrimeiro(No* novoNo); //torna "novoNo" o primeiro nó da lista
								  //Métodos
	int posicao(int elem);
	int soma();
	void remocao(int elem);
	int total(int elem);
	bool eVazia(); //retorna verdadeiro se a lista é uma lista vazia
	void insere(int elem); //insere elemento no início da lista
	No* remove(int elem); //remove todas as ocorrencias de elem na lista
	bool existe(int elem); //verifica se elem existe na lista
	void imprime(); //imprime todos os elementos da lista
					//Destrutor
	~Lista(); //Destroi todos os nós da lista
};