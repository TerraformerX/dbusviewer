#include "dbusviewer.h"
#include "ui_dbusviewer.h"
#include <string>
#include <QtDBus/QtDBus>
//#include <QtCore/QDebug>
//#include <QtCore/QCoreApplication>



DBusViewer::DBusViewer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DBusViewer)
{
    ui->setupUi(this);
    //ui->pteResults->setPlainText("test\n");

    if (!QDBusConnection::sessionBus().isConnected()) {
        ui->pteResults->setPlainText("Cannot connect to the D-Bus session bus.\n");
//                                             "To start it, run:\n"
//                                             "\teval `dbus-launch --auto-syntax`\n");
    }

}

DBusViewer::~DBusViewer()
{
    delete ui;
}

void DBusViewer::on_btnDbusList_clicked()
{
    QStringList qslResults = QDBusConnection::sessionBus().interface()->registeredServiceNames();
    QString strResults;
    for (int i = 0; i<qslResults.size(); ++i) {
        strResults.append(qslResults.at(i).toLocal8Bit().constData() + QString("\n"));
    }

    ui->pteResults->setPlainText(strResults.trimmed());
    ui->lneServicename->setText("");

}

void DBusViewer::on_btnSearch_clicked()
{
    QString searchString = ui->lneSearch->text();
    ui->pteResults->find(searchString, QTextDocument::FindWholeWords);
}

void DBusViewer::on_btnQuery_clicked()
{

    QDBusConnection bus = QDBusConnection::sessionBus();
    QDBusMessage msgIntrospect = QDBusMessage::createMethodCall(ui->lneServicename->text().trimmed(),"/org/freedesktop/DBus",
                                                                "org.freedesktop.DBus.Introspectable",
                                                                "Introspect");
    QDBusMessage reply = bus.call(msgIntrospect);

    QList<QVariant> args = reply.arguments();

    QString strResults;
    for (int i = 0; i<args.count(); ++i) {
        strResults.append(args.at(i).toString() + QString("\n"));
    }

    ui->pteResults->setPlainText(strResults.trimmed());
//    qDebug() << reply;


}
