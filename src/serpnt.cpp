#include "serpnt.h"

void crearSerpiente(void)
{
    cabeza = (snake)malloc(sizeof(body));
    cabeza->x = sx;
    cabeza->y = sy;
    cabeza->sig = NULL;
    cabeza->ant = NULL;

    if (temp == NULL)
    {
        princi = cabeza;
        temp = cabeza;
        cola = cabeza;
    }
    else
    {
        cabeza->ant = princi;
        princi->sig = cabeza;
        princi = cabeza;
    }
}

void limpiarSerpiente(void)
{
    while (temp->sig != NULL)
    {
        cola = temp->sig;
        cola->ant = temp->ant;
        free(temp);
        temp = cola;
        aux = NULL;
    }
}

int verificarAutocanibalismo(void)
{
    aux = princi->ant->ant;
    while (aux != NULL)
    {
        if (princi->x == aux->x && princi->y == aux->y)
        {
            return 1; // Se encontró auto-canibalismo
        }
        aux = aux->ant;
    }
    return 0; // No hay auto-canibalismo
}