#include "mainpage.h"
#include "ui_mainpage.h"
#include <QtDebug>
#include <Qdir>
#include <QFileInfo>
#include<QtXml>
#include<QFileDialog>



QString globalpath;
QString qmakepath;
QString makepath;

Mainpage::Mainpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Mainpage)
{
    ui->setupUi(this);
    QObject::connect(this,SIGNAL(mainpageopened()),this,SLOT(opengroup()));


     mainpageopened();
}////////////////End Constructor1
Mainpage::Mainpage(QString appdirpath) :

    ui(new Ui::Mainpage)
{
    appdir=appdirpath;
    qDebug()<<appdir<<"import dir";
    globalpath=appdir;
    ui->setupUi(this);
    QObject::connect(this,SIGNAL(mainpageopened()),this,SLOT(opengroup()));

     mainpageopened();
}

Mainpage::~Mainpage()
{
    delete ui;
}
void Mainpage::opengroup()
{

    if(ui->testlistwidget->selectedItems().size()==0)
    {ui->removegroup->setEnabled(false);
    ui->addpro->setEnabled(false);}else{ui->removegroup->setEnabled(true); ui->addpro->setEnabled(true);}
    if(ui->testlistwidget2->selectedItems().size()==0)
    {ui->removepro->setEnabled(false);}else{ui->removepro->setEnabled(true);}


    QDir groupdir;

    groupdir.setCurrent(appdir);



    qDebug()<<groupdir.absoluteFilePath("TEST_GROUP.xml");

     QFile groupfile(groupdir.absoluteFilePath("TEST_GROUP.xml"));



    qDebug()<<groupfile.open(QIODevice::ReadOnly);
    qDebug()<<"Group Opened";

QDomDocument groupdoc;
qDebug()<<groupdoc.setContent(&groupfile)<<"file";

QDomElement groupdocelem=groupdoc.documentElement();
qDebug()<<groupdocelem.tagName();
QDomNode groupnode=groupdocelem.firstChild();



while(!groupnode.isNull())
{
    ui->testlistwidget->addItem(groupnode.toElement().attributeNode("name").value());
groupnode=groupnode.nextSibling();
}
 groupfile.close();
 qDebug()<<"Group Closed";

 QFile exe1(groupdir.absoluteFilePath("qmakepath.txt"));
 if (!exe1.exists()){ui->qmakelabel->setText("No File Selected");}
 else
 {
 exe1.open(QIODevice::ReadOnly);
 QTextStream ts(&exe1);
 qmakepath=ts.readLine();
 ui->qmakelabel->setText(qmakepath);
 }
 exe1.close();

 QFile exe2(groupdir.absoluteFilePath("makepath.txt"));
 if (!exe2.exists()){ui->makelabel->setText("No File Selected");}
 else
 {
     exe2.open(QIODevice::ReadOnly);
     QTextStream ts(&exe2);
     makepath=ts.readLine();
     ui->makelabel->setText(makepath);
 }
exe2.close();




}//////////End opengroup///////////////////////////

void Mainpage::openfiledialog()
{

    QDir groupdir ;
    groupdir.setCurrent(appdir);
     QFile groupfile(groupdir.absoluteFilePath("TEST_GROUP.xml"));
     /////////read xml
     qDebug()<<groupfile.open(QIODevice::ReadWrite)<<"File Opened from button";
     QDomDocument groupdoc;
     qDebug()<<groupdoc.setContent(&groupfile)<<"file from button";
     groupfile.close();
     if(groupdoc.documentElement().tagName()!="root")
     {
         QDomElement root=groupdoc.createElement("root");

    groupdoc.appendChild(root);

     }




    QStringList filename =QFileDialog::getOpenFileNames(this,"Choose Files",QDir::currentPath(),"XML GroupList(*.xml)");
    for(int i=0;i<filename.size();++i)
    {


          ///////////manipulate xml
         QDir dir=QDir(filename.value(i));
         qDebug()<<dir.dirName();

         QDomElement a =groupdoc.createElement("filename");
         a.setAttribute("name",dir.dirName());
         QDomText b=groupdoc.createTextNode(filename.value(i));
         groupdoc.firstChild().appendChild(a);
         a.appendChild(b);

         //////////write xml


     qDebug()<<filename.value(i);
    }

    qDebug()<<groupfile.open(QIODevice::ReadWrite|QIODevice::Text);
    QTextStream stream(&groupfile);

    groupdoc.save(stream,2);


   groupfile.close();
   qDebug()<<"Files Closed";
   ui->testlistwidget->clear();
   mainpageopened();



}////////////End openfiledialog

