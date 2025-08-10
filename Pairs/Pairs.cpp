// Pairs.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
    /*
    * Dans cet exo nous allons calculer la somme des nombres pairs d'une liste donnée.
    */

    std::vector<int> nombres = { 2, 78, 3, 55, 51, 68 };

    // Stratégie 1 : Notre boucle for dans le but de parcourir le tableau de nombres et d'y tester via modulo les nombres pairs.
    // Stratégie 2 : Via une lambda (condition, prédicat).

	/*
    * Utilisons la deuxième stratégie pour calculer la somme des nombres pairs.
	* Cette stratégie utilise un accumulateur pour parcourir le vecteur et additionner uniquement les nombres pairs.
	* La valeur initiale de l'accumulateur est 0.
    */
    int somme = std::accumulate(nombres.begin(), nombres.end(), 0, [](int acc, int nombre) {
        return acc + (nombre % 2 == 0 ? nombre : 0);
    });

    // Affichage de la somme des nombres pairs.
    std::cout << "La somme des nombres pairs est : " << somme << std::endl;

    /*
    * Néanmoins, un range based for loop aurait été davantage approprié et plus lisible.
    * Remettons la somme à zéro pour la démonstration suivante.
    */
	somme = 0;

    // Parcours des nombres dont le type nombre est déduit automatiquement.
    for (const auto& nombre : nombres)
    {
		// Si le nombre est pair, on l'ajoute à la somme.
        if (nombre % 2 == 0) somme += nombre;
	}

    // Affichage de la somme des nombres pairs.
    std::cout << "La somme des nombres pairs est : " << somme << std::endl;

    /*
    * Dernier petit exercice, avec un électro cardiogramme(ECG) où nous allons identifier les indices où l'amplitude est supérieure à 20.
    */

    struct Anomalie {
        int indice;
        int valeur;
    };

    std::vector<int> ecg_data{ 5, 7, 8, 12, 30, 25, 10, 6, 7, 5, 4, 3, 5, 8, 35, 40, 38, 20, 15, 7 };
    std::vector<Anomalie> anomalies {};
    int threshold = 20;

    // Avec boucle classique.
    for (int i = 0; i < ecg_data.size(); i++)
    {
        // Si la donnée dépasse le seuil, on ajoute l'anomalie (structure) dans la liste.
        if (ecg_data[i] > threshold) anomalies.push_back({i, ecg_data[i]});
    }

    std::cout << "Anomalies : ";
    for (const auto& anomalie : anomalies) std::cout << anomalie.indice << anomalie.valeur << std::endl;

    return 0;
}
