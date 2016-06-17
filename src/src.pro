TARGET = QtPhysicsUnofficial
TEMPLATE = lib
PROJECT_NAME=QtPhysicsUnofficial

QT+= 3dcore 3dquick 3drender 3dcore-private 3drender-private

DESTDIR+= ./lib

CONFIG += c++11

DEFINES += QTPHYSICSUNOFFICIAL_LIBRARY

HEADERS += \
    qtphysicsunofficial_global.h

include(frontend/frontend.pri)
include(backend/backend.pri)

INCLUDEPATH += $$PWD

headersDataFiles.path = $$[QT_INSTALL_HEADERS]/$$PROJECT_NAME
headersDataFiles.files = $$PWD/*.h


INSTALLS += headersDataFiles

target.path = $$[QT_INSTALL_LIBS]
INSTALLS +=target
