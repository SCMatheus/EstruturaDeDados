#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    diretorioArquivo(QFileDialog::getOpenFileName(this,"Ordenar Por Codigo",QDir::currentPath(),"Arquivos Textos (*.csv *.txt)"))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonOrdenarPorCodigo_clicked()
{
    ED1::ArvoreBinariaPorCodigo<ED1::Aluno> *arvore;
    ED1::Fila<ED1::Aluno> *fila;

    try{
        fila = new ED1::Fila<ED1::Aluno>();

        ED1::Persistencia ordenacao(diretorioArquivo);

        arvore = ordenacao.PegaDadosArquivo();
        arvore->imprimirCDireita(fila);

        exibeDados(fila);

    }catch(QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }
    catch(std::bad_alloc){
           throw QString("falta espaço na memória");
        }
}

void MainWindow::on_pushButtonOrdenarPorNome_clicked()
{
    ED1::ArvoreBinariaPorCodigo<ED1::Aluno> *arvore = 0;
    ED1::Pilha<ED1::Aluno> *pilha;

    try{
        pilha = new ED1::Pilha<ED1::Aluno>();
        ED1::Persistencia ordenacao(diretorioArquivo);

        arvore = ordenacao.PegaDadosArquivo();
        arvore->imprimirCEsquerda(pilha);

        exibeDadoPilha(pilha);

    }catch(QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }
    catch(std::bad_alloc){
           throw QString("falta espaço na memória");
        }
}

void MainWindow::exibeDados(ED1::Fila<ED1::Aluno> *filaDeDados){

    ED1::Aluno exibeAluno;
    int linha = 0;

    ui->tableWidgetSaida -> setRowCount ( filaDeDados->getQuantidadedeElementos()) ;
    ui->tableWidgetSaida->setItem(1 , 1, new QTableWidgetItem(exibeAluno.getNome()));
    while(!filaDeDados->vazia()){
        exibeAluno = filaDeDados->remover();
        ui->tableWidgetSaida->setItem(linha , 0, new QTableWidgetItem(QString::number(exibeAluno.getCodigo())));
        ui->tableWidgetSaida->setItem(linha , 1, new QTableWidgetItem(exibeAluno.getNome()));
        ui->tableWidgetSaida->setItem(linha , 2, new QTableWidgetItem(exibeAluno.getCurso()));
        ui->tableWidgetSaida->setItem(linha , 3, new QTableWidgetItem(exibeAluno.getGraduacao()));
        ui->tableWidgetSaida->setItem(linha , 4, new QTableWidgetItem(exibeAluno.getNaosei()));
        ui->tableWidgetSaida->setItem(linha , 5, new QTableWidgetItem(exibeAluno.getData()));
        linha++;
    }


}

void MainWindow::exibeDadoPilha(ED1::Pilha<ED1::Aluno> *pilhaDeDados){

    ED1::Aluno exibeAluno;
    int linha = 0;

    ui->tableWidgetSaida -> setRowCount ( pilhaDeDados->getQuantidadedeElementos()) ;
    ui->tableWidgetSaida->setItem(1 , 1, new QTableWidgetItem(exibeAluno.getNome()));
    while(!pilhaDeDados->vazia()){
        exibeAluno = pilhaDeDados->remover();
        ui->tableWidgetSaida->setItem(linha , 0, new QTableWidgetItem(QString::number(exibeAluno.getCodigo())));
        ui->tableWidgetSaida->setItem(linha , 1, new QTableWidgetItem(exibeAluno.getNome()));
        ui->tableWidgetSaida->setItem(linha , 2, new QTableWidgetItem(exibeAluno.getCurso()));
        ui->tableWidgetSaida->setItem(linha , 3, new QTableWidgetItem(exibeAluno.getGraduacao()));
        ui->tableWidgetSaida->setItem(linha , 4, new QTableWidgetItem(exibeAluno.getNaosei()));
        ui->tableWidgetSaida->setItem(linha , 5, new QTableWidgetItem(exibeAluno.getData()));
        linha++;
    }


}

void MainWindow::on_pushButtonPreFDireita_clicked()
{
    ED1::ArvoreBinariaPorCodigo<ED1::Aluno> *arvore = 0;
    ED1::Fila<ED1::Aluno> *fila;

    try{
        fila = new ED1::Fila<ED1::Aluno>();
        ED1::Persistencia ordenacao(diretorioArquivo);

        arvore = ordenacao.PegaDadosArquivo();
        arvore->imprimirPreFDireita(fila);

        exibeDados(fila);

    }catch(QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }
    catch(std::bad_alloc){
           throw QString("falta espaço na memória");
        }
}

