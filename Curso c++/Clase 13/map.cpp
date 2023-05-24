#include <iostream>
#include <map>
#include <string>

int
dictionary()
{
    std::map<std::string, std::string> m;
    while(true)
    {
        std::string spanish, english;
        std::cout << "enter a word in spanish [\"end\" to finish]: ";
        std::cin >> spanish;
        if (spanish == "end")
            break;
        if (m.find(spanish) != m.end())
            std::cout << spanish << " is " << m[spanish] << " in English." << std::endl;
        else
        {
            std::cout << "what's " << spanish << " in English? ";
            std::cin >> english;
            m[spanish] = english;
        }   
    }
    
    for (auto i : m)
        std::cout << i.second << " means: " << i.first << std::endl;
    return 0;
}

int word_count()
{
    std::map<std::string, int> word_counts;
    
    std::string sentence = "to be or not to be that is the question";
    std::string word;
    for (auto it = sentence.begin(); it != sentence.end(); it++) //Recorremos el string de la sentencia
    {
        bool last_word = it == sentence.end() - 1;
        if (*it == ' ' || last_word) //Si estamos en un espacio o en el final.
        {
            if (last_word)
                word += *it;
            if (word.length() > 0)
                word_counts[word]++;
            word.clear();
        }
        else
            word += *it;
    }
    
    for (auto wc : word_counts)
    std::cout << wc.first << ": " << wc.second << std::endl;
    return 0;
}

int
main()
{
    word_count();
}


/*
Un mapa es un array, digamos, de pairs.

DEFINICION DE ITERADOR: Un puntero hacia los elementos del array.

la funcion end devuelve un valor especial, que da a entender que un iterador es invalido, por lo que podemos
igualarlo al iterador para ver como anda.

*/


/*
    CONCEPTO DE ARBOL BINARIO
    Al recorrerlo, te revela el orden de busqueda que permite encontrar mas facilmente una clave.
    
    Esta compuesto de nodos, estos pueden tener como maximo 2 hijos.
    Cada bifurcación te genera dos ramas nuevas, la de la izquierda es la mejor, la de la derecha la mayor.
*/o