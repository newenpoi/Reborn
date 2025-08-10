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

char shift(char c, const string& alphabet, int offset)
{
	// Cherche la position du caractère dans l'alphabet.
	size_t pos = alphabet.find(c);

	// Si le caractère n'est pas trouvé, aucun changement.
	if (pos == string::npos) return c;

	// Compatibilité avec les décalages négatifs ou supérieurs à la taille de l'alphabet.
	// On utilisera le modulo pour calculer la nouvelle position.
	size_t new_pos = (pos + offset + alphabet.size()) % alphabet.size();

	// Renvoie le caractère de l'alphabet à la nouvelle position.
	return alphabet[new_pos];
}

int main()
{
	string input, output;
	int offset = 3;

	string lowercase = "abcdefghijklmnopqrstuvwxyz";
	string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string digits = "0123456789";

	// Attente de l'entrée utilisateur.
	cout << u8"Entrez la chaîne de caractères à encoder." << endl;
	cin >> input;

	/*
	* Pour chaque caractère de la chaîne d'entrée, on applique le décalage.
	* La fonction shift est utilisée pour déterminer le nouveau caractère en fonction de l'alphabet approprié.
	*/
	for (char c : input)
	{
		if (islower(c)) output += shift(c, lowercase, offset);
		else if (isupper(c)) output += shift(c, uppercase, offset);
		else if (isdigit(c)) output += shift(c, digits, offset);
		else output += c;
	}

	cout << "Résultat de l'encodage :" << endl;
	cout << output << endl;
}

