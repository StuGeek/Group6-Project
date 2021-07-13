# Group6

## 介绍

这是系统分析与设计第6组的项目仓库

## 软件架构

这是一个网格mesh软件，我们将为领域用户（领域程序员）开发一个面向对象的类库（我们称为网格应用程序开发系统）。类库应该是让领域用户在其网格应用程序中处理、编辑、存储、计算网格的基本基础。

## 目录说明

`code`文件夹里放着此次项目代码，其中`MeshApp`文件夹里是本次项目代码的完整版，带有图形界面，运行时要安装Visual Stdio和QT5，才能够顺利运行，具体运行效果和操作可以见`code`文件夹目录下的`test`视频文件。

如果运行环境配置不成功，也可以使用`MeshApp(No GUI)`文件夹目录下的不完整代码验证程序是可以跑通，在Windows命令行输入命令`g++ main.cpp data.cpp -o main -O3 -fopenmp`和`main`，或在Linux终端输入`make run`，都可以跑通程序，看代码效果。

`docx`文件夹下是项目工件的文档的集合，`markdown`文件夹下是项目工件的md文件的集合，其中包含一个`Artifects 工件(总).md`的文件，包含所有的工件，可以查看效果。
