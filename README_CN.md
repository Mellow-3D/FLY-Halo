# FLY-Halo

* [English version](./README.md)

* Halo官方文档 [FLY-Halo-CN](https://mellow.klipper.cn/?lang=zh_cn#/board/fly_halo/)
* Halo的发布版固件不开源
* 我们为Halo提供了一个基于发布版固件和ESP-IDF的开源demo，您可以在此demo基础上开发您的固件

## Halo-demo

* demo已经适配LCD屏幕及触摸和LVGL，可直接开发
* 后续看用户需求再考虑是否做UI框架

* DEMO食用方法

  1. Windows/Linux/Mac均可，请预先安装[ESP-IDF v5.1](https://github.com/espressif/esp-idf/tree/release/v5.1)
  2. 安装[ESP-IDF](https://github.com/espressif/esp-idf/tree/release/v5.1)后进入`Halo-demo`目录
  3. 执行命令`idf.py menuconfig`
  4. 选择`Halo Demo Configuration`进入菜单配置WIFI和密码，其余选项可以不管
  5. 输入`q`，弹窗后输入`y`即可退出并保存配置
  6. 执行命令`idf.py build`进行编译，如果编译报错请检查ESP-IDF环境（ESP-IDF版本要求5.1或更高）
  7. 将Halo通过USB连接到电脑，查看其COM，如果没有，请按住Halo背面的**B**按键再连接USB
  8. 执行命令`idf.py -p COM14 flash`烧录固件,将COM14更换为您电脑中Halo的实际端口
  9. 如果需要打开串行监视器可使用命令`idf.py -p COM14 monitor`,如果需要烧录后自动打开使用`idf.py -p COM14 flash monitor`

## 外设引脚

[nc]: https://img.shields.io/badge/-NC-red "NC"

* LCD GC9A01 Pins

  |     FUN       |          GPIO           |
  | :-----------: | :---------------------: |
  |   BACKLIGHT   | ![alt text](https://img.shields.io/badge/-GPIO08-green) |
  |     DC        | ![alt text](https://img.shields.io/badge/-GPIO09-green) |
  |     CS        | ![alt text](https://img.shields.io/badge/-GPIO10-green) |
  |     MOSI      | ![alt text](https://img.shields.io/badge/-GPIO11-green) |
  |     SCLK      | ![alt text](https://img.shields.io/badge/-GPIO12-green) |
  |     RST       | ![alt text](https://img.shields.io/badge/-GPIO13-green) |
  |     MISO      | ![alt text][nc] |

----

* TOUCH CST816D Pins

  |     FUN       |          GPIO           |
  | :-----------: | :---------------------: |
  |     SDA       | ![alt text](https://img.shields.io/badge/-GPIO39-blue) |
  |     SCL       | ![alt text](https://img.shields.io/badge/-GPIO40-blue) |
  |     INT       | ![alt text](https://img.shields.io/badge/-GPIO41-blue) |
  |     RST       | ![alt text](https://img.shields.io/badge/-GPIO42-blue) |

----

* Magnetic Encoder AS5047D Pins

  |     FUN       |          GPIO           |
  | :-----------: | :---------------------: |
  |     CS        | ![alt text](https://img.shields.io/badge/-GPIO15-indigo) |
  |     SCLK      | ![alt text](https://img.shields.io/badge/-GPIO16-indigo) |
  |     MISO      | ![alt text](https://img.shields.io/badge/-GPIO17-indigo) |
  |     MOSI      | ![alt text](https://img.shields.io/badge/-GPIO18-indigo) |

----


