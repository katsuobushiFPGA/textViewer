#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextStream>

namespace {
   QString fileName;
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QFile file( fileName );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QString line("");
        QString tmp;
        QTextStream stream( &file );
        while(true) {
            tmp = stream.readLine();
            if(tmp == NULL)
            {
                break;
            }
             else
            {
                line += tmp;
                line += "\n";
            }
         }
        ui->textBrowser->setPlainText(line);
    }
}

void MainWindow::on_toolButton_clicked()
{
    fileName = QFileDialog::getOpenFileName(this,tr("Open text"), "/home", tr("text Files (*)"));
    if(fileName != NULL)
    {
        ui->textEdit->setPlainText(fileName);
    }
}
