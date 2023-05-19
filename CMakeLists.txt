cmake_minimum_required (VERSION 3.14)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project("CVRecognition")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /permissive- /Zc:__cplusplus ")

#查找OpenSSL库
find_package(OpenSSL REQUIRED)
if(OPENSSL_FOUND)
  include_directories(${OPENSSL_INCLUDE_DIRS})
  message(STATUS "OpenSSL Found!")
  message(STATUS ${OPENSSL_INCLUDE_DIRS})
endif()

#查找libcurl库
find_package(CURL REQUIRED)
if(CURL_FOUND)
  include_directories(${CURL_INCLUDE_DIRS})
  message(STATUS "CURL Found!")
  message(STATUS ${CURL_INCLUDE_DIRS})
endif()

#添加cmss_cpp_sdk
include_directories(./cmss_cpp_sdk)

add_definitions(-DBUILDING_LIBCURL)
add_definitions(-DHTTP_ONLY)

#设置Qt版本
set(QT_VERSION_MAJOR 6)
set(QT_VERSION_MINOR 0)
set(QT_VERSION_PATCH 0)

#查找Qt的包
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Gui Widgets Pdf AxContainer REQUIRED)
if(Qt6_FOUND)
  message(STATUS "Qt6 Found!")
  message(STATUS ${QT_PATH})
endif()

# set(CMAKE_PREFIX_PATH ${QT_PATH}/lib/cmake)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

ADD_DEFINITIONS(-DTORRENT_LIBRARY)
ADD_DEFINITIONS(-DNO_FREETYPE)
ADD_DEFINITIONS(-DUNICODE -D_UNICODE)
ADD_DEFINITIONS(-DHCPP_LEGACY_API)

FILE(GLOB_RECURSE HEADER_FILES "header/*.h")
FILE(GLOB_RECURSE SRC_FILES "src/*.cpp")
FILE(GLOB_RECURSE FORMS "forms/*.ui")
FILE(GLOB_RECURSE RESOURCE_FILES "*.qrc")
FILE(GLOB TS_FILES "*.ts")
FILE(GLOB MOC_FILES "moc/moc_*.cpp")

include_directories(./header)

IF(FORMS)
    qt_wrap_ui(FORMS_UIC ${FORMS})
ENDIF()

#将包含Q_OBJECT的头文件编译成moc_*.cpp文件
qt_wrap_cpp(MOC_FILES ${HEADER_FILES})

#启用当前头文件目录
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#将所有文件编译成EXE
add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SRC_FILES} ${MOC_FILES} ${FORMS_UIC} ${RESOURCE_FILES} ${RES_FILES})

target_link_libraries(${PROJECT_NAME}
PRIVATE 
    Qt${QT_VERSION_MAJOR}::Core 
    Qt${QT_VERSION_MAJOR}::Gui 
    Qt${QT_VERSION_MAJOR}::Widgets 
    Qt${QT_VERSION_MAJOR}::Pdf
    Qt${QT_VERSION_MAJOR}::AxContainer
    OpenSSL::SSL 
    OpenSSL::Crypto 
    ${CURL_LIBRARIES}
)
