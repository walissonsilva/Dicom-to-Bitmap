#-------------------------------------------------
#
# Project created by QtCreator 2015-07-31T23:49:07
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = dcm-to-bmp
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui
LIBS += -L/usr/local/lib
LIBS += -lopencv_core
LIBS += -lopencv_imgproc
LIBS += -lopencv_highgui
LIBS += -lopencv_ml
LIBS += -lopencv_video
LIBS += -lopencv_features2d
LIBS += -lopencv_calib3d
LIBS += -lopencv_objdetect
LIBS += -lopencv_contrib
LIBS += -lopencv_legacy
LIBS += -lopencv_flann

INCLUDEPATH += /usr/local/include/dcmtk/dcmnet/
INCLUDEPATH += /usr/local/include/dcmtk/config/
LIBS += -L/usr/local/lib/ -ldcmnet -ldcmdata -loflog -lofstd

SOURCES += main.cpp \
    MedicalImage.cpp
DEFINES += HAVE_CONFIG_H
DEFINES += USE_NULL_SAFE_OFSTRING

HEADERS += \
    MedicalImage.h
