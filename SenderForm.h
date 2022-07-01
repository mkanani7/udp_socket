#pragma once

#include <QWidget>

#include "DataSender.h"

namespace Ui {
class SenderForm;
}

class SenderForm : public QWidget {
    Q_OBJECT

public:
    explicit SenderForm(QWidget* parent = nullptr);
    ~SenderForm();

private slots:
    void on_pushButton_browse_clicked();

    void on_pushButton_send_clicked();

private:
    Ui::SenderForm* ui;

    std::shared_ptr<DataSender> sender;
};