void MainWindow::on_pushButtonPosFDireita_clicked()
{
    ED1::ArvoreBinariaPorCodigo<ED1::Aluno> *arvore = 0;
    ED1::Fila<ED1::Aluno> *fila;

    try{
        fila = new ED1::Fila<ED1::Aluno>();
        ED1::Persistencia ordenacao(diretorioArquivo);

        arvore = ordenacao.PegaDadosArquivo();
        arvore->imprimirPosFDireita(fila);

        exibeDados(fila);

    }catch(QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }
    catch(std::bad_alloc){
           throw QString("falta espaço na memória");
        }
}

void MainWindow::on_pushButtonPreFEsquerda_clicked()
{
    ED1::ArvoreBinariaPorCodigo<ED1::Aluno> *arvore = 0;
    ED1::Pilha<ED1::Aluno> *pilha;

    try{
        pilha = new ED1::Pilha<ED1::Aluno>();
        ED1::Persistencia ordenacao(diretorioArquivo);

        arvore = ordenacao.PegaDadosArquivo();
        arvore->imprimirPreFEsquerda(pilha);

        exibeDadoPilha(pilha);

    }catch(QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }
    catch(std::bad_alloc){
           throw QString("falta espaço na memória");
        }
}

void MainWindow::on_pushButtonProsFEsquerda_clicked()
{
    ED1::ArvoreBinariaPorCodigo<ED1::Aluno> *arvore = 0;
    ED1::Pilha<ED1::Aluno> *pilha;

    try{
        pilha = new ED1::Pilha<ED1::Aluno>();
        ED1::Persistencia ordenacao(diretorioArquivo);

        arvore = ordenacao.PegaDadosArquivo();
        arvore->imprimirPosFEsquerda(pilha);

        exibeDadoPilha(pilha);

    }catch(QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }
    catch(std::bad_alloc){
           throw QString("falta espaço na memória");
        }
}

void MainWindow::on_pushButtonOrdenarPorNomeFila_clicked()
{
    ED1::ArvoreBinariaPorNome<ED1::Aluno> *arvore;
    ED1::Fila<ED1::Aluno> *fila;

    try{
        fila = new ED1::Fila<ED1::Aluno>();
        ED1::Persistencia ordenacao(diretorioArquivo);

        arvore = ordenacao.PegaDadosArquivoPorNome();
        arvore->imprimirCDireita(fila);

        exibeDados(fila);

    }catch(QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }
    catch(std::bad_alloc){
           throw QString("falta espaço na memória");
        }
}

void MainWindow::on_pushButtonOrdenarPorNomePilha_clicked()
{
    ED1::ArvoreBinariaPorNome<ED1::Aluno> *arvore = 0;
    ED1::Pilha<ED1::Aluno> *pilha;

    try{
        pilha = new ED1::Pilha<ED1::Aluno>();
        ED1::Persistencia ordenacao(diretorioArquivo);

        arvore = ordenacao.PegaDadosArquivoPorNome();
        arvore->imprimirCEsquerda(pilha);

        exibeDadoPilha(pilha);

    }catch(QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }
    catch(std::bad_alloc){
           throw QString("falta espaço na memória");
        }
}

void MainWindow::on_pushButtonNomePreFDireita_clicked()
{
    ED1::ArvoreBinariaPorNome<ED1::Aluno> *arvore = 0;
    ED1::Fila<ED1::Aluno> *fila;

    try{
        fila = new ED1::Fila<ED1::Aluno>();
        ED1::Persistencia ordenacao(diretorioArquivo);

        arvore = ordenacao.PegaDadosArquivoPorNome();
        arvore->imprimirPreFDireita(fila);

        exibeDados(fila);

    }catch(QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }
    catch(std::bad_alloc){
           throw QString("falta espaço na memória");
        }
}

void MainWindow::on_pushButtonNomePosFDireita_clicked()
{
    ED1::ArvoreBinariaPorNome<ED1::Aluno> *arvore = 0;
    ED1::Fila<ED1::Aluno> *fila;

    try{
        fila = new ED1::Fila<ED1::Aluno>();
        ED1::Persistencia ordenacao(diretorioArquivo);

        arvore = ordenacao.PegaDadosArquivoPorNome();
        arvore->imprimirPosFDireita(fila);

        exibeDados(fila);

    }catch(QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }
    catch(std::bad_alloc){
           throw QString("falta espaço na memória");
        }
}

void MainWindow::on_pushButtonNomePreFEsquerda_clicked()
{
    ED1::ArvoreBinariaPorNome<ED1::Aluno> *arvore = 0;
    ED1::Pilha<ED1::Aluno> *pilha;

    try{
        pilha = new ED1::Pilha<ED1::Aluno>();
        ED1::Persistencia ordenacao(diretorioArquivo);

        arvore = ordenacao.PegaDadosArquivoPorNome();
        arvore->imprimirPreFEsquerda(pilha);

        exibeDadoPilha(pilha);

    }catch(QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }
    catch(std::bad_alloc){
           throw QString("falta espaço na memória");
        }
}

