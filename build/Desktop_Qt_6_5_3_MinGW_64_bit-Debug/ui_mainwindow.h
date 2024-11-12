/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QGroupBox *groupBox_3;
    QLabel *label;
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
    QLineEdit *telephone;
    QLineEdit *email;
    QPushButton *annuler;
    QPushButton *exporter;
    QLineEdit *adresse;
    QGroupBox *groupBox_6;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *modifier;
    QPushButton *supprimer;
    QPushButton *afficher;
    QTableView *tableView;
    QLineEdit *recherche;
    QPushButton *rechercher;
    QPushButton *trier_2;
    QComboBox *comboBox;
    QWidget *tab_11;
    QGroupBox *groupBox_8;
    QPushButton *pushButton_23;
    QLabel *label_23;
    QLabel *label_24;
    QGroupBox *groupBox_5;
    QLabel *label_25;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QTableWidget *tableWidget_2;
    QWidget *widget_7;
    QPushButton *pushButton_18;
    QPushButton *pushButton_19;
    QGroupBox *groupBox_13;
    QPushButton *pushButton_20;
    QPushButton *pushButton_40;
    QPushButton *pushButton_41;
    QWidget *tab_10;
    QGroupBox *groupBox_7;
    QTableView *tableView_2;
    QPushButton *pushButton_21;
    QLabel *label_14;
    QLabel *label_15;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_7;
    QRadioButton *radioButton_8;
    QRadioButton *radioButton_9;
    QPushButton *pushButton_29;
    QLabel *label_16;
    QLabel *label_17;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_9;
    QCheckBox *checkBox_10;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *tab_5;
    QWidget *tab_6;
    QWidget *tab_2;
    QMenuBar *menubar;
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
        label = new QLabel(groupBox_3);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 0, 241, 81));
        label->setPixmap(QPixmap(QString::fromUtf8("../../../../Pictures/Screenshots/Capture d'\303\251cran 2024-09-28 124219.png")));
        label->setScaledContents(true);
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
        label_7->setGeometry(QRect(30, 140, 71, 16));
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("border:none;"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(30, 180, 81, 31));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("border:none;"));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 250, 91, 16));
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8("border:none;"));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(30, 310, 49, 16));
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("border:none;"));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(30, 360, 161, 16));
        label_12->setFont(font1);
        label_12->setStyleSheet(QString::fromUtf8("border:none;"));
        valider = new QPushButton(groupBox_2);
        valider->setObjectName("valider");
        valider->setGeometry(QRect(280, 490, 91, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI Black")});
        font2.setPointSize(12);
        valider->setFont(font2);
        valider->setStyleSheet(QString::fromUtf8("background-color: rgba(129,211,22,255); \n"
"color: rgb(255, 255, 255);"));
        id_client = new QLineEdit(groupBox_2);
        id_client->setObjectName("id_client");
        id_client->setGeometry(QRect(180, 90, 191, 21));
        id_client->setStyleSheet(QString::fromUtf8(" border: 2px solid rgba(129,211,22,255);  padding: 1px; ;\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;\n"
"\n"
""));
        nom = new QLineEdit(groupBox_2);
        nom->setObjectName("nom");
        nom->setGeometry(QRect(180, 140, 191, 21));
        nom->setStyleSheet(QString::fromUtf8(" border: 2px solid rgba(129,211,22,255);  padding: 1px; ;\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;\n"
"\n"
""));
        prenom = new QLineEdit(groupBox_2);
        prenom->setObjectName("prenom");
        prenom->setGeometry(QRect(180, 190, 191, 21));
        prenom->setStyleSheet(QString::fromUtf8(" border: 2px solid rgba(129,211,22,255);  padding: 1px; ;\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;\n"
"\n"
""));
        telephone = new QLineEdit(groupBox_2);
        telephone->setObjectName("telephone");
        telephone->setGeometry(QRect(170, 250, 191, 21));
        telephone->setStyleSheet(QString::fromUtf8(" border: 2px solid rgba(129,211,22,255);  padding: 1px; ;\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;\n"
"\n"
""));
        email = new QLineEdit(groupBox_2);
        email->setObjectName("email");
        email->setGeometry(QRect(180, 310, 191, 21));
        email->setStyleSheet(QString::fromUtf8(" border: 2px solid rgba(129,211,22,255);  padding: 1px; ;\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;\n"
"\n"
""));
        annuler = new QPushButton(groupBox_2);
        annuler->setObjectName("annuler");
        annuler->setGeometry(QRect(30, 490, 91, 31));
        annuler->setFont(font2);
        annuler->setStyleSheet(QString::fromUtf8("background-color: rgba(129,211,22,255); \n"
"color: rgb(255, 255, 255);"));
        exporter = new QPushButton(groupBox_2);
        exporter->setObjectName("exporter");
        exporter->setGeometry(QRect(110, 610, 181, 41));
        exporter->setFont(font2);
        exporter->setStyleSheet(QString::fromUtf8("background-color: rgba(129,211,22,255); \n"
"color: rgb(255, 255, 255);"));
        adresse = new QLineEdit(groupBox_2);
        adresse->setObjectName("adresse");
        adresse->setGeometry(QRect(180, 360, 191, 26));
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
        modifier->setGeometry(QRect(430, 560, 141, 41));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Segoe UI")});
        font4.setPointSize(9);
        font4.setBold(false);
        font4.setItalic(false);
        modifier->setFont(font4);
        modifier->setStyleSheet(QString::fromUtf8("background-color: rgba(129,211,22,255);\n"
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
        supprimer->setGeometry(QRect(20, 560, 141, 41));
        supprimer->setFont(font4);
        supprimer->setStyleSheet(QString::fromUtf8("background-color: rgba(129,211,22,255);\n"
"font: 9pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;"));
        supprimer->setIcon(icon2);
        afficher = new QPushButton(groupBox_6);
        afficher->setObjectName("afficher");
        afficher->setGeometry(QRect(440, 220, 141, 41));
        afficher->setFont(font4);
        afficher->setStyleSheet(QString::fromUtf8("background-color: rgba(129,211,22,255);\n"
"font: 9pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;"));
        afficher->setIcon(icon2);
        tableView = new QTableView(groupBox_6);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 10, 571, 201));
        recherche = new QLineEdit(groupBox_6);
        recherche->setObjectName("recherche");
        recherche->setGeometry(QRect(70, 330, 191, 21));
        recherche->setStyleSheet(QString::fromUtf8(" border: 2px solid rgba(129,211,22,255);  padding: 1px; ;\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;\n"
"\n"
""));
        rechercher = new QPushButton(groupBox_6);
        rechercher->setObjectName("rechercher");
        rechercher->setGeometry(QRect(310, 320, 141, 41));
        rechercher->setFont(font4);
        rechercher->setStyleSheet(QString::fromUtf8("background-color: rgba(129,211,22,255);\n"
"font: 9pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;"));
        rechercher->setIcon(icon2);
        trier_2 = new QPushButton(groupBox_6);
        trier_2->setObjectName("trier_2");
        trier_2->setGeometry(QRect(310, 380, 141, 41));
        trier_2->setFont(font4);
        trier_2->setStyleSheet(QString::fromUtf8("background-color: rgba(129,211,22,255);\n"
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
        comboBox->setGeometry(QRect(110, 390, 76, 26));
        tabWidget_2->addTab(tab_9, QString());
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
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Segoe UI")});
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setItalic(false);
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
        label_25->setGeometry(QRect(40, 40, 981, 491));
        label_25->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/icons8-test-account-50 (1).png")));
        label_25->setScaledContents(true);
        pushButton_16 = new QPushButton(groupBox_5);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setGeometry(QRect(280, 460, 231, 41));
        pushButton_16->setFont(font5);
        pushButton_16->setStyleSheet(QString::fromUtf8("background-color: rgba(129,211,22,255); \n"
"color: rgb(255, 255, 255);"));
        pushButton_17 = new QPushButton(groupBox_5);
        pushButton_17->setObjectName("pushButton_17");
        pushButton_17->setGeometry(QRect(50, 460, 211, 41));
        pushButton_17->setFont(font5);
        pushButton_17->setStyleSheet(QString::fromUtf8("background-color: rgba(129,211,22,255); \n"
"color: rgb(255, 255, 255);"));
        tableWidget_2 = new QTableWidget(groupBox_5);
        if (tableWidget_2->columnCount() < 7)
            tableWidget_2->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget_2->setObjectName("tableWidget_2");
        tableWidget_2->setGeometry(QRect(70, 140, 421, 261));
        tableWidget_2->setStyleSheet(QString::fromUtf8(" border: 2px solid rgba(129,211,22,255);   padding: 1px; ;\n"
"background-color: rgb(255, 255, 255);\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius:10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;\n"
"\n"
"\n"
""));
        widget_7 = new QWidget(groupBox_5);
        widget_7->setObjectName("widget_7");
        widget_7->setGeometry(QRect(80, 70, 291, 31));
        widget_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;\n"
" border: 2px solid rgba(129,211,22,255);  padding: 1px; \n"
"\n"
""));
        pushButton_18 = new QPushButton(widget_7);
        pushButton_18->setObjectName("pushButton_18");
        pushButton_18->setGeometry(QRect(10, 10, 15, 15));
        pushButton_18->setMinimumSize(QSize(15, 15));
        pushButton_18->setMaximumSize(QSize(15, 15));
        pushButton_18->setStyleSheet(QString::fromUtf8("border: none;"));
        pushButton_18->setIcon(icon);
        pushButton_19 = new QPushButton(groupBox_5);
        pushButton_19->setObjectName("pushButton_19");
        pushButton_19->setGeometry(QRect(390, 70, 111, 41));
        pushButton_19->setFont(font5);
        pushButton_19->setStyleSheet(QString::fromUtf8("background-color: rgba(129,211,22,255); \n"
"color: rgb(255, 255, 255);"));
        groupBox_13 = new QGroupBox(groupBox_5);
        groupBox_13->setObjectName("groupBox_13");
        groupBox_13->setGeometry(QRect(570, 70, 421, 431));
        groupBox_13->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";\n"
"/*background-color: rgb(50, 54, 63);*/\n"
"border-top-left-radius: 20px ;\n"
"border-bottom-left-radius:20px ;\n"
"border-top-right-radius:20px ;\n"
"border-bottom-right-radius:20px ;\n"
"background-color: rgb(50, 54, 63);\n"
"\n"
""));
        pushButton_20 = new QPushButton(groupBox_13);
        pushButton_20->setObjectName("pushButton_20");
        pushButton_20->setGeometry(QRect(730, 40, 75, 24));
        pushButton_20->setIcon(icon1);
        pushButton_20->setIconSize(QSize(30, 30));
        pushButton_40 = new QPushButton(groupBox_13);
        pushButton_40->setObjectName("pushButton_40");
        pushButton_40->setGeometry(QRect(70, 570, 141, 41));
        pushButton_40->setFont(font4);
        pushButton_40->setStyleSheet(QString::fromUtf8("background-color: rgba(129,211,22,255);\n"
"font: 9pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;"));
        pushButton_40->setIcon(icon2);
        pushButton_41 = new QPushButton(groupBox_13);
        pushButton_41->setObjectName("pushButton_41");
        pushButton_41->setGeometry(QRect(410, 570, 141, 41));
        pushButton_41->setFont(font4);
        pushButton_41->setStyleSheet(QString::fromUtf8("background-color: rgba(129,211,22,255);\n"
"font: 9pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;"));
        pushButton_41->setIcon(icon2);
        tabWidget_2->addTab(tab_11, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName("tab_10");
        groupBox_7 = new QGroupBox(tab_10);
        groupBox_7->setObjectName("groupBox_7");
        groupBox_7->setGeometry(QRect(-10, 0, 1131, 711));
        groupBox_7->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";\n"
"background-color: rgb(50, 54, 63);\n"
"border-top-left-radius: 20px ;\n"
"border-bottom-left-radius:20px ;\n"
"border-top-right-radius:20px ;\n"
"border-bottom-right-radius:20px ;\n"
"\n"
""));
        tableView_2 = new QTableView(groupBox_7);
        tableView_2->setObjectName("tableView_2");
        tableView_2->setGeometry(QRect(40, 120, 1051, 481));
        tableView_2->setStyleSheet(QString::fromUtf8(" border: 2px solid rgba(129,211,22,255); padding: 1px; ;\n"
"background-color: rgb(255, 255, 255);\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius:10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;\n"
"\n"
""));
        pushButton_21 = new QPushButton(groupBox_7);
        pushButton_21->setObjectName("pushButton_21");
        pushButton_21->setGeometry(QRect(740, 40, 41, 24));
        pushButton_21->setIcon(icon1);
        pushButton_21->setIconSize(QSize(30, 30));
        label_14 = new QLabel(groupBox_7);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(70, 130, 401, 31));
        label_14->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_15 = new QLabel(groupBox_7);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(70, 180, 61, 21));
        label_15->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 700 italic 7pt \"Segoe UI\";\n"
