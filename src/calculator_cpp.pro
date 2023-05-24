QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    axis_window.cpp \
    credit_window.cpp \
    graph_window.cpp \
    main.cpp \
    calculations.cc \
    credit_calculations.cc \
    main_window.cpp \
    validation.cc \
    parser.cc


HEADERS += \
    axis_window.h \
    calculations.h \
    credit_calculations.h \
    credit_window.h \
    graph_window.h \
    main_window.h

FORMS += \
    axis_window.ui \
    credit_window.ui \
    graph_window.ui \
    main_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
