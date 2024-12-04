/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QGroupBox *groupBox_3;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_4;
    QWidget *widget_6;
    QPushButton *pushButton_15;
    QLabel *label_18;
    QTabWidget *tabWidget;
    QWidget *tab_7;
    QGroupBox *groupBox_4;
    QLabel *label_28;
    QWidget *tab;
    QTabWidget *tabWidget_2;
    QWidget *tab_9;
    QGroupBox *groupBox_2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_12;
    QPushButton *valider;
    QLineEdit *id_client;
    QLineEdit *nom;
    QLineEdit *prenom;
    QLineEdit *adresse;
    QLineEdit *email;
    QPushButton *annuler;
    QPushButton *exporter;
    QGroupBox *groupBox_6;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *modifier;
    QPushButton *supprimer;
    QPushButton *afficher;
    QTableView *tableView_afficher;
    QLineEdit *recherche;
    QPushButton *rechercher;
    QPushButton *trier_2;
    QComboBox *comboBox;
    QPushButton *QR_button;
    QLabel *qr_code;
    QLineEdit *telephone;
    QLabel *label_11;
    QLabel *label_19;
    QLineEdit *pt_fidelite;
    QLineEdit *dn;
    QLabel *label_13;
    QLineEdit *genre;
    QPushButton *update;
    QWidget *tab_10;
    QGroupBox *groupBox_9;
    QPushButton *pushButton_24;
    QLabel *label_27;
    QGroupBox *groupBox_7;
    QPushButton *statistique;
    QGraphicsView *stat_view;
    QStackedWidget *stackedWidget_stat;
    QWidget *page;
    QWidget *page_2;
    QPushButton *stat_genre;
    QWidget *tab_11;
    QGroupBox *groupBox_8;
    QPushButton *pushButton_23;
    QLabel *label_23;
    QLabel *label_24;
    QGroupBox *groupBox_5;
    QLabel *label_25;
    QPushButton *button_mail;
    QPushButton *updateNotifications;
    QTableView *notification;
    QWidget *tab_8;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *tab_5;
    QWidget *tab_6;
    QWidget *tab_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1253, 1060);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(-80, -60, 1261, 861));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(80, 0, 1131, 91));
        groupBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 54, 63);\n"
"border-color: rgb(50, 54, 63);\n"
""));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(1080, 30, 31, 20));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/log-out.svg")));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(1040, 30, 21, 20));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/user (1).svg")));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(380, 30, 21, 31));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/search.svg")));
        widget_6 = new QWidget(groupBox_3);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(420, 30, 291, 31));
        widget_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;\n"
