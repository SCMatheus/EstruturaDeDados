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

Pilha<Aluno>* Persistencia::PegaDadosArquivo(){

    Aluno aluno;
    Pilha<Aluno> *listaAluno = 0;
    QStringList informacao;
    try{
        listaAluno = new Pilha<Aluno>();
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

            listaAluno->inserir(aluno);

        }
        /*getline(arquivo,linha);
        linhaAux = QString::fromStdString(linha);*/
    }
    arquivoErro.close();
    return listaAluno;
}

Persistencia::~Persistencia(){
    arquivo.close();
}

}