void MainWindow::on_pushButtonNomeProsFEsquerda_clicked()
{
    ED1::ArvoreBinariaPorNome<ED1::Aluno> *arvore = 0;
    ED1::Pilha<ED1::Aluno> *pilha;

    try{
        pilha = new ED1::Pilha<ED1::Aluno>();
        ED1::Persistencia ordenacao(diretorioArquivo);

        arvore = ordenacao.PegaDadosArquivoPorNome();
        arvore->imprimirPosFEsquerda(pilha);

        exibeDadoPilha(pilha);

    }catch(QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }
    catch(std::bad_alloc){
           throw QString("falta espaço na memória");
        }
}

void MainWindow::on_pushButtonOrdenarPorSobrenomeFila_clicked()
{
    ED1::ArvoreBinariaPorNome<ED1::Aluno> *arvore;
    ED1::Fila<ED1::Aluno> *fila;

    try{
        fila = new ED1::Fila<ED1::Aluno>();
        ED1::Persistencia ordenacao(diretorioArquivo);

        arvore = ordenacao.PegaDadosArquivoPorSobreNome();
        arvore->imprimirCDireita(fila);

        exibeDados(fila);

    }catch(QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }
    catch(std::bad_alloc){
           throw QString("falta espaço na memória");
        }
}

void MainWindow::on_pushButtonSobrenomePreFDireita_clicked()
{
    ED1::ArvoreBinariaPorNome<ED1::Aluno> *arvore = 0;
    ED1::Fila<ED1::Aluno> *fila;

    try{
        fila = new ED1::Fila<ED1::Aluno>();
        ED1::Persistencia ordenacao(diretorioArquivo);

        arvore = ordenacao.PegaDadosArquivoPorSobreNome();
        arvore->imprimirPreFDireita(fila);

        exibeDados(fila);

    }catch(QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }
    catch(std::bad_alloc){
           throw QString("falta espaço na memória");
        }
}

void MainWindow::on_pushButtonSobrenomePosFDireita_clicked()
{
    ED1::ArvoreBinariaPorNome<ED1::Aluno> *arvore = 0;
    ED1::Fila<ED1::Aluno> *fila;

    try{
        fila = new ED1::Fila<ED1::Aluno>();
        ED1::Persistencia ordenacao(diretorioArquivo);

        arvore = ordenacao.PegaDadosArquivoPorSobreNome();
        arvore->imprimirPosFDireita(fila);

        exibeDados(fila);

    }catch(QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }
    catch(std::bad_alloc){
           throw QString("falta espaço na memória");
        }
}

void MainWindow::on_pushButtonOrdenarPorSobrenomePilha_clicked()
{
    ED1::ArvoreBinariaPorNome<ED1::Aluno> *arvore = 0;
    ED1::Pilha<ED1::Aluno> *pilha;

    try{
        pilha = new ED1::Pilha<ED1::Aluno>();
        ED1::Persistencia ordenacao(diretorioArquivo);

        arvore = ordenacao.PegaDadosArquivoPorSobreNome();
        arvore->imprimirCEsquerda(pilha);

        exibeDadoPilha(pilha);

    }catch(QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }
    catch(std::bad_alloc){
           throw QString("falta espaço na memória");
        }
}

void MainWindow::on_pushButtonSobreNomePreFEsquerda_clicked()
{
    ED1::ArvoreBinariaPorNome<ED1::Aluno> *arvore = 0;
    ED1::Pilha<ED1::Aluno> *pilha;

    try{
        pilha = new ED1::Pilha<ED1::Aluno>();
        ED1::Persistencia ordenacao(diretorioArquivo);

        arvore = ordenacao.PegaDadosArquivoPorSobreNome();
        arvore->imprimirPreFEsquerda(pilha);

        exibeDadoPilha(pilha);

    }catch(QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }
    catch(std::bad_alloc){
           throw QString("falta espaço na memória");
        }
}

void MainWindow::on_pushButtonSobrenomeProsFEsquerda_clicked()
{
    ED1::ArvoreBinariaPorNome<ED1::Aluno> *arvore = 0;
    ED1::Pilha<ED1::Aluno> *pilha;

    try{
        pilha = new ED1::Pilha<ED1::Aluno>();
        ED1::Persistencia ordenacao(diretorioArquivo);

        arvore = ordenacao.PegaDadosArquivoPorSobreNome();
        arvore->imprimirPosFEsquerda(pilha);

        exibeDadoPilha(pilha);

    }catch(QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }
    catch(std::bad_alloc){
           throw QString("falta espaço na memória");
        }
}