" border: 2px solid rgba(129,211,22,255);  padding: 1px; \n"
"\n"
""));
        pushButton_15 = new QPushButton(widget_6);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(10, 10, 15, 15));
        pushButton_15->setMinimumSize(QSize(15, 15));
        pushButton_15->setMaximumSize(QSize(15, 15));
        pushButton_15->setStyleSheet(QString::fromUtf8("border: none;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../Downloads/icon/icons8-chercher-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8("../../../../Downloads/icon/icons8-chercher-64.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_15->setIcon(icon);
        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(990, 20, 31, 41));
        label_18->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/settings.svg")));
        tabWidget = new QTabWidget(groupBox);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(80, 90, 1121, 771));
        tabWidget->setTabPosition(QTabWidget::TabPosition::North);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(false);
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        groupBox_4 = new QGroupBox(tab_7);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(-70, 0, 1241, 571));
        label_28 = new QLabel(groupBox_4);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(310, 190, 631, 221));
        label_28->setStyleSheet(QString::fromUtf8("font: 72pt \"French Script MT\";\n"
"font: 9pt \"Nirmala UI\";\n"
"background-color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 85, 0);\n"
"font: 72pt \"Vladimir Script\";\n"
"color: rgb(197, 197, 197);\n"
"background-color: rgb(255, 255, 255);"));
        tabWidget->addTab(tab_7, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        tabWidget_2 = new QTabWidget(tab);
        tabWidget_2->setObjectName("tabWidget_2");
        tabWidget_2->setGeometry(QRect(0, 0, 1531, 741));
        tabWidget_2->setStyleSheet(QString::fromUtf8(""));
        tab_9 = new QWidget();
        tab_9->setObjectName("tab_9");
        groupBox_2 = new QGroupBox(tab_9);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(80, 0, 1031, 671));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        groupBox_2->setFont(font);
        groupBox_2->setStyleSheet(QString::fromUtf8("border: 1px solid #000000; padding: 1px; ;\n"
"background-color: rgb(255, 255, 255);\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;\n"
""));
        groupBox_2->setFlat(true);
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 30, 381, 511));
        label_5->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/icons8-test-account-50 (1).png")));
        label_5->setScaledContents(true);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(30, 80, 49, 16));
        QFont font1;
        font1.setPointSize(10);
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("border:none;"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 120, 71, 16));
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("border:none;"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(30, 160, 81, 31));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("border:none;"));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(30, 350, 91, 16));
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8("border:none;"));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(30, 390, 49, 16));
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("border:none;"));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(30, 430, 161, 16));
        label_12->setFont(font1);
        label_12->setStyleSheet(QString::fromUtf8("border:none;"));
        valider = new QPushButton(groupBox_2);
        valider->setObjectName("valider");
        valider->setGeometry(QRect(280, 490, 91, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI Black")});
        font2.setPointSize(12);
        valider->setFont(font2);
        valider->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);\n"
"color: rgb(255, 255, 255);"));
        id_client = new QLineEdit(groupBox_2);
        id_client->setObjectName("id_client");
        id_client->setGeometry(QRect(180, 80, 191, 21));
        id_client->setStyleSheet(QString::fromUtf8(" border: 2px solid rgb(255, 85, 0);  padding: 1px; ;\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;\n"
"\n"
""));
        nom = new QLineEdit(groupBox_2);
        nom->setObjectName("nom");
        nom->setGeometry(QRect(180, 120, 191, 21));
        nom->setStyleSheet(QString::fromUtf8(" border: 2px solid rgb(255, 85, 0);  padding: 1px; ;\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;\n"
"\n"
""));
        prenom = new QLineEdit(groupBox_2);
        prenom->setObjectName("prenom");
        prenom->setGeometry(QRect(180, 160, 191, 21));
        prenom->setStyleSheet(QString::fromUtf8(" border: 2px solid rgb(255, 85, 0);  padding: 1px; ;\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;\n"
"\n"
"\n"
""));
        adresse = new QLineEdit(groupBox_2);
        adresse->setObjectName("adresse");
        adresse->setGeometry(QRect(180, 210, 191, 21));
        adresse->setStyleSheet(QString::fromUtf8(" border: 2px solid rgb(255, 85, 0);  padding: 1px; ;\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;\n"
"\n"
""));
        email = new QLineEdit(groupBox_2);
        email->setObjectName("email");
        email->setGeometry(QRect(180, 350, 191, 21));
        email->setStyleSheet(QString::fromUtf8(" border: 2px solid rgb(255, 85, 0);  padding: 1px; ;\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;\n"
"\n"
"\n"
""));
        annuler = new QPushButton(groupBox_2);
        annuler->setObjectName("annuler");
        annuler->setGeometry(QRect(30, 490, 91, 31));
        annuler->setFont(font2);
        annuler->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);\n"
"color: rgb(255, 255, 255);"));
        exporter = new QPushButton(groupBox_2);
        exporter->setObjectName("exporter");
        exporter->setGeometry(QRect(110, 610, 181, 41));
        exporter->setFont(font2);
        exporter->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);\n"
"color: rgb(255, 255, 255);"));
        groupBox_6 = new QGroupBox(groupBox_2);
        groupBox_6->setObjectName("groupBox_6");
        groupBox_6->setGeometry(QRect(410, 30, 591, 621));
        groupBox_6->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";\n"
