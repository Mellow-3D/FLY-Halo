# FLY-Halo

The Fly-HALO can be purchased from here https://s.click.aliexpress.com/e/_DmDJzHf

This link is affiliated URL. If you purchase via link above it will give tiny cent of commission to the community organizers. (We are not Mellow employees, just 3D printer enthusiasts) This will not hurt your wallet and at the same time help us to maintain the GitHub better.

* [中文版本](./README_CN.md)

* Halo Official Documentation [FLY-Halo-EN](https://mellow.klipper.cn/?lang=en#/board/fly_halo/)
* Halo release version firmware is not open source
* We provide Halo with an open source demo based on released firmware and ESP-IDF, you can develop your firmware based on this demo

## Halo-demo

* The demo has been adapted to LCD screen, touch and LVGL, and can be directly developed
* Follow-up to see user needs and then consider whether to do UI framework

* DEMO edible method

  1. Windows/Linux/Mac are available, please install [ESP-IDF v5.1](https://github.com/espressif/esp-idf/tree/release/v5.1) in advance
  2.Enter the `Halo-demo` directory after installing [ESP-IDF](https://github.com/espressif/esp-idf/tree/release/v5.1)
  3. Execute the command `idf.py menuconfig`
  4. Select `Halo Demo Configuration` to enter the menu to configure WIFI and password, and the rest of the options can be ignored
  5. Enter `q`, enter `y` after the pop-up window to exit and save the configuration
  6. Execute the command `idf.py build` to compile, if there is an error when compiling, please check the ESP-IDF environment (ESP-IDF version requires 5.1 or higher)
  7. Connect Halo to the computer via USB, check its COM, if not, please press and hold the **B** button on the back of Halo and then connect the USB
  8. Execute the command `idf.py -p COM14 flash` to burn the firmware, and replace COM14 with the actual port of Halo in your computer
  9. If you need to open the serial monitor, you can use the command `idf.py -p COM14 monitor`, if you need to open it automatically after burning, use `idf.py -p COM14 flash monitor`

## Peripheral pins

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


