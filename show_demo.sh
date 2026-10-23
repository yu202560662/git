#!/usr/bin/env bash
# 在真实终端窗口中演示 CMake + OpenCV + Git 流程，运行结果留在窗口里
cd "$(dirname "$0")" || exit 1

echo "Ubuntu 22.04.5 LTS (WSL2)   CMake + OpenCV + Git"
echo

echo "\$ cmake -S . -B build"
cmake -S . -B build 2>&1 | grep -E "OpenCV|Configuring|Generating|Build files"
echo

echo "\$ cmake --build build -j\$(nproc)"
cmake --build build -j"$(nproc)" 2>&1 | tail -3
echo

echo "\$ ./build/opencv_demo"
./build/opencv_demo
echo

echo "\$ git status"
git status --short || true
echo
