#include "SenderForm.h"
#include "ui_SenderForm.h"

#include <QFileDialog>

SenderForm::SenderForm(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::SenderForm)
{
    ui->setupUi(this);
    sender = std::make_shared<DataSender>();
    ui->label_warning->hide();
}

SenderForm::~SenderForm()
{
    delete ui;
}

void SenderForm::on_pushButton_browse_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File");
    ui->lineEdit_fileName->setText(fileName);
}

void SenderForm::on_pushButton_send_clicked()
{
    const QString fileName = ui->lineEdit_fileName->text();
    const QString ip = ui->lineEdit_ip->text();
    const QString port = ui->lineEdit_port->text();
    if (ip.isEmpty() || fileName.isEmpty() || port.isEmpty()) {
        ui->label_warning->setText("Please fill all inputs");
        ui->label_warning->show();
        return;
    }
    NetworkInfos infos;
    infos.filePath = fileName;
    infos.ip = ui->lineEdit_ip->text();
    infos.port = ui->lineEdit_port->text().toInt();
    qDebug() << sender->sendData(infos);
}
