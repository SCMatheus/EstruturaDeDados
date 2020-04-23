#ifndef PILOTO_H
#define PILOTO_H
#include<QString>

namespace ED1{
class Piloto
{
private:
    int numero;
    QString nome;
    QString pais;
    int idade;
    QString equipe;
    QString motor;
    int pontos;

public:
    Piloto();
    void setNumero(int numero);
    void setNome(QString nome){this->nome = nome;}
    void setPais(QString pais){this->pais = pais;}
    void setIdade(int idade);
    void setEquipe(QString equipe){this->equipe = equipe;}
    void setMotor(QString motor){this->motor = motor;}
    void setPontos(int pontos);

    int getNumero()const{return numero;}
    QString getNome()const{return nome;}
    QString getPais()const{return pais;}
    int getIdade()const{return idade;}
    QString getEquipe(){return equipe;}
    QString getMotor()const{return motor;}
    int getPontos()const{return pontos;}
    bool operator < (Piloto piloto);
    bool operator >= (Piloto piloto);
    bool operator == (Piloto piloto);
    bool operator != (Piloto piloto);

};
}
#endif // PILOTO_H
