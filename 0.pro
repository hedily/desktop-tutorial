#INCLUDEPATH += path/to/qrcodegen
#INCLUDEPATH += $$PWD/qrcodegen
# Nom du projet
TEMPLATE = app
TARGET = YourProjectName

# Modules Qt nécessaires
QT += core gui sql widgets printsupport charts network

# Configuration de la version de C++
CONFIG += c++17

# Désactive les API obsolètes de Qt avant Qt 6.0 (optionnel)
# DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

# Ajoute les fichiers source de ton projet
SOURCES += \
    client.cpp \
    connection.cpp \
    main.cpp \
    mainwindow.cpp

# Ajoute les fichiers d'en-tête de ton projet
HEADERS += \
    client.h \
    connection.h \
    mainwindow.h

# Formulaires Qt Designer (UI files)
FORMS += \
    mainwindow.ui

# Règles par défaut pour le déploiement
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Ajoutez le chemin pour QtSMTP si vous l'utilisez
# Remplacez par le chemin correct vers QtSMTP
# INCLUDEPATH += path/to/QtSmtp/src
# SOURCES += path/to/QtSmtp/src/QtSmtp.cpp  # Ajoutez d'autres fichiers .cpp si nécessaires
# HEADERS += path/to/QtSmtp/src/QtSmtp.h

# Si vous n'utilisez pas QtSMTP, commentez ou supprimez les lignes ci-dessus
