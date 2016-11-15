/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2016 Yasir Khan
 * Email: yasir_electronics@yahoo.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef __LIB_SERIAL_H__
#define __LIB_SERIAL_H__

#include <termios.h>

typedef int32_t (*ready_to_read_callback_t)(int32_t fd);
typedef int32_t (*ready_to_write_callback_t)(int32_t fd);
typedef int32_t (*console_cmd_handler_t)(char *cmd_str, int16_t len);

int32_t serial_open(const char *name);
int32_t serial_close(int fd);
int32_t serial_setup(int fd, int baudrate);
int32_t serial_write(int fd, char *data, uint16_t len);
int32_t serial_read(int fd, char *data, int len);
int32_t serial_start(int32_t fd, ready_to_read_callback_t read_cb, ready_to_write_callback_t write_cb, console_cmd_handler_t command_handler);

#endif
