# Update

调整了针对性测试qlm的数据范围，新增了可生成负数id的方法

注：std.cpp由于使用了邻接矩阵存储图，含负数id的数据无法正确运行，根据需要可选择使用random.cpp第170/171行

# 仓库简介

本仓库提供BUAA-OO-2023 Homework11中qlm方法的针对性测试

同时提供Homework11除oktest指令外的随机数据生成器及对拍程序

## 使用说明

首先将本仓库克隆到本地，将你的程序导出为jar包

### 针对性测试qlm指令

将要测试的jar放入同目录下并重命名为mine.jar，直接运行check.cpp即可，其将与本人所写的std.cpp程序进行对拍, 仅测试ap、ar、qlm指令（采用最短路树实现）

### 随机生成其他指令

注：仅提供数据生成和对拍检查，无标程

请先将check.cpp中第18行取消注释，并注释掉第17行 同时把第20行的字符串改为fc out1.txt out2.txt

你需要在同目录下放入两个jar，分别命名为mine.jar 和 std.jar

将random.cpp中主函数部分的mode改为Valid，m=random(3000),然后单独运行一遍random.cpp(为了更新random.exe)

随后直接运行check.cpp即可对拍

## 注

以上使用说明仅供参考，由于该测试程序原先只在我本地做正确性检查，所以几乎没有任何封装，DIY空间很大同时使用也较繁琐，上述说明仅供只想简单对拍不想深究程序逻辑的朋友们参考
