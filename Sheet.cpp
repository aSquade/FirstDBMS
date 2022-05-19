#include "sheet.h"
Sheet::Sheet(){

}
Sheet::Sheet(QString username,QString tableName,QString databasename){
    this->tableName=tableName;
    this->databasename=databasename;
    this->username = username;
    //打开字段文件
    QFile f(QCoreApplication::applicationDirPath()+'/'+"data/"+username+'/'+
            databasename+'/'+tableName+'/'+tableName+".tdf");
    if(!f.exists())
    {
         throw QString("table "+tableName+" is not exist!");
    }
    else if(!readHead()||!readData()){
       throw QString("table "+tableName+":There is no or exception");
    }
}

bool Sheet::readHead(){
    //读取字段文件
    QFile f(QCoreApplication::applicationDirPath()+'/'+"data/"+username+'/'+
            databasename+'/'+tableName+'/'+tableName+".tdf");
    if(!f.open(QIODevice::ReadOnly|QIODevice::Text)){
        throw QString("table "+tableName+":The field file cannot be opened");
        return false;
    }
    //记录字段属性
    while(!f.atEnd()){
        QByteArray line = f.readLine();
        QString str(line);
        str = str.simplified();
        QStringList list = str.split("#");
        field row;
        row.set_name(list.at(0));
        row.set_dataType(list.at(1));
        //row.set_PK(list.at(2));//主键
        //row.set_unique(list.at(3));//唯一性
        //row.set_notNull(list.at(4));//非空
        //row.set_defaultValue(list.at(5));//默认值
        head.append(row);
    }
    f.close();
    return true;
}
void Sheet::setData(QVector<QVector<QString> > newData){
    this->data=newData;
}
void Sheet::setHead(QVector<field > newHead){
    this->head=newHead;
}
bool Sheet::readData(){
    //读取数据文件
    QFile f(QCoreApplication::applicationDirPath()+'/'+"data/"+username+'/'+
            databasename+'/'+tableName+'/'+tableName+".trd");
    if(!f.open(QIODevice::ReadOnly|QIODevice::Text)){
        throw QString("table"+tableName+"The data file could not be opened");
        return false;
    }
    while(!f.atEnd()){
        QVector<QString> row;
        QByteArray line = f.readLine();
        QString str(line);
//        str = str.simplified();
        QStringList list = str.split("#");
        for(int i=0;i<list.size();i++){
            if(list.at(i)!="\n"){
                QStringList li = list.at(i).split(":");
                row.append(li.at(1));
            }
        }
        data.append(row);
    }
    f.close();
    return true;
}
QVector<field> Sheet::getHead(){
    return head;
}
QVector<QVector<QString>> Sheet::getData(){
    return data;
}
int Sheet::getFieldIndex(QString name){
    for(int i=0;i<head.size();i++){
        if(head[i].get_name()==name){
            return i;
        }
    }
    return -1;
}
QString Sheet::getFieldType(QString name){
    for(int i=0;i<head.size();i++){
        if(head[i].get_name()==name){
            return head[i].get_dataType();
        }
    }
    throw QString("Unknown field"+name);
    return "";
}
QVector<int> Sheet::FindAllData(QString column, QString judge, QString condtion){
    QVector<int> all;
    int order = getFieldIndex(column);
    if(order==-1){
        throw QString("Unknown field"+column);
    }
    //qDebug()<<condtion;
    int order2 = getFieldIndex(condtion);
   // qDebug()<<"order2:"<<order2;

    for(int j=0;j<data.size();j++){
        if(order2!=-1){
            condtion = data[j].at(order2);
            //qDebug()<<"111:"<<condtion;
            //qDebug()<<"222"<<data[j][order2];
        }
        if(judge==">="){
            if(data.at(j).at(order)>=condtion){
                all.append(j);
            }
        }
        else if(judge=="<="){
            if(data.at(j).at(order)<=condtion){
                all.append(j);
            }
        }
        else if(judge=="!="){
            if(data.at(j).at(order)!=condtion){
                all.append(j);
            }
        }
        else if(judge==">"){
            if(data.at(j).at(order)>condtion){
                all.append(j);
            }
        }
        else if(judge=="<"){
            if(data.at(j).at(order)<condtion){
                all.append(j);
            }
        }
        else if(judge=="="){
            if(data.at(j).at(order)==condtion){
                all.append(j);
            }
        }
    }
    return all;
}
//得到两个表的笛卡尔积
Sheet Sheet::Cartesian(Sheet t){
    Sheet newT;
    QString sameFieldName;
    int id=-1;
    //添加字段
    if(newT.tableName.isEmpty()){
        newT.tableName=t.getTableName();
    }
    for(int i=0;i<t.getHead().size();i++){
        id = getFieldIndex(t.getHead()[i].get_name());
        //具有相同字段时加前缀 table.field
        if(id!=-1){
            sameFieldName = head[id].get_name();
            QString newName;
            newName.append(t.getTableName());
            newName.append(".");
            newName.append(sameFieldName);
            t.head[i].set_name(newName);
            newName.clear();
            newName.append(tableName);
            newName.append(".");
            newName.append(sameFieldName);
            head[id].set_name(newName);
        }
        //newT.head.append(t.getHead()[i]);
    }
    //添加字段
    for(int i=0;i<getHead().size();i++){
      newT.head.append(getHead()[i]);
    }
    for(int i=0;i<t.getHead().size();i++){
        newT.head.append(t.getHead()[i]);
    }
    //添加数据
    if(getData().size()==0){
        for(int j=0;j<t.getData().size();j++){
            QVector<QString> row;
            row.append(t.getData()[j]);
            newT.data.append(row);
        }
    }
    else if(t.getData().size()==0){
        for(int j=0;j<getData().size();j++){
            QVector<QString> row;
            row.append(getData()[j]);
            newT.data.append(row);
        }
    }
    else{
        for(int i=0;i<getData().size();i++){
            for(int j=0;j<t.getData().size();j++){
                QVector<QString> row;
                row.append(getData()[i]);
                row.append(t.getData()[j]);
                newT.data.append(row);
            }
        }
    }
    return newT;
}
QString Sheet::getTableName(){
    return tableName;
}
QVector<int> Sheet::getWhere(QStringList judgeList){
    QString temp;
    QRegularExpression re("([A-Za-z_\\.]+)\\s?(>|<|>=|<=|!=|=)\\s?([\\w\\.]+)");
    QRegularExpressionMatch match;
    QString column;
    QString judge;
    QString value;
    QVector<int> OR;
    // or判断
    for(int i=0;i<judgeList.size();i++){
        temp=judgeList[i];
        qDebug()<<"temp"<<temp;
        QVector<int> AND;
        // and 判断
        if(temp.contains(" and ")){
            QStringList AndList = temp.split(" and ");
            for(int i=0;i<AndList.size();i++){
                QVector<int> tem;
                match = re.match(AndList[i]);
                if(match.hasMatch())
                {
                    column = match.captured(1);
                    judge=match.captured(2);
                    value = match.captured(3);
                    //判断字段是否存在
                    if(getFieldIndex(column)==-1){
                        throw QString("出现未知字段");
                    }
                    tem = FindAllData(column,judge,value);
                    if(i==0){
                      AND=tem;
                    }
                    else{
                        //交集
                        QVector<int> temAND;
                        std::sort(tem.begin(),tem.end());
                        std::sort(AND.begin(),AND.end());
                        std::set_intersection(AND.begin(),AND.end(),tem.begin(),tem.end(),std::back_inserter(temAND));
                        AND = temAND;
                    }
                }
                else {
                    AND.clear();
                }
            }
            //并集
            QVector<int> ORAND;
            std::sort(OR.begin(),OR.end());
            std::sort(AND.begin(),AND.end());
            std::set_union(AND.begin(),AND.end(),OR.begin(),OR.end(),std::back_inserter(ORAND));
            OR = ORAND;
        }
        else{
            QVector<int> tem;
            match = re.match(temp);
            if(match.hasMatch())
            {
                column = match.captured(1);
                judge=match.captured(2);
                value = match.captured(3);
                qDebug()<<"column"<<column;
                tem = FindAllData(column,judge,value);
            }
            else{
                throw QString("匹配失败");
            }
            //做并集
            QVector<int> temOR;
            std::sort(OR.begin(),OR.end());
            std::sort(tem.begin(),tem.end());
            std::set_union(tem.begin(),tem.end(),OR.begin(),OR.end(),std::back_inserter(temOR));
            OR = temOR;
        }
    }
    return OR;
}

