// ProyectoCFinalizado.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

// Juego.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>


using namespace std;

//empezar batalla;
int batalla;

//Atributos del enemigo
int enemy1HP = 100;
string enemy1Name = "Creeper1";
bool enemy1IsAlive = true;
int enemy1Damage = 1+ (rand() % 40);

int enemy2HP = 100;
string enemy2Name = "Creeper2";
bool enemy2IsAlive = true;
int enemy2Damage = 1+ (rand() % 40);

//Atributos de héroe
string heroName;
int heroHP = 100;
bool heroIsAlive = true;

//ataques hero
int punetazo = 10;
int espada = 20;
int magia = 100;

//contadores habilidades
int punetazocount = 15;
int espadacount = 10;
int magiacount = 5;

void start() {
    srand(time(NULL));
    cout << "Como se llama el heroe?\n";
    cin >> heroName;
    cout << "Dos enemigos acaban de aparecer, tienen " << enemy1HP << " puntos de vida\n";
    cout << "1.batalla\n" << "2.huir\n";
}

bool attackenemy1() {
    if (enemy1IsAlive == false) {
        system("cls");
        cout << "========================================================================================================================\n";
        cout << "turno de " << enemy2Name << "\n";
        heroHP = heroHP - (1 + (rand() % 40));
        if (heroHP <= 0) {
           return heroIsAlive = false;
        }
        else {
            cout << "al heroe de quedan " << heroHP << " puntos de vida\n";
        }
    }
}

bool attackenemy() {
    if (enemy1IsAlive == true && enemy2IsAlive == true) {
        system("cls");
        cout << "turno de " << enemy1Name << "\n";
        heroHP = heroHP - (1 + (rand() % 40));
        cout << "turno de " << enemy2Name << "\n";
        heroHP = heroHP - (1 + (rand() % 40));

        if (heroHP <= 0) {
          return  heroIsAlive = false;
        }
        else {
            cout << "al heroe de quedan " << heroHP << " puntos de vida\n";
        }
    }
}

bool attackenemy2() {
    if (enemy2IsAlive == false) {
        system("cls");
        cout << "========================================================================================================================\n";
        cout << "turno de " << enemy1Name << "\n";
        heroHP = heroHP - (1 + (rand() % 40));
        if (heroHP <= 0) {
            return heroIsAlive = false;
        }
        else {
            cout << "al heroe de quedan " << heroHP << " puntos de vida\n";
        }
    }
}

bool FinalEnemy() {
    if (heroIsAlive == false) {
        system("cls");
        system("color c");
        cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n";
        cout << "                                             Fin del juego                                                              \n";
        cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n";
        exit(-1);
    }
}

bool FinalHero() {
    if (enemy1IsAlive == false && enemy2IsAlive == false) {
        system("cls");
        system("color a");
        cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n";
        cout << "                                             Ganastes                                                                   \n";
        cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n";
        exit(-1);
    }
}

void attackDecision() {
    cout << "========================================================================================================================\n";
    cout << "Turno de " << heroName << "\n";
    cout << "que ataque vas a hacer\n" << "1.punetazo\n" << "2.espada\n" << "3.magia\n";
}

int heroDecision() {
    cout << "========================================================================================================================\n";
    cout << "Turno de " << heroName << "\n";
    cout << "a que enemigo quieres atacar?\n" << "1." << enemy1Name << "\n" << "2." << enemy2Name << "\n";

    //atacar al enemigo 1
    int heroDecision;
    cin >> heroDecision;
    if (heroDecision == 1) {
        return 1;
    }else if (heroDecision == 2) {
        return 2;
    }
}

void atackHero(int& enemyHP,bool& isAlive, string enemyName) {
    int ataqueheroe;
    cin >> ataqueheroe;
    if (ataqueheroe == 1 && punetazocount != 0) {
        cout << heroName << " ha usado punetazo\n";
        punetazocount = punetazocount - 1;
        enemyHP = enemyHP - punetazo;

        if (enemyHP <= 0) {
            isAlive = false;
            cout << "has matado a " << enemyName << "\n";
        }
        else {
            cout << "al enemigo le quedan " << enemyHP << " puntos de vida\n";
            cout << punetazocount << "\n";
        }
        system("pause");
    }
    if (punetazocount == 0) {
        cout << "no tienes ataques, has perdido el turno \n";
        system("pause");
    }

    if (ataqueheroe == 2 && espadacount != 0) {
        cout << heroName << "ha usado espada\n";
        espadacount = espadacount - 1;
        enemyHP = enemyHP - espada;

        if (enemyHP <= 0) {
            isAlive = false;
            cout << "has matado a " << enemyName << "\n";
        }
        else {
            cout << "al enemigo le quedan " << enemyHP << " puntos de vida\n";
            cout << espadacount << "\n";
        }
        system("pause");
    }
    if (espadacount == 0) {
        cout << "no tienes ataques, has perdido el turno \n";
        system("pause");
    }




    if (ataqueheroe == 3 && magiacount != 0) {
        cout << heroName << "ha usado magia\n";
        magiacount = magiacount - 1;
        enemyHP = enemyHP - magia;

        if (enemyHP <= 0) {
            isAlive = false;
            cout << "has matado a " << enemyName << "\n";
        }
        else {
            cout << "al enemigo le quedan " << enemyHP << " puntos de vida\n";
            cout << magiacount << "\n";
        }
        system("pause");
    }
    if (magiacount == 0) {
        cout << "no tienes ataques, has perdido el turno \n";
        system("pause");
    }
}


int main() {

    start();

    int batalla;
    cin >> batalla;

    if (batalla == 1) {
        while (enemy1IsAlive == true || enemy2IsAlive == true && heroIsAlive == true) {
            if (enemy1IsAlive == true && enemy2IsAlive == true) {
                //decision heroe 
                int eleccion =  heroDecision();
                
                if (eleccion == 1) {
                    system("cls");
                    attackDecision();

                    atackHero(enemy1HP, enemy1IsAlive, enemy1Name);
                   

                }

                //atafcar enemigo 2
                if (eleccion == 2) {
                    system("cls");
                    attackDecision();
                    
                    atackHero(enemy2HP, enemy2IsAlive, enemy2Name);
                }


                //turno de los enemigos
                attackenemy();


            //turno de los enemigos si uno esta muerto
                attackenemy1();


                //turno del heroe

                
                attackDecision();
                int ataqueheroe3;
                cin >> ataqueheroe3;

                atackHero(enemy2HP, enemy2IsAlive, enemy2Name);

            }

            FinalHero();

            //si el enemigo 2 esta muerto
            attackenemy2();


                //turno del heroe

                
                attackDecision();
                int ataqueheroe4;
                cin >> ataqueheroe4;

                atackHero(enemy1HP, enemy1IsAlive, enemy1Name);
            }


            //Final del juego por que el heroe esta muerto

            FinalEnemy();
            FinalHero();
        }


        if (batalla == 2) {
            cout << heroName << " ha huido";
        }
    }


//acabar si el enemigo 1 esa vivo que ataque y al revés

//añadir count a los ataques

// ver que el bucle se repita perfectamente

//añadir sonido