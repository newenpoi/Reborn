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
*/

int main()
{
	string input, output;
	int offset = 3;
	string lowercase = "abcdefghijklmnopqrstuvwxyz";
	string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	// Attente de l'entrée utilisateur.
	cout << u8"Entrez la chaîne de caractères à encoder." << endl;
	cin >> input;

	// Encodage grâce à une boucle for où i est le parcours de l'input par rapport à sa taille.
	for (int i = 0, j = 0; i < input.size(); i++)
	{
		// Uppercase.
		if (input[i] >= 65 && input[i] <= 90)
		{
			// Récupère la position du caractère.
			size_t pos = uppercase.find(input[i]);

			// Gère les limites de l'offset acceptables grâce à modulo.
			size_t new_pos = (pos + offset) % uppercase.size();

			// Ajoute le caractère avec un décalage (encodage).
			output.push_back(uppercase[new_pos]);
		}

		// Lowercase.
		else if (input[i] >= 97 && input[i] <= 122)
		{
			// Récupère la position du caractère.
			size_t pos = lowercase.find(input[i]);
			
			// Gère les limites de l'offset acceptables grâce à modulo.
			size_t new_pos = (pos + offset) % lowercase.size();
			
			// Ajoute le caractère avec un décalage (encodage).
			output.push_back(lowercase[new_pos]);
		}

		// Numerics.
		else if (input[i] >= 48 && input[i] <= 57)
		{
			// Récupère la position du caractère (converti le caractère en entier).
			size_t pos = input[i] - '0';
			
			// Gère les limites de l'offset acceptables grâce à modulo.
			size_t new_pos = (pos + offset) % 10;
			
			// Ajoute le caractère avec un décalage (encodage).
			output.push_back(new_pos + '0');
		}

		else
		{
			// Pour tout autre caractère, on le laisse tel quel.
			output.push_back(input[i]);
		}
	}

	cout << "Résultat de l'encodage :" << endl;
	cout << output << endl;
}