"/*background-color: rgb(50, 54, 63);*/\n"
"border-top-left-radius: 20px ;\n"
"border-bottom-left-radius:20px ;\n"
"border-top-right-radius:20px ;\n"
"border-bottom-right-radius:20px ;\n"
"background-color: rgb(50, 54, 63);\n"
"\n"
""));
        pushButton_11 = new QPushButton(groupBox_6);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(730, 40, 75, 24));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../../Downloads/icon/icons8-filtre-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon1);
        pushButton_11->setIconSize(QSize(30, 30));
        pushButton_12 = new QPushButton(groupBox_6);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(680, 100, 111, 24));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Segoe UI")});
        font3.setPointSize(9);
        font3.setBold(false);
        font3.setItalic(true);
        pushButton_12->setFont(font3);
        pushButton_12->setStyleSheet(QString::fromUtf8("border: 1px solid #FD7E14; padding: 1px; ;\n"
"background-color: rgb(255, 255, 255);\n"
"border-top-left-radius: 5px ;\n"
"border-bottom-left-radius: 5px ;\n"
"border-top-right-radius:5px ;\n"
"border-bottom-right-radius:5px ;\n"
"font: italic 9pt \"Segoe UI\";\n"
"\n"
""));
        pushButton_13 = new QPushButton(groupBox_6);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(680, 140, 111, 24));
        pushButton_13->setFont(font3);
        pushButton_13->setStyleSheet(QString::fromUtf8("border: 1px solid #FD7E14; padding: 1px; ;\n"
"background-color: rgb(255, 255, 255);\n"
"border-top-left-radius: 5px ;\n"
"border-bottom-left-radius: 5px ;\n"
"border-top-right-radius:5px ;\n"
"border-bottom-right-radius:5px ;\n"
"font: italic 9pt \"Segoe UI\";\n"
"\n"
""));
        pushButton_14 = new QPushButton(groupBox_6);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(680, 180, 111, 24));
        pushButton_14->setFont(font3);
        pushButton_14->setStyleSheet(QString::fromUtf8("border: 1px solid #FD7E14; padding: 1px; ;\n"
"background-color: rgb(255, 255, 255);\n"
"border-top-left-radius: 5px ;\n"
"border-bottom-left-radius: 5px ;\n"
"border-top-right-radius:5px ;\n"
"border-bottom-right-radius:5px ;\n"
"font: italic 9pt \"Segoe UI\";\n"
"\n"
""));
        modifier = new QPushButton(groupBox_6);
        modifier->setObjectName("modifier");
        modifier->setGeometry(QRect(440, 440, 141, 41));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Segoe UI")});
        font4.setPointSize(9);
        font4.setBold(false);
        font4.setItalic(false);
        modifier->setFont(font4);
        modifier->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);\n"
"font: 9pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../../../.designer/.designer/Downloads/search (4).svg"), QSize(), QIcon::Normal, QIcon::Off);
        modifier->setIcon(icon2);
        supprimer = new QPushButton(groupBox_6);
        supprimer->setObjectName("supprimer");
        supprimer->setGeometry(QRect(440, 380, 141, 41));
        supprimer->setFont(font4);
        supprimer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);\n"
"font: 9pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;"));
        supprimer->setIcon(icon2);
        afficher = new QPushButton(groupBox_6);
        afficher->setObjectName("afficher");
        afficher->setGeometry(QRect(440, 290, 141, 41));
        afficher->setFont(font4);
        afficher->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);\n"
"font: 9pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;"));
        afficher->setIcon(icon2);
        tableView_afficher = new QTableView(groupBox_6);
        tableView_afficher->setObjectName("tableView_afficher");
        tableView_afficher->setGeometry(QRect(10, 90, 571, 201));
        tableView_afficher->setStyleSheet(QString::fromUtf8(" border: 2px solid rgb(255, 85, 0);  padding: 1px; ;\n"
"color: rgb(0, 0, 0);\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;\n"
"\n"
""));
        recherche = new QLineEdit(groupBox_6);
        recherche->setObjectName("recherche");
        recherche->setGeometry(QRect(20, 10, 191, 21));
        recherche->setStyleSheet(QString::fromUtf8(" border: 2px solid rgb(255, 85, 0);  padding: 1px; ;\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;\n"
"\n"
""));
        rechercher = new QPushButton(groupBox_6);
        rechercher->setObjectName("rechercher");
        rechercher->setGeometry(QRect(50, 40, 141, 41));
        rechercher->setFont(font4);
        rechercher->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);\n"
