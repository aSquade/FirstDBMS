# FirstDBMS
This is the first DBMS project we will build in the coming April and May.Wish there'll not be bugs!
使用什么网站托管项目？（github
使用何种语言？（C++
项目的分工？（图形界面1人（排除原始界面）、功能实现2人、网络连接1人……（待定
第一周的任务是？
DBMS要求：
1、有图形界面
2、能联网，有客户端和服务端通讯
3、基本功能：
a.创建删除数据库（数据库管理）
b.创建、修改、删除表（表管理）
c.增加、修改、删除字段（字段管理）
d.插入、更新、删除、查询记录（数据管理）
e.客户端管理：实现server和client功能，一个server可为多个client服务
f.事务管理（？）
g.完整性管理：实现完整性约束的检查与管理：主键、外键、check、unique、not null、default……
h.数据库维护与安全性管理：数据库备份与还原，用户管理、权限管理
i.索引管理：使用索引可以优化查询
4、数据库分为用户数据库和系统数据库，系统数据库是设计系统时必须自带的，不能删除
5、数据类型：integer、bool、double、varchar、datetime
6、文件管理：根目录：DBMS_ROOT。
7、存储：所有文件以二进制文件形式存储
8、数据库结构：数据库名称（name，char最大128），数据库类型（既系统or用户）（type，bool），
数据库数据文件夹全路径（filename，char最大256），创建时间（crtime，datetime）
