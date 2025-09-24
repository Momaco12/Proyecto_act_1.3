#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>
#include "Log.h"
#include "Herramientas.h"
#include <sstream>
using namespace std;
// Función para guardar los registros ordenados en un archivo
void guardarArchivo(const vector<Log>& registros, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (Log  reg : registros) {
            archivo << reg.getMes() << " " << reg.getDia() << " " << reg.getTiempo() << " " << reg.getIp() << " " << reg.getLog() << endl;
        }
        archivo.close();
        cout << "Registros ordenados guardados en '" << nombreArchivo << "'." << endl;
    } else {
        cerr << "Error: No se pudo crear el archivo '" << nombreArchivo << "'." << endl;
    }
}
int main() {




    ifstream fin("bitacora.txt");
    if (!fin.is_open()) {
        cerr << "No se pudo abrir el archivo.\n";
        return 1;
    }
    Log prueba;

    vector<Log> reportes;

    string linea;
    while (getline(fin, linea)) {
        istringstream iss(linea);

        string mes, dia, hora, ip, resto;
        iss >> mes >> dia >> hora >> ip;
        getline(iss, resto);

        prueba.setMes(mes);
        prueba.setDia(dia);
        prueba.setTiempo(hora);
        prueba.setIp(ip);
        prueba.setLog(resto);

        reportes.push_back(prueba);

    }
    herramientas::quickSort(reportes, 0, reportes.size() - 1);

    // int i = 0;
    // while (i < reportes.size()) {
    //     cout << reportes[i].getNumber() << endl;
    //     i++;
    // }

//inputs

     string mes_inicio, mes_fin;
     string dia_inicio, dia_fin;
     cout<<"Ingrese la fecha de inicio (Ejemplo: Jun 15): ";
     cin >> mes_inicio>> dia_inicio;
     cout << "Ingrese la fecha de fin (Ejemplo: Sep 30): ";
     cin>> mes_fin>>dia_fin;

    int segundos_inicio = herramientas::getNumberBI(mes_inicio, dia_inicio);
    int segundos_final = herramientas::getNumberBI(mes_fin, dia_fin);

    int punto_inicio  = herramientas::busquedaBi(reportes,segundos_inicio);
    int punto_final  = herramientas::busquedaBi(reportes,segundos_final);
    cout << punto_inicio<< endl << punto_final;
      // Abrir el archivo de salida para escribir los resultados de la búsqueda
        ofstream fout("busqueda.txt");
        if (!fout.is_open()) {
            cerr << "Error: No se pudo crear el archivo de salida.\n";
            return 1;
        }

        // Bucle para iterar y escribir los registros en el archivo
        for (int j = punto_inicio; j <= punto_final; ++j) {
            if (j < 0 || j >= reportes.size()) {
                continue; // Evita acceder a índices fuera de rango
            }
            Log reg = reportes[j];
            cout << reg.getMes() << " " << reg.getDia() << " " << reg.getTiempo() << " " << reg.getIp() << " " << reg.getLog() << endl;
            fout << reg.getMes() << " " << reg.getDia() << " " << reg.getTiempo() << " " << reg.getIp() << " " << reg.getLog() << endl;

        }

        fout.close(); // Cerrar el archivo de salida
        cout << "Registros encontrados y guardados en 'busqueda.txt'." << endl;
}



