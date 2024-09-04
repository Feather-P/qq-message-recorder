# qq-message-recorder

## 项目简介

`qq-message-recorder` 是一个使用 C++ 编写的练手项目，旨在~~给我自己练习摸鱼~~ 。该项目大概能够记录 QQ 消息，并提供简单的数据展示功能。

## 计划中的功能特性

- [x] 消息记录：自动记录指定 QQ 群聊的消息
- [x] 数据展示：以文本形式展示记录的消息内容
- [x] 界面简洁：提供简单的命令行界面，方便用户操作
- [x] 跨平台：支持 Windows、Linux 和 macOS 系统

## 环境要求

- 操作系统：Windows、Linux 或 macOS
- 编译器：支持 C++11 标准的编译器（如 GCC、Clang 或 Visual Studio）
- 依赖库：sqlite3

## 安装教程

1. 克隆项目到本地：

```
git clone https://github.com/Feather-P/qq-message-recorder.git
```

2. 进入项目目录：

```
cd qq-message-recorder
```

3. 配置vcpkg：
   
   见 https://learn.microsoft.com/zh-cn/vcpkg/https://learn.microsoft.com/zh-cn/vcpkg

4. 安装sqlite3依赖：

```
vcpkg install sqlite3
```

5. 编译项目：

```
cmake
```

6. 运行程序：

```
./qq-message-recorder
```

## To Do List

- [ ] 完善DAO层
- [ ] 完善业务逻辑层
- [ ] 对接Onebot标准的QQ Bot框架
- [ ] 支持消息记录
- [ ] 支持自定义消息记录保存路径
- [ ] 添加单元测试，提高代码质量
- [ ] 添加Web图形界面

## 许可证

本项目采用 MIT 许可证，详情请见 [LICENSE]文件。
