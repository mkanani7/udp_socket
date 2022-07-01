#include "DataSender.h"

#include <QFile>

DataSender::DataSender()
{
    socket = std::make_shared<QUdpSocket>();
}

qint64 DataSender::sendData(NetworkInfos infos)
{
    auto data = readFile(infos.filePath);
    return socket->writeDatagram(data, infos.ip, infos.port);
}

QByteArray DataSender::readFile(const QString path)
{
    QFile reader(path);
    if (!reader.open(QFile::ReadOnly)) {
        qDebug() << "Can't open file";
        return {};
    }
    auto data = reader.readAll();
    return data;
}
