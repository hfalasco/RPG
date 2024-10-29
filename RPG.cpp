#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <windows.h>

using namespace std;

struct Player{
	string nome, classe, raca, item;
	int forca, inteligencia, idade, destreza, carisma, xp, nivel, qntI, stamina;
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

void Falas(string fala){
       for (char L : fala){ // transformando string em char
           cout << L; // printando letra por letra
           Sleep(150); // delay de 150 ms para cada letra (podendo alterar)
       }
	   cout << "\n";
	   system("pause");
}

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
Player CalculaStamina(Player &player, int qntS, string lugar){
	int qntP = 0;
	if (player.stamina < qntS) {
                int x = qntS - player.stamina;
                int y = 60 / x; // conta para saber quantos segundos demora para a stamina carregar!
                cout << "Espere " << y << " segundos para carregar sua barra de stamina!";

                auto start = chrono::high_resolution_clock::now();                
				Sleep(y * 1000);
                auto end = chrono::high_resolution_clock::now();

                auto duracao = chrono::duration_cast<chrono::seconds>(end - start);
				cout << "\nStamina CARREGADA!" << endl;
				Sleep(1000);
				player.stamina -= qntS;
				
				while (qntP < 4)
				{
					system("cls");
					cout << "Caminhando ";
					cout << " . ";
					Sleep(1000);
					cout << " . ";
					Sleep(1000);
					cout << " . ";
					Sleep(1000);
					qntP++;
				}
				cout << "\n\nVoce chegou " << lugar << "!";				
            }
			else{
				player.stamina -= qntS;
				while (qntP < 4)
				{
					system("cls");
					cout << "Caminhando ";
					cout << " . ";
					Sleep(1000);
					cout << " . ";
					Sleep(1000);
					cout << " . ";
					Sleep(1000);
					qntP++;
				}
				cout << "\n\nVoce chegou " << lugar << "!";
			}
	return player;
}

float Luta(Player &player, Inventario inventario[10], Item item[50], Mob mob){
	bool LutaAcabou = false;
	int escolha, bater, Eitem, i, dadoP, dadoM;

	while (!LutaAcabou) // loop para verificar se a luta acabou
	{
		cout << "\n\n1- Atacar\n2- Usar item\n"; // player escolhe oq ele quer fazer
		cin >> escolha;
		switch (escolha)
		{
		case 1 :
			cout << "1- " << player.item << endl; // Aqui vai aparecer se ele quer atacar com a espada que ele tem
			cout << "2- Soco" << endl;
			cin >> bater;
			if (bater == 1){
				srand(time(0));
				dadoM = rand() % 20; // dados para ver qual a chance dele bater
				dadoP = rand() % 20;
				if (dadoP > dadoM){ // se o numero aqui for maior ele bate
					mob.vida -= player.forca;
				}
				else{
					player.vida -= mob.forca;
				}
			} 
			else{
				dadoM = rand() % 20; // mesma coisa com o soco
				dadoP = rand() % 20;
				if (dadoP > dadoM){
					mob.vida -= 2;
				}
				else{
					player.vida -= mob.forca;
				}
			}
			break;
			case 2: // aqui começa umas gambiarras (não tentem entender)
			if(player.qntI > 0){
				for (i = 0; i < player.qntI; i++) {
						cout << i + 1 << "- " << inventario[i].nome << endl; // mostra os itens que ele tem no inventario
				}
				cin >> Eitem;
				Eitem -= 1; // aqui ele tira 1 para poder pegar pelo codigo do item
				for (i = 0; i < 12; i++) {
					if (item[i].nome == inventario[Eitem].nome) { // aqui ele localiza qual o item que voce selecionou
						SomaItem(player, item[i]); //funcao para usar o item
						break;
					}
				}
				player.qntI -= 1;
				for (i = Eitem; i < player.qntI; i++) { // aqui ele atualzia o inventario
						inventario[i] = inventario[i + 1];
				}
				dadoM = rand() % 20; // o mob tem uma chance maior de te bater
				dadoP = rand() % 15;
				if (dadoM > dadoP){
					player.vida -= mob.forca;
				}
			}
			else{
				cout << "Inventario VAZIO!";
			}
    break;
		default:
			break;
		}
		if (mob.vida <= 0 || player.vida <= 0){ // funcao para dropar item, não tenta entender tb o importante é que funciona!
			LutaAcabou = true;					
			int qntItem = (rand() % 4) + 1;
			player.qntI = qntItem;
			cout << "\n\nOs itens dropados foram: ";
			for (int i = 0; i < qntItem; i++){
				int ItemDropado = rand() % 12;
				while (ItemDropado >= 3 && ItemDropado <= 5 && player.classe == "Mago") {
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
				return player.vida; // aqui ele vai retornar apenas a vida restaurando os outros atributos pro padrão
		}
	}	
}

int main() {
	Player player;
	Inventario inventario[10];
	player.qntI = 0; // Inicializa player.qntI
	player.stamina = 1; // esse valor pode mudar!

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
	item[11] = {"Capa Revestida", 18, 12};

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

	int escolha, qntS;
	string lugar;

	cout << "\nDeseja ir para puta que pariu?(- 10 stamina)\n1- Sim\n2- Nao\n"; // EXEMPLO DE APLICAÇÃO!!!!!
	cin >> escolha;
    switch (escolha) {
        case 1:
			qntS = 10; // esse valor vai variar depende do quanto deseja gastar de stamina!
			lugar = "Puta que Pariu"; // puta que pariu é um exemplo aqui voce coloca o nome do local!
            CalculaStamina(player, qntS, lugar);
            break;
		case 2:
			//aqui depende da historia para onde ele deseja seguir!
		break;
        default:
        break;
    }
	string fala = "Testando"; // onde as falas vão ser registradas
	cout << "Perosnagem: "; // Nome do personagem
	Falas(fala); // função fala que da a impressão de digitação nas frases
	fala = "Testando2";
	cout << "\nPersonagem2: ";
	Falas(fala);
}