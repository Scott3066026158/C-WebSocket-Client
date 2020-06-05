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
    crypto/base32_bch.c \
    crypto/base58.c \
    crypto/bch.c \
    crypto/bignum.c \
    crypto/bignum256.c \
    crypto/bip32.c \
    crypto/bip39.c \
    crypto/bitcoinkeys.c \
    crypto/ecdsa.c \
    crypto/ecdsa1.c \
    crypto/endian.c \
    crypto/eoskeys.c \
    crypto/eth.c \
    crypto/etherkeys.c \
    crypto/hash.c \
    crypto/hmac.c \
    crypto/hmac_drbg.c \
    crypto/hmac_sha512.c \
    crypto/keccak.c \
    crypto/pbkdf2.c \
    crypto/rand.c \
    crypto/ripemd160.c \
    crypto/secp256k1.c \
    crypto/sha2.c \
    crypto/sha256.c \
    encrypt/HMAC.cpp \
    encrypt/HMAC_SHA256.cpp \
    encrypt/MD5.cpp \
    encrypt/SHA.cpp \
    main.cpp \
    model/AppConfig.cpp \
    model/FileUploadForm.cpp \
    model/JsonRPC.cpp \
    model/KeyPair.cpp \
    model/UserDirectory.cpp \
    model/UserFile.cpp \
    net/JsonRPCNet.cpp \
    net/Request.cpp \
    service/CCDNService.cpp \
    stdafx.cpp \
    util/FileUtil.cpp \
    util/Lock.cpp \
    util/Log.cpp \
    util/MathUtil.cpp \
    util/StringUtil.cpp \
    widget.cpp

HEADERS += \
    crypto/base32_bch.h \
    crypto/base58.h \
    crypto/bch.h \
    crypto/bignum.h \
    crypto/bignum256.h \
    crypto/bip32.h \
    crypto/bip39.h \
    crypto/bip39_english.h \
    crypto/bitcoinkeys.h \
    crypto/common.h \
    crypto/ecdsa.h \
    crypto/ecdsa1.h \
    crypto/endian.h \
    crypto/eoskeys.h \
    crypto/eth.h \
    crypto/etherkeys.h \
    crypto/hash.h \
    crypto/hmac.h \
    crypto/hmac_drbg.h \
    crypto/hmac_sha512.h \
    crypto/keccak.h \
    crypto/options.h \
    crypto/pbkdf2.h \
    crypto/rand.h \
    crypto/ripemd160.h \
    crypto/secp256k1.h \
    crypto/sha2.h \
    crypto/sha256.h \
    encrypt/HMAC.h \
    encrypt/HMAC_DATA.h \
    encrypt/HMAC_SHA256.h \
    encrypt/MD5.h \
    encrypt/SHA.h \
    model/AppConfig.h \
    model/FileUploadForm.h \
    model/JsonRPC.h \
    model/JsonString.h \
    model/KeyPair.h \
    model/KeyStore.h \
    model/UserDirectory.h \
    model/UserFile.h \
    model/UserInfo.h \
    net/GaiaURL.h \
    net/JsonRPCNet.h \
    net/Request.h \
    service/CCDNService.h \
    stdafx.h \
    util/DateUtil.h \
    util/FileUtil.h \
    util/Lock.h \
    util/Log.h \
    util/MathUtil.h \
    util/StringUtil.h \
    widget.h

FORMS += \
    widget.ui

TRANSLATIONS += \
    NetDisk_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    crypto/README.md
