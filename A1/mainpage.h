#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QMainWindow>


namespace Ui {
class Mainpage;
}

class Mainpage : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Mainpage(QWidget *parent = 0);
    explicit Mainpage(QString appdirpath);
    bool shellrun(QString dotprofilename);
    ~Mainpage();
    int compile_error_num;
    /////////////////////////////
    QString appdir;
    
private:
    Ui::Mainpage *ui;

signals :
    void mainpageopened();

private slots:
    void opengroup();
    void openfiledialog();
    void removegroup();
    void removebuttonenable();
    void removeproenable();
    void firstlistitemselected();
    void openprodialog();
    void secondlistselected();
    void removepro();
    void dummyslot();

    void selectqmake();
    void selectmake();
};///////////////////////////////////////////////////////////



#endif // MAINPAGE_H

