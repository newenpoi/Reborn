// Sorting.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // Initialise un vecteur d'entiers avec des valeurs aléatoires non triées.
	std::vector<int> scores = { 5, 2, 9, 54, 35, 25 };

	// Affiche le tableau de score initial.
	for (int score : scores) std::cout << score << " ";

	// Tri par ordre décroissant avec un tri stable (début, fin et prédicat).
	std::stable_sort(scores.begin(), scores.end(), [](int a, int b) { return a > b; });

	// Affichage du score trié.
	std::cout << std::endl;
	for (int score : scores) std::cout << score << " ";
}
