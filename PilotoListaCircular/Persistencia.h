#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H
#include<ListaCircular.h>
#include<QString>
#include<No.h>
#include<Piloto.h>
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
    Lista* inclusaoInicio();
    Lista* inclusaoFim();
    Lista* inclusaoOrdenada();
};
}
#endif // PERSISTENCIA_H
