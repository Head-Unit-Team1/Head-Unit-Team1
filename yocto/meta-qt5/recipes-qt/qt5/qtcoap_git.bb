require qt5.inc
require qt5-lts.inc

LICENSE = "GFDL-1.3 & BSD-3-Clause & GPL-3.0-only | The-Qt-Company-Commercial"
LIC_FILES_CHKSUM = " \
    file://LICENSE.GPL3;md5=d32239bcb673463ab874e80d47fae504 \
"

PACKAGECONFIG ?= "qtdeclarative"
PACKAGECONFIG[qtdeclarative] = ",,qtdeclarative"

DEPENDS += "qtbase"

SRCREV = "29e81260ef8a52a8da402928aa2de4cde91a2cc4"
