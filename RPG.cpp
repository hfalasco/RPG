#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

struct Player{
	string nome, classe, raca;
	int forca, inteligencia, idade, destreza, carisma, xp, nivel;
	float vida;
};

struct Item{
	string nome;
	int atributo;
};

Player SomaXp(Player &player, int xp){
	int soma = player.xp + xp;
	player.xp += xp;
	
	if (soma >= 10){
		soma = 10;
	}
	if (soma % 10 == 0){
		player.nivel += 1;
		return player;
	}
	else{
		return player;
	}
}

Player SomaItem(Player &player, Item item[50]){ // terminar
	if (item[0].nome == "Pocao de Cura Pequena"){
		player.vida += item[0].atributo;
	}
	else if (item[1].nome == "Pocao de Cura Media"){
		player.vida += item[1].atributo;
	}
	else if (item[2].nome == "Pocao de Cura Grande"){

	}
}

int main(){
	Player player;
	int classe, raca;
	Item item[50]; // 50 É O NUMERO DE ITENS QUE PODEM SER CRIADOS! MAS DA PRA ALTERAR
	//POÇOES
	item[0] = {"Pocao de Cura Pequena", 3}; // EXEMPLO! primeiro setor é o nome e o segundo é a quantidade do atributo.
	item[1] = {"Pocao de Cura Media", 9};
	item[2] = {"Pocao de Cura Grande", 18};
	// ESPADAS
	item[3] = {"Espada Sem fio", 3};
	item[4] = {"Espada", 9};
	item[5] = {"Espada BOA", 18}; // Sem criatividade nao sei que nome por
	//ESCUDOS
	item[6] = {"Escudo Degastado", 3};
	item[7] = {"Escudo", 9};
	item[8] = {"Escudo Revestido", 18};
	//CAPAS
	item[9] = {"Capa Degastada", 3};
	item[10] = {"Capa", 9};
	item[11] = {"Capa Revestida", 18};


	srand(time(0));
	player.xp = 0;
	player.nivel = 1;
	
	cout << "Digite o nome do seu jogador: ";
	cin.ignore();
	getline(cin, player.nome);
	cout << "Insira sua idade: ";
	cin >> player.idade;
	system ("cls");
	cout << "Selecione sua classe:\n1- Mago\n2- Guerreiro\n3- Arqueiro\n\n";
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


	cout << "\n\nSelecione sua raca: \n1- Elfo  \n2- Humano \n3- Orc\n\n"; // só adicionar o nome das racas e se precisar colocar mais não tem problema
	cin >> raca;	
	system ("cls");

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
	cout << "Seus atributos sorteados foram:" << endl;
	cout << "Vida: " << player.vida << endl;
	cout << "Forca: " << player.forca << endl;
	cout << "Inteligencia: " << player.inteligencia << endl;
	cout << "Carisma: " << player.carisma << endl;
	cout << "Destreza: " << player.destreza << endl;

	int xp = 2;
	SomaXp (player, xp);
	cout << player.xp << endl;
	cout << player.nivel << endl;	
	xp = 7;
	SomaXp (player, xp);
	cout << player.xp << endl;
	cout << player.nivel << endl;

	cout << "escrevi qualquer merda" ;
}