void Mainpage::removegroup()
{
    QDir groupdir ;
   groupdir.setCurrent(appdir);
    qDebug()<<groupdir.absoluteFilePath("TEST_GROUP.xml");

     QFile groupfile(groupdir.absoluteFilePath("TEST_GROUP.xml"));



    qDebug()<<groupfile.open(QIODevice::ReadOnly|QIODevice::Text);
    qDebug()<<"Group Opened";

QDomDocument groupdoc;
groupdoc.setContent(&groupfile);
groupfile.close();
QDomElement groupdocelem=groupdoc.documentElement();
qDebug()<<groupdocelem.tagName();
QDomNode groupnode=groupdocelem.firstChild();
for(int i=0;i<ui->testlistwidget->currentRow();i++)
{
    if(ui->testlistwidget->currentRow()!=0)
        groupnode=groupnode.nextSibling();

}
groupdocelem.removeChild(groupnode);
qDebug()<<groupfile.open(QIODevice::WriteOnly|QIODevice::Text);
qDebug()<<"Group Opened for write";

QTextStream stream(&groupfile);

groupdoc.save(stream,2);


groupfile.close();
ui->testlistwidget->clear();
mainpageopened();
}////////End removegroup

void Mainpage::removebuttonenable()
{
ui->removegroup->setEnabled(true);
 ui->addpro->setEnabled(true);
}//////////Endremovebuttonenable

void Mainpage::removeproenable()
{
ui->removepro->setEnabled(true);
}

void Mainpage::firstlistitemselected()
{
//////////////////////////////////////////////
     ui->testlistwidget2->clear();
    QDir groupdir ;
    groupdir.setCurrent(appdir);
    qDebug()<<groupdir.absoluteFilePath("TEST_GROUP.xml");

     QFile groupfile(groupdir.absoluteFilePath("TEST_GROUP.xml"));



    qDebug()<<groupfile.open(QIODevice::ReadOnly|QIODevice::Text);
    qDebug()<<"Group Opened";

QDomDocument groupdoc;
groupdoc.setContent(&groupfile);
groupfile.close();
QDomElement groupdocelem=groupdoc.documentElement();
qDebug()<<groupdocelem.tagName();
QDomNode groupnode=groupdocelem.firstChild();
for(int i=0;i<ui->testlistwidget->currentRow();i++)
{
    if(ui->testlistwidget->currentRow()!=0)
        groupnode=groupnode.nextSibling();

}
/////////////////////////////////////////////
/////////////////////////////////////////////
qDebug()<<groupnode.toElement().attribute("name","");
globalpath=groupnode.firstChild().toText().data();
qDebug()<<globalpath;


QFile selectedfile(globalpath);
qDebug()<<selectedfile.open(QIODevice::ReadOnly|QIODevice::Text);
qDebug()<<"Group Opened";
QDomDocument selecteddoc;
selecteddoc.setContent(&selectedfile);
selectedfile.close();


QDomElement selectedelem=selecteddoc.documentElement();
QDomNode selectednode=selectedelem.firstChild();

while(!selectednode.isNull())
{
    ui->testlistwidget2->addItem(selectednode.toElement().attributeNode("name").value());
selectednode=selectednode.nextSibling();
}


}///////////End firstlistitemselected

