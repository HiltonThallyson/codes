#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std::chrono;



int busca_sequencial(int k, int colecao[], int tamanho)
{
	int posicao = 0;
	do{
		if(k == colecao[posicao]){
			return posicao;
		}
		posicao = posicao + 1;
	}while(posicao < tamanho);
	return -1;
}

int busca_binaria(int k, int colecao[], int tamanho)
{	
	int inicio = 0, fim = tamanho-1, meio;
	while (inicio<=fim){
		meio = (inicio+fim)/2;
		if(k < colecao[meio]){
			fim = meio - 1;
		}
		else if(k > colecao[meio]){
			inicio = meio + 1;
		}
		else{
			return meio;
		}
	}
	return -1;
}
int main(){
	srand(time(NULL));
	long double d_b;
	long double d_s;
	int N[5];
	int *colecao = NULL;
	long double duracao_s[5];
	long double duracao_b[5];


	
	for (int vezes = 0; vezes < 5; vezes++){
		std::cout << "Digite o tamanho da colecao: " << std::endl;
		std::cin >> N[vezes];
		colecao = new int[N[vezes]];
		for (int i=0; i < N[vezes]; i++){
			colecao[i] = rand()%100;
		}
		high_resolution_clock::time_point t1_s = high_resolution_clock::now();
		busca_sequencial(101,colecao,N[vezes]);
		high_resolution_clock::time_point t2_s = high_resolution_clock::now();
		high_resolution_clock::time_point t1_b = high_resolution_clock::now();
		busca_binaria(101,colecao,N[vezes]);
		high_resolution_clock::time_point t2_b = high_resolution_clock::now();
		d_s = duration<long double, std::micro>(t2_s - t1_s).count();
		duracao_s[vezes] = d_s;
		d_b = duration<long double, std::micro>(t2_b- t1_b).count();
		duracao_b[vezes] = d_b;
		
		delete [] colecao;
	}
	std::cout << "|   N   |    tempo_seq   |    tempo_bi   |" << std::endl;
	for (int vezes = 0 ; vezes < 5 ;vezes++){
		std::cout << "|   " <<  N[vezes] << "   | " << duracao_s[vezes] << " | " << duracao_b[vezes] << " | " << std::endl;
	}
	
	return 0;
}
