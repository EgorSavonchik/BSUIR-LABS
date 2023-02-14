#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tree.insert(4, 4);
    tree.insert(2, 2);
    tree.insert(3, 3);
    tree.insert(1, 1);
    tree.insert(5, 5);

    QTreeWidgetItem* r = new QTreeWidgetItem;

    if(tree.root)
    {
        tree.vis(r);
    }

    ui->deleteEdit->setInputMask("00000");
    ui->searchEdit->setInputMask("00000");
    ui->keyEdit->setInputMask("00000");
    ui->valueEdit->setInputMask("00000");

    r->setText(0, "root");
    ui->treeWidget->clear();
    ui->treeWidget->addTopLevelItem(r);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    if(ui->keyEdit->text().isEmpty() || ui->valueEdit->text().isEmpty())
    {
        QMessageBox::information(this, "sosi", "edit empty");

        return;
    }

    if(tree.search(ui->keyEdit->text().toInt()))
    {
        QMessageBox::information(this, "sosi", "key exist");

        return;
    }

    tree.insert(ui->keyEdit->text().toInt(), ui->valueEdit->text().toInt());

    QTreeWidgetItem* r = new QTreeWidgetItem;

    if(tree.root)
    {
        tree.vis(r);
    }

    r->setText(0, "root");
    ui->treeWidget->clear();
    ui->treeWidget->addTopLevelItem(r);
}


void MainWindow::on_postOrderButton_clicked()
{
    if(!tree.root)
    {
        QMessageBox::information(this, "sosi", "tree empty");

        return;
    }

    ui->plainTextEdit->clear();

    list<int> temp;
    temp = tree.postorder();

    for(int i = 0; i < temp.size; i++)
    {
        ui->plainTextEdit->appendPlainText(QString::number(temp[i]));
    }
}


void MainWindow::on_inOrderButton_clicked()
{
    if(!tree.root)
    {
        QMessageBox::information(this, "sosi", "tree empty");

        return;
    }

    ui->plainTextEdit->clear();

    list<int> temp;
    temp = tree.inorder();

    for(int i = 0; i < temp.size; i++)
    {
        ui->plainTextEdit->appendPlainText(QString::number(temp[i]));
    }
}


void MainWindow::on_preOrderButton_clicked()
{
    if(!tree.root)
    {
        QMessageBox::information(this, "sosi", "tree empty");

        return;
    }

    ui->plainTextEdit->clear();

    list<int> temp;
    temp = tree.preorder();

    for(int i = 0; i < temp.size; i++)
    {
        ui->plainTextEdit->appendPlainText(QString::number(temp[i]));
    }
}


void MainWindow::on_deleteButton_clicked()
{
    if(ui->deleteEdit->text().isEmpty())
    {
        QMessageBox::information(this, "sosi", "edit empty");

        return;
    }

    if(!tree.root)
    {
        QMessageBox::information(this, "sosi", "tree empty");

        return;
    }

    tree.remove(ui->deleteEdit->text().toInt());
    ui->deleteEdit->clear();

    QTreeWidgetItem* r = new QTreeWidgetItem;

    if(tree.root)
    {
        tree.vis(r);
    }

    r->setText(0, "root");
    ui->treeWidget->clear();
    ui->treeWidget->addTopLevelItem(r);
}


void MainWindow::on_searchButton_clicked()
{
    if(ui->searchEdit->text().isEmpty())
    {
        QMessageBox::information(this, "sosi", "edit empty");

        return;
    }

    if(!tree.root)
    {
        QMessageBox::information(this, "sosi", "tree empty");

        return;
    }

    AVL::node* temp = tree.search(ui->searchEdit->text().toInt());

    if(temp)
    {
        ui->resultSearchEdit->setText(QString::number(temp->value));
    }
    else
    {
        ui->resultSearchEdit->setText("not found");
    }

}


void MainWindow::on_countButton_clicked()
{
    if(!tree.root)
    {
        QMessageBox::information(this, "sosi", "tree empty");

        return;
    }

    ui->nomer->setText(QString::number(tree.count()));
}


void MainWindow::on_pushButton_clicked()
{
    if(ui->keysEdit->text().isEmpty() || ui->valueEdit_2->text().isEmpty())
    {
        QMessageBox::information(this, "sosi", "edit empty");

        return;
    }

    QStringList keys = ui->keysEdit->text().split(' ');
    QStringList values = ui->valueEdit_2->text().split(' ');

    if(keys.size() != values.size())
    {
        QMessageBox::information(this, "sosi", "invalid arrays");

        return;
    }

    for(int i = 0; i < keys.size(); i++)
    {
        if((keys[i] != "0" && !keys[i].toInt()) || (values[i] != "0" && !values[i].toInt()))
        {
            QMessageBox::information(this, "sosi", "invalid arrays");

            return;
        }
    }

    if(tree.root)
    {
        tree.clear();
    }

    for(int i = 0; i < keys.size(); i++)
    {
        tree.insert(keys[i].toInt(), values[i].toInt());
    }

    QTreeWidgetItem* r = new QTreeWidgetItem;

    if(tree.root)
    {
        tree.vis(r);
    }

    r->setText(0, "root");
    ui->treeWidget->clear();
    ui->treeWidget->addTopLevelItem(r);
}

