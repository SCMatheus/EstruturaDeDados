#ifndef ALUNO_H
#define ALUNO_H
#include <QString>
namespace ED1 {
class Aluno
{
private:
    int codigo;
    QString nome;
    QString curso;
    QString graduacao;
    QString naosei;
    QString data;
public:
    Aluno():codigo(0),nome(""),curso(""),graduacao(""),naosei(""),data(""){}
    Aluno(int codigo, QString nome, QString curso, QString graduacao, QString naosei, QString data);

    //Sets

    void setCodigo(int codigo){this->codigo = codigo;}
    void setNome(QString nome){this->nome = nome;}
    void setCurso(QString curso){this->curso = curso;}
    void setGraduacao(QString graduacao){this->graduacao = graduacao;}
    void setNaosei(QString naosei){this->naosei = naosei;}
    void setData(QString data){this->data = data;}

    //Gets

    int getCodigo()const{return codigo;}
    QString getNome()const{return nome;}
    QString getCurso()const{return curso;}
    QString getGraduacao()const{return graduacao;}
    QString getNaosei()const{return naosei;}
    QString getData()const{return data;}

    operator <(Aluno elemento2);
    operator >(Aluno elemento2);
    operator ==(Aluno elemento2);

};
}
#endif // ALUNO_H
