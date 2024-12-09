cmake_minimum_required(VERSION 3.16)

project(resto_projet VERSION 0.1 LANGUAGES CXX)

# Configuration du standard C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Configuration du chemin de Qt
set(CMAKE_PREFIX_PATH "F:/logiciels/QT/6.8.0/mingw_64")

# Activation des fonctionnalités automatiques de Qt
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Inclure les répertoires de sources
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#set(MYSQL_CONNECTOR_PATH "C:/Program Files/MySQL/MySQL Connector C++ 9.1")
#include_directories(${MYSQL_CONNECTOR_PATH}/include)
#link_directories(${MYSQL_CONNECTOR_PATH}/lib64)

# Trouver les composants nécessaires de Qt
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
#find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)

# Liste des fichiers sources et ressources
set(PROJECT_SOURCES
        main.cpp
        View/view.cpp
        View/view.h
        ressources.qrc
        controller/ViewController.h
        controller/ViewController.cpp
        model/ViewModel.h
        model/ViewModel.cpp
        model/chefrang.h
        model/chefrang.cpp
        model/maitrehotel.h
        model/maitrehotel.cpp
        model/serveur.cpp
        model/cuisinier.h
        model/commis.h
        model/plongeur.h
        model/cuisinier.cpp
        model/commis.cpp
        model/plongeur.cpp
        model/client.h
        model/client.cpp
        model/Database.h
        model/Database.cpp
)

# Création de l'exécutable
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(resto_projet
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
    )
else()
    add_executable(resto_projet
            ${PROJECT_SOURCES}
    )
endif()

find_package(Qt6 REQUIRED COMPONENTS Sql)

target_link_libraries(resto_projet PRIVATE Qt6::Widgets Qt6::Sql)

# Configuration des propriétés pour Windows et macOS
set_target_properties(resto_projet PROPERTIES
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
)

# Installation de l'exécutable
include(GNUInstallDirs)
install(TARGETS resto_projet
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Finalisation pour Qt 6
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(resto_projet)
endif()
