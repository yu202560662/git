# OpenCV + CMake + Git 环境（Ubuntu 22.04 / WSL2）

在 WSL2 的 Ubuntu 22.04 上配置 Git、CMake（C++）并验证 OpenCV 可正常构建运行。

## 环境（已验证，无需额外安装）

| 组件 | 版本 |
|---|---|
| 系统 | Ubuntu 22.04.5 LTS（WSL2，内核 6.6.87.2-microsoft-standard-WSL2） |
| git | 2.34.1 |
| cmake | 3.22.1 |
| GNU Make | 4.3 |
| g++ | 11.4.0 |
| pkg-config | 0.29.2 |
| OpenCV（libopencv-dev） | 4.5.4 |
| Python / cv2 | 3.10.12 / 4.5.4 |

`OpenCVConfig.cmake`：`/usr/lib/x86_64-linux-gnu/cmake/opencv4/OpenCVConfig.cmake`
（CMake 默认搜索路径内，`find_package(OpenCV 4 REQUIRED)` 直接可用）

## 目录结构

```text
opencv-check/
├── CMakeLists.txt          # find_package(OpenCV) + 两个 C++ 目标
├── src/main.cpp            # OpenCV 功能验证：画图 → 高斯模糊 → 写盘 → 读回
├── version_cpp.cpp         # 版本打印程序（C++）
├── version_py.py           # 版本打印程序（Python）
├── run_demo.sh             # 一键：环境检查 → cmake 配置/编译 → 运行
├── show_demo.sh            # 终端窗口演示脚本
├── README.md
└── .gitignore              # 忽略 build/、out.png
```

## 构建与运行

```bash
cd /mnt/c/Users/yun/Documents/deepseek-harness/default-workspace/opencv-check

cmake -S . -B build            # 配置，输出应包含 Found OpenCV: /usr (4.5.4)
cmake --build build -j"$(nproc)"

./build/opencv_demo            # 输出 OpenCV 4.5.4，并生成 out.png
./build/version_cpp            # OpenCV 4.5.4
python3 version_py.py          # OpenCV 4.5.4
```

一键运行（含环境信息）：

```bash
bash run_demo.sh
```

## Git

仓库已在 `opencv-check/` 初始化（分支 `main`），已完成首次提交：

```bash
git status
git log --oneline
```

若本机未配置全局身份，本仓库已设置本地 `user.name` / `user.email`，可自行修改：

```bash
git config user.name  "你的名字"
git config user.email "you@example.com"
```

## 备注

- `build/`、`out.png` 已加入 `.gitignore`，不会进入版本库
- 两个 C++ 目标都通过 `${OpenCV_LIBS}` 链接，`${OpenCV_INCLUDE_DIRS}` 提供头文件路径
