QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    pages/UpRtdPort/uprtdport.cpp \
    pages/login/login.cpp \
    pages/login/uprtdport.cpp \
    widgets/highlightSlidingNav.cpp

HEADERS += \
    login.h \
    mainwindow.h \
    pages/UpRtdPort/uprtdport.h \
    pages/login/login.h \
    pages/login/uprtdport.h \
    widgets/highlightSlidingNav.h

FORMS += \
    login.ui \
    mainwindow.ui \
    pages/UpRtdPort/uprtdport.ui \
    pages/login/login.ui \
    pages/login/uprtdport.ui

TRANSLATIONS += \
    RTD_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc \
    res.qrc

DISTFILES += \
    ../style.qss \
    .gitignore
