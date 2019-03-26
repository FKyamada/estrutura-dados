#include "Lista.h"
//Construtor
Lista::Lista()
{
	primeiro = NULL;
}
//--------------------------------------------------------------------------------

//Métodos de Acesso
No* Lista::getPrimeiro()
{
	return primeiro;
}
//--------------------------------------------------------------------------------

void Lista::setPrimeiro(No* novoNo)
{
	primeiro = novoNo;
}
//--------------------------------------------------------------------------------

//Métodos
bool Lista::eVazia()
{
	if (primeiro == NULL)
		return true;
	return false;
}
//--------------------------------------------------------------------------------

void Lista::insere(int elem)
{
	No *segundo = primeiro; //armazena segundo nó da nova lista
	primeiro = new No(elem); //o primeiro elemento da lista passa a ser o novo nó;
	primeiro->setProximo(segundo);//o proximo nó da lista é aquele
								  // armazenado anteriormente
}
//--------------------------------------------------------------------------------

void Lista::imprime()
{
	if (eVazia())
		cout << "{ }";
	else
	{
		No* pAux = primeiro;
		cout << "{";
		while (true)
		{
			cout << pAux->getInfo();//impressão do nó atual
			if (pAux->getProximo() != NULL)//Se ainda existem nós...
			{
				cout << ", ";
				pAux = pAux->getProximo(); //passa-se ao próximo nó
			}
			else
			{ //fim da lista
				cout << "}";
				break;
			}
		}
	}
}
//--------------------------------------------------------------------------------

bool Lista::existe(int elem)
{
	if (eVazia())
		return false;
	No* pAux = primeiro;
	while (pAux != NULL)
	{
		if (pAux->getInfo() == elem)//elemento encontrado!
			return true;
		else
			pAux = pAux->getProximo(); //passa-se ao próximo nó
	}
	return false; //nenhum nó com valor "elem" foi encontrado
}
//--------------------------------------------------------------------------------

No* Lista::remove(int elem)
{
	if (eVazia())
		return NULL;//o metodo retorna um ponteiro para No...
					//Quando o elem é o primeiro da lista...
	while (primeiro->getInfo() == elem)
	{
		No* aux = primeiro;//armazena o primeiro a ser removido.
		primeiro = primeiro->getProximo(); //passa-se ao próximo nó,
										   //que agora é o primeiro.
		aux->~No(); //destruição do nó removido
		delete aux; //destruição do nó removido de forma mais limpa
		if (primeiro == NULL) //se for encontrado fim de lista....
			return primeiro;
	}
	//O primeiro não é mais um elemento a ser removido...
	Lista *pAux = new Lista(); //Cria lista auxiliar...
	pAux->primeiro = primeiro->getProximo();//... que se inicia no
											//proximo elemento da lista atual
	primeiro->setProximo(pAux->remove(elem)); //remove elem da nova lista,
											  // associando seu início à lista atual
	return primeiro;
}
//--------------------------------------------------------------------------------

int Lista::soma() //Total de itens na lista
{
	No* pAux = primeiro;
	int i = 0;

	while (pAux != NULL)
	{
		i++;
		pAux = pAux->getProximo();
	}
	return i;
}
//--------------------------------------------------------------------------------

int Lista::total(int n) //Conta o numero de vezes que um elemento aparece na lista 
{
	No* pAux = primeiro;
	int i = 0;

	while (pAux != NULL)
	{
		if (n == pAux->getInfo())
			i++;

		pAux = pAux->getProximo();
	}
	return i;
}
//-------------------------------------------------------------------------------

int Lista::posicao(int n) // Exibe a posicao de um item na lista
{
	No* pAux = primeiro;
	int i = 1;

	while (n != pAux->getInfo())
	{
		i++;
		pAux = pAux->getProximo();
	}

	return i;
}
//--------------------------------------------------------------------------------

void Lista::remocao(int n) // Exibe a posicao de um item na lista
{
	No* pAux1 = primeiro;
	No* pAux2 = primeiro->getProximo();

	if (primeiro->getInfo() == n) //Exclusao de primeiro elemento
	{
		pAux1->~No();
		primeiro = pAux2;
		pAux1 = primeiro;
		pAux2 = pAux1->getProximo();
	}
	else if(pAux2->getProximo() != NULL) //Exclusao de miolo
	{
		while (pAux2 != NULL)
		{
			pAux1 = primeiro->getProximo();
			pAux2 = pAux1->getProximo();
			if (pAux2->getInfo() == n)
			{
				pAux1->getProximo()->~No();
				pAux2 = pAux2->getProximo();
				break;
			}
		}
	}
	else //Exclusao de elemento final 
	{
		


	}

}
//--------------------------------------------------------------------------------


//Destrutor
Lista::~Lista()
{//A lista deve ser destruída nó por nó.
	No* pAux;
	while (primeiro != NULL)
	{
		pAux = primeiro;
		primeiro = primeiro->getProximo();
		pAux->~No();
	}
}
//---------------------------------------------------------------------------------