cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("CVRecognition")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# openssl
find_package(OpenSSL REQUIRED)
if(OPENSSL_FOUND)
  include_directories(${OPENSSL_INCLUDE_DIRS})
  message(STATUS "OpenSSL Found!")
  message(STATUS ${OPENSSL_INCLUDE_DIRS})
endif()

#curl
find_package(Curl REQUIRED)

if(CURL_FOUND)
  include_directories(${CURL_INCLUDE_DIRS})
  message(STATUS "CURL Found!")
  message(STATUS ${CURL_INCLUDE_DIRS})
endif()

add_definitions(-DBUILDING_LIBCURL)
add_definitions(-DHTTP_ONLY)

add_executable (CVRecognition "test_ocr.cpp")

target_link_libraries(CVRecognition OpenSSL::Crypto OpenSSL::SSL)
target_link_libraries(CVRecognition ${CURL_LIBRARIES})

include_directories(./cmss_cpp_sdk)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CVRecognition PROPERTY CXX_STANDARD 14)
endif()