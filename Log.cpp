//
// Created by Andre on 23/09/2025.
//
#include "Log.h"
#include <iostream>
#include <sstream>
using namespace std;

void Log::setMes(string n){
  this->mes = n;
}
void Log::setDia(string n){
  this->dia = n;
}
void Log::setTiempo(string n){
  this->tiempo = n;
  stringstream cambio(tiempo);

  string horas, minutos, segundos;

  getline(cambio, horas, ':');    // lee hasta el primer ':'
  getline(cambio, minutos, ':');  // lee hasta el segundo ':'
  getline(cambio, segundos, ':'); // lee lo que queda

  this->hora = horas;
  this->minuto = minutos;
  this->segundo = segundos;

}
void Log::setIp(string n){
  this->ip = n;
}
void Log::setLog(string n){
  this->log = n;
}


string Log::getMes(){
  return mes;
}
string Log::getDia(){
  return dia;
}
string Log::getTiempo(){
  return tiempo;
}
string Log::getIp(){
  return ip;
}
string Log::getLog(){
  return log;
}



int Log::getNumber(){
  int DiaSegundos = (std::stoi(dia) * 86400)-86400;
  int MinSegundos = std::stoi(minuto) * 60;
  int HoraSegundos = std::stoi(hora) * 3600;
  int MesesSegundos;
  if(mes=="Jun"){
  MesesSegundos=13046400;}
  else if(mes=="Jul"){
  MesesSegundos=15638400;}
  else if(mes=="Ago"){
  MesesSegundos=18316800;}
  else if(mes=="Sep"){
  MesesSegundos=21004800;}
  else if(mes=="Oct"){
  MesesSegundos=23587200;}
  else{
    MesesSegundos=0;}
    return (DiaSegundos + MinSegundos + HoraSegundos + MesesSegundos + std::stoi(segundo));
}

int Log::getNumberBI(){
  int DiaSegundos = (std::stoi(dia) * 86400)-86400;
  int MesesSegundos;
  if(mes=="Jun"){
    MesesSegundos=13046400;}
  else if(mes=="Jul"){
    MesesSegundos=15638400;}
  else if(mes=="Ago"){
    MesesSegundos=18316800;}
  else if(mes=="Sep"){
    MesesSegundos=21004800;}
  else if(mes=="Oct"){
    MesesSegundos=23587200;}
  else{
    MesesSegundos=0;}
  return (DiaSegundos + MesesSegundos);
}
