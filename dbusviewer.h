#ifndef DBUSVIEWER_H
#define DBUSVIEWER_H

#include <QMainWindow>

namespace Ui {
class DBusViewer;
}

class DBusViewer : public QMainWindow
{
    Q_OBJECT

public:
    explicit DBusViewer(QWidget *parent = 0);
    ~DBusViewer();

private slots:
    void on_btnDbusList_clicked();

    void on_btnSearch_clicked();

    void on_btnQuery_clicked();

private:
    Ui::DBusViewer *ui;
};

#endif // DBUSVIEWER_H
