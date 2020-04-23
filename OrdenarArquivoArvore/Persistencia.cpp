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

    if(linha.size() == 0) throw QString ("Arquivo vazio");

    arquivo.seekg(std::ios::beg);

}

ArvoreBinariaPorCodigo<Aluno> *Persistencia::PegaDadosArquivo(){

    Aluno aluno;
    ArvoreBinariaPorCodigo<Aluno> *listaAlunos = 0;
    QStringList informacao;
    try{
       listaAlunos = new ArvoreBinariaPorCodigo<Aluno>();
    }catch(std::bad_alloc){
       throw QString("falta espaço na memória");
    }

    //getline(arquivo,linha);
    //linhaAux = QString::fromStdString(linha);

    std::ofstream arquivoErro;
    arquivoErro.open("Erro.csv", std::fstream::out);

    while(!arquivo.eof()){

        getline(arquivo,linha);

        //if(linha == "") throw QString("Arquivo Vazio");

        linhaAux = QString::fromStdString(linha);

        informacao = linhaAux.split(';');

        if(informacao.size() != 6){
            arquivoErro<<linha<<std::endl;
        }else
        {
            aluno.setCodigo(informacao[0].toInt());
            aluno.setNome(informacao[1]);
            aluno.setCurso(informacao[2]);
            aluno.setGraduacao(informacao[3]);
            aluno.setNaosei(informacao[4]);
            aluno.setData(informacao[5]);

            listaAlunos->inserir(aluno);

        }
        /*getline(arquivo,linha);
        linhaAux = QString::fromStdString(linha);*/
    }
    arquivoErro.close();
    return listaAlunos;
}

ArvoreBinariaPorNome<Aluno> *Persistencia::PegaDadosArquivoPorNome(){

    Aluno aluno;
    ArvoreBinariaPorNome<Aluno> *listaAlunos = 0;
    QStringList informacao;
    try{
       listaAlunos = new ArvoreBinariaPorNome<Aluno>();
    }catch(std::bad_alloc){
       throw QString("falta espaço na memória");
    }

    //getline(arquivo,linha);
    //linhaAux = QString::fromStdString(linha);

    std::ofstream arquivoErro;
    arquivoErro.open("Erro.csv", std::fstream::out);

    while(!arquivo.eof()){

        getline(arquivo,linha);

        //if(linha == "") throw QString("Arquivo Vazio");

        linhaAux = QString::fromStdString(linha);

        informacao = linhaAux.split(';');

        if(informacao.size() != 6){
            arquivoErro<<linha<<std::endl;
        }else
        {
            aluno.setCodigo(informacao[0].toInt());
            aluno.setNome(informacao[1]);
            aluno.setCurso(informacao[2]);
            aluno.setGraduacao(informacao[3]);
            aluno.setNaosei(informacao[4]);
            aluno.setData(informacao[5]);

            listaAlunos->inserir(aluno);

        }
        /*getline(arquivo,linha);
        linhaAux = QString::fromStdString(linha);*/
    }
    arquivoErro.close();
    return listaAlunos;
}

ArvoreBinariaPorNome<Aluno> *Persistencia::PegaDadosArquivoPorSobreNome(){

    Aluno aluno;
    ArvoreBinariaPorNome<Aluno> *listaAlunos = 0;
    QStringList informacao;
    QStringList nome;
    QString nomeAux = "";
    int i = 0;
    try{
       listaAlunos = new ArvoreBinariaPorNome<Aluno>();
    }catch(std::bad_alloc){
       throw QString("falta espaço na memória");
    }

    //getline(arquivo,linha);
    //linhaAux = QString::fromStdString(linha);

    std::ofstream arquivoErro;
    arquivoErro.open("Erro.csv", std::fstream::out);

    while(!arquivo.eof()){

        getline(arquivo,linha);

        //if(linha == "") throw QString("Arquivo Vazio");

        linhaAux = QString::fromStdString(linha);

        informacao = linhaAux.split(';');

        if(informacao.size() != 6){
            arquivoErro<<linha<<std::endl;
        }else
        {

            nome = informacao[1].split(' ');
            i = nome.size();
            nomeAux = nome[(i-1)]+",";
            for(int j = 0; j < (i-1); j++){
                nomeAux += " " + nome[j];
            }

            aluno.setCodigo(informacao[0].toInt());
            aluno.setNome(nomeAux);
            aluno.setCurso(informacao[2]);
            aluno.setGraduacao(informacao[3]);
            aluno.setNaosei(informacao[4]);
            aluno.setData(informacao[5]);

            listaAlunos->inserir(aluno);

        }
        /*getline(arquivo,linha);
        linhaAux = QString::fromStdString(linha);*/
    }
    arquivoErro.close();
    return listaAlunos;
}

Persistencia::~Persistencia(){
    arquivo.close();
}

}


