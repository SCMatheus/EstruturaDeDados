#include "Piloto.h"
namespace ED1 {
    Piloto::Piloto():
        numero(0),
        nome(""),
        pais(""),
        idade(0),
        equipe(""),
        motor(""),
        pontos(0)
    {
    }

    void Piloto::setNumero(int numero){
        if(numero < 0) throw QString("Número inválido");
        this->numero = numero;
    }

    void Piloto::setIdade(int idade){
        if(idade < 0) throw QString("Idade inválido");
        this->idade = idade;
    }

    void Piloto::setPontos(int pontos){
        if(pontos < 0) throw QString("Pontos inválido");
        this->pontos = pontos;
    }

    bool Piloto::operator < (Piloto piloto){
        if(getNome() < piloto.getNome()){
            return 1;
        }
        else return 0;
    }

    bool Piloto::operator>= (Piloto piloto){
        if(getNome() >= piloto.getNome()){
            return 1;
        }
        else return 0;
    }

    bool Piloto::operator == (Piloto piloto){
        if(getNome() == piloto.getNome()){
            return 1;
        }
        else return 0;
    }

    bool Piloto::operator != (Piloto piloto){
        if(getNome() != piloto.getNome()){
            return 1;
        }
        else return 0;
    }

}
