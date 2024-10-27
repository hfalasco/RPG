#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

struct Player{
	string nome, classe, raca, item;
	int forca, inteligencia, idade, destreza, carisma, xp, nivel, qntI;
	float vida;
};

struct Item{
	string nome;
	int atributo, codigo;
};

struct Inventario
{
	string nome;
	int qnt;
};


struct Mob {
	string nome;
	int forca;
	float vida;
};

Player SomaXp(Player &player, int xp) {
	int soma = player.xp + xp;
	player.xp += xp;
	
	if (soma >= 10) {
		soma = 10;
	}
	if (soma % 10 == 0) {
		player.nivel += 1;
	}
	return player;
}
Player SomaItem(Player &player, Item item) { 
    if (item.nome == "Pocao de Cura Pequena" || item.nome == "Pocao de Cura Media" || item.nome == "Pocao de Cura Grande") {
        player.vida += item.atributo;
    } else if (item.nome == "Espada Sem fio" || item.nome == "Espada" || item.nome == "Espada BOA") {
        player.forca += item.atributo;
    } else if (item.nome == "Escudo Desgastado" || item.nome == "Escudo" || item.nome == "Escudo Revestido") {
        player.vida += item.atributo;
    } else if (item.nome == "Capa Desgastada" || item.nome == "Capa" || item.nome == "Capa Revestida") {
        player.vida += item.atributo;
    }
    return player;
}

float Luta(Player &player, Inventario inventario[10], Item item[50], Mob mob){
	bool LutaAcabou = false;
	int escolha, bater, Eitem, i;

	while (!LutaAcabou == true)
	{
		cout << "\n\n1- Atacar\n2- Usar item\n";
		cin >> escolha;
		switch (escolha)
		{
		case 1 :
			cout << "\n1- " << player.item << endl;
			cout << "2- Soco";
			cin >> bater;
			if (bater == 1){
				mob.vida -= player.forca;
			} 
			else{
				mob.vida -= 2;
			}
			break;
			case 2:
			if(player.qntI > 0){
				for (i = 0; i < player.qntI; i++) {
						cout << i + 1 << "- " << inventario[i].nome << endl;
				}
				cin >> Eitem;
				Eitem -= 1;
				for (i = 0; i < 12; i++) {
					if (item[i].nome == inventario[Eitem].nome) {
						SomaItem(player, item[i]); 
						break;
					}
				}
				player.qntI -= 1;
				for (i = Eitem; i < player.qntI; i++) {
						inventario[i] = inventario[i + 1];
				}
				player.vida -= mob.forca;
			}
			else{
				cout << "Inventario VAZIO!";
			}
    break;
		default:
			break;
		}
		if (mob.vida <= 0 || player.vida <= 0){
			LutaAcabou = true;
			
			int qntItem = (rand() % 4) + 1;
			player.qntI = qntItem;
			cout << "\n\nOs itens dropados foram: ";
			for (int i = 0; i < qntItem; i++){
				int ItemDropado = rand() % 12;
				while (( ItemDropado >= 3 && ItemDropado <= 5) || (ItemDropado >= 6 && ItemDropado <= 8 && player.classe == "Mago")) {
					ItemDropado = rand() % 12;
				}
				while ((ItemDropado >= 3 && ItemDropado <= 5) || (ItemDropado >= 6 && ItemDropado <= 8 && player.classe == "Arqueiro")) {
					ItemDropado = rand() % 12;
				}
				if (i == qntItem - 1) {
					cout << item[ItemDropado].nome << ".";
				} else {
					cout << item[ItemDropado].nome << ", ";
				}
				inventario[i].nome = item[ItemDropado].nome;
			}
					return player.vida;
				}
			}
			
		}


int main() {
	Player player;
	Inventario inventario[10];
	player.qntI = 0; // Inicializa player.qntI

	int classe, raca;
	Item item[50];
	//POÇOES
	item[0] = {"Pocao de Cura Pequena", 3, 1}; 
	item[1] = {"Pocao de Cura Media", 9, 2};
	item[2] = {"Pocao de Cura Grande", 18, 3};
	// ESPADAS
	item[3] = {"Espada Sem fio", 3, 4};
	item[4] = {"Espada", 9, 5};
	item[5] = {"Espada BOA", 18, 6};
	//ESCUDOS
	item[6] = {"Escudo Desgastado", 3, 7};
	item[7] = {"Escudo", 9, 8};
	item[8] = {"Escudo Revestido", 18, 9};
	//CAPAS
	item[9] = {"Capa Desgastada", 3, 10};
	item[10] = {"Capa", 9, 11};
	item[11] = {"Capa Revestida", 18l, 12};

	srand(time(0));
	player.xp = 0;
	player.nivel = 1;

	cout << "Digite o nome do seu jogador: ";
	cin.ignore();
	getline(cin, player.nome);
	cout << "Insira sua idade: ";
	cin >> player.idade;
	system("cls");

	cout << "Selecione sua classe:\n1- Mago\n2- Guerreiro\n3- Arqueiro\n\n";
	cin >> classe;
	system("cls");

	switch (classe) {		
		case 1:
			player.classe = "Mago";
			player.vida = 10;
			player.forca = (rand() % 11) + 1;
			player.inteligencia = (rand() % 11) + 1;
			player.carisma = (rand() % 11) + 1;
			player.destreza = (rand() % 11) + 1;
		break;		
		case 2:
			player.classe = "Guerreiro";
			player.vida = 10;
			player.forca = (rand() % 11) + 1;
			player.inteligencia = (rand() % 11) + 1;
			player.carisma = (rand() % 11) + 1;
			player.destreza = (rand() % 11) + 1;
		break;		
		case 3:
			player.classe = "Arqueiro";
			player.vida = 10;
			player.forca = (rand() % 11) + 1;
			player.inteligencia = (rand() % 11) + 1;
			player.carisma = (rand() % 11) + 1;
			player.destreza = (rand() % 11) + 1;
		break;
	}

	cout << "A classe selecionada foi: " << player.classe << endl;
	cout << "\n\nSelecione sua raca: \n1- Elfo  \n2- Humano \n3- Orc\n\n";
	cin >> raca;
	system("cls");

	switch (raca) {
		case 1:
			player.raca = "Elfo";
			player.vida += 2;
			player.forca += 1;
			player.inteligencia += 3;
			player.carisma += 1;
			player.destreza += 2;
		break;
		case 2:
			player.raca = "Humano";
			player.vida += 1;
			player.forca += 2;
			player.inteligencia += 1;
			player.carisma += 2;
			player.destreza += 1;
		break;
		case 3:
			player.raca = "Orc";
			player.vida += 5;
			player.forca += 4;
			player.inteligencia -= 2;
			player.destreza += 5;
		break;		
	}

	cout << "Seus atributos sorteados foram:" << endl;
	cout << "Vida: " << player.vida << endl;
	cout << "Forca: " << player.forca << endl;
	cout << "Inteligencia: " << player.inteligencia << endl;
	cout << "Carisma: " << player.carisma << endl;
	cout << "Destreza: " << player.destreza << endl;
}