"font: 9pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;"));
        rechercher->setIcon(icon2);
        trier_2 = new QPushButton(groupBox_6);
        trier_2->setObjectName("trier_2");
        trier_2->setGeometry(QRect(360, 40, 141, 41));
        trier_2->setFont(font4);
        trier_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);\n"
"font: 9pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;"));
        trier_2->setIcon(icon2);
        comboBox = new QComboBox(groupBox_6);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(320, 10, 201, 21));
        comboBox->setStyleSheet(QString::fromUtf8(" border: 2px solid rgb(255, 85, 0);  padding: 1px; ;\n"
"color: rgb(255, 255, 255);\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;\n"
"\n"
""));
        QR_button = new QPushButton(groupBox_6);
        QR_button->setObjectName("QR_button");
        QR_button->setGeometry(QRect(10, 290, 351, 31));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Segoe UI")});
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setItalic(false);
        QR_button->setFont(font5);
        QR_button->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);\n"
"color: rgb(255, 255, 255);"));
        qr_code = new QLabel(groupBox_6);
        qr_code->setObjectName("qr_code");
        qr_code->setGeometry(QRect(20, 330, 331, 251));
        telephone = new QLineEdit(groupBox_2);
        telephone->setObjectName("telephone");
        telephone->setGeometry(QRect(180, 270, 191, 21));
        telephone->setStyleSheet(QString::fromUtf8(" border: 2px solid rgb(255, 85, 0);  padding: 1px; ;\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;\n"
"\n"
""));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(30, 270, 91, 16));
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8("border:none;"));
        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(30, 220, 91, 16));
        label_19->setFont(font1);
        label_19->setStyleSheet(QString::fromUtf8("border:none;"));
        pt_fidelite = new QLineEdit(groupBox_2);
        pt_fidelite->setObjectName("pt_fidelite");
        pt_fidelite->setGeometry(QRect(180, 430, 191, 21));
        pt_fidelite->setStyleSheet(QString::fromUtf8(" border: 2px solid rgb(255, 85, 0);  padding: 1px; ;\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;\n"
"\n"
""));
        dn = new QLineEdit(groupBox_2);
        dn->setObjectName("dn");
        dn->setGeometry(QRect(180, 390, 191, 21));
        dn->setStyleSheet(QString::fromUtf8(" border: 2px solid rgb(255, 85, 0);  padding: 1px; ;\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;\n"
"\n"
""));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(30, 310, 91, 16));
        label_13->setFont(font1);
        label_13->setStyleSheet(QString::fromUtf8("border:none;"));
        genre = new QLineEdit(groupBox_2);
        genre->setObjectName("genre");
        genre->setGeometry(QRect(180, 310, 191, 21));
        genre->setStyleSheet(QString::fromUtf8(" border: 2px solid rgb(255, 85, 0);  padding: 1px; ;\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;\n"
"\n"
""));
        update = new QPushButton(groupBox_2);
        update->setObjectName("update");
        update->setGeometry(QRect(130, 490, 141, 24));
        tabWidget_2->addTab(tab_9, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName("tab_10");
        groupBox_9 = new QGroupBox(tab_10);
        groupBox_9->setObjectName("groupBox_9");
        groupBox_9->setGeometry(QRect(10, 0, 1131, 711));
        groupBox_9->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";\n"
"background-color: rgb(50, 54, 63);\n"
"border-top-left-radius: 20px ;\n"
"border-bottom-left-radius:20px ;\n"
"border-top-right-radius:20px ;\n"
"border-bottom-right-radius:20px ;\n"
"\n"
""));
        pushButton_24 = new QPushButton(groupBox_9);
        pushButton_24->setObjectName("pushButton_24");
        pushButton_24->setGeometry(QRect(740, 40, 41, 24));
        pushButton_24->setIcon(icon1);
        pushButton_24->setIconSize(QSize(30, 30));
        label_27 = new QLabel(groupBox_9);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(690, 20, 21, 41));
        label_27->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
