#include <QCoreApplication>
#include<iostream>
#include <string>
#include <No.h>
#include <Lista.h>


int main(){
    std::cout<<"Teste classe No \n\n";
    ED1::No<int> noTeste;
    noTeste.setInformacao(10);
    std::cout<<"Dado: "<<noTeste.getInformacao()<<"\n";
    std::cout<<"Ponteiro proximo: "<<noTeste.getProximo();
    std::cout<<"\n";
    std::cout<<"Ponteiro anterior: "<<noTeste.getAnterior();
    std::cout<<"\n\n";
    try{
        ED1::Lista<int> listaTeste;
        std::cout<<"Teste classe Lista \n";
        std::cout<<"Teste incluir no inicio \n";
        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n";
        listaTeste.inserirInicio(10);
        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n";
        listaTeste.inserirInicio(20);
        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n";
        listaTeste.inserirInicio(30);
        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n\n";

        std::cout<<"Teste retirar do inicio \n";
        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n";
        std::cout<<"Dado: "<<listaTeste.retirarInicio()<<"\n";
        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n";
        std::cout<<"Dado: "<<listaTeste.retirarInicio()<<"\n";
        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n";
        std::cout<<"Dado: "<<listaTeste.retirarInicio()<<"\n";
        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n";
        //std::cout<<"Dado: "<<listaTeste.retirarInicio()<<"\n\n";

        std::cout<<"Teste incluir no Fim \n";
        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n";
        listaTeste.inserirFim(10);
        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n";
        listaTeste.inserirFim(20);
        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n";
        listaTeste.inserirFim(30);
        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n\n";

        std::cout<<"Teste retirar do fim \n";
        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n";
        std::cout<<"Dado: "<<listaTeste.retirarFim()<<"\n";
        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n";
        std::cout<<"Dado: "<<listaTeste.retirarFim()<<"\n";
        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n";
        std::cout<<"Dado: "<<listaTeste.retirarFim()<<"\n";
        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n";
        //std::cout<<"Dado: "<<listaTeste.retirarInicio()<<"\n\n";

        std::cout<<"Teste incluir no inicio \n";
        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n";
        listaTeste.inserirInicio(10);
        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n";
        listaTeste.inserirInicio(20);
        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n";
        listaTeste.inserirInicio(30);
        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n\n";

        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n";
        std::cout<<"Dado: "<<listaTeste.retirarFim()<<"\n";
        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n";
        std::cout<<"Dado: "<<listaTeste.retirarFim()<<"\n";
        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n";
        std::cout<<"Dado: "<<listaTeste.retirarFim()<<"\n";
        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n";
        //std::cout<<"Dado: "<<listaTeste.retirarInicio()<<"\n\n";

        std::cout<<"Teste incluir no Fim \n";
        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n";
        listaTeste.inserirFim(10);
        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n";
        listaTeste.inserirFim(20);
        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n";
        listaTeste.inserirFim(30);
        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n\n";

        std::cout<<"Teste retirar do inicio \n";
        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n";
        std::cout<<"Dado: "<<listaTeste.retirarInicio()<<"\n";
        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n";
        std::cout<<"Dado: "<<listaTeste.retirarInicio()<<"\n";
        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n";
        std::cout<<"Dado: "<<listaTeste.retirarInicio()<<"\n";
        std::cout<<"Quantidade de Elementos: "<<listaTeste.getQuantidadeDeElementos()<<"\n\n";
        //std::cout<<"Dado: "<<listaTeste.retirarInicio()<<"\n\n";


    }catch (QString &erro) {
        std::cout<<"\n\nERRO: "<<erro.toStdString()<<"\n\n";
    }
}