"font: 10pt \"Segoe UI\";\n"
"font: 700 italic 9pt \"Segoe UI\";"));
        radioButton_3 = new QRadioButton(groupBox_7);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setGeometry(QRect(270, 220, 41, 24));
        radioButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 9pt \"Segoe UI\";"));
        radioButton_4 = new QRadioButton(groupBox_7);
        radioButton_4->setObjectName("radioButton_4");
        radioButton_4->setGeometry(QRect(350, 220, 41, 24));
        radioButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 9pt \"Segoe UI\";"));
        radioButton_5 = new QRadioButton(groupBox_7);
        radioButton_5->setObjectName("radioButton_5");
        radioButton_5->setGeometry(QRect(590, 220, 41, 24));
        radioButton_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 9pt \"Segoe UI\";"));
        radioButton_6 = new QRadioButton(groupBox_7);
        radioButton_6->setObjectName("radioButton_6");
        radioButton_6->setGeometry(QRect(510, 220, 41, 24));
        radioButton_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 9pt \"Segoe UI\";"));
        radioButton_7 = new QRadioButton(groupBox_7);
        radioButton_7->setObjectName("radioButton_7");
        radioButton_7->setGeometry(QRect(430, 220, 41, 24));
        radioButton_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 9pt \"Segoe UI\";"));
        radioButton_8 = new QRadioButton(groupBox_7);
        radioButton_8->setObjectName("radioButton_8");
        radioButton_8->setGeometry(QRect(660, 220, 41, 24));
        radioButton_8->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 9pt \"Segoe UI\";"));
        radioButton_9 = new QRadioButton(groupBox_7);
        radioButton_9->setObjectName("radioButton_9");
        radioButton_9->setGeometry(QRect(740, 220, 41, 24));
        radioButton_9->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 9pt \"Segoe UI\";"));
        pushButton_29 = new QPushButton(groupBox_7);
        pushButton_29->setObjectName("pushButton_29");
        pushButton_29->setGeometry(QRect(380, 540, 271, 41));
        pushButton_29->setFont(font5);
        pushButton_29->setStyleSheet(QString::fromUtf8("background-color: rgba(129,211,22,255); \n"
"color: rgb(255, 255, 255);\n"
"border-top-left-radius: 10px ;\n"
"border-bottom-left-radius: 10px ;\n"
"border-top-right-radius:10px ;\n"
"border-bottom-right-radius:10px ;"));
        label_16 = new QLabel(groupBox_7);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(70, 260, 131, 21));
        label_16->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 700 italic 7pt \"Segoe UI\";\n"
