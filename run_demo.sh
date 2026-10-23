#!/usr/bin/env bash
# 一键：环境检查 → CMake 配置/编译 → 运行 OpenCV 程序
set -e
cd "$(dirname "$0")"

echo "== 环境 =="
. /etc/os-release
echo "OS:        $PRETTY_NAME ($(uname -r))"
echo "git:       $(git --version)"
echo "cmake:     $(cmake --version | head -1)"
echo "compiler:  $(g++ --version | head -1)"
echo "opencv4:   $(pkg-config --modversion opencv4)  (pkg-config)"
echo "python:    $(python3 --version) / cv2 $(python3 -c 'import cv2; print(cv2.__version__)')"

echo
echo "== CMake 配置 =="
cmake -S . -B build

echo
echo "== 编译 =="
cmake --build build -j"$(nproc)"

echo
echo "== 运行 C++ (opencv_demo) =="
./build/opencv_demo

echo
echo "== 运行 C++ (version_cpp) =="
./build/version_cpp

echo
echo "== 运行 Python =="
python3 version_py.py