Sheet Sheet::SelectData(QStringList columnList){
    Sheet t;
    //全参
    if(columnList[0]=="*"){
        for(int i=0;i<getHead().size();i++){
            field row;
            row.set_name(getHead()[i].get_name());
            row.set_dataType(getHead()[i].get_dataType());
            t.head.append(row);
        }
    }
    //部分参
    else{
        for(int i=0;i<columnList.size();i++){
            field row;
            //存在未知字段
            if(getFieldIndex(columnList.at(i))==-1){
                throw QString("There is an unknown field"+columnList.at(i));
            }
            row.set_name(columnList.at(i));
            row.set_dataType(getFieldType(columnList.at(i)));
            t.head.append(row);
        }
    }
    for(int i=0;i<getData().size();i++){
        QVector<QString> row;
        for(int j=0;j<getHead().size();j++){
            if(t.getFieldIndex(getHead()[j].get_name())!=-1){
                row.append(getData()[i][j]);
            }
        }
        t.data.append(row);
    }
    return t;
}
bool Sheet::ExistinTable(QVector<QString> row){
    bool same = true;
    for(int i=0;i<this->data.size();i++){
        same=true;
        for(int j=0;j<this->head.size();j++){
            if(this->data[i][j]!=row[j]){
                same=false;
                break;
            }
        }
        if(same){
            return true;
        }
    }
    return false;
}


