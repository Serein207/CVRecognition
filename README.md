# CVRecognition

智能简历识别

# 项目配置指南

## 1. 下载OpenSSL

群文件下载 `Win64OpenSSL-1_1_1t.exe`。

安装路径自定义，并且记住该文件位置。

## 2. 下载libcurl

群文件下载 `curl-8.0.1.zip` 并解压到OpenSSL同级目录下

## 3. 修改系统环境变量

将 `xxxx\OpenSSL-Win64` 添加到 **系统** 环境变量中

将 `xxxx\curl-8.0.1\builds\libcurl-vc16-x64-release-dll-ipv6-sspi-schannel\bin` 添加到 **系统** 环境变量中

## 4. 下载Qt

本项目采用 `Qt6.x`，请确认使用C++17以及Qt6，编译器使用msvc

将 `xxxx\Qt\6.5.0\msvc2019_64\bin` 添加到 **系统** 环境变量中

**修改环境变量后请重启IDE！**

下载需要的模块

1. 打开 `xxxx\Qt\MaintenanceTool.exe` 安装程序 
2. 添加或移除组件>Qt>Qt6.5.0>Addtional Libraries
3. 下载 `Qt PDF` 和 `Active Qt` 模块

## 5. 开发

clone地址 `https://github.com/Serein207/CVRecognition.git`

载入 `CMakeLists.txt`

头文件位于 `header` ；源文件位于 `src`