""));
        label_27->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/bell.svg")));
        groupBox_7 = new QGroupBox(groupBox_9);
        groupBox_7->setObjectName("groupBox_7");
        groupBox_7->setGeometry(QRect(10, 10, 1061, 601));
        groupBox_7->setFont(font5);
        groupBox_7->setStyleSheet(QString::fromUtf8("border: 1px solid #000000; padding: 1px; ;\n"
"background-color: rgb(255, 255, 255);\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;\n"
""));
        groupBox_7->setFlat(true);
        statistique = new QPushButton(groupBox_7);
        statistique->setObjectName("statistique");
        statistique->setGeometry(QRect(40, 20, 251, 41));
        statistique->setFont(font5);
        statistique->setStyleSheet(QString::fromUtf8("background-color: rgba(129,211,22,255); \n"
"background-color: rgb(255, 85, 0);\n"
"color: rgb(255, 255, 255);"));
        stat_view = new QGraphicsView(groupBox_7);
        stat_view->setObjectName("stat_view");
        stat_view->setGeometry(QRect(90, 80, 511, 501));
        stackedWidget_stat = new QStackedWidget(groupBox_7);
        stackedWidget_stat->setObjectName("stackedWidget_stat");
        stackedWidget_stat->setGeometry(QRect(630, 90, 411, 491));
        page = new QWidget();
        page->setObjectName("page");
        stackedWidget_stat->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget_stat->addWidget(page_2);
        stat_genre = new QPushButton(groupBox_7);
        stat_genre->setObjectName("stat_genre");
        stat_genre->setGeometry(QRect(630, 20, 251, 41));
        stat_genre->setFont(font5);
        stat_genre->setStyleSheet(QString::fromUtf8("background-color: rgba(129,211,22,255); \n"
"background-color: rgb(255, 85, 0);\n"
"color: rgb(255, 255, 255);"));
        tabWidget_2->addTab(tab_10, QString());
        tab_11 = new QWidget();
        tab_11->setObjectName("tab_11");
        groupBox_8 = new QGroupBox(tab_11);
        groupBox_8->setObjectName("groupBox_8");
        groupBox_8->setGeometry(QRect(0, 0, 1131, 711));
        groupBox_8->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";\n"
"background-color: rgb(50, 54, 63);\n"
"border-top-left-radius: 20px ;\n"
"border-bottom-left-radius:20px ;\n"
"border-top-right-radius:20px ;\n"
"border-bottom-right-radius:20px ;\n"
"\n"
""));
        pushButton_23 = new QPushButton(groupBox_8);
        pushButton_23->setObjectName("pushButton_23");
        pushButton_23->setGeometry(QRect(740, 40, 41, 24));
        pushButton_23->setIcon(icon1);
        pushButton_23->setIconSize(QSize(30, 30));
        label_23 = new QLabel(groupBox_8);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(360, 20, 401, 31));
        label_23->setStyleSheet(QString::fromUtf8("color:  rgba(129,211,22,255); \n"
"color: rgb(255, 255, 255);\n"
"font: 350 italic 18pt \"Segoe UI\";"));
        label_24 = new QLabel(groupBox_8);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(690, 20, 21, 41));
        label_24->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
""));
        label_24->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/bell.svg")));
        groupBox_5 = new QGroupBox(groupBox_8);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(30, 70, 1061, 601));
        groupBox_5->setFont(font5);
        groupBox_5->setStyleSheet(QString::fromUtf8("border: 1px solid #000000; padding: 1px; ;\n"
"background-color: rgb(255, 255, 255);\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;\n"
""));
        groupBox_5->setFlat(true);
        label_25 = new QLabel(groupBox_5);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(40, 40, 981, 551));
        label_25->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/icons8-test-account-50 (1).png")));
        label_25->setScaledContents(true);
        button_mail = new QPushButton(groupBox_5);
        button_mail->setObjectName("button_mail");
        button_mail->setGeometry(QRect(730, 520, 261, 41));
        button_mail->setFont(font5);
        button_mail->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);\n"
