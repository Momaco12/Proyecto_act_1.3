


//
// Created by Andre on 23/09/2025.
//

#ifndef HERRAMIENTAS_H
#define HERRAMIENTAS_H
#include "Log.h"
#include <vector>


class herramientas {

  public:
    static void quickSort( vector<Log> &arr, int low, int high);
    static int partition( vector<Log> &arr, int low, int high);
    void static swap(Log* val1, Log* val2);
    static int fechaATotalSegundos(const string& mes, const string &dia, const string& hora, const string &minuto, const string &segundo);
    static int busquedaBi(std::vector<Log> &vector,int clave);
    static int getNumberBI(string meses, string dias);
};

#endif
