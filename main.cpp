#include <QCoreApplication>

#include "DataSender.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    DataSender sender;
    NetworkInfos infos;
    infos.filePath = ""; // give your file path
    infos.ip = QHostAddress::LocalHost; // you can use any ip
    infos.port = 12893;
    sender.sendData(infos);

    return a.exec();
}
