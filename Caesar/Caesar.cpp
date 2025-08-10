// Caesar.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string>

using namespace std;

/*
* Dans ce projet, nous allons avoir en entrée une chaine de caractères que nous allons encoder.
* On utilisera un décalage de 3 caractères pour l'encodage (comme un code César).
* Contraintes :
* Gérer le cas où l'offset serait hors limites (%).
* Tout d'abord tester uniquement avec des minuscules (on procède étape par étape).
* Gérer maintenant les majuscules et les minuscules (décalage identique mais conserver la casse).
* Les caractères spéciaux ne changent pas.
* Peut être que str.at() serait utile.
*/

int main()
{
	string input, output;
	int offset = 3;
	string characters = "abcdefghijklmnopqrstuvwxyz";

	// Attente de l'entrée utilisateur.
	cout << u8"Entrez la chaîne de caractères à encoder." << endl;
	cin >> input;

	// Encodage grâce à une boucle for où i est le parcours de l'input par rapport à sa taille.
	for (int i = 0, j = 0; i < input.size(); i++)
	{
		// Récupère la position du caractère.
		size_t pos = characters.find(input[i]);

		// Gère les limites de l'offset acceptables grâce à modulo.
		size_t new_pos = (pos + offset) % characters.size();

		// Ajoute le caractère avec un décalage (encodage).
		output.push_back(characters[new_pos]);
	}

	cout << "Résultat de l'encodage :" << endl;
	cout << output << endl;
}

