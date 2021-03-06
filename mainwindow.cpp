 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createwindow.h"
#include "deletewindow.h"
#include "columnaddwindow.h"
#include "columnalterwindow.h"
#include "columndeletewindow.h"
#include "datainsertwindow.h"
#include "datadeletewindow.h"
#include "user.h"
#include "string"
#include "split.h"
#include "split.cpp"
#include "sheet.h"
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QWindow>
#include <QRegExp>
#include <QRegExpValidator>
#include "database.h"
#include "row.h"
#include "display.h"
#include <iostream>
#include <fstream>

using namespace std;
MainWindow::MainWindow(QString usrname,QString pow,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setStyleSheet("#MainWindow{border-image:url(:/pic/background.png)}");

    ui->createButton->setStyleSheet("QPushButton{image: url(:/pic/create1.png);}"
                                    "QPushButton:hover{image: url(:/pic/create.png);}");
    ui->createButton->setFlat(true);

    ui->deleteButton->setStyleSheet("QPushButton{image: url(:/pic/delete1.png);}"
                                    "QPushButton:hover{image: url(:/pic/delete.png);}");
    ui->deleteButton->setFlat(true);

    ui->addColumnButton->setStyleSheet("QPushButton{image: url(:/pic/addCol.png);}"
                                       "QPushButton:hover{image: url(:/pic/add.png);}");
    ui->addColumnButton->setFlat(true);

    ui->alterColumnBotton->setStyleSheet("QPushButton{image: url(:/pic/alterCol.png);}"
                                         "QPushButton:hover{image: url(:/pic/alter.png);}");
    ui->alterColumnBotton->setFlat(true);

    ui->deleteColumnButton->setStyleSheet("QPushButton{image: url(:/pic/delCol.png);}"
                                          "QPushButton:hover{image: url(:/pic/delete.png);}");
    ui->deleteColumnButton->setFlat(true);

    ui->insertDataButton->setStyleSheet("QPushButton{image: url(:/pic/insert1.png);}"
                                        "QPushButton:hover{image: url(:/pic/insert.png);}");
    ui->insertDataButton->setFlat(true);

    ui->deleteDataButton->setStyleSheet("QPushButton{image: url(:/pic/delData.png);}"
                                        "QPushButton:hover{image: url(:/pic/delete.png);}");
    ui->deleteDataButton->setFlat(true);

    ui->clearButton->setStyleSheet("QPushButton{image: url(:/pic/clear1.png);}"
                                   "QPushButton:hover{image: url(:/pic/clear.png);}");
    ui->clearButton->setFlat(true);

    ui->comfirmButton->setStyleSheet("QPushButton{image: url(:/pic/comfirm1.png);}"
                                     "QPushButton:hover{image: url(:/pic/comfirm.png);}");
    ui->comfirmButton->setFlat(true);
    //ui->refreshButton->setFlat(true);

    username=usrname;
    power = pow;
    this->display();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//?????? ???????????? ??????
void MainWindow::on_createButton_clicked()
{
    CreateWindow *c = new CreateWindow(username);
    c->setWindowModality(Qt::ApplicationModal);
    c->show();
}

//?????? ?????????" ??????
void MainWindow::on_deleteButton_clicked()
{
    DeleteWindow *d = new DeleteWindow(username);
    d->setWindowModality(Qt::ApplicationModal);
    d->show();
}

//?????? ????????????????????? ??????
void MainWindow::on_addColumnButton_clicked()
{
    ColumnAddWindow *c = new ColumnAddWindow(username);
    c->setWindowModality(Qt::ApplicationModal);
    c->show();
}

//?????? ????????????????????? ??????
void MainWindow::on_alterColumnBotton_clicked()
{
    ColumnAlterWindow *c = new ColumnAlterWindow(username);
    c->setWindowModality(Qt::ApplicationModal);
    c->show();
}

//?????? ????????????????????? ??????
void MainWindow::on_deleteColumnButton_clicked()
{
    ColumnDeleteWindow *c = new ColumnDeleteWindow(username);
    c->setWindowModality(Qt::ApplicationModal);
    c->show();
}

//?????? ?????????????????? ??????
void MainWindow::on_insertDataButton_clicked()
{
    DataInsertWindow *d = new DataInsertWindow(username);
    d->setWindowModality(Qt::ApplicationModal);
    d->show();
}

//?????? ?????????????????? ??????
void MainWindow::on_deleteDataButton_clicked()
{
    DataDeleteWindow *d = new DataDeleteWindow();
    d->setWindowModality(Qt::ApplicationModal);
    d->show();
}




void MainWindow::on_clearButton_clicked()
{
    ui->textInput->setText("");
}


void MainWindow::on_comfirmButton_clicked()
{
    QString strtext = ui->textInput->toPlainText();//????????????
    QStringList list = strtext.split(";");  //????????????????????????????????????

    QStringList list2;      //?????????
    list.removeAll(QString(""));    //???????????????????????????????????????????????????..????????????

    QString strExec = list.at(list.size()-1);//?????????????????????????????????????????????????????????
    const int acsize = list.size();     //?????????
    //qDebug() << strExec << endl;

    strExec = strExec.simplified(); //??????????????????????????????????????????????????????????????????1?????????
    strExec = strExec.toLower();
    QStringList strlist = strExec.split(" ");
    if(strlist.size() < 3){
        QMessageBox::information(this,"??????","??????????????????????????????",QMessageBox::Ok);
        for(int i =0;i<list.size()-1;i++){
            list2.append(list.at(i));
        }
        ui->textInput->clear();         //??????
        //for(int i = 0;i<acsize-1;i++){
            //ui->textInput->setText(list2.at(i)+';');
        //}

    }
    else
    {
        QString keyword = strlist[0];
        //qDebug() << keyword << endl;
        int opt1 = QString::compare(keyword, "create", Qt::CaseInsensitive);
        int opt2 = QString::compare(keyword, "drop", Qt::CaseInsensitive);  //ok
        int opt3 = QString::compare(keyword, "alter", Qt::CaseInsensitive);
        int opt4 = QString::compare(keyword, "insert", Qt::CaseInsensitive);//ok
        int opt5 = QString::compare(keyword, "delete", Qt::CaseInsensitive);//ok
        int opt6 = QString::compare(keyword, "select", Qt::CaseInsensitive);
        int opt7 = QString::compare(keyword, "rename", Qt::CaseInsensitive);//ok
        int opt8 = QString::compare(keyword, "open", Qt::CaseInsensitive);//ok
        int opt9 = QString::compare(keyword, "close", Qt::CaseInsensitive);//ok
        int opt10= QString::compare(keyword, "grant", Qt::CaseInsensitive);
        int opt11 = QString::compare(keyword, "revoke", Qt::CaseInsensitive);



        if(power ==  "admin power")//?????????????????????
        {
            int flag=0;
            //grant all privileges to ?????????;
            if (opt10 == 0)//grant
            {
               if(strlist[1]=="all" &&strlist[2]=="privileges"&&strlist[3]=="to")
               {
                   QString user_name = strlist[4];
                   //??????user.txt????????????
                   QString FileName = QCoreApplication::applicationDirPath();
                   QString pathName = FileName+"/data";//????????????????????????
                   QString fileName= pathName+"/"+"user.txt";//???????????????????????????

                   QFile file(fileName);
                   file.open(QIODevice::ReadWrite|QIODevice::Text);
                   if(file.isOpen())
                   {
                       //?????????????????????????????????
                       if(file.size()==0)
                       {
                           QMessageBox::information(this,"??????","???????????????",QMessageBox::Ok);   //???????????????????????????
                       }
                       else
                       {
                           QStringList lines;
                           QTextStream out(&file);
                           QString info;
                           while(!out.atEnd())
                            {
                                QString info = out.readLine();
                                QStringList information=info.split(":");

                                if(user_name!=information.at(0))
                                {
                                    //?????????????????????????????????????????????
                                    lines.push_back(info);
                                }
                                else
                                {
                                    //???????????????????????????
                                    flag=1;
                                    QString str=user_name+":"+information.at(1)+":"+"user power";//??????????????????
                                    lines.push_back(str);
                                }
                            }

                            file.remove();
                            if(flag==0)
                            {
                                file.close();

                            }
                            else
                            {
                                file.close();
                                QFile file2(fileName);
                                if(file2.open(QIODevice::WriteOnly | QIODevice::Text))
                                {
                                    QTextStream edit(&file2);
                                    for(int i=0;i<lines.size();i++)
                                    {
                                        edit<<lines[i]<<endl;
                                    }
                                      QMessageBox::information(this,"??????","???????????????",QMessageBox::Ok);
                                    file2.close();

                               }
                            }

                       }
                   }

               }

               else
               {
                    QMessageBox::information(this,"??????","??????????????????????????????",QMessageBox::Ok);
               }










            }
            else if (opt11 == 0)//revoke
            {
                //revoke all privileges
                //from ?????????;
                   if(strlist[1]=="all" &&strlist[2]=="privileges"&&strlist[3]=="from")
                   {
                       QString user_name = strlist[4];
                       QString FileName = QCoreApplication::applicationDirPath();
                       QString pathName = FileName+"/data";//????????????????????????
                       QString fileName= pathName+"/"+"user.txt";//???????????????????????????

                       QFile file(fileName);
                       file.open(QIODevice::ReadWrite|QIODevice::Text);
                       if(file.isOpen())
                       {
                           //?????????????????????????????????
                           if(file.size()==0)
                           {
                               QMessageBox::information(this,"??????","???????????????",QMessageBox::Ok);   //???????????????????????????
                           }
                           else
                           {
                               QStringList lines;
                               QTextStream out(&file);
                               QString info;
                               while(!out.atEnd())
                                {
                                    QString info = out.readLine();
                                    QStringList information=info.split(":");

                                    if(user_name!=information.at(0))
                                    {
                                        //?????????????????????????????????????????????
                                        lines.push_back(info);
                                    }
                                    else
                                    {
                                        //???????????????????????????
                                        flag=1;
                                        QString str=user_name+":"+information.at(1)+":"+"no power";//??????????????????
                                        lines.push_back(str);
                                    }
                                }

                                file.remove();
                                if(flag==0)
                                {
                                    file.close();
                                }
                                else
                                {
                                    file.close();
                                    QFile file2(fileName);
                                    if(file2.open(QIODevice::WriteOnly | QIODevice::Text))
                                    {
                                        QTextStream edit(&file2);
                                        for(int i=0;i<lines.size();i++)
                                        {
                                            edit<<lines[i]<<endl;
                                        }
                                        QMessageBox::information(this,"??????","?????????????????????",QMessageBox::Ok);
                                        file2.close();

                                   }
                                }

                           }
                       }

                   }

                   else
                   {
                        QMessageBox::information(this,"??????","??????????????????????????????",QMessageBox::Ok);
                   }

            }
            else
            {
                 QMessageBox::information(this,"??????","????????????????????????????????????????????????????????????",QMessageBox::Ok);
            }
        }
        else if(power == "no power")
        {
            QMessageBox::information(this,"??????","???????????????????????????????????????????????????",QMessageBox::Ok);
        }
        else if(power == "user power")
        {
            if (opt1 == 0){
                QStringList list1 = strExec.split(" ");
                if (list1[1] == "database"){
                    if (list1.size() == 3){
                        QString s = list1[2];//????????????????????????????????????

                        if(!variablecheck(s))
                        {
                            QMessageBox::question(this,
                            tr("error"),
                            tr("??????????????????????????????"),
                            QMessageBox::Ok | QMessageBox::Cancel,
                            QMessageBox::Ok);
                        }
                        //??????????????????,????????????????????????????????????????????????
                        Database db(username,s);
                        int chexists = db.check_dbexists(username,s);//????????????????????????
                        if(chexists==-1||chexists==-2){
                            QMessageBox::information(this,"??????","????????????????????????",QMessageBox::Ok);
                        }else if(chexists == 3){
                            QMessageBox::information(this,"??????","?????????????????????",QMessageBox::Ok);
                        }else{
                            //????????????database.txt?????????
                            int chdone = db.db_write(username,s);
                            if(chdone==1){
                                //????????????
                                QMessageBox::information(this,"??????","????????????????????????",QMessageBox::Ok);
                            }else if(chdone==-2){
                                QMessageBox::information(this,"??????","?????????????????????",QMessageBox::Ok);
                            }
                            else{
                                QMessageBox::information(this,"??????","????????????????????????",QMessageBox::Ok);
                            }
                        }

                        //split here
                    }else{
                        QMessageBox::information(this,"??????","??????????????????",QMessageBox::Ok);
                    }


                }else if (list1[1] == "table"){


                    int size_ = list1.size();


                    if (list1[size_-2] != "database"){
                        QMessageBox::information(this,"??????","??????????????????",QMessageBox::Ok);

                    }else{

                        QString db_name = list1[size_-1];
                        QString tail = list1[size_-1] + list1[size_-2] + list1[size_-3];
                        int tail_ = tail.length() + 3;
                        strExec = strExec.left(strExec.size() - tail_);
                        list1 = strExec.split(" ");

                        //??????
                        QString dbName = db_name;
                        QString pathName = QCoreApplication::applicationDirPath()+"/data/"+username+"/"+dbName;
                        QString fileName =  pathName+"/logfile.log";
                        QFile file(fileName);
                        file.open(QIODevice::Append|QIODevice::Text);
                        if(file.isOpen())
                        {
                             QFileInfo info(fileName);
                             //QString str = info.birthTime().toString();
                             QString lastModified = info.lastModified().toString();
                             QString dbInfo = username+"#"+dbName+"#"+ pathName+"#"+lastModified+"#"+strExec+"#"+"??????";//#???????????????
                             QTextStream out(&file);//??????
                             out << dbInfo<<endl;
                             file.close();
                        }
                        else
                        {
                            //?????????????????????????????????
                            file.close();
                        }
                        QString col_name = "";
                        QString col_type = "";
                        QString check_name = "";
                        QString check = "";

                        if (list1.size() < 4){
                            QMessageBox::information(this,"??????","??????????????????",QMessageBox::Ok);
                        }else{
                            QStringList list2 = list1[2].split("(");
                            QString tbl_name = list2[0].simplified();

                            qDebug() << tbl_name << endl;

                            QString str1 = strExec.right(strExec.size() - 14 - tbl_name.size());
                            QString str2 = str1.left(str1.size() - 1).simplified();

                            QStringList list3 = str2.split(",");
                            for (int var = 0; var < list3.size(); ++var) {
                                list3[var] = list3[var].simplified();

                                QStringList list4 = list3[var].split(" ");

                                if (list4.size() < 2){
                                    QMessageBox::information(this,"??????","??????????????????",QMessageBox::Ok);
                                    break;
                                }else{

                                    col_name = list4[0];
                                    col_type = list4[1];


                                    if (col_type != "integer" && col_type != "bool" && col_type != "double" && col_type != "varchar" && col_type != "datetime"){
                                        QMessageBox::information(this,"??????","??????????????????",QMessageBox::Ok);
                                        break;
                                    }

                                    if (list4.size() == 3){
                                        if (list4[2] == "unique"){
                                            check_name = "unique";
                                        }else{
                                            if (list4[2].split("(")[0] == "check"){
                                                check_name = "check";
                                                check = list4[2].split("(")[1].left(list4[2].split("(")[1].size() - 1);
                                            }else{
                                                QMessageBox::information(this,"??????","??????????????????",QMessageBox::Ok);
                                                break;
                                            }
                                        }
                                    }else if (list4.size() == 2){
                                    }
                                    else if (list4.size() == 4){
                                        QString ap1 = list4[2]+list4[3];
                                        if (ap1 == "primarykey" || ap1 == "notnull"){
                                            check_name = list4[2]+" "+list4[3];
                                        }else{
                                            QMessageBox::information(this,"??????","??????????????????",QMessageBox::Ok);
                                            break;
                                        }
                                    }else if (list4.size() == 6){
                                        QString ap2 = list4[2]+list4[3];
                                        if (ap2 == "foreignkey"){
                                            check_name = "foreign key";
                                            check = list4[4]+" "+list4[5];
                                        }else{
                                            QMessageBox::information(this,"??????","??????????????????",QMessageBox::Ok);
                                            break;
                                        }
                                    }else{
                                        QMessageBox::information(this,"??????","??????????????????",QMessageBox::Ok);
                                        break;
                                    }
                                }

                                //add here

                                if(!variablecheck(tbl_name))
                                {
                                    QMessageBox::question(this,
                                    tr("error"),
                                    tr("????????????????????????"),
                                    QMessageBox::Ok | QMessageBox::Cancel,
                                    QMessageBox::Ok);
                                }
                                table tbl(username, db_name, tbl_name); //??????????????????,???????????????????????????????????????????????????
                                int db_exists = tbl.db_exists(username,db_name);//????????????????????????
                                if(db_exists!=-1)
                                {
                                    QMessageBox::information(this,"??????","????????????????????????????????????????????????",QMessageBox::Ok);
                                }
                                else
                                {
                                    int tbl_exists = tbl.tbl_exists(username,db_name,tbl_name);//????????????????????????
                                    if(tbl_exists==-1)
                                    {
                                        QMessageBox::information(this,"??????","??????????????????",QMessageBox::Ok);
                                    }
                                    else
                                    {
                                        //????????????table.txt?????????
                                        int chdone = tbl.table_in(username,db_name,tbl_name,col_name,col_type,check_name,check);
                                        if(chdone==-1)
                                        {
                                            //????????????
                                            QMessageBox::information(this,"??????","??????????????????",QMessageBox::Ok);
                                        }
                                        else
                                        {
                                            QMessageBox::information(this,"??????","??????????????????",QMessageBox::Ok);
                                        }
                                   }

                                }
                            }

                            qDebug() << str2 << endl;
                            qDebug() << col_name << endl;
                            qDebug() << col_type << endl;
                            qDebug() << check_name << endl;
                            qDebug() << check << endl;
                            qDebug() << tail << endl;

                        }
                    }

                }else if (list1[1] == "index"){

                    int size_ = list1.size();
                    if (list1[size_-2] != "database" || size_<8){
                        QMessageBox::information(this,"??????","??????????????????",QMessageBox::Ok);
                    }else{

                        QString dbName = list1[size_-1];
                        QString tail = list1[size_-1] + list1[size_-2] + list1[size_-3];
                        int tail_ = tail.length() + 3;
                        strExec = strExec.left(strExec.size() - tail_);
                        list1 = strExec.split(" ");


                        QString pathName = QCoreApplication::applicationDirPath()+"/data/"+username+"/"+dbName;
                        QString fileName =  pathName+"/logfile.log";
                        QFile file(fileName);
                        file.open(QIODevice::Append|QIODevice::Text);
                        if(file.isOpen())
                        {
                             QFileInfo info(fileName);
                             //QString str = info.birthTime().toString();
                             QString lastModified = info.lastModified().toString();
                             QString dbInfo = username+"#"+dbName+"#"+ pathName+"#"+lastModified+"#"+strExec+"#"+"??????";//#???????????????
                             QTextStream out(&file);//??????
                             out << dbInfo<<endl;
                             file.close();
                        }
                        else
                        {
                            //?????????????????????????????????
                            file.close();
                        }
                        if (list1.size() >= 5 && list1[3] == "on"){
                            QString idxName = list1[2];
                            QStringList list5 = list1[4].split("(");
                            QString tblName = list5[0];
                            QString colName = list5[1].left(list5[1].size() - 1);

                            table tbl(username, dbName, tblName); //??????????????????,???????????????????????????????????????????????????
                            int db_exists = tbl.db_exists(username,dbName);//????????????????????????
                            if(db_exists!=-1)
                            {
                                QMessageBox::information(this,"??????","????????????????????????????????????????????????",QMessageBox::Ok);
                            }
                            else
                            {
                                int tbl_exists = tbl.tbl_exists(username,dbName,tblName);//????????????????????????
                                if(tbl_exists==1)
                                {
                                    QMessageBox::information(this,"??????","????????????????????????????????????",QMessageBox::Ok);
                                }
                                else
                                {
                                    QString FileName = QCoreApplication::applicationDirPath();
                                    QString pathName = FileName+"/data/"+username+"/"+dbName+"/"+tblName+"/"+tblName+".tid";//??????????????????

                                    QFile file(pathName);

                                    QDir dir;

                                    file.open(QIODevice::Append|QIODevice::Text);

                                    if(file.isOpen()){
                                         QFileInfo info(pathName);

                                         QString dbInfo = idxName+"#"+tblName+"#"+colName;

                                         QTextStream out(&file);//??????

                                         out << dbInfo<<endl;

                                         file.close();
                                         QMessageBox::information(this,"??????","?????????????????????",QMessageBox::Ok);
                                    }
                                }
                            }


                        }else{
                            QMessageBox::information(this,"??????","??????????????????",QMessageBox::Ok);
                        }
                    }
                //
                }else{
                    QMessageBox::information(this,"??????","??????????????????",QMessageBox::Ok);
                }

            }
            else if (opt2 == 0)//drop
            {
                QString type = strlist[1];
                if(type == "database")//?????????(?????????open???????????????????????????????????????
                {
                    QString s =  strlist[2];
                    Database db(username,s);
                    int chexists = db.check_dbexists(username,s);//????????????????????????

                    if(chexists==-1)
                    {
                        //????????????????????????????????????
                        QString dbName = s;
                        QString pathName = QCoreApplication::applicationDirPath()+"/data/"+username+"/"+dbName;
                        QString fileName =  pathName+"/logfile.log";
                        QFile file(fileName);
                        file.open(QIODevice::Append|QIODevice::Text);
                        if(file.isOpen())
                        {
                             QFileInfo info(fileName);
                             //QString str = info.birthTime().toString();
                             QString lastModified = info.lastModified().toString();
                             QString dbInfo = username+"#"+dbName+"#"+ pathName+"#"+lastModified+"#"+strExec+"#"+"??????";//#???????????????
                             QTextStream out(&file);//??????
                             out << dbInfo<<endl;
                             file.close();
                        }
                        else
                        {
                            //?????????????????????????????????
                            file.close();
                        }
                        db.db_out(username,s);
                        QMessageBox::information(this,"??????","???????????????",QMessageBox::Ok);
                    }
                    else
                    {
                        QMessageBox::information(this,"??????","????????????????????????",QMessageBox::Ok);
                    }
                    ui->textInput->clear();
                }
                else if (type == "table" && strlist[3]== "in" && strlist[4]=="database")//?????????
                {
                    QString s =  strlist[2];//??????????????????????????????
                    QString d =  strlist[5];//???????????????????????????????????????

                    QString dbName = d;
                    QString pathName = QCoreApplication::applicationDirPath()+"/data/"+username+"/"+dbName;
                    QString fileName1 =  pathName+"/logfile.log";
                    QFile file(fileName1);
                    file.open(QIODevice::Append|QIODevice::Text);
                    if(file.isOpen())
                    {
                         QFileInfo info(fileName1);
                         //QString str = info.birthTime().toString();
                         QString lastModified = info.lastModified().toString();
                         QString dbInfo = username+"#"+dbName+"#"+ pathName+"#"+lastModified+"#"+strExec+"#"+"??????";//#???????????????
                         QTextStream out(&file);//??????
                         out << dbInfo<<endl;
                         file.close();
                    }
                    else
                    {
                        //?????????????????????????????????
                        file.close();
                    }
                    QString FileName = QCoreApplication::applicationDirPath();
                    QString strPath = FileName+"/data/"+username+"/"+d;
                    QString fileName = strPath+"table.txt";

                    table tbl(username,d,s);
                    int tbl_exists = tbl.tbl_exists(username,d,s);//????????????????????????
                    if(tbl_exists==-1)
                    {
                        //??????????????????????????????
                        tbl.table_out(username,d,s);
                        QMessageBox::information(this,"??????","???????????????",QMessageBox::Ok);
                    }
                    else
                    {
                        QMessageBox::information(this,"??????","??????????????????",QMessageBox::Ok);
                    }
                    ui->textInput->clear();


                }
                //drop index ????????? on ?????? in database ????????????
                              else if(type == "index"&&strlist[3] =="on"&&strlist[5]=="in"&&strlist[6]=="database" )
                              {
                                  QString s =  strlist[4];//??????????????????????????????
                                  QString d =  strlist[7];//???????????????????????????????????????
                                  QString x =  strlist[2];//?????????
                                  //??????
                                  QString dbName = d;
                                  QString pathName = QCoreApplication::applicationDirPath()+"/data/"+username+"/"+dbName;
                                  QString fileName =  pathName+"/logfile.log";
                                  QFile file(fileName);
                                  file.open(QIODevice::Append|QIODevice::Text);
                                  if(file.isOpen())
                                  {
                                       QFileInfo info(fileName);
                                       //QString str = info.birthTime().toString();
                                       QString lastModified = info.lastModified().toString();
                                       QString dbInfo = username+"#"+dbName+"#"+ pathName+"#"+lastModified+"#"+strExec+"#"+"??????";//#???????????????
                                       QTextStream out(&file);//??????
                                       out << dbInfo<<endl;
                                       file.close();
                                  }
                                  else
                                  {
                                      //?????????????????????????????????
                                      file.close();
                                  }


                                  QString FileName = QCoreApplication::applicationDirPath();
                                  QString pathName1 = FileName+"/data/"+username+"/"+dbName+"/"+s;//?????????????????????
                                  QString fileName1= pathName1+"/"+s+".tid";//????????????????????????
                                  QFile inputfile(fileName1);
                                  QStringList lines;

                                  inputfile.open(QIODevice::ReadWrite|QIODevice::Text);
                                  if(inputfile.isOpen())
                                  {
                                      QTextStream out(&inputfile);
                                      QString data;
                                       while(!out.atEnd())
                                       {
                                           data = out.readLine();
                                           QStringList info=data.split("#");
                                           if(x!=info.at(0))
                                           {
                                               //??????????????????????????????????????????
                                              lines.push_back(data);
                                           }
                                      }
                                       inputfile.remove();
                                       QFile outputfile(fileName1);
                                       if(outputfile.open(QIODevice::WriteOnly | QIODevice::Text))
                                       {
                                               QTextStream edit(&outputfile);
                                               for(int i=0;i<lines.size();i++)
                                               {
                                                   edit<<lines[i]<<endl;
                                               }
                                               outputfile.close();
                                               QMessageBox::information(this,"??????","?????????????????????",QMessageBox::Ok);
                                       }


                                  }


                              }
                              else//???????????????????????????
                              {
                                  QMessageBox::information(this,"??????","??????????????????????????????",QMessageBox::Ok);
                                  ui->textInput->clear();
                              }


            }
            else if (opt3 == 0)
            {
                QStringList list_0 = strExec.split(" ");
                if (list_0[list_0.size() - 2] == "database" && list_0[list_0.size() - 3] == "in"){

                    QString dbName = list_0[list_0.size() - 1];
                    QString tail = list_0[list_0.size() - 3]+list_0[list_0.size() - 2]+list_0[list_0.size() - 1];
                    strExec = strExec.left(strExec.length() - tail.length() - 3);

                    QString pathName = QCoreApplication::applicationDirPath()+"/data/"+username+"/"+dbName;
                    QString fileName =  pathName+"/logfile.log";
                    QFile file(fileName);
                    file.open(QIODevice::Append|QIODevice::Text);
                    if(file.isOpen())
                    {
                         QFileInfo info(fileName);
                         //QString str = info.birthTime().toString();
                         QString lastModified = info.lastModified().toString();
                         QString dbInfo = username+"#"+dbName+"#"+ pathName+"#"+lastModified+"#"+strExec+"#"+"??????";//#???????????????
                         QTextStream out(&file);//??????
                         out << dbInfo<<endl;
                         file.close();
                    }
                    else
                    {
                        //?????????????????????????????????
                        file.close();
                    }
                    qDebug() << tail << endl;
                    qDebug() << strExec << endl;

                    QStringList list_1 = strExec.split(" ");
                    if (list_1.size() < 6 || list_1[1] != "table"){
                        QMessageBox::information(this,"??????","??????????????????",QMessageBox::Ok);
                    }else if(list_1.size() == 6){
                        QString tblName = list_1[2];

                        if (list_1[3] == "drop" && list_1[4] == "column"){
                            QString colName = list_1[5];
                            //add here
                            //qDebug() << "drop" + col_name << endl;
                            QString FileName = QCoreApplication::applicationDirPath();
                            QString pathName = FileName+"/data/"+username+"/"+dbName+"/"+tblName ;//??????????????????
                            QString fileName1 = pathName+"/"+tblName+".tdf";
                            QString fileName2 = pathName+"/"+tblName+".tic";
                            QString delPath = QString(pathName);

                            QFile inputfile1(fileName1);
                            QFile inputfile2(fileName2);

                            QStringList lines;

                            inputfile1.open(QIODevice::ReadWrite|QIODevice::Text);
                            inputfile2.open(QIODevice::ReadWrite|QIODevice::Text);

                            if(inputfile1.isOpen()&&inputfile2.isOpen()){
                                QTextStream out1(&inputfile1);
                                QTextStream out2(&inputfile2);

                                QString data1;
                                QString data2;

                                 while(!out1.atEnd()){
                                     data1 = out1.readLine();
                                     QStringList data_=data1.split("#");
                                     if(colName!=data_.at(0)){
                                         //??????????????????????????????????????????
                                        lines.push_back(data1);
                                     }
                                }

                                 while(!out2.atEnd()){
                                     data2 = out2.readLine();
                                     QStringList data_=data2.split("#");
                                     if(colName!=data_.at(0)){
                                         //??????????????????????????????????????????
                                        lines.push_back(data2);
                                     }
                                }

                                 inputfile1.remove();
                                 inputfile2.remove();

                                 QFile outputfile1(fileName1);
                                 QFile outputfile2(fileName2);

                                 if(outputfile1.open(QIODevice::WriteOnly | QIODevice::Text))
                                 {
                                         QTextStream edit(&outputfile1);
                                         for(int i=0;i<lines.size();i++){
                                         edit<<lines[i]<<endl;
                                 }
                                         outputfile1.close();
                            }
                                 if(outputfile2.open(QIODevice::WriteOnly | QIODevice::Text))
                                 {
                                         QTextStream edit(&outputfile2);
                                         for(int i=0;i<lines.size();i++){
                                         edit<<lines[i]<<endl;
                                 }
                                         outputfile2.close();
                            }

                                 QDir qDir(delPath);

                            }
                            QMessageBox::information(this,"??????","???????????????",QMessageBox::Ok);

                        }else{
                            QMessageBox::information(this,"??????","??????????????????",QMessageBox::Ok);
                        }

                    }else if(list_1.size() == 7){
                        QString tblName = list_1[2];
                        QString colName = list_1[5];
                        QString colType = list_1[6];

                        if (list_1[4] == "column"){
                            if (list_1[3] == "add"){
                                table tbl(username, dbName, tblName); //??????????????????,???????????????????????????????????????????????????
                                int db_exists = tbl.db_exists(username,dbName);//????????????????????????
                                if(db_exists!=-1)
                                {
                                    QMessageBox::information(this,"??????","????????????????????????????????????????????????",QMessageBox::Ok);
                                }
                                else
                                {
                                    int tbl_exists = tbl.tbl_exists(username,dbName,tblName);//????????????????????????
                                    if(tbl_exists==1)
                                    {
                                        QMessageBox::information(this,"??????","????????????????????????????????????",QMessageBox::Ok);
                                    }
                                    else
                                    {
                                        QString FileName = QCoreApplication::applicationDirPath();
                                        QString pathName = FileName+"/data/"+username+"/"+dbName+"/"+tblName+"/"+tblName+".tdf";//??????????????????

                                        QFile file(pathName);

                                        QDir dir;

                                        file.open(QIODevice::Append|QIODevice::Text);

                                        if(file.isOpen()){
                                             QFileInfo info(pathName);

                                             QString dbInfo = colName + "#" + colType;

                                             QTextStream out(&file);//??????

                                             out << dbInfo<<endl;

                                             file.close();
                                             QMessageBox::information(this,"??????","???????????????",QMessageBox::Ok);
                                        }
                                    }
                                }
                                //qDebug() << "add" + col_name << endl;


                            }else if (list_1[3] == "modify"){
                                QString FileName = QCoreApplication::applicationDirPath();
                                QString pathName = FileName+"/data/"+username+"/"+dbName+"/"+tblName ;//??????????????????
                                QString fileName = pathName+"/"+tblName+".tdf";
                                QString delPath = QString(pathName);

                                QFile inputfile(fileName);

                                QStringList lines;

                                inputfile.open(QIODevice::ReadWrite|QIODevice::Text);

                                if(inputfile.isOpen()){
                                    QTextStream out(&inputfile);

                                    QString data;

                                     while(!out.atEnd()){
                                         data = out.readLine();
                                         QStringList data_=data.split("#");
                                         if(colName!=data_.at(0)){
                                             //??????????????????????????????????????????
                                            lines.push_back(data);
                                         }
                                    }

                                     inputfile.remove();

                                     QFile outputfile(fileName);

                                     if(outputfile.open(QIODevice::WriteOnly | QIODevice::Text))
                                     {
                                             QTextStream edit(&outputfile);
                                             for(int i=0;i<lines.size();i++){
                                             edit<<lines[i]<<endl;
                                     }
                                             outputfile.close();
                                }

                                     QDir qDir(delPath);

                                }

                                table tbl(username, dbName, tblName); //??????????????????,???????????????????????????????????????????????????
                                int db_exists = tbl.db_exists(username,dbName);//????????????????????????
                                if(db_exists!=-1)
                                {
                                    QMessageBox::information(this,"??????","????????????????????????????????????????????????",QMessageBox::Ok);
                                }
                                else
                                {
                                    int tbl_exists = tbl.tbl_exists(username,dbName,tblName);//????????????????????????
                                    if(tbl_exists==1)
                                    {
                                        QMessageBox::information(this,"??????","????????????????????????????????????",QMessageBox::Ok);
                                    }
                                    else
                                    {
                                        QString FileName = QCoreApplication::applicationDirPath();
                                        QString pathName = FileName+"/data/"+username+"/"+dbName+"/"+tblName+"/"+tblName+".tdf";//??????????????????

                                        QFile file(pathName);

                                        QDir dir;

                                        file.open(QIODevice::Append|QIODevice::Text);

                                        if(file.isOpen()){
                                             QFileInfo info(pathName);

                                             QString dbInfo = colName + "#" + colType;

                                             QTextStream out(&file);//??????

                                             out << dbInfo<<endl;

                                             file.close();
                                             QMessageBox::information(this,"??????","???????????????",QMessageBox::Ok);
                                        }
                                    }
                                }




                            }else{
                                QMessageBox::information(this,"??????","??????????????????",QMessageBox::Ok);
                            }
                        }else{
                            QMessageBox::information(this,"??????","??????????????????",QMessageBox::Ok);
                        }

                    }else{
                        QMessageBox::information(this,"??????","??????????????????",QMessageBox::Ok);
                    }
                }else{
                    QMessageBox::information(this,"??????","??????????????????",QMessageBox::Ok);
                }
            }
            //insert
            else if (opt4 == 0)//insert into ?????????(?????????,?????????...)???values(???,???,???...) in database ??????;??????????????????????????????????????????????????????//?????????????????????
            {
                //insert into ?????? (??????) values (?????????) in database ??????;//????????????
                if(strlist[1] == "into" &&  strlist[4] == "values"&& strlist[6] == "in"&& strlist[7] == "database")
                {

                    QString tbl_name =  strlist[2];//??????????????????????????????
                    QString col_name  = strlist[3];//??????????????????????????????
                    col_name.replace(")","");//????????????
                    col_name.replace("(","");
                    QStringList col_list = col_name.split(",");//???????????????
                    QString data_item  =  strlist[5];//????????????????????????
                    data_item.replace(")","");//????????????
                    data_item.replace("(","");
                    data_item.replace("'","");//???????????????
                    QStringList data_list = data_item.split(",");//???????????????
                    QString db_name  =  strlist[8];//???????????????????????????????????????

                    QString dbName = db_name;
                    QString pathName = QCoreApplication::applicationDirPath()+"/data/"+username+"/"+dbName;
                    QString fileName =  pathName+"/logfile.log";
                    QFile file(fileName);
                    file.open(QIODevice::Append|QIODevice::Text);
                    if(file.isOpen())
                    {
                         QFileInfo info(fileName);
                         //QString str = info.birthTime().toString();
                         QString lastModified = info.lastModified().toString();
                         QString dbInfo = username+"#"+dbName+"#"+ pathName+"#"+lastModified+"#"+strExec+"#"+"??????";//#???????????????
                         QTextStream out(&file);//??????
                         out << dbInfo<<endl;
                         file.close();
                    }
                    else
                    {
                        //?????????????????????????????????
                        file.close();
                    }
                    if(data_list.length()==col_list.length()) //???????????????????????????????????????
                    {
                            row rw(username, db_name, tbl_name,col_list,data_list); //??????????????????,??????????????????????????????????????????????????????
                            int db_exists = rw.db_exists(username,db_name);//????????????????????????
                            if(db_exists!=-1)
                            {
                                QMessageBox::information(this,"??????","????????????????????????????????????????????????",QMessageBox::Ok);
                            }
                            else
                            {
                                    int tbl_exists = rw.tbl_exists(username,db_name,tbl_name);//????????????????????????
                                    if(tbl_exists==-1)
                                    {
                                           int col_exists = rw.col_exists(username,db_name,tbl_name,col_list);//????????????????????????
                                           {
                                                 if(col_exists!=-1)
                                                 {
                                                      QMessageBox::information(this,"??????","????????????????????????????????????",QMessageBox::Ok);
                                                 }
                                                 else  //?????????????????????
                                                 {
                                                     int chdone = rw.row_in(username,db_name,tbl_name,col_list,data_list);
                                                     if(chdone==-1)
                                                     {
                                                         //????????????
                                                         QMessageBox::information(this,"??????","?????????????????????",QMessageBox::Ok);
                                                     }
                                                     else
                                                     {
                                                         QMessageBox::information(this,"??????","?????????????????????",QMessageBox::Ok);
                                                     }
                                                 }
                                           }
                                    }
                                    else
                                    {
                                         QMessageBox::information(this,"??????","??????????????????",QMessageBox::Ok);
                                    }
                           }

                       }

                   else
                {
                    QMessageBox::information(this,"??????","?????????????????????????????????",QMessageBox::Ok);

                }
                ui->textInput->clear();
             }
                //insert into ?????? values (?????????) in database ??????;//??????????????????????????????
                else if(strlist[1] == "into" &&  strlist[3] == "values"&& strlist[5] == "in"&& strlist[6] == "database")
                {
                    QString tbl_name =  strlist[2];//??????????????????????????????
                    QString data_item  =  strlist[4];//????????????????????????
                    data_item.replace(")","");//???????????????
                    data_item.replace("(","");//???????????????
                    data_item.replace("'","");//???????????????
                    QStringList data_list = data_item.split(",");//???????????????
                    QString db_name  =  strlist[7];//???????????????????????????????????????
                    QStringList col_list;

                    QString dbName = db_name;
                    QString pathName1 = QCoreApplication::applicationDirPath()+"/data/"+username+"/"+dbName;
                    QString fileName1=  pathName1+"/logfile.log";
                    QFile file1(fileName1);
                    file1.open(QIODevice::Append|QIODevice::Text);
                    if(file1.isOpen())
                    {
                         QFileInfo info(fileName1);
                         //QString str = info.birthTime().toString();
                         QString lastModified = info.lastModified().toString();
                         QString dbInfo = username+"#"+dbName+"#"+ pathName1+"#"+lastModified+"#"+strExec+"#"+"??????";//#???????????????
                         QTextStream out(&file1);//??????
                         out << dbInfo<<endl;
                         file1.close();
                    }
                    else
                    {
                        //?????????????????????????????????
                        file1.close();
                    }
                    //??????????????????
                    QString FileName = QCoreApplication::applicationDirPath();
                    QString pathName = FileName+"/data/"+username+"/"+db_name+"/"+tbl_name;//?????????????????????
                    QString fileName= pathName+"/"+tbl_name+".tdf";//????????????????????????
                    QFile file(fileName);
                    int num = 0;
                    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                    {
                          QMessageBox::information(this,"??????","??????????????????",QMessageBox::Ok);
                    }
                    QTextStream in(&file);
                    while (!in.atEnd())
                    {
                          QString line = in.readLine();
                          QStringList oneline = line.split('#');
                          col_list.append(oneline[0]);
                          num++;
                    }
                    if(data_list.length()==num) //???????????????????????????????????????
                    {

                                row rw(username, db_name, tbl_name,col_list,data_list); //??????????????????,??????????????????????????????????????????????????????
                                int db_exists = rw.db_exists(username,db_name);//????????????????????????
                                if(db_exists!=-1)
                                {
                                    QMessageBox::information(this,"??????","????????????????????????????????????????????????",QMessageBox::Ok);
                                }
                                else
                                {
                                        int tbl_exists = rw.tbl_exists(username,db_name,tbl_name);//????????????????????????
                                        if(tbl_exists==-1)
                                        {
                                               int col_exists = rw.col_exists(username,db_name,tbl_name,col_list);//????????????????????????
                                               {
                                                     if(col_exists!=-1)
                                                     {
                                                          QMessageBox::information(this,"??????","????????????????????????????????????",QMessageBox::Ok);
                                                     }
                                                     else  //?????????????????????
                                                     {
                                                         int chdone = rw.row_in(username,db_name,tbl_name,col_list,data_list);
                                                         if(chdone==-1)
                                                         {
                                                             //????????????
                                                             QMessageBox::information(this,"??????","?????????????????????",QMessageBox::Ok);
                                                         }
                                                         else
                                                         {
                                                             QMessageBox::information(this,"??????","?????????????????????",QMessageBox::Ok);
                                                         }
                                                     }
                                               }
                                        }
                                        else
                                        {
                                             QMessageBox::information(this,"??????","??????????????????",QMessageBox::Ok);
                                        }
                               }

                    }
                    else
                   {
                                QMessageBox::information(this,"??????","?????????????????????????????????",QMessageBox::Ok);
                   }
                   ui->textInput->clear();

            }
                 ui->textInput->clear();

    }
            else if (opt5 == 0)//delete
            {
                //delete from ?????? where ?????? = ??? in database ?????????
                if(strlist[1] == "from" && strlist[3]=="where" && strlist[5]=="="&&strlist[7]=="in"&&strlist[8]=="database")
                {
                    QString tblName = strlist[2];//??????
                    QString colName =  strlist[4];//??????
                    QString dataItem =  strlist[6];//'???'
                    dataItem.replace("'","");//???????????????
                    QString dbName = strlist[9];//????????????
                    QStringList col_name;
                    col_name.append(colName);
                    QStringList data_item;
                    data_item.append(dataItem);


                    QString pathName = QCoreApplication::applicationDirPath()+"/data/"+username+"/"+dbName;
                    QString fileName =  pathName+"/logfile.log";
                    QFile file(fileName);
                    file.open(QIODevice::Append|QIODevice::Text);
                    if(file.isOpen())
                    {
                         QFileInfo info(fileName);
                         //QString str = info.birthTime().toString();
                         QString lastModified = info.lastModified().toString();
                         QString dbInfo = username+"#"+dbName+"#"+ pathName+"#"+lastModified+"#"+strExec+"#"+"??????";//#???????????????
                         QTextStream out(&file);//??????
                         out << dbInfo<<endl;
                         file.close();
                    }
                    else
                    {
                        //?????????????????????????????????
                        file.close();
                    }
                    row rw(username,dbName,tblName,col_name,data_item);
                    int tbl_exists = rw.tbl_exists(username,dbName,tblName);//????????????????????????
                    if(tbl_exists==-1) //???????????????
                    {

                        int col_exists = rw.col_exists(username,dbName,tblName,col_name);//????????????????????????
                        if(col_exists==-1) //?????????????????????????????????
                        {
                             int row_exists = rw.row_exists(username,dbName,tblName,col_name,data_item);//????????????????????????
                             if(row_exists==-1)//?????????????????????
                            {
                                rw.row_out(username,dbName,tblName,col_name,data_item);
                                QMessageBox::information(this,"??????","???????????????",QMessageBox::Ok);
                            }
                            else
                             {
                                   QMessageBox::information(this,"??????","???????????????????????????",QMessageBox::Ok);
                             }

                        }
                        else
                        {
                            QMessageBox::information(this,"??????","?????????????????????",QMessageBox::Ok);
                        }

                    }
                    else
                    {
                        QMessageBox::information(this,"??????","??????????????????",QMessageBox::Ok);
                    }


                }
                ui->textInput->clear();


            }
            else if (opt6 == 0)
            {
                Sheet t = select_(strExec,username);
                ui->tableWidget->clear();
                ui->tableWidget->setColumnCount(t.getHead().size());//????????????
                ui->tableWidget->setRowCount(t.getData().size());//????????????
                for(int i = 0;i<t.getData().size();i++){
                    for(int j = 0;j<t.getHead().size();j++){
                        //??????
                        ui->tableWidget->setHorizontalHeaderItem(
                                    j,new QTableWidgetItem(
                                        t.getHead()[j].get_name()));
                        if(t.getData()[i][j] ==NULL){
                            ui->tableWidget->setItem(i,j,new QTableWidgetItem(""));
                        }else{
                            ui->tableWidget->setItem(i,j,new QTableWidgetItem(t.getData()[i][j]));
                        }
                    }
                }
                ui->textInput->clear();
            }
            else if(opt7 == 0)
            {
                //rename database ?????? to ??????;
                //rename table ?????? to ?????? in database ??????;
                QString type = strlist[1];
                if(type == "database" && strlist[3]=="to")
                {
                    Database db(username,strlist[4]);
                    QString dbName = strlist[4];
                    QString pathName = QCoreApplication::applicationDirPath()+"/data/"+username+"/"+dbName;
                    QString fileName =  pathName+"/logfile.log";
                    QFile file(fileName);
                    file.open(QIODevice::Append|QIODevice::Text);
                    if(file.isOpen())
                    {
                         QFileInfo info(fileName);
                         //QString str = info.birthTime().toString();
                         QString lastModified = info.lastModified().toString();
                         QString dbInfo = username+"#"+dbName+"#"+ pathName+"#"+lastModified+"#"+strExec+"#"+"??????";//#???????????????
                         QTextStream out(&file);//??????
                         out << dbInfo<<endl;
                         file.close();
                    }
                    else
                    {
                        //?????????????????????????????????
                        file.close();
                    }
                    int op = db.rename_database(username, strlist[2], strlist[4]);
                    if(op==1){
                        QMessageBox::information(this,"??????","???????????????",QMessageBox::Ok);
                    }
                    if(op==-1){
                        QMessageBox::information(this,"??????","???????????????",QMessageBox::Ok);
                    }
                    if(op==-2){
                        QMessageBox::information(this,"??????","????????????????????????",QMessageBox::Ok);
                    }
                    if(op == -3){
                        QMessageBox::information(this,"??????","???????????????????????????",QMessageBox::Ok);
                    }
                }else if(type == "table" && strlist[6] == "database"&&strlist[5]=="in"&&strlist[3]=="to"){
                    table tbl(username,strlist[7],strlist[4]);
                    QString dbName = strlist[7];
                    QString pathName = QCoreApplication::applicationDirPath()+"/data/"+username+"/"+dbName;
                    QString fileName =  pathName+"/logfile.log";
                    QFile file(fileName);
                    file.open(QIODevice::Append|QIODevice::Text);
                    if(file.isOpen())
                    {
                         QFileInfo info(fileName);
                         //QString str = info.birthTime().toString();
                         QString lastModified = info.lastModified().toString();
                         QString dbInfo = username+"#"+dbName+"#"+ pathName+"#"+lastModified+"#"+strExec+"#"+"??????";//#???????????????
                         QTextStream out(&file);//??????
                         out << dbInfo<<endl;
                         file.close();
                    }
                    else
                    {
                        //?????????????????????????????????
                        file.close();
                    }
                    int op = tbl.rename_tbl(username, strlist[2], strlist[4], strlist[7]);
                    if(op == 1){
                        QMessageBox::information(this,"??????","????????????????????????",QMessageBox::Ok);
                    }else if(op ==2){
                        QMessageBox::information(this,"??????","??????????????????????????????????????????",QMessageBox::Ok);
                    }else if(op == 3){
                        QMessageBox::information(this,"??????","????????????????????????????????????",QMessageBox::Ok);
                    }else if(op == 4){
                        QMessageBox::information(this,"??????","???????????????",QMessageBox::Ok);
                    }else if(op == 5){
                        QMessageBox::information(this,"??????","???????????????????????????",QMessageBox::Ok);
                    }else if(op == 6){
                        QMessageBox::information(this,"??????","???????????????????????????????????????",QMessageBox::Ok);
                    }
                    else{
                        //????????????
                        QMessageBox::information(this,"??????","???????????????",QMessageBox::Ok);
                    }
                }else{
                    QMessageBox::information(this,"??????","??????????????????????????????",QMessageBox::Ok);
                }
                ui->textInput->clear();
            }
            else if(opt8 == 0)
            {
                //strlist??????????????????3???????????? open???database???????????????
                //????????????????????????????????????????????????????????????
                //?????????database????????????????????????
                //??????????????????????????????????????????????????????
                QString letter = strlist[1];
                if(letter == "database"){
                    QString dbname = strlist[2];    //?????????????????????????????????????????????
                    QString dbName = dbname;
                    QString pathName = QCoreApplication::applicationDirPath()+"/data/"+username+"/"+dbName;
                    QString fileName =  pathName+"/logfile.log";
                    QFile file(fileName);
                    file.open(QIODevice::Append|QIODevice::Text);
                    if(file.isOpen())
                    {
                         QFileInfo info(fileName);
                         //QString str = info.birthTime().toString();
                         QString lastModified = info.lastModified().toString();
                         QString dbInfo = username+"#"+dbName+"#"+ pathName+"#"+lastModified+"#"+strExec+"#"+"??????";//#???????????????
                         QTextStream out(&file);//??????
                         out << dbInfo<<endl;
                         file.close();
                    }
                    else
                    {
                        //?????????????????????????????????
                        file.close();
                    }
                    qDebug() << dbname << endl;
                    Database db(username,dbname);
                    int op = db.open_database(dbname,username);
                    if(op == -1){
                        QMessageBox::information(this,"??????","?????????????????????",QMessageBox::Ok);
                    }else if(op == 1){
                        QMessageBox::information(this,"??????","????????????????????????",QMessageBox::Ok);
                    }else if(op == -4){
                        QMessageBox::information(this,"??????","???????????????????????????",QMessageBox::Ok);
                    }
                }else{
                    QMessageBox::information(this,"??????","??????????????????????????????",QMessageBox::Ok);
                }
                ui->textInput->clear();         //??????
            }
            else if(opt9 == 0){
                QString letter = strlist[1];
                if(letter == "database"){
                    QString dbname = strlist[2];
                    QString dbName = dbname;
                    QString pathName = QCoreApplication::applicationDirPath()+"/data/"+username+"/"+dbName;
                    QString fileName =  pathName+"/logfile.log";
                    QFile file(fileName);
                    file.open(QIODevice::Append|QIODevice::Text);
                    if(file.isOpen())
                    {
                         QFileInfo info(fileName);
                         //QString str = info.birthTime().toString();
                         QString lastModified = info.lastModified().toString();
                         QString dbInfo = username+"#"+dbName+"#"+ pathName+"#"+lastModified+"#"+strExec+"#"+"??????";//#???????????????
                         QTextStream out(&file);//??????
                         out << dbInfo<<endl;
                         file.close();
                    }
                    else
                    {
                        //?????????????????????????????????
                        file.close();
                    }
                    qDebug() << dbname << endl;
                    Database db(username,dbname);
                    int op = db.close_database(dbname,username);
                    if(op == -1){
                        QMessageBox::information(this,"??????","?????????????????????",QMessageBox::Ok);
                    }else if(op == 1){
                        QMessageBox::information(this,"??????","????????????????????????",QMessageBox::Ok);
                    }
                }else{
                    QMessageBox::information(this,"??????","??????????????????????????????",QMessageBox::Ok);
                }
                ui->textInput->clear();         //??????
            }
            else
            {
                QMessageBox::information(this,"??????","??????????????????",QMessageBox::Ok);
                ui->textInput->clear();         //??????
            }

        }
        else
        {
             qDebug() << "power fail" << endl;
        }
      }


}

//???????????????????????????????????????????????????????????????
void MainWindow::display()
{
    ui->fileDisplay->setFont(QFont("Timers", 16, QFont::Bold));
    Display *d = new Display(username);
    ui->fileDisplay->setText(d->getText());
    ui->fileDisplay->setEnabled(false);
}

void MainWindow::on_refreshButton_clicked()
{
    this->display();
}

