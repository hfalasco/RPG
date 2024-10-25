#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

struct Player{
	string nome, classe, raca;
	int forca, inteligencia, idade, destreza, carisma, xp;
	float vida;
};

int main(){
	Player player;
	int classe, raca;
	srand(time(0));
	player.xp = 0;
	
	cout << "Digite o nome do seu jogador: ";
	cin.ignore();
	getline(cin, player.nome);
	cout << "Insira sua idade: ";
	cin >> player.idade;
	
	cout << "\nSelecione sua classe:\n1- Mago\n2- Guerreiro\n3- Arqueiro\n\n";
	cin >> classe;
	system ("cls");
	
	switch (classe){		
		case 1 :
			player.classe = "Mago";
			player.vida = 10;
			player.forca = (rand() % 11) + 1; // TODOS ATRIBUTOS VAO ATE O NIVEL 10!
			player.inteligencia = (rand() % 11) + 1;
			player.carisma = (rand() % 11) + 1;
			player.destreza = (rand() % 11) + 1;
		break;		
		case 2 :
			player.classe = "Guerreiro";
			player.vida = 10;
			player.forca = (rand() % 11) + 1; // TODOS ATRIBUTOS VAO ATE O NIVEL 10!
			player.inteligencia = (rand() % 11) + 1;
			player.carisma = (rand() % 11) + 1;
			player.destreza = (rand() % 11) + 1;
		break;		
		case 3 :
			player.classe = "Arqueiro";
			player.vida = 10;
			player.forca = (rand() % 11) + 1; // TODOS ATRIBUTOS VAO ATE O NIVEL 10!
			player.inteligencia = (rand() % 11) + 1;
			player.carisma = (rand() % 11) + 1;
			player.destreza = (rand() % 11) + 1;
		break;		
	}

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "A classe selecionada foi: ";
	SetConsoleTextAttribute(h, 13); // ESSE COMANDO MEXE NA COR DA LINHA DEBAIXO!
	cout << player.classe;
	SetConsoleTextAttribute(h, 7); // VALOR 7 PQ VOLTA O RESTO PARA O PADRÃO! nao mexe se não entendeu.


	cout << "\n\nSelecione sua raca: \n1- Elfo  \n2- Humano \n3- Orc\n\n "; // só adicionar o nome das racas e se precisar colocar mais não tem problema
	cin >> raca;

	switch (raca) // esse switch está com erro por conta que não foi colocado os valores!
	{
	case 1 : 
		player.raca = "Elfo" ;
		player.vida += 2 ;       // ESSE += SOMA NOS VALORES DOS ATRIBUTOS DIRETAMENTE ATUALIZANDO ELE!
		player.forca += 1 ;      // ESSE += SOMA NOS VALORES DOS ATRIBUTOS DIRETAMENTE ATUALIZANDO ELE!
		player.inteligencia += 3 ;   // ESSE += SOMA NOS VALORES DOS ATRIBUTOS DIRETAMENTE ATUALIZANDO ELE!
		player.carisma += 1 ;    // ESSE += SOMA NOS VALORES DOS ATRIBUTOS DIRETAMENTE ATUALIZANDO ELE!
		player.destreza += 2 ;   // ESSE += SOMA NOS VALORES DOS ATRIBUTOS DIRETAMENTE ATUALIZANDO ELE!
		break;
	case 2 :
		player.raca = "Humano" ;   
		player.vida += 1 ;       // ESSE += SOMA NOS VALORES DOS ATRIBUTOS DIRETAMENTE ATUALIZANDO ELE!
		player.forca += 2 ;      // ESSE += SOMA NOS VALORES DOS ATRIBUTOS DIRETAMENTE ATUALIZANDO ELE!
		player.inteligencia += 1 ;   // ESSE += SOMA NOS VALORES DOS ATRIBUTOS DIRETAMENTE ATUALIZANDO ELE!
		player.carisma += 2  ;   // ESSE += SOMA NOS VALORES DOS ATRIBUTOS DIRETAMENTE ATUALIZANDO ELE!
		player.destreza += 1 ;   // ESSE += SOMA NOS VALORES DOS ATRIBUTOS DIRETAMENTE ATUALIZANDO ELE!
		break;
	case 3 :
		player.raca = "Orc" ;   
		player.vida += 5	;    // ESSE += SOMA NOS VALORES DOS ATRIBUTOS DIRETAMENTE ATUALIZANDO ELE!
		player.forca += 4 	;    // ESSE += SOMA NOS VALORES DOS ATRIBUTOS DIRETAMENTE ATUALIZANDO ELE!
		player.inteligencia -= 2 ;   // ESSE += SOMA NOS VALORES DOS ATRIBUTOS DIRETAMENTE ATUALIZANDO ELE!
		player.carisma += 0  ;   // ESSE += SOMA NOS VALORES DOS ATRIBUTOS DIRETAMENTE ATUALIZANDO ELE!
		player.destreza += 5 ;   // ESSE += SOMA NOS VALORES DOS ATRIBUTOS DIRETAMENTE ATUALIZANDO ELE!
		break;				
	
	default:
		break;
	}
	
	cout << "\nSeus atributos sorteados foram:" << endl;
	cout << "Vida: " << player.vida << endl;
	cout << "Forca: " << player.forca << endl;
	cout << "Inteligencia: " << player.inteligencia << endl;
	cout << "Carisma: " << player.carisma << endl;
	cout << "Destreza: " << player.destreza << endl;
}