void Mainpage::openprodialog()
{
qDebug()<<globalpath;
     QFile profile(globalpath);
     /////////read xml
     qDebug()<<profile.open(QIODevice::ReadWrite)<<"File Opened from profile";
     QDomDocument prodoc;
     qDebug()<<prodoc.setContent(&profile)<<"file from glo";
     profile.close();
     if(prodoc.documentElement().tagName()!="root")
     {
         QDomElement root=prodoc.createElement("root");

    prodoc.appendChild(root);

     }




    QStringList filename =QFileDialog::getOpenFileNames(this,"Choose Files",QDir::currentPath(),"Qt Project File(*.pro)");
    for(int i=0;i<filename.size();++i)
    {


          ///////////manipulate xml
         QDir dir=QDir(filename.value(i));
         qDebug()<<dir.dirName();

         QDomElement a =prodoc.createElement("filename");
         a.setAttribute("name",dir.dirName());
         QDomText b=prodoc.createTextNode(filename.value(i));
        prodoc.firstChild().appendChild(a);
         a.appendChild(b);

         //////////write xml


     qDebug()<<filename.value(i);
    }

    qDebug()<<profile.open(QIODevice::ReadWrite|QIODevice::Text);
    QTextStream stream(&profile);

    prodoc.save(stream,2);


   profile.close();
   qDebug()<<"Files Closed";
   firstlistitemselected();


}////////////////////End openprodialog

void Mainpage::secondlistselected()
{
ui->removepro->setEnabled(true);
}///////////////End secondlistselected

void Mainpage::removepro()
{


     QFile groupfile(globalpath);



    qDebug()<<groupfile.open(QIODevice::ReadOnly|QIODevice::Text);
    qDebug()<<"Group Opened";

QDomDocument groupdoc;
groupdoc.setContent(&groupfile);
groupfile.close();
QDomElement groupdocelem=groupdoc.documentElement();
qDebug()<<groupdocelem.tagName();
QDomNode groupnode=groupdocelem.firstChild();
for(int i=0;i<ui->testlistwidget2->currentRow();i++)
{
    if(ui->testlistwidget2->currentRow()!=0)
        groupnode=groupnode.nextSibling();

}
groupdocelem.removeChild(groupnode);
qDebug()<<groupfile.open(QIODevice::WriteOnly|QIODevice::Text);
qDebug()<<"Group Opened for write";

QTextStream stream(&groupfile);

groupdoc.save(stream,2);


groupfile.close();
ui->testlistwidget2->clear();
firstlistitemselected();
}

void Mainpage::dummyslot()
{
    //////dummy
    shellrun("D:/aaa/dummy.pro");
}

bool Mainpage::shellrun(QString dotprofilename)
{
    QDir app1(appdir);
    QDir prodir(dotprofilename);
    prodir.cdUp();
    qDebug()<<prodir.path()<<"path only";
    prodir.setCurrent(prodir.path());
    qDebug()<<prodir.currentPath()<<"shell";

 QProcess br;
 QStringList filename;
 filename<<dotprofilename;
 br.setWorkingDirectory(prodir.currentPath());

    br.start(qmakepath,filename);
    br.waitForFinished();
    qDebug()<<"fin1";
    if(!br.readAllStandardError().isEmpty()){return false;}


 QStringList filename2;
 br.setWorkingDirectory(prodir.currentPath());
 filename2<<"-f"<<"makefile.release";
 br.start(makepath,filename2);
 br.waitForFinished();
// qDebug()<<br.readAllStandardError();
 if(!br.readAllStandardError().isEmpty()){return false;}
 qDebug()<<"fin all";
}

void Mainpage::selectqmake()
{
    QString str=QFileDialog::getOpenFileName(this,"Choose Files",QDir::currentPath(),"qmake File(*.exe)");
    if(str!=NULL) {qmakepath=str;}
    QDir dir;
    dir.setCurrent(appdir);
    QFile file(dir.absoluteFilePath("qmakepath.txt"));


        file.open(QIODevice::WriteOnly);
        QTextStream text(&file);
        text<<qmakepath;
        file.close();
        ui->qmakelabel->setText(qmakepath);


}

void Mainpage::selectmake()
{
    QString str=QFileDialog::getOpenFileName(this,"Choose Files",QDir::currentPath(),"make File(*.exe)");
    if(str!=NULL) {makepath=str;}
    QDir dir;
    dir.setCurrent(appdir);
    QFile file(dir.absoluteFilePath("makepath.txt"));


        file.open(QIODevice::WriteOnly);
        QTextStream text(&file);
        text<<makepath;
        file.close();
        ui->makelabel->setText(makepath);
}
