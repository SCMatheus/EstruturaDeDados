//#include <QCoreApplication>
//#include <IPilha.h>
#include <Pilha.h>
#include <iostream>
int main(/*int argc, char *argv[]*/)
{
   /* QCoreApplication a(argc, argv);

    return a.exec();
*/
    //No

    ED1::No<int> a;

    a.setInformacao(30);
    a.setAnterior(0);
    a.setProximo(0);


    std::cout<<a.getInformacao()<<" "<<a.getAnterior()<<" "<<a.getProximo()<<std::endl;


    ED1::ListaDuplamenteEncadeadaCircular<int> Lista;

    Lista.inserirInicio(10);
    Lista.inserirInicio(20);
    Lista.inserirInicio(30);
    Lista.inserirInicio(40);

    std::cout<<Lista.retirarFim()<<" "<<Lista.retirarFim()<<" "<<Lista.retirarFim()<<" "<<Lista.retirarFim()<<std::endl;

    Lista.inserirFim(10);
    Lista.inserirFim(20);
    Lista.inserirFim(30);

    std::cout<<"Quantidade de Elementos: "<<Lista.getQuantidadeDeElementos()<<"\n";
    std::cout<<"Dado: "<<Lista.retirarFim()<<"\n";
    std::cout<<"Quantidade de Elementos: "<<Lista.getQuantidadeDeElementos()<<"\n";
    std::cout<<"Dado: "<<Lista.retirarFim()<<"\n";
    std::cout<<"Quantidade de Elementos: "<<Lista.getQuantidadeDeElementos()<<"\n";
    std::cout<<"Dado: "<<Lista.retirarFim()<<"\n";
    std::cout<<"Quantidade de Elementos: "<<Lista.getQuantidadeDeElementos()<<"\n";
    //std::cout<<"Dado: "<<listaTeste.retirarInicio()<<"\n\n";

    ED1::Pilha<int> pilha;

//    std::cout<<Lista.retirarFim()<<std::endl<<Lista.retirarFim()<<std::endl<<Lista.retirarFim()<<std::endl;

}