"color: rgb(255, 255, 255);"));
        updateNotifications = new QPushButton(groupBox_5);
        updateNotifications->setObjectName("updateNotifications");
        updateNotifications->setGeometry(QRect(90, 100, 281, 21));
        updateNotifications->setFont(font5);
        updateNotifications->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);\n"
"color: rgb(255, 255, 255);\n"
""));
        notification = new QTableView(groupBox_5);
        notification->setObjectName("notification");
        notification->setGeometry(QRect(80, 130, 931, 361));
        notification->setStyleSheet(QString::fromUtf8(" border: 2px solid  rgb(255, 85, 0);\n"
"color: rgb(0, 0, 0);   padding: 1px; ;\n"
"background-color: rgb(255, 255, 255);\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius:10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;\n"
"\n"
"\n"
"\n"
""));
        tabWidget_2->addTab(tab_11, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName("tab_8");
        tabWidget_2->addTab(tab_8, QString());
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        tabWidget->addTab(tab_6, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        groupBox_3->setTitle(QString());
        label_3->setText(QString());
        label_2->setText(QString());
        label_4->setText(QString());
        pushButton_15->setText(QString());
        label_18->setText(QString());
        groupBox_4->setTitle(QString());
        label_28->setText(QCoreApplication::translate("MainWindow", "ModaMotive", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QCoreApplication::translate("MainWindow", "        Profil          ", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Ajout d'un client", nullptr));
        label_5->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "ID*", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Nom*", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "prenom*", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Email*", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "DN*", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Pt_fidelite*", nullptr));
        valider->setText(QCoreApplication::translate("MainWindow", "Valider", nullptr));
        email->setText(QString());
        annuler->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        exporter->setText(QCoreApplication::translate("MainWindow", "EXPORTER", nullptr));
        groupBox_6->setTitle(QString());
        pushButton_11->setText(QString());
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "Voir D\303\251tails", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "Voir D\303\251tails", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "Voir D\303\251tails", nullptr));
        modifier->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        supprimer->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        afficher->setText(QCoreApplication::translate("MainWindow", "afficher", nullptr));
        rechercher->setText(QCoreApplication::translate("MainWindow", "rechercher", nullptr));
        trier_2->setText(QCoreApplication::translate("MainWindow", "trier", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "nom", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "point de fidelite", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "prenom", nullptr));

        QR_button->setText(QCoreApplication::translate("MainWindow", "Obtenir le QR code du client selectionnee", nullptr));
        qr_code->setText(QString());
        label_11->setText(QCoreApplication::translate("MainWindow", "Telephone*", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Adresse*", nullptr));
        pt_fidelite->setText(QString());
        dn->setText(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "Genre*", nullptr));
        update->setText(QCoreApplication::translate("MainWindow", "valider la modification", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_9), QCoreApplication::translate("MainWindow", "Add Client", nullptr));
        groupBox_9->setTitle(QString());
        pushButton_24->setText(QString());
        label_27->setText(QString());
        groupBox_7->setTitle(QString());
        statistique->setText(QCoreApplication::translate("MainWindow", "statistique selon adresse", nullptr));
        stat_genre->setText(QCoreApplication::translate("MainWindow", "statistique selon Genre", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_10), QCoreApplication::translate("MainWindow", "Statistique", nullptr));
        groupBox_8->setTitle(QString());
        pushButton_23->setText(QString());
        label_23->setText(QCoreApplication::translate("MainWindow", "Notification d'aujourd'hui", nullptr));
        label_24->setText(QString());
        groupBox_5->setTitle(QString());
        label_25->setText(QString());
        button_mail->setText(QCoreApplication::translate("MainWindow", "Envoyer un  Mail de Reduction", nullptr));
        updateNotifications->setText(QCoreApplication::translate("MainWindow", "Afficher les clients qui sont Fid\303\251le", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_11), QCoreApplication::translate("MainWindow", "Fid\303\251lit\303\251", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_8), QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "          Client            ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "             Produit          ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "         Commande           ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "          Article          ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("MainWindow", "       Personnel        ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "             Service         ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
