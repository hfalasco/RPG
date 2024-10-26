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
	int atributo, codigo;
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
		return player;
	}
	else if (item[1].nome == "Pocao de Cura Media"){
		player.vida += item[1].atributo;
		return player;
	}
	else if (item[2].nome == "Pocao de Cura Grande"){
		player.vida += item[2].atributo;
		return player;
	}
	else if (item[3].nome == "Espada Sem fio"){
		player.forca += item[3].atributo;
		return player;
	}
	else if (item[4].nome == "Espada"){
		player.forca += item[4].atributo;
		return player;
	}
	else if (item[5].nome == "Espada BOA"){
		player.forca += item[5].atributo;
		return player;
	}
	else if (item[6].nome == "Escudo Desgastado"){
		player.vida += item[6].atributo;
		return player;
	}
	else if (item[7].nome == "Escudo"){
		player.vida += item[7].atributo;
		return player;
	}
	else if (item[8].nome == "Escudo Revestido"){
		player.vida += item[8].atributo;
		return player;
	}
	else if (item[9].nome == "Capa Desgastada"){
		player.vida += item[9].atributo;
		return player;
	}
	else if (item[10].nome == "Capa"){
		player.vida += item[10].atributo;
		return player;
	}
	else if (item[11].nome == "Capa Revestida"){
		player.vida += item[11].atributo;
		return player;
	}
}

int main(){
	Player player;
	int classe, raca;
	Item item[50]; // 50 É O NUMERO DE ITENS QUE PODEM SER CRIADOS! MAS DA PRA ALTERAR
	//POÇOES
	item[0] = {"Pocao de Cura Pequena", 3, 0}; // EXEMPLO! primeiro setor é o nome e o segundo é a quantidade do atributo.
	item[1] = {"Pocao de Cura Media", 9, 1};
	item[2] = {"Pocao de Cura Grande", 18, 2};
	// ESPADAS
	item[3] = {"Espada Sem fio", 3, 3};
	item[4] = {"Espada", 9, 4};
	item[5] = {"Espada BOA", 18, 5}; // Sem criatividade nao sei que nome por
	//ESCUDOS
	item[6] = {"Escudo Desgastado", 3, 6};
	item[7] = {"Escudo", 9, 7};
	item[8] = {"Escudo Revestido", 18, 8};
	//CAPAS
	item[9] = {"Capa Desgastada", 3, 9};
	item[10] = {"Capa", 9, 10};
	item[11] = {"Capa Revestida", 18, 11};


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

	int qntItem = rand() % 4; // aqui ele sorteia quantos itens vão ser dropados!
	cout << "\n\nOs itens dropados foram: ";
	for (int i=0 ; i < qntItem ; i++){ // aqui é o loop com o tanto de itens que foram sorteados
		int ItemDropado = rand() % 12;
		while (ItemDropado >=3 && ItemDropado <=5 && player.classe == "Mago") // aqui a condição se ele for um mago ele não pode dropar uma espada (fazer para outras classes tb)
		{
			ItemDropado = rand() % 12;
		}
		if (i == qntItem - 1){ // aqui é só pra ser o ultimo item escrito ter um ponto final
		cout << item[ItemDropado].nome << ".";
		}
		else{
			cout << item[ItemDropado].nome << ", ";
		}
	}
}