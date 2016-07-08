# server

## Pré-requis :
* Debian => build-essential qt5-default
* QTWebApp http://stefanfrings.de/qtwebapp/index-en.html (présent dans le répertoire Lib)

## Utilisation :
Se placer dans le répertoire puis lancer les commandes suivantes :
* cmake CMakeLists.txt
* make
* ./server

## Test unitaires
Se placer dans le répertoire puis lancer les commandes suivantes :
* cmake CMakeLists.txt -DUnitTest=ON
* make
* ./server

## Générer le paquet debian
* cmake CMakeLists.txt
* make package