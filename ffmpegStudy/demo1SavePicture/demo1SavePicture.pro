TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

#ffmpeg lib
# INCLUDEPATH += $$PWD/ffmpeg/include
INCLUDEPATH += /home/yuanjl/ffmpegStudy/ffmpeg/include
LIBS +=-L /home/yuanjl/ffmpegStudy/ffmpeg/lib -lavcodec -lavutil -lavformat -lavdevice -lavfilter -lpostproc -lswresample -lswscale
