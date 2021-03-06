# try use global config
exists(../../../../config.pri) {
    ROOT_DIR=../../../..
    #message(Using global config)
    include($$ROOT_DIR/config.pri)
} else {
    #message(Using local config)
    ROOT_DIR=../..
    include($$ROOT_DIR/cvs-config.pri)
}
ROOT_DIR=$$PWD/$$ROOT_DIR

DESTDIR = $$ROOT_DIR/bin
OBJECTS_DIR = $$ROOT_DIR/.obj/$$TARGET$$BUILD_CFG_NAME
MOC_DIR  = $$OBJECTS_DIR
UI_DIR   = $$OBJECTS_DIR
RCC_DIR  = $$OBJECTS_DIR

TEMPLATE = app
TARGET   = reprojector
CONFIG  += console
QT      += core

include(../../core/core.pri)
#include(../../utils/utils.pri)                      # it uses TARGET, ROOT_DIR and detects UTILS_BINDIR, OBJECTS_DIR, DESTDIR, ...!


SOURCES += \
    main_reprojector.cpp

with_libjpeg {
    LIBJPEG_WRAPPER_DIR = ../../wrappers/libjpeg
    include($$LIBJPEG_WRAPPER_DIR/libjpeg.pri)

    contains(DEFINES, WITH_LIBJPEG) {
        INCLUDEPATH += $$LIBJPEG_WRAPPER_DIR
    }
}

with_libpng {
    LIBPNG_WRAPPER_DIR = ../../wrappers/libpng

    include($$LIBPNG_WRAPPER_DIR/libpng.pri)
    contains(DEFINES, WITH_LIBPNG) {
        INCLUDEPATH += $$LIBPNG_WRAPPER_DIR
    }
}

with_jsonmodern {
    message(We have Json for Modern C++ )
    JSONMODERN_WRAPPER_DIR = ../../wrappers/jsonmodern
    include($$JSONMODERN_WRAPPER_DIR/jsonmodern.pri)

    contains(DEFINES, WITH_JSONMODERN) {
        INCLUDEPATH += $$JSONMODERN_WRAPPER_DIR
    }
}

OTHER_FILES +=     \
    reproject.sh   \
    CMakeLists.txt

