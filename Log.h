//
// Created by Andre on 23/09/2025.
//
#include <string>
using namespace std;

#ifndef LOG_H
#define LOG_H



class Log {
    string mes, dia, tiempo, hora, minuto, segundo, ip, log, cantidad;

  public:
    void setMes(string n);
    void setDia(string n);
    void setTiempo(string n);
    void setIp(string n);
    void setLog(string n);

    string getMes();
    string getDia();
    string getTiempo();
    string getIp();
    string getLog();

    int getNumber();
    int getNumberBI();

};



#endif //LOG_H
