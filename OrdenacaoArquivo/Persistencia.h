#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H
#include<Pilha.h>
#include<QString>
#include <Aluno.h>
#include<fstream>
#include <QStringList>
namespace ED1 {
class Persistencia
{
private:
    std::string linha;
    QString linhaAux;
    std::ifstream arquivo;
public:
    Persistencia(QString nomeDoArquivo);
    ~Persistencia();
    Pilha<Aluno>* PegaDadosArquivo();
};
}
#endif // PERSISTENCIA_H
