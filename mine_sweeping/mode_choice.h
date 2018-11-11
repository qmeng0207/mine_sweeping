﻿#ifndef MODE_CHOICE_H
#define MODE_CHOICE_H

#include <QDialog>
#include "mainwindow.h"
#include <QCloseEvent>
#include <QPushButton>
#include "designwindow.h"
#include "dialog_userdefined.h"
#include "mine.h"
#include "socket_server_hq.h"
#include "socket_client_hq.h"
#include <QVBoxLayout>

namespace Ui {
class mode_choice;
}

class mode_choice : public QDialog
{
    Q_OBJECT

public:
    explicit mode_choice(QWidget *parent = 0);
    ~mode_choice();

private slots:
    void on_modeButton_Exit_clicked();

    void on_modeButton_Normal_pressed();

    void on_modeButton_Designed_clicked();

    void on_modeButton_Online_pressed();

    void on_designedButton_Return_clicked();

    void on_designedButton_New_clicked();

    void on_onlineButton_Return_clicked();

    void on_onlineButton_Server_clicked();

    void on_onlineButton_Client_clicked();

private:
    Ui::mode_choice *ui;
    MainWindow *pNormalWindow;
    QVBoxLayout *pMainLayout;

    QPushButton *modeButton_normal;
    QPushButton *modeButton_designed;
    QPushButton *modeButton_Online;
    QPushButton *modeButton_Exit;

    /*设计模式下的按钮*/
    QPushButton *designedButton_New;
    QPushButton *designedButton_Load;
    QPushButton *designedButton_Return;

    /*联机模式下的按钮*/
    QPushButton *onlineButton_Server;
    QPushButton *onlineButton_Client;
    QPushButton *onlineButton_Return;

    socket_server_hq *tcp_server_hq;
    socket_client_hq *tcp_client_hq;

    DesignWindow *pDesignWindow;
    Dialog_userDefined *pUserDefined;

    void Set_modeButton_visible(bool flag);
    void Set_designedButton_visible(bool flag);
    void Set_onlineButton_visible(bool flag);

    void Init_modeWindow();

    void closeEvent(QCloseEvent *event);
};

#endif // MODE_CHOICE_H
