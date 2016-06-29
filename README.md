# server

# Pré-requis :
* Debian => build-essential qt5-default
* QTWebApp http://stefanfrings.de/qtwebapp/index-en.html (présent dans le répertoire Lib)

# Utilisation :

Se placer dans le répertoire puis lancer les commandes suivantes :
* qmake -o Makefile Server.pro
* make
* ./server

# Test unitaires
Se placer dans le répertoire puis lancer les commandes suivantes :
* qmake "QT += testlib" "CONFIG+=test_unit" -o Makefile Server.pro
* make
* ./server