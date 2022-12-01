QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Haffuman.cpp \
    Kmp.cpp \
    Note.cpp \
    Notebook.cpp \
    Singleton.cpp \
    User.cpp \
    UserLoginDialog.cpp \
    UserManager.cpp \
    UserRegisterDialog.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    Haffuman.h \
    Kmp.h \
    Note.h \
    Notebook.h \
    Singleton.h \
    User.h \
    UserLoginDialog.h \
    UserManager.h \
    UserRegisterDialog.h \
    widget.h

FORMS += \
    UserLoginDialog.ui \
    UserRegisterDialog.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
