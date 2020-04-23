#include "Persistencia.h"
namespace ED1 {
Persistencia::Persistencia(QString nomeDoArquivo):
    linha("")
{
    //Buscando o arquivo no disco
    if(nomeDoArquivo.isEmpty()) throw QString("Arquivo nao foi selecionado");

    // abrindo um arquivo de entrada
    arquivo.open(nomeDoArquivo.toStdString().c_str());

    // verificando erro de abertura do arquivo de entrada
    if(!arquivo.is_open()){
        throw QString("ERRO Arquivo nao pode ser aberto");
    }

    getline(arquivo, linha);

    if(linha == "") throw QString ("Arquivo vazio");

    arquivo.seekg(std::ios::beg);

}

Lista* Persistencia::inclusaoInicio(){

    Piloto piloto;
    Lista *listaPiloto = 0;
    QStringList informacao;
    try{
        listaPiloto = new Lista();
    }catch(std::bad_alloc){
       throw QString("falta espaço na memória");
    }

    /*getline(arquivo,linha);
    linhaAux = QString::fromStdString(linha);*/

    std::ofstream arquivoErro;
    arquivoErro.open("Erro.csv", std::fstream::out);

    while(!arquivo.eof()){

        getline(arquivo,linha);

        //if(linha == "") throw QString("Arquivo Vazio");

        linhaAux = QString::fromStdString(linha);

        informacao = linhaAux.split(',');

        if(informacao.size() != 7){
            arquivoErro<<linha<<std::endl;
        }else
        {
            piloto.setNumero(informacao[0].toInt());
            piloto.setNome(informacao[1]);
            piloto.setPais(informacao[2]);
            piloto.setIdade(informacao[3].toInt());
            piloto.setEquipe(informacao[4]);
            piloto.setMotor(informacao[5]);
            piloto.setPontos(informacao[6].toInt());

            listaPiloto->inserirInicio(piloto);
        }
        /*getline(arquivo,linha);
        linhaAux = QString::fromStdString(linha);*/
    }
    arquivoErro.close();
    return listaPiloto;
}

Lista* Persistencia::inclusaoFim(){

    Piloto piloto;
    Lista *listaPiloto = 0;
    QStringList informacao;
    try{
        listaPiloto = new Lista();
    }catch(std::bad_alloc){
       throw QString("falta espaço na memória");
    }

    /*getline(arquivo,linha);
    linhaAux = QString::fromStdString(linha);*/

    std::ofstream arquivoErro;
    arquivoErro.open("Erro.csv", std::fstream::out);

    while(!arquivo.eof()){

        getline(arquivo,linha);

        //if(linha == "") throw QString("Arquivo Vazio");

        linhaAux = QString::fromStdString(linha);

        informacao = linhaAux.split(',');

        if(informacao.size() != 7){
            arquivoErro<<linha<<std::endl;
        }else
        {
            piloto.setNumero(informacao[0].toInt());
            piloto.setNome(informacao[1]);
            piloto.setPais(informacao[2]);
            piloto.setIdade(informacao[3].toInt());
            piloto.setEquipe(informacao[4]);
            piloto.setMotor(informacao[5]);
            piloto.setPontos(informacao[6].toInt());

            listaPiloto->inserirFim(piloto);
        }
        /*getline(arquivo,linha);
        linhaAux = QString::fromStdString(linha);*/
    }
    arquivoErro.close();
    return listaPiloto;
}

Lista* Persistencia::inclusaoOrdenada(){

    Piloto piloto;
    Lista *listaPiloto = 0;
    QStringList informacao;
    try{
        listaPiloto = new Lista();
    }catch(std::bad_alloc){
       throw QString("falta espaço na memória");
    }

    /*getline(arquivo,linha);
    linhaAux = QString::fromStdString(linha);*/

    std::ofstream arquivoErro;
    arquivoErro.open("Erro.csv", std::fstream::out);

    while(!arquivo.eof()){

        getline(arquivo,linha);

        linhaAux = QString::fromStdString(linha);

        informacao = linhaAux.split(',');

        if(informacao.size() != 7){
            arquivoErro<<linha<<std::endl;
        }else
        {
            piloto.setNumero(informacao[0].toInt());
            piloto.setNome(informacao[1]);
            piloto.setPais(informacao[2]);
            piloto.setIdade(informacao[3].toInt());
            piloto.setEquipe(informacao[4]);
            piloto.setMotor(informacao[5]);
            piloto.setPontos(informacao[6].toInt());

            listaPiloto->inserirOrdenado(piloto);
        }
        /*getline(arquivo,linha);
        linhaAux = QString::fromStdString(linha);*/
    }
    arquivoErro.close();
    return listaPiloto;
}

Persistencia::~Persistencia(){
    arquivo.close();
}

}


