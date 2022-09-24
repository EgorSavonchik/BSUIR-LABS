#ifndef DIALOGCORRECT_H
#define DIALOGCORRECT_H

#include <QDialog>
#include "train.h"

namespace Ui {
class DialogCorrect;
}

class DialogCorrect : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCorrect(QWidget *parent = nullptr);
    ~DialogCorrect();
    QString filename;
    train returnAdd;

    bool normaltrain = false;
    bool normalToInt(QString str);

    void setTrain(train input);
signals:
    void correctClose();
private slots:
    void on_pushButton_clicked();
private:
    Ui::DialogCorrect *ui;
};

#endif // DIALOGCORRECT_H
