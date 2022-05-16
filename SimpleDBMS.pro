QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    columnaddwindow.cpp \
    columnalterwindow.cpp \
    columndeletewindow.cpp \
    createwindow.cpp \
    database.cpp \
    datadeletewindow.cpp \
    datainsertwindow.cpp \
    db_createwindow.cpp \
    db_deletewindow.cpp \
    deletewindow.cpp \
    main.cpp \
    login.cpp \
    mainwindow.cpp \
    register.cpp \
    row.cpp \
    split.cpp \
    table.cpp \
    tbl_createwindow.cpp \
    tbl_deletewindow.cpp \
    user.cpp \
    column.cpp

HEADERS += \
    columnaddwindow.h \
    columnalterwindow.h \
    columndeletewindow.h \
    createwindow.h \
    database.h \
    datadeletewindow.h \
    datainsertwindow.h \
    db_createwindow.h \
    db_deletewindow.h \
    deletewindow.h \
    login.h \
    mainwindow.h \
    register.h \
    row.h \
    split.h \
    table.h \
    tbl_createwindow.h \
    tbl_deletewindow.h \
    user.h \
    column.h

FORMS += \
    columnaddwindow.ui \
    columnalterwindow.ui \
    columndeletewindow.ui \
    createwindow.ui \
    datadeletewindow.ui \
    datainsertwindow.ui \
    db_createwindow.ui \
    db_deletewindow.ui \
    deletewindow.ui \
    login.ui \
    mainwindow.ui \
    register.ui \
    tbl_createwindow.ui \
    tbl_deletewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
