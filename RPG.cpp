#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
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
	int codigo;
};

struct Mob {
	string nome;
	int forca;
	float vida;
};

void Falas(string fala){
       for (char L : fala){ // transformando string em char
           cout << L; // printando letra por letra
           Sleep(170); // delay de 150 ms para cada letra (podendo alterar)
       }
	   cout << "\n";
	   getchar(); // pausa para o player clicar para aparecer outra fala (um pouco paia pq aparece "pressione qualuqer tecla para continuar"), passivel de retirada!
}
void DropItem(Player &player, Item item[50], Inventario inventario[10]) {
    srand(time(0));
    cout << "Os itens dropados foram:\n";
    int qntI = 0, i, codigoItem;
    qntI = (rand() % 4) + 1;
    player.qntI += qntI;

    for (i = 0; i < qntI; i++) {
        codigoItem = (rand() % 14); // para evitar valores fora do índice do array
        inventario[i].codigo = codigoItem;
        inventario[i].nome = item[codigoItem].nome; // associar nome do item ao inventário
        cout << item[codigoItem].nome << endl;
    }
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
float Luta(Player player, Inventario inventario[10], Item item[50], Mob mob){
	system ("cls");
	bool LutaAcabou = false;
	int dadoP, dadoM, escolha, escolhaI, i;
	srand(time(0));
	while (!LutaAcabou)
	{
		cout << "Vida player: " << player.vida << " || Forca player: " << player.forca << endl;
		cout << "Vida mob: " << mob.vida << " || forca mob: " << mob.forca << "\n\n";
		cout << "O que deseja fazer?\n1- Bater\n2- Usar item\n";
		cin >> escolha;
		switch (escolha)
		{
		case 1:
			system ("cls");
			dadoP = rand() % 20;
			dadoM = rand() % 20;
			cout << "Resultado dos dados: " << endl;
			cout << "Player: " << dadoP << endl;
			cout << mob.nome << ": " << dadoM << "\n";
			if (dadoP > dadoM){
				mob.vida -= player.forca;
				cout << "\n" << player.nome << " CAUSOU " << player.forca << " de dano" << "\n\n";
			}
			else{
				player.vida -= mob.forca;
				cout << "\n" << player.nome << " SOFREU " << mob.forca << " de dano" << "\n\n";
			}
			if (mob.vida <= 0){
				cout << player.nome << " VENCEU!" << endl;
				system ("pause");
				DropItem (player, item, inventario);
				return player.vida;
				LutaAcabou = true;
			}
			if (player.vida <= 0){
				cout << player.nome << " morreu... talvez em uma outra vida..." << endl;
				system ("pause");
				LutaAcabou = true;
				return 0;
			}
			break;
case 2:
    if (player.qntI == 0) {
        cout << "Inventário VAZIO!\n\n";
    } else {
        for (i = 0; i < player.qntI; i++) {
            cout << i + 1 << "- " << inventario[i].nome << "\n";
        }
        cin >> escolhaI;
        escolhaI--;
        if (escolhaI >= 0 && escolhaI < player.qntI) {
            int codigoItem = inventario[escolhaI].codigo;
            SomaItem(player, item[codigoItem]); 
            for (i = escolhaI; i < player.qntI - 1; i++) {
                inventario[i] = inventario[i + 1];
            }
            player.qntI--;

            dadoP = rand() % 10;
            dadoM = rand() % 15;
            if (dadoM > dadoP) {
                player.vida -= mob.forca;
                if (player.vida <= 0) {
                    cout << player.nome << " morreu... talvez em uma outra vida..." << endl;
                    system("pause");
                    LutaAcabou = true;
                    return 0;
                }
            }
        } else {
            cout << "Item INVALIDO!\n\n";
        }
    }
    break;

		
		default:
			break;
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
	item[0] = {"Pocao de Cura Pequena", 3, 0}; 
	item[1] = {"Pocao de Cura Media", 9, 1};
	item[2] = {"Pocao de Cura Grande", 18, 2};
	// ESPADAS
	item[3] = {"Espada Sem fio", 3, 3};
	item[4] = {"Espada", 9, 4};
	item[5] = {"Espada BOA", 18, 5};
	//ESCUDOS
	item[6] = {"Escudo Desgastado", 3, 6};
	item[7] = {"Escudo", 9, 7};
	item[8] = {"Escudo Revestido", 18, 8};
	//CAPAS
	item[9] = {"Capa Desgastada", 3, 9};
	item[10] = {"Capa", 9, 10};
	item[11] = {"Capa Revestida", 18, 11};
	//MACHADO
	item[12] = {"Machado Desgastado", 4, 12};
	item[13] = {"Machado", 4, 13};

	srand(time(0));
	player.xp = 0;
	player.nivel = 1;

	cout << "Digite o nome do seu jogador: ";
	getline(cin, player.nome);
	cout << "Insira sua idade: ";
	cin >> player.idade;
	system("cls");

	cout << "Selecione sua raca: \n1- Elfo  \n2- Humano \n3- Orc\n\n";
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
	cout << "Seus atributos sorteados foram:" << endl;
	cout << "Vida: " << player.vida << endl;
	cout << "Forca: " << player.forca << endl;
	cout << "Inteligencia: " << player.inteligencia << endl;
	cout << "Carisma: " << player.carisma << endl;
	cout << "Destreza: " << player.destreza << endl;

	Mob mob;
	mob.vida = 5;
	mob.forca = 1;
	mob.nome = "Teste";
	DropItem(player, item, inventario);

	player.vida = Luta(player, inventario, item, mob);

	system ("cls");
	cout << "Vida: " << player.vida << endl;
	cout << "Forca: " << player.forca << endl;
	cout << "Inteligencia: " << player.inteligencia << endl;
	cout << "Carisma: " << player.carisma << endl;
	cout << "Destreza: " << player.destreza << endl;
}