"font: 10pt \"Segoe UI\";\n"
"font: 700 italic 9pt \"Segoe UI\";"));
        label_17 = new QLabel(groupBox_7);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(570, 260, 201, 21));
        label_17->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 700 italic 7pt \"Segoe UI\";\n"
"font: 10pt \"Segoe UI\";\n"
"font: 700 italic 9pt \"Segoe UI\";"));
        checkBox = new QCheckBox(groupBox_7);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(60, 310, 471, 24));
        checkBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 9pt \"Segoe UI\";"));
        checkBox_2 = new QCheckBox(groupBox_7);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setGeometry(QRect(60, 470, 431, 24));
        checkBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 9pt \"Segoe UI\";"));
        checkBox_3 = new QCheckBox(groupBox_7);
        checkBox_3->setObjectName("checkBox_3");
        checkBox_3->setGeometry(QRect(60, 430, 381, 24));
        checkBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 9pt \"Segoe UI\";"));
        checkBox_4 = new QCheckBox(groupBox_7);
        checkBox_4->setObjectName("checkBox_4");
        checkBox_4->setGeometry(QRect(60, 390, 351, 24));
        checkBox_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 9pt \"Segoe UI\";"));
        checkBox_5 = new QCheckBox(groupBox_7);
        checkBox_5->setObjectName("checkBox_5");
        checkBox_5->setGeometry(QRect(60, 350, 291, 24));
        checkBox_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 9pt \"Segoe UI\";"));
        checkBox_6 = new QCheckBox(groupBox_7);
        checkBox_6->setObjectName("checkBox_6");
        checkBox_6->setGeometry(QRect(570, 470, 351, 24));
        checkBox_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 9pt \"Segoe UI\";"));
        checkBox_7 = new QCheckBox(groupBox_7);
        checkBox_7->setObjectName("checkBox_7");
        checkBox_7->setGeometry(QRect(570, 430, 281, 24));
        checkBox_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 9pt \"Segoe UI\";"));
        checkBox_8 = new QCheckBox(groupBox_7);
        checkBox_8->setObjectName("checkBox_8");
        checkBox_8->setGeometry(QRect(570, 390, 361, 24));
        checkBox_8->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 9pt \"Segoe UI\";"));
        checkBox_9 = new QCheckBox(groupBox_7);
        checkBox_9->setObjectName("checkBox_9");
        checkBox_9->setGeometry(QRect(570, 350, 391, 24));
        checkBox_9->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 9pt \"Segoe UI\";"));
        checkBox_10 = new QCheckBox(groupBox_7);
        checkBox_10->setObjectName("checkBox_10");
        checkBox_10->setGeometry(QRect(570, 310, 451, 24));
        checkBox_10->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 9pt \"Segoe UI\";"));
        tabWidget_2->addTab(tab_10, QString());
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
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1253, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        groupBox_3->setTitle(QString());
        label->setText(QString());
        label_3->setText(QString());
        label_2->setText(QString());
        label_4->setText(QString());
        pushButton_15->setText(QString());
        label_18->setText(QString());
        groupBox_4->setTitle(QString());
        label_28->setText(QCoreApplication::translate("MainWindow", "CleanXpert", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QCoreApplication::translate("MainWindow", "        Profil          ", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Ajout d'un client", nullptr));
        label_5->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "prenom", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone *", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Email *", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "adresse", nullptr));
        valider->setText(QCoreApplication::translate("MainWindow", "Valider", nullptr));
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
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "id", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "nom", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "prenom", nullptr));

        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_9), QCoreApplication::translate("MainWindow", "Add Client", nullptr));
        groupBox_8->setTitle(QString());
        pushButton_23->setText(QString());
        label_23->setText(QCoreApplication::translate("MainWindow", "Notification d'aujourd'hui", nullptr));
        label_24->setText(QString());
        groupBox_5->setTitle(QString());
        label_25->setText(QString());
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "Envoyer un reduction", nullptr));
        pushButton_17->setText(QCoreApplication::translate("MainWindow", "Envoyer un mail", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Prenom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Telephone", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_2->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Date de naissance ", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_2->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Genre", nullptr));
        pushButton_18->setText(QString());
        pushButton_19->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        groupBox_13->setTitle(QString());
        pushButton_20->setText(QString());
        pushButton_40->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        pushButton_41->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_11), QCoreApplication::translate("MainWindow", "Fid\303\251lit\303\251", nullptr));
        groupBox_7->setTitle(QString());
        pushButton_21->setText(QString());
        label_14->setText(QCoreApplication::translate("MainWindow", "Leave Your Feedback", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Rating :", nullptr));
        radioButton_3->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        radioButton_4->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        radioButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        radioButton_6->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        radioButton_7->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        radioButton_8->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        radioButton_9->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_29->setText(QCoreApplication::translate("MainWindow", "Submit Feedback", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Feedback Positifs:", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Feedback N\303\251gatifs:", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", " \"Support rapide et efficace.\"", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", " \"Il fonctionne rapidement, id\303\251al pour les urgences.\"", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainWindow", " \"L'odeur apr\303\250s nettoyage est agr\303\251able et fra\303\256che.\"", nullptr));
        checkBox_4->setText(QCoreApplication::translate("MainWindow", " \"L'application simplifie mes commandes.\"", nullptr));
        checkBox_5->setText(QCoreApplication::translate("MainWindow", " \"Mes v\303\252tements sont impeccables !\"", nullptr));
        checkBox_6->setText(QCoreApplication::translate("MainWindow", " \" j'ai eu une r\303\251action allergique.\"", nullptr));
        checkBox_7->setText(QCoreApplication::translate("MainWindow", "\"L'odeur est trop forte pour moi.\"", nullptr));
        checkBox_8->setText(QCoreApplication::translate("MainWindow", " \"Les livraisons prennent trop de temps.\"", nullptr));
        checkBox_9->setText(QCoreApplication::translate("MainWindow", " \"Un peu cher pour la quantit\303\251 fournie.\"", nullptr));
        checkBox_10->setText(QCoreApplication::translate("MainWindow", " \"Le v\303\252tement a perdu sa couleur apr\303\250s un seul lavage.\"", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_10), QCoreApplication::translate("MainWindow", "Feedback", nullptr));
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
