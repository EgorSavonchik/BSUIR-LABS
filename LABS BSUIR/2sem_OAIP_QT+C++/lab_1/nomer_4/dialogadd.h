#ifndef DIALOGADD_H
#define DIALOGADD_H

#include <QDialog>
#include "train.h"
#include <QFile>

namespace Ui {
class DialogAdd;
}

class DialogAdd : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAdd(QWidget *parent = nullptr);
    ~DialogAdd();

    QString filename;
    train returnAdd;

    bool normaltrain = false;
    bool normalToInt(QString str);

    void setFile(QString file);
private slots:

    void on_pushButton_clicked();
signals:
    void addclose();


private:
    Ui::DialogAdd *ui;
};

#endif // DIALOGADD_H
