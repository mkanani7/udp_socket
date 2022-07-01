#pragma once

#include <QUdpSocket>
#include <memory>

#include "NetworkInfos.h"

class DataSender {
public:
    DataSender();
    qint64 sendData(NetworkInfos infos);

private:
    QByteArray readFile(const QString path);

private:
    std::shared_ptr<QUdpSocket> socket;
};
