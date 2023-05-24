#include <iostream>

//Strings!!!


//Funcion de asignacion de strings
//Si vos agarras un valor (from en este caso) y lo queres meter en otro lado,
//no tiene por que modificarse, por lo que le ponemos const.
//y lo que pasa es q es el VALOR AL QUE APUNTA lo que no se modifica.
void copy_string(char* to, const char* from) 
{
    while(*from)
        *to++ = *from++;
    *to = 0;
}

//Ahora, el tema es que from no puede ser mas grande que to, por lo que una cosa que podriamos hacer es
//Pasar por parametro el tamaño de from.
void copy_string_with_size(char* to, unsigned size, const char* from)
{
    for (unsigned i = 0; i < size; i++)
    {
        to[i] = from[i];
        if (!from[i])
            return; //Si llegamos al final de from, cortamos
    }
    to[size - 1] = 0; //Pone un 0 al final del string.
}
//Esta funcion hace que si el string se queda corto, lo corte, en lugar de destrozar el programa.


int main()
{
    //La primer parte del for se ejecuta una vez al inicializar el for.
    //La segunda parte se ejecuta antes de cada bucle.
    //La tercera al finalizar el bucle, para que luego la 2da pueda verificar uwu.
    for (unsigned i = 0; i < 10; i++);

    char saludo[] = "hola"; //Aca estoy asignando un string constante a un string no constante
    char *ptr = saludo; //Agarro un string variable y le asigno lo que tiene el string constante

    for (char *ptr = saludo; *ptr; ptr++)
    {
        std::cout << *ptr << std::endl;
    }

    char despedida[] = "adios";
    char *ptr2 = despedida;

    (*ptr2)++;
    (*ptr2)++;
    (*ptr2)++;
    (*ptr2)++;
    (*ptr2)++;

    //Asignar cotenido al que apunta, luego incrementar. *(1) ptr2 ++(3) =(2) 
    //La diferencia habria estado en escribir *++p, basicamente, ++p es incrementar y luego usar.

    //Entonces * te dereferenciaria lo que esta a su derecha.
    //Ahora, ¿Cómo puedo aumentar los valores de los espacios de un array?
    //Creo que en tal caso eso sería (*p)++

    char string[20];

    copy_string(string,"Hola,Funciona");

    std::cout << string << std::endl;
    
    
}