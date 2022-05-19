#include "display.h"

Display::Display(QString username)
{
    //遍历所有的数据库文件，并将数据库名加入到字符串中
    QString filePath = QCoreApplication::applicationDirPath() + "/data/" + username;
    QDir *dir = new QDir(filePath);
    QStringList filter;
    QList<QFileInfo> *fileInfo = new QList<QFileInfo>(dir->entryInfoList(filter));
    for(int i = 2; i<fileInfo->count(); i++)
    {
        //qDebug()<< fileInfo->at(i).fileName();
        if(fileInfo->at(i).fileName() == "database.txt")
        {
            continue;
        }
        this->displayText = this->displayText + fileInfo->at(i).fileName() + "\n";
        //遍历一个数据库中所有的表文件，并将表名加入到字符串中
        QString subPath = filePath +"/"+ fileInfo->at(i).fileName();
        QDir *subDir = new QDir(subPath);
        QStringList subFil;
        QList<QFileInfo> *subInfo = new QList<QFileInfo>(subDir->entryInfoList(subFil));
            for(int j = 2; j < subInfo->count(); j++)
            {
                //qDebug()<< "    "<<subInfo->at(j).fileName();
                if(subInfo->at(j).fileName() == "table.txt" || subInfo->at(j).fileName() == "logfile.log")
                {
                    continue;
                }
                this->displayText = this->displayText +"    " + subInfo->at(j).fileName() + "\n";
            }
    }
}

QString Display::getText()
{
    return this->displayText;
}

