QT       += core gui widgets datavisualization charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(nomograms/nomograms.pri)
include(utils/utils.pri)

SOURCES += \
    dlgaddnewgraph.cpp \
    graphicseditorwindow.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    dlgaddnewgraph.h \
    graphicseditorwindow.h \
    mainwindow.h

FORMS += \
    dlgaddnewgraph.ui \
    graphicseditorwindow.ui \
    mainwindow.ui

TRANSLATIONS += \
    Graphs_en_US.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin $$[QT_INSTALL_EXAMPLES]/charts/multiaxis
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


unix|win32: LIBS += -L$$PWD/libtorch/lib/ -ltorch -ltorch_cpu -lc10

INCLUDEPATH += $$PWD/libtorch/include/torch/csrc/api/include
DEPENDPATH += $$PWD/libtorch/include/torch/csrc/api/include

INCLUDEPATH += $$PWD/libtorch/include
DEPENDPATH += $$PWD/libtorch/include
