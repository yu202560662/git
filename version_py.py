#!/usr/bin/env python3
"""OpenCV 版本打印程序（Python 版）：打印版本号并弹窗显示，方便截图。"""
import platform
import sys

import cv2
import numpy as np

WINDOW = "OpenCV version - Python"


def main() -> None:
    print(f"OpenCV {cv2.__version__}")
    py = f"{sys.version_info.major}.{sys.version_info.minor}.{sys.version_info.micro}"
    print(f"Python demo | python {py} | cv2 {cv2.__version__}")

    if "--window" not in sys.argv and "-w" not in sys.argv:
        return

    width, height = 860, 360
    canvas = np.full((height, width, 3), (34, 30, 30), dtype=np.uint8)

    cv2.putText(canvas, f"OpenCV {cv2.__version__}", (48, 120),
                cv2.FONT_HERSHEY_SIMPLEX, 1.7, (120, 220, 90), 3, cv2.LINE_AA)
    cv2.putText(canvas, "Language: Python  (cv2 module)", (48, 190),
                cv2.FONT_HERSHEY_SIMPLEX, 0.85, (235, 235, 235), 2, cv2.LINE_AA)
    cv2.putText(canvas, f"Python {py}  |  {platform.system()} {platform.machine()} (WSL2)", (48, 245),
                cv2.FONT_HERSHEY_SIMPLEX, 0.7, (185, 175, 170), 1, cv2.LINE_AA)
    cv2.putText(canvas, "Press any key to close", (48, 315),
                cv2.FONT_HERSHEY_SIMPLEX, 0.6, (135, 125, 120), 1, cv2.LINE_AA)

    cv2.namedWindow(WINDOW, cv2.WINDOW_AUTOSIZE)
    cv2.moveWindow(WINDOW, 80, 480)
    cv2.imshow(WINDOW, canvas)
    print(f"window shown: {WINDOW} (press any key in the window to close)")
    cv2.waitKey(0)
    cv2.destroyWindow(WINDOW)


if __name__ == "__main__":
    main()
