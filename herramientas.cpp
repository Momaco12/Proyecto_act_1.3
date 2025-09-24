//
// Created by Andre on 23/09/2025.
//

#include "herramientas.h"
#include "Log.h"
#include <vector>

int herramientas::partition(vector<Log> &arr, int low, int high) {
    Log pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].getNumber() <= pivot.getNumber()) { // compara según criterio
            i++;
            swap(&arr[i], &arr[j]); // swap de objetos Log
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void herramientas::quickSort(vector<Log> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

void herramientas::swap(Log* val1, Log* val2)
{
    Log temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

int herramientas::fechaATotalSegundos(const string& mes, const string &dia, const string& hora, const string &minuto, const string &segundo){
        int DiaSegundos = (stoi(dia) * 86400) - 86400; // días a segundos
        int HoraSegundos = stoi(hora) * 3600;
        int MinSegundos  = stoi(minuto) * 60;
        int Segundos     = stoi(segundo);

        int MesesSegundos = 0;
        if(mes=="Jun")  MesesSegundos = 13046400;
        else if(mes=="Jul") MesesSegundos = 15638400;
        else if(mes=="Ago") MesesSegundos = 18316800;
        else if(mes=="Sep") MesesSegundos = 21004800;
        else if(mes=="Oct") MesesSegundos = 23587200;
        // ... agrega más meses si es necesario

        return MesesSegundos + DiaSegundos + HoraSegundos + MinSegundos + Segundos;
    }


int herramientas::busquedaBi(std::vector<Log> &vector,int clave){
    int valorCentral = 0;
    int baja = 0;
    int alto = vector.size()-1;
    int central = 0;

    while (baja <= alto){
        central = (alto + baja) / 2;
        valorCentral = vector[central].getNumberBI();
        if (valorCentral == clave)
            return central;

        else if (valorCentral > clave )
            alto = central -1;

        else
            baja = central +1;

    }

    return -1;
};

int herramientas::getNumberBI(string meses, string dias){
    int DiaSegundos = (std::stoi(dias) * 86400)-86400;
    int MesesSegundos;
    if(meses=="Jun"){
        MesesSegundos=13046400;}
    else if(meses=="Jul"){
        MesesSegundos=15638400;}
    else if(meses=="Ago"){
        MesesSegundos=18316800;}
    else if(meses=="Sep"){
        MesesSegundos=21004800;}
    else if(meses=="Oct"){
        MesesSegundos=23587200;}
    else{
        MesesSegundos=0;}
    return (DiaSegundos + MesesSegundos);
}
