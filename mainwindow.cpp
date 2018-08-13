#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    vw = new VideoWidget;
 connect(vw,SIGNAL(sendurl(QString)),this,SLOT(reshow(QString)));
 connect(this,SIGNAL(sendurl(QString)),vw,SLOT(revurl(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toolButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                        NULL,
                                                        tr("txtFile (*.* *.txt)"));
     QFile file(fileName);

     if(!fileName.isEmpty()){
        if(ui->comboBox->findText(fileName)==-1)
            ui->comboBox->addItem(fileName);
        ui->comboBox->setCurrentIndex(ui->comboBox->findText(fileName));
    }
}
void MainWindow::reshow(QString f)
{
    this->show();
    ui->lineEdit->setText(f);
}

void MainWindow::on_pushButton_clicked()
{

    QString fileName = ui->comboBox->currentText();
    emit sendurl(fileName);
    vw->show();
    this->hide